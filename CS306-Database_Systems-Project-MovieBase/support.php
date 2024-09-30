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

header("refresh: 60");

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

function send_msg($msg, $name, $topic)
{
    if (isset($_SESSION['userID'])) {
        global $URL;
        $ch = curl_init();
        $msg_json = new stdClass();
        $msg_json->msg_id = uniqid();
        $msg_json->user_id = $_SESSION['userID'];
        $msg_json->msg = $msg;
        $msg_json->name = $name;
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
}

$msg_res_json = get_messages();

if (isset($_POST['topic']) && isset($_POST['usermsg'])) {
    $user_msg = $_POST['usermsg'];
    if (isset($_SESSION['userID'])) {
        $uid = $_SESSION['userID'];
        $uname = mysqli_fetch_assoc(mysqli_query($db, "SELECT Username FROM Participant WHERE UserID = $uid"))['Username'];
    } else {
        $uname = "Guest";
    }
    $user_topic = $_POST['topic'];

    send_msg($user_msg, $uname, $user_topic);
    echo $user_msg;
}
?>


<!DOCTYPE html>
<html>

<head>
    <title>
        Support
    </title>
    <link rel="stylesheet" href="styles.css">
</head>
<div class="menu">
    <div class="back"><a href="admin.php" style="color:#fafafa;"><i class="fa fa-chevron-left"></i> <img src="https://i.imgur.com/DY6gND0.png" draggable="false" /></a></div>
    <div class="name">Support</div>
    <div class="last"><?php echo date('H:i') ?></div>
</div>
<ol class="chat">
    <?php
    $keys = array_keys($msg_res_json);
    for ($i = 0; $i < count($keys); $i++) {
        $chat_msg = $msg_res_json[$keys[$i]];
        $uid = $chat_msg['user_id'];
        $msg = $chat_msg['msg'];
        $name = $chat_msg['name'];
        $topic = $chat_msg['topic'];
        $time = $chat_msg['time'];
        // $time = "16.34";
        if ($uid == $_SESSION['userID']) {
            if ($name == 'admin') {
                $from = 'other';
            } else {
                $from = 'self';
            }
            echo  '
        <li class="' . $from . '">
        <div class="avatar">
                    <img src="https://i.imgur.com/DY6gND0.png" draggable="false"/>
                </div>
                    <div class="msg">
                        <p><u>' . $topic . '</u></p> <br>
                        <p><b>' . $name . '</b></p>
                        <p>' . $msg . '</p>
                        <time>' . $time . '</time>
                    </div>
                </li>';
        }
    }
    ?>
</ol>
<div style="position: absolute;
    bottom: 30px;
    width: 100%;">
    <form name=" form" action="support.php" method="POST">
        <select name="topic" class="topicselect">
            <option value="Report Movie">Report Movie</option>
            <option value="Comment Movie">Comment to Movie</option>
            <option value="Missing Movie">Missing Movie</option>
            <option value="Wrong Information">Wrong Information about Movie</option>
        </select>
        <input name="usermsg" class="textarea" type="text" placeholder="Type here!" />
        <input type="submit" style="display: none" />
    </form>
</div>