<!-- Support Page must cover the following specifications:
- Name of the user or guest should be given by user or guest
- Subject of the issue should be chosen from a dropdown menu (example: "Defected
Product", "Late Order", "Lost Product", "Suggestion")
- Chat Message
- Message Date
- Admin support page should be a separate page, so he/she can respond to that
SPECIFIC user or guest
- Users or guests must not see each other’s messages, so each support page must
be unique for each user or guest, admin can see all messages together -->

<?php
session_start();
include "config.php";
// $URL = "https://cs306-recit-default-rtdb.firebaseio.com/Chats.json";
$URL = "https://moviebase-befd5-default-rtdb.firebaseio.com/Chats.json";


function get_messages()
{
    global $URL;
    $ch = curl_init();
    curl_setopt_array($ch, [
        CURLOPT_URL => $URL,
        CURLOPT_POST => FALSE, // It will be a get request 
        CURLOPT_RETURNTRANSFER => true,
    ]);
    $response = curl_exec($ch);
    curl_close($ch);
    return json_decode($response, true);
}

function send_msg_as_admin($msg, $userid, $topic)
{
    global $URL;
    $ch = curl_init();
    $msg_json = new stdClass();
    $msg_json->msg_id = uniqid();
    $msg_json->user_id = $userid;
    $msg_json->msg = $msg;
    $msg_json->name = "admin";
    $msg_json->topic = $topic;
    $msg_json->time = date('H:i');
    $encoded_json_obj = json_encode($msg_json);
    curl_setopt_array($ch, array(
        CURLOPT_URL => $URL,
        CURLOPT_POST => TRUE,
        CURLOPT_RETURNTRANSFER => TRUE,
        CURLOPT_HTTPHEADER => array('Content-Type: application/json'),
        CURLOPT_POSTFIELDS => $encoded_json_obj
    ));
    $response = curl_exec($ch);
    return $response;
}

$msg_res_json = get_messages();

if (isset($_POST['msgs']) && isset($_POST['adminmsg'])) {
    $admin_msg = $_POST['adminmsg'];
    $msg_index = intval($_POST['msgs']);

    $keys = array_keys($msg_res_json);

    $user_id = $msg_res_json[$keys[$msg_index]]['user_id'];
    $topic = $msg_res_json[$keys[$msg_index]]['topic'];

    send_msg_as_admin($admin_msg, $user_id, $topic);
    //echo "Admin Message: " . $admin_msg . " UserID: " . $user_id . " Topic: " . $topic; 
}
?>


<!DOCTYPE html>
<html>

<head>
    <title>
        Admin Support
    </title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-0evHe/X+R7YkIZDRvuzKMRqM+OrBnVFBL6DOitfPri4tjfHxaWutUpFmBp4vmVor" crossorigin="anonymous">
    <style>
        table {
            font-family: arial, sans-serif;
            border-collapse: collapse;
            width: 100%;
        }

        td,
        th {
            border: 1px solid #dddddd;
            text-align: left;
            padding: 8px;
            color: #fafafa;
        }

        tr:nth-child(even) {
            background-color: #dddddd;
        }

        input[type=text],
        select {
            width: 100%;
            padding: 12px 20px;
            margin: 8px 0;
            display: inline-block;
            border: 1px solid #ccc;
            border-radius: 4px;
            box-sizing: border-box;
        }
    </style>

</head>

<body>
    <nav class="navbar navbar-light" style="background-color: #e3f2fd; margin-bottom: 25px;">
        <div class="container-fluid" style="padding: 20px;">
            <a class="navbar-brand" href="index.php">MovieBase</a>
            <a class="nav-link" href="admin.php">Admin Page</a>
            <a class="nav-link" href="movie.php">Movie Page</a>
            <a class="nav-link" href="filtermoviefrontend.php">Filter Page</a>
            <a class="nav-link" href="support.php">Support Page</a>
            <a class="nav-link disabled" href="adminsupport.php">Admin Support Page</a>
            <a class="nav-link" href="myaccount.php">My Account</a>
        </div>
    </nav>
    <div align="center">

        <table class="table table-hover table-primary">

            <tr>
                <th> MESSAGE ID </th>
                <th> USER ID </th>
                <th> NAME </th>
                <th>TOPIC</th>
                <th> MESSAGE </th>
                <th> TIME </th>
            </tr>
            <?php
            $keys = array_keys($msg_res_json);
            for ($i = 0; $i < count($keys); $i++) {
                $chat_msg = $msg_res_json[$keys[$i]];
                $msgid = $chat_msg['msg_id'];
                $uid = $chat_msg['user_id'];
                $msg = $chat_msg['msg'];
                $name = $chat_msg['name'];
                $topic = $chat_msg['topic'];
                $time = $chat_msg['time'];
                // $time = "16.34";
                if ($name != 'admin') {
                    echo  '
                    <tr>
                    <th> ' . $msgid . ' </th> 
                    <th> ' . $uid . ' </th>
                    <th> ' . $name . ' </th>
                    <th> ' . $topic . ' </th>
                    <th> ' . $msg . ' </th>
                    <th> ' . $time . ' </th>
                    </tr>';
                }
            }
            ?>
        </table>

        <form action="adminsupport.php" method="POST">
            <br>
            <br>
            <br>
            <b>Respond to Message</b>
            <br>
            <br>
            <br>
            <select name="msgs">
                <?php
                $keys = array_keys($msg_res_json);
                for ($i = 0; $i < count($keys); $i++) {
                    $chat_msg = $msg_res_json[$keys[$i]];
                    $msgid = $chat_msg['msg_id'];
                    $name = $chat_msg['name'];
                    if ($name != 'admin') {
                        echo "<option value=$i>" . $msgid . "-" . $name . "</option>";
                    }
                }
                ?>
            </select>
            <br>
            <br>
            <div class="input-group justify-content-center">
                <div class="form-group">
                    <input type="text" name="adminmsg" placeholder="Type your response "><br>
                </div>
            </div>

            <button class="btn btn-outline-primary">Respond</button>
        </form>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/js/bootstrap.bundle.min.js" integrity="sha384-pprn3073KE6tl6bjs2QrFaJGz5/SUsLqktiwsUTF55Jfv3qYSDhgCecCxMW52nD2" crossorigin="anonymous"></script>
</body>

</html>