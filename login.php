<!DOCTYPE html>
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Logowanie</title>
    <meta name="description" content="blank">
	<meta name="keywords" content="IT">
    <meta name="author" content="L Rogowski">

    <link rel="Stylesheet" type="text/css" href="css/style.css"/>
    <link rel="Stylesheet" type="text/css" href="css/bootstrap.min.css"/>
    
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Oswald&display=swap" rel="stylesheet"> 

    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="js/bootstrap.min.js"></script>
    <style>
        body{
            background-image: url(img/bg_final.jpg);
            /*height: 1080px;*/
            background-attachment: fixed;
            background-position: center;
            background-repeat: no-repeat;
            background-size: cover;
        }

    </style>
</head>
<body>
    <form name="logowanko" class="vh-100" action="main.php" method="POST">
        <div class="container py-5 h-100">
            <div class="row d-flex justify-content-center align-items-center h-100">
            <div class="col-12 col-md-8 col-lg-6 col-xl-5">
                <div class="card bg-dark text-white" style="border-radius: 1rem;">
                <div class="card-body p-5 text-center">
        
                    <div class="mb-md-5 mt-md-4 pb-5">
        
                    <h2 class="display-5 mb-3">Logowanie</h2>
        
                    <div class="form-outline form-white mb-4">
                        <img src="img/icons-nav/me.svg" class="" alt="..." width="25" height="25">
                        <label class="form-label" for="typeEmailX">Login</label>
                        <input type="login" id="typeLoginX" class="form-control form-control-lg" />
                    </div>
        
                    <div class="form-outline form-white mb-4">
                        <img src="img/icons-nav/code.svg" class="" alt="..." width="25" height="25">
                        <label class="form-label" for="typePasswordX">Password</label>
                        <input type="password" id="typePasswordX" class="form-control form-control-lg" />
                        
                    </div>

                    <input type="submit" name="submit" value="LOGIN" class="btn btn-outline-light btn-lg px-5" />
                </div>
                </div>
            </div>
            </div>
        </div>
    </form>    
</body>
</html>