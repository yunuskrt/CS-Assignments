<!DOCTYPE html>
<html>

<head>
    <title>Rate</title>

    <style>
        .rate {
            width: 50%;
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

    <div align="center">
        <table class="table table-hover table-warninf">

            <tr>
                <th> User ID </th>
                <th> Rating Value </th>
                <th>Rate Date</th>
            </tr>

            <?php
            
            include "config.php";
            if (isset($_SESSION['movieID'])){
                $movie_id = $_SESSION['movieID'];
                $sql_statement = "SELECT UserID,NumericRating,RateDate FROM Rate WHERE MovieID = $movie_id";

                $result = mysqli_query($db, $sql_statement);

                while ($row = mysqli_fetch_assoc($result)) {
                    $user_id = $row['UserID'];
                    $numeric_rating = $row['NumericRating'];
                    $rate_date = $row['RateDate'];

                    echo "<tr>" . "<th>" . $user_id . "</th>" . "<th>" . $numeric_rating . "</th>" . "<th>" . $rate_date . "</th>" . "</tr>";
                }
            }
            ?>
        </table>
        <form action='ratemovie.php' method='POST'>
            <input type="number" name="ratings" step="0.1" min="0" max="5" class="rate">
            <br>
            <button class='btn btn-outline-warning'>Rate</button>
        </form>


    </div>

</body>

</html>