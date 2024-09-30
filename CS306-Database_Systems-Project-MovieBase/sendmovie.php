<?php

include "config.php";

if (isset($_POST['title']) and isset($_POST['date']) and isset($_POST['genre']) and isset($_POST['director']) and isset($_POST['producer'])){
$title = $_POST['title'];
$date = intval($_POST['date']);
$genre = $_POST['genre'];
$director = $_POST['director'];
$producer = $_POST['producer'];


mysqli_query($db, "INSERT INTO Movie(Title,ReleaseDate) VALUES ('$title','$date')");
$movieID = mysqli_insert_id($db);

mysqli_query($db, "INSERT INTO Director(DirectorName) VALUES ('$director')");
$dirID = mysqli_insert_id($db); 

mysqli_query($db, "INSERT INTO Producer(ProducerName) VALUES ('$producer')");
$proID = mysqli_insert_id($db);

mysqli_query($db, "INSERT INTO Directed(MovieID,DirID) VALUES ($movieID,$dirID)");

mysqli_query($db, "INSERT INTO Genre(Name) VALUES ('$genre')");
mysqli_query($db, "INSERT INTO Genre_Of(Name,MovieID) VALUES ('$genre',$movieID)");
mysqli_query($db, "INSERT INTO Produced(MovieID,ProID) VALUES ($movieID,$proID)");


header ("Location: admin.php");

}

else
{
    echo "The form is not set.";
}

?>