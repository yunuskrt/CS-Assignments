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
  <tr> <th> ID </th> <th>  RATING </th> <th> TITLE </th> 
<?php

    include "config.php";


    $minRate = 0.0;
    $maxRate = 5.0;

    if (isset($_POST['minRate'])){
        $minRate = intval($_POST['minRate']);
        $maxRate = intval($_POST['maxRate']);
        
        $sql_statement = "SELECT M.MovieID, R.NumericRating, M.Title
        FROM Movie M, Rate R
        WHERE M.MovieID = R.MovieID AND NumericRating >= $minRate AND NumericRating <= $maxRate
        ";


       
        $result = mysqli_query($db,$sql_statement);
        
        while($row = mysqli_fetch_assoc($result))
        {
            $id = $row['MovieID'];
            $NumericRating = $row['NumericRating'];
            $title = $row['Title']; 
          
        
            echo "<tr>" . "<th>" . $id . "</th>" . "<th>" . $NumericRating . "</th>" . "<th>" . $title . "</th>" . "</tr>";
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

