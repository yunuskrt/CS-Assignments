<!DOCtype html>
<html>

<head>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-0evHe/X+R7YkIZDRvuzKMRqM+OrBnVFBL6DOitfPri4tjfHxaWutUpFmBp4vmVor" crossorigin="anonymous">
    <title>
        Create User
    </title>
    <style>
        .notif {
            background-color: cornflowerblue;
            color: #fafafa;
            border-radius: 5px;
            width: 50%;
            margin: auto;
            margin-top: 5px;
            height: 50px;
            text-align: center;
            padding-top: 10px;
            font-size: 20px;
        }
    </style>
</head>

<body>
    <br><br><br>
    <div class="notif">
        Enter date of birth, username and a different user id to register a user.
    </div>

    <div class="container justify-content-center align-items-center">
        <div class="row justify-content-center" style="margin-top: 100px;">
            <div class="col-lg-4 col-md-6 col-sm-6">
                <div class="card shadowy" style="background-color: cornflowerblue;">
                    <div class="card-title text-center border-bottom">
                        <h2 class="p-3 text-white">Login | Register</h2>
                    </div>
                    <div class="card-body d-flex justify-content-center">
                        <form action="createuser.php" method="POST">
                            <!-- date_of_birth date
                            username string
                            userID integer -->
                            <div class="mb-4">
                                <label for="date_of_birth" class="form-label text-white">Date Of Birth</label>
                                <input type="date" class="form-control" id="date_of_birth" name="date_of_birth" />
                            </div>
                            <div class="mb-4">
                                <label for="username" class="form-label text-white">Username</label>
                                <input type="text" class="form-control" id="username" name="username" />
                            </div>
                            <div class="mb-4">
                                <label for="userID" class="form-label text-white">User ID</label>
                                <input type="text" class="form-control" id="userID" name="userID" />
                            </div>
                            <div>
                                <button class="btn btn-outline-info btn-lg text-white" style="margin-left: 60px;">Login</button>
                            </div>
                        </form>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <script src=" https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/js/bootstrap.bundle.min.js" integrity="sha384-pprn3073KE6tl6bjs2QrFaJGz5/SUsLqktiwsUTF55Jfv3qYSDhgCecCxMW52nD2" crossorigin="anonymous"></script>
</body>


</html>