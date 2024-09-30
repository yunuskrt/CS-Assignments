<?php
include "config.php";
session_start();

if (isset($_SESSION['userID']) && isset ($_POST['ratings']) && isset($_SESSION['movieID']) ) {   
    // insert into rate table
    $user_id = $_SESSION['userID'];
    $rate = floatval($_POST['ratings']);
    $movie_id = $_SESSION['movieID'];
    $curr_date = date("Y-m-d");
    
    mysqli_query($db, "INSERT INTO Rate(UserID,NumericRating,MovieID,RateDate) 
                VALUES ($user_id,$rate,$movie_id,'$curr_date')");
    
    header ("Location: movie.php");
}