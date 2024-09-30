<!DOCtype html>
<html>

<head>
    <title>
        Filter Movie
    </title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-0evHe/X+R7YkIZDRvuzKMRqM+OrBnVFBL6DOitfPri4tjfHxaWutUpFmBp4vmVor" crossorigin="anonymous">
</head>

<body>
    <nav class="navbar navbar-light" style="background-color: #e3f2fd;">
        <div class="container-fluid" style="padding: 20px;">
            <a class="navbar-brand" href="index.php">MovieBase</a>

            <a class="nav-link" href="admin.php">Admin Page</a>
            <a class="nav-link" href="movie.php">Movie Page</a>
            <a class="nav-link disabled" href="filtermoviefrontend.php">Filter Page</a>
            <a class="nav-link" href="support.php">Support Page</a>
            <a class="nav-link" href="adminsupport.php">Admin Support Page</a>
            <a class="nav-link" href="myaccount.php">My Account</a>
        </div>
    </nav>
    <br>
    <br>
    <div align="center ">
        <b>Filter Movies from Netflix Database</b>
        <br>
        <br>
        <br>
        <br>

        <form action="filtbyrating.php" method="POST">
            <input type="text" name="minRate" placeholder="Minimum Rate"><br>
            <input type="text" name="maxRate" placeholder="Maximum Rate"><br>

            <br>
            <button>FILTER BY RATING</button>
        </form>


        <form action="filtbyyear.php" method="POST">
            <input type="text" name="startYear" placeholder="Start Year"><br>
            <input type="text" name="endYear" placeholder="End Year"><br>


            <br>
            <button>FILTER BY YEAR</button>
        </form>
        <br>
        <br>
        <br>

    </div>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/js/bootstrap.bundle.min.js" integrity="sha384-pprn3073KE6tl6bjs2QrFaJGz5/SUsLqktiwsUTF55Jfv3qYSDhgCecCxMW52nD2" crossorigin="anonymous"></script>
</body>

</html>