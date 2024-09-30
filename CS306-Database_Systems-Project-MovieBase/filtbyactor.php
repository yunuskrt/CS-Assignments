<!DOCTYPE html>
<html>
<head>
	<title>Movies</title>
    <style>
table {
  font-family: arial, sans-serif;
  border-collapse: collapse;
  width: 100%;
}

td, th {
  border: 1px solid #dddddd;
  text-align: left;
  padding: 8px;
}

tr:nth-child(even) {
  background-color: #dddddd;
}
</style>
</head>
<body>
    <div align="center">

	<table>
  <tr> <th> MOVIE ID </th> <th>  LEADING ACTOR </th> <th> TITLE </th> 
<?php

    include "config.php";



    if (isset($_POST['leadingActor'])){
        $leadingActor = ($_POST['leadingActor']);

        
        $actorID = mysqli_query($db,"SELECT A.ActorID FROM Actor A WHERE A.ActorName = $leadingActor" );
        $movieID = mysqli_query($db,"SELECT AC.MovieID FROM $actorID AC WHERE AC.ActorID = $actorID ");
        

        $sql_statement = "SELECT M.Title FROM $movieID M WHERE M.MovieID = $movieID AND EXISTS (SELECT A.ActorID FROM Actor A 
        WHERE A.ActorName = $leadingActor AND EXISTS (SELECT AC.MovieID FROM $actorID AC WHERE AC.ActorID = $actorID))";
        

        $result = mysqli_query($db,$sql_statement);
        
        while($row = mysqli_fetch_assoc($result))
        {
            $id = $row['MovieID'];
            $ActorName = $row['ActorName'];
            $title = $row['Title']; 
          
        
            echo "<tr>" . "<th>" . $id . "</th>" . "<th>" . $ActorName . "</th>" . "<th>" . $title . "</th>" . "</tr>";
        }
        
        }
        
        
        else
        {
            echo "The form is not set.";
        }
?>

</table>
</div>

</body>
</html>

