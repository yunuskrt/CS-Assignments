 <?php
    session_start();
    include "config.php";
    $uid = $_SESSION['userID'];

    //USER
    $user_data = mysqli_fetch_assoc(mysqli_query($db, "SELECT DateOfBirth,Username FROM Participant WHERE UserID = $uid"));
    $username = $user_data['Username'];
    $birthdate = $user_data['DateOfBirth'];
    $firstLetter = strtoupper($username[0]);

    //RATE
    $rate_data = mysqli_query($db, "SELECT R.MovieID, M.Title, R.NumericRating FROM Rate R, Movie M WHERE R.UserID = $uid AND R.MovieID = M.MovieID");
    ?>

 <!DOCTYPE html>
 <html>

 <head>
     <title>My Account</title>

     <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-0evHe/X+R7YkIZDRvuzKMRqM+OrBnVFBL6DOitfPri4tjfHxaWutUpFmBp4vmVor" crossorigin="anonymous">

     <style>
         .avatar {
             width: 300px;
             height: 300px;
             border-radius: 50%;
             background-color: gray;
             text-align: center;
             font-size: 200px;
             color: white;
         }
     </style>
 </head>

 <body>
     <nav class="navbar navbar-light" style="background-color: #e3f2fd;">
         <div class="container-fluid" style="padding: 20px;">
             <a class="navbar-brand" href="index.php">MovieBase</a>

             <a class="nav-link" href="admin.php">Admin Page</a>
             <a class="nav-link" href="movie.php">Movie Page</a>
             <a class="nav-link" href="filtermoviefrontend.php">Filter Page</a>
             <a class="nav-link" href="support.php">Support Page</a>
             <a class="nav-link" href="adminsupport.php">Admin Support Page</a>
             <a class="nav-link disabled" href="myaccount.php">My Account</a>
         </div>
     </nav>
     <div align="center">
         <br>
         <div class="avatar"><?php echo $firstLetter; ?></div>
         <br>
         <div>
             <?php echo "<b>Born in " . $birthdate . "</b><br><br>" . $uid . "   -   " . $username; ?>
         </div>
         <hr style="width: 75%">
         <br>
         <br>

         <h5><b>Rated Movies</b></h5>
         <br>
         <table class="table table-hover table-striped">

             <tr>
                 <th> MOVIE ID </th>
                 <th> MOVIE TITLE </th>
                 <th> RATING </th>
             </tr>

             <?php
                while ($row = mysqli_fetch_assoc($rate_data)) {
                    // MovieID-Title-NumericRating
                    $movie_id = $row['MovieID'];
                    $title = $row['Title'];
                    $rating = $row['NumericRating'];

                    echo "<tr>" . "<td>" . $movie_id . "</td>" . "<td>" . $title . "</td>" . "<td>" . $rating . "</td>" . "</tr>";
                }
                ?>
         </table>

     </div>
     <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/js/bootstrap.bundle.min.js" integrity="sha384-pprn3073KE6tl6bjs2QrFaJGz5/SUsLqktiwsUTF55Jfv3qYSDhgCecCxMW52nD2" crossorigin="anonymous"></script>
 </body>

 </html>