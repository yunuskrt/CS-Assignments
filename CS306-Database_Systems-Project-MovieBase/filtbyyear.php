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
<tr> <th> ID </th> <th> RELEASE DATE </th> <th> TITLE </th> 
<?php

include "config.php";

if (isset($_POST['startYear'])){
$startYear = intval($_POST['startYear']);
$endYear = intval($_POST['endYear']);

$sql_statement = "SELECT * FROM Movie  WHERE ReleaseDate >= $startYear AND ReleaseDate <= $endYear";

$result = mysqli_query($db,$sql_statement);

while($row = mysqli_fetch_assoc($result))
{
    $id = $row['MovieID'];
    $releaseDate = $row['ReleaseDate'];
    $title = $row['Title'];

	echo "<tr>" . "<th>" . $id . "</th>" . "<th>" . $releaseDate . "</th>" . "<th>" . $title . "</th>" . "</tr>";
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