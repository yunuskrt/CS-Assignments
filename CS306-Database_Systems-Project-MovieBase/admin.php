<!DOCtype html>
<html>

<head>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-0evHe/X+R7YkIZDRvuzKMRqM+OrBnVFBL6DOitfPri4tjfHxaWutUpFmBp4vmVor" crossorigin="anonymous">
  <title>
    Main Page
  </title>
  <style>
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

    input[type=submit] {
      width: 100%;
      background-color: #4CAF50;
      color: white;
      padding: 14px 20px;
      margin: 8px 0;
      border: none;
      border-radius: 4px;
      cursor: pointer;
    }

    input[type=submit]:hover {
      background-color: #45a049;
    }

    .button2 {
      background-color: #4CAF50;
      border: none;
      color: white;
      padding: 15px 32px;
      text-align: center;
      text-decoration: none;
      display: inline-block;
      font-size: 16px;
      margin: 4px 2px;
      cursor: pointer;
    }

    /* Blue */

    div {
      border-radius: 5px;
      /* background-color: #f2f2f2; */
      padding: 20px;
    }
  </style>
</head>

<body>
  <nav class="navbar navbar-light" style="background-color: #e3f2fd;">
    <div class="container-fluid">
      <a class="navbar-brand" href="index.php">MovieBase</a>

      <a class="nav-link disabled" href="admin.php">Admin Page</a>
      <a class="nav-link" href="movie.php">Movie Page</a>
      <a class="nav-link" href="filtermoviefrontend.php">Filter Page</a>
      <a class="nav-link" href="support.php">Support Page</a>
      <a class="nav-link" href="adminsupport.php">Admin Support Page</a>
      <a class="nav-link" href="myaccount.php">My Account</a>
    </div>
  </nav>
  <div align="center ">

    <b>Welcome to Netflix Database</b>
    <br>
    <br>
    <br>
    <br>


    <?php
    include "config.php";
    include "movies.php";
    ?>
    <br>
    <br>
    <br>

    <b>Insert a Movie</b>
    <form action="sendmovie.php" method="POST">
      <div class="input-group justify-content-center">
        <div class="form-group">
          <input type="text" name="title" placeholder="Type title of movie"><br>
        </div>
        <div class="form-group">
          <input type="text" name="date" placeholder="Type release year"><br>
        </div>
        <br>
        <div class="form-group">
          <input type="text" name="genre" placeholder="Type genre of movie"><br>
        </div>
        <div class="form-group">
          <input type="text" name="director" placeholder="Type director of movie"><br>
        </div>
        <div class="form-group">
          <input type="text" name="producer" placeholder="Type producer of movie"><br>
        </div>
        <br>
      </div>
      <button class="btn btn-outline-dark btn-lg">INSERT</button>
    </form>

    <form action="sendactor.php" method="POST">
      <br>
      <br>
      <br>
      <b>Insert an Actor</b>
      <br>
      <br>
      <br>
      <select name="ids">

        <?php

        $sql_command = "SELECT MovieID,Title FROM Movie";

        $myresult = mysqli_query($db, $sql_command);

        while ($id_rows = mysqli_fetch_assoc($myresult)) {
          $id = $id_rows['MovieID'];
          $movName = $id_rows['Title'];
          echo "<option value=$id>" . $id . "-" . $movName . "</option>";
        }
        ?>

      </select>

      <br>
      <br>

      <div class="input-group justify-content-center">
        <div class="form-group">
          <input type="text" name="actorname" placeholder="Type name of actor"><br>
        </div>
        <div class="form-group">
          <input type="text" name="actorgender" placeholder="Type gender of actor"><br>
        </div>
      </div>

      <button class="btn btn-outline-dark">Add Actor</button>
    </form>

    <form action="delmovie.php" method="POST">
      <br>
      <br>
      <br>
      <b>Delete a Movie</b>
      <br>
      <br>
      <br>
      <select name="idx">

        <?php

        $sql_command = "SELECT MovieID,Title FROM Movie";

        $myresult = mysqli_query($db, $sql_command);

        while ($id_rows = mysqli_fetch_assoc($myresult)) {
          $id = $id_rows['MovieID'];
          $movName = $id_rows['Title'];
          echo "<option value=$id>" . $id . "-" . $movName . "</option>";
        }

        ?>
      </select>

      <button class="btn btn-outline-dark">Delete Movie</button>
    </form>
    <br>
    <br>
    <br>

  </div>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/js/bootstrap.bundle.min.js" integrity="sha384-pprn3073KE6tl6bjs2QrFaJGz5/SUsLqktiwsUTF55Jfv3qYSDhgCecCxMW52nD2" crossorigin="anonymous"></script>
</body>

</html>