<?php

include "config.php";

if (isset($_POST['ids']) and isset($_POST['actorname']) and isset($_POST['actorgender'])){
$movie_id = $_POST['ids'];
$actor_name = $_POST['actorname'];
$actor_gender = $_POST['actorgender'];

mysqli_query($db, "INSERT INTO Actor(ActorName,Gender) VALUES ('$actor_name','$actor_gender')");
$actorID = mysqli_insert_id($db);

mysqli_query($db, "INSERT INTO Acted_In(MovieID,ActorID) VALUES ($movie_id,$actorID)");

header ("Location: admin.php");
}
else
{
    echo "The form is not set.";
}

?>