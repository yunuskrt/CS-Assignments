<?php
include "config.php";

if ( isset($_POST['date_of_birth']) && isset($_POST['username']) && isset($_POST['userID']) ) {
    // SELECT EXISTS(SELECT * from ExistsRowDemo WHERE ExistId=105)
    // $user_id = D
    // $dirId = mysqli_fetch_assoc(mysqli_query($db, "SELECT DirID FROM Directed WHERE MovieID = $movie_id"))['DirID'];
    $user_id = intval($_POST['userID']);   
    $uname = $_POST['username'];
    
    $numrows= mysqli_fetch_assoc(mysqli_query($db, "SELECT COUNT(1) AS Total, Username FROM Participant WHERE userID = $user_id"))['Total'];

    if($numrows == 0){ // No Match --> INSERT(REGISTER)
        $birth_date = strtotime($_POST['date_of_birth']);
        $birth_date = date('Y-m-d H:i:s', $birth_date);
        mysqli_query($db, "INSERT INTO Participant(DateOfBirth,Username,UserID) VALUES ('$birth_date','$uname',$user_id)");
        header("Location: index.php");
    } else { // User Exists - LOGIN
        session_start();
        $_SESSION['userID'] = $user_id;
        header("Location: admin.php");
    }
    
}
?>
