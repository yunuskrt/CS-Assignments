<!DOCTYPE html>
<html>

<head>
    <title>Movie</title>

    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-0evHe/X+R7YkIZDRvuzKMRqM+OrBnVFBL6DOitfPri4tjfHxaWutUpFmBp4vmVor" crossorigin="anonymous">

    <style>
        .movieTable {
            border-collapse: separate;
            border-spacing: 15px 55px;
        }



        .movieTable th,
        .movieTable td {
            width: 150px;
            text-align: center;
            border: 1px solid black;
            padding: 5px
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
    <nav class="navbar navbar-light" style="background-color: #e3f2fd;">
        <div class="container-fluid" style="padding: 20px;">
            <a class="navbar-brand" href="index.php">MovieBase</a>

            <a class="nav-link" href="admin.php">Admin Page</a>
            <a class="nav-link disabled" href="movie.php">Movie Page</a>
            <a class="nav-link" href="filtermoviefrontend.php">Filter Page</a>
            <a class="nav-link" href="support.php">Support Page</a>
            <a class="nav-link" href="adminsupport.php">Admin Support Page</a>
            <a class="nav-link" href="myaccount.php">My Account</a>
        </div>
    </nav>
    <div align="center">
        <br>
        <br>
        <br>

        <form method="POST">
            <select name="ids">
                <?php
                session_start();
                include "config.php";

                $sql_command = "SELECT MovieID,Title FROM Movie";

                $myresult = mysqli_query($db, $sql_command);

                while ($id_rows = mysqli_fetch_assoc($myresult)) {
                    $id = $id_rows['MovieID'];
                    $movName = $id_rows['Title'];
                    echo "<option value=$id>" . $id . "-" . $movName . "</option>";
                }
                ?>

            </select>
            <button class="btn btn-outline-warning">Display Movie</button>
        </form>

        <br>
        <br>

        <?php
        if (isset($_POST['ids'])) {

            $movie_id = $_POST['ids'];

            $mymovie = mysqli_fetch_assoc(mysqli_query($db, "SELECT * FROM Movie WHERE MovieID = $movie_id"));

            $dirId = mysqli_fetch_assoc(mysqli_query($db, "SELECT DirID FROM Directed WHERE MovieID = $movie_id"))['DirID'];
            $prodId = mysqli_fetch_assoc(mysqli_query($db, "SELECT ProID FROM Produced WHERE MovieID = $movie_id"))['ProID'];

            $dirName = mysqli_fetch_assoc(mysqli_query($db, "SELECT DirectorName FROM Director WHERE DirID = $dirId"))['DirectorName'];

            $relYear = $mymovie['ReleaseDate'];
            $title = $mymovie['Title'];

            $genreType = mysqli_fetch_assoc(mysqli_query($db, "SELECT Name FROM Genre_Of WHERE MovieID = $movie_id"))['Name'];
            $prodName = mysqli_fetch_assoc(mysqli_query($db, "SELECT ProducerName FROM Producer WHERE ProID = $prodId"))['ProducerName'];

            $rating_data = mysqli_fetch_assoc(mysqli_query($db, "SELECT AVG(NumericRating) AS Avg, COUNT(NumericRating) AS Cnt FROM Rate WHERE MovieID=$movie_id"));
            $rating_cnt = intval($rating_data['Cnt']);
            $ratingInfo = $rating_cnt == 0 ? "No ratings yet." :
                $rating_data['Avg'] . " (Average of " . $rating_cnt . " rates.)";

            $actorInfo = "";
            $result = mysqli_query($db, "SELECT ActorName FROM Actor WHERE ActorID IN (SELECT ActorID FROM Acted_In WHERE MovieID= $movie_id)");

            while ($row = mysqli_fetch_assoc($result)) {
                $actorInfo =  $row['ActorName'] . " | " . $actorInfo;
            }


            echo "<caption class='text-warning'>" . $title . "</caption>"
                . "<table class='table table-hover table-warning table-striped table-lg text-center movieTable'>"
                . "<tr>" . "<th>" . "Director" . "</th>" . "<td>" . $dirName . "</td>" . "</tr>"
                . "<tr>" . "<th>" . "Release Year" . "</th>" . "<td>" . $relYear . "</td>" . "</tr>"
                . "<tr>" . "<th>" . "Genre" . "</th>" . "<td>" . $genreType . "</td>" . "</tr>"
                . "<tr>" . "<th>" . "Producer" . "</th>" . "<td>" . $prodName . "</td>" . "</tr>"
                . "<tr>" . "<th>" . "Rating" . "</th>" . "<td>" . $ratingInfo . "</td>" . "</tr>"
                . "<tr>" . "<th>" . "Actors" . "</th>" . "<td>" . $actorInfo . "</td>" . "</tr>"
                . "</table" . "<br>" . "<br>" . "<br>";
            if (isset($_SESSION['userID'])) {
                $_SESSION['movieID'] = $movie_id;
                $uid = $_SESSION['userID'];
                $uname = mysqli_fetch_assoc(mysqli_query($db, "SELECT Username FROM Participant WHERE UserID = $uid"))['Username'];
                echo "<h4>" . $uname . ", Rate the Movie: " . "</h4>" . "<br>";
                include "rateform.php";
            } else {
            }
        } else {
            echo "Choose a Movie to display.";
        }
        ?>

        <br>
        <br>
        <br>
        <br>
        <br>

    </div>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/js/bootstrap.bundle.min.js" integrity="sha384-pprn3073KE6tl6bjs2QrFaJGz5/SUsLqktiwsUTF55Jfv3qYSDhgCecCxMW52nD2" crossorigin="anonymous"></script>
</body>

</html>