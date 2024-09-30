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
<tr> <th> ID </th> <th> GENRE </th> <th> TITLE </th> 
<?php

include "config.php";

if (isset($_POST['genre'])){

$genre = strval($_POST['genre']);

$sql_statement = "SELECT M.MovieID, G.Name, M.Title
FROM Movie M, Genre_Of G
WHERE M.MovieID = G.MovieID AND G.Name = $genre ";

$result = mysqli_query($db,$sql_statement);

while($row = mysqli_fetch_assoc($result))
{
    $id = $row['MovieID'];
    $genre = $row['Name'];
    $title = $row['Title'];

	echo "<tr>" . "<th>" . $id . "</th>" . "<th>" . $genre . "</th>" . "<th>" . $title . "</th>" . "</tr>";
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