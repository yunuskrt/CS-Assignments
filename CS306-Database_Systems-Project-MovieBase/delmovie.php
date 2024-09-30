<?php 

include "config.php";

if (isset($_POST['idx'])){

$selection_id = $_POST['idx'];


mysqli_query($db, "DELETE FROM Acted_In WHERE MovieID = $selection_id");
mysqli_query($db, "DELETE FROM Directed WHERE MovieID = $selection_id");
mysqli_query($db, "DELETE FROM Genre_Of WHERE MovieID = $selection_id");
mysqli_query($db, "DELETE FROM Produced WHERE MovieID = $selection_id");
mysqli_query($db, "DELETE FROM Movie WHERE MovieID = $selection_id");


header ("Location: admin.php");

}

else
{
	echo "The form is not set.";
}

?>