<?php
    $ID_preset = "0";
    $sid = $_POST["dot"];
    $well = false;
    //echo $sid."\n";
    //var_dump($_POST);
    if(isset($sid)){
        $well=true;

        $sklep = file("TXT/sklep.txt");
        foreach($sklep as $key => $value){
            $data = explode("   ",$value);
            if($data[0]==$sid){
                $nazwa=$data[1];
                $cena=$data[2];
                //echo "koszt: ".$cena;
                break;
            }
        }

        $usr = file("TXT/user.txt");
        foreach($usr as $key => $value){
            $data = explode("   ",$value);
            if($data[0]==$ID_preset){
                $uid=$data[0];
                $login=$data[1];
                $pass=$data[2];
                $score=$data[3];
                $portfel=$data[4];
                break;
            }
        }
    }
    else{
        $cena=0;
        $usr = file("TXT/user.txt");
        foreach($usr as $key => $value){
            $data = explode("   ",$value);
            if($data[0]==$ID_preset){
                $uid=$data[0];
                $login=$data[1];
                $pass=$data[2];
                $score=$data[3];
                $portfel=$data[4];
                break;
            }
        }
    }
?>

<!DOCTYPE html>
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Zakup</title>
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
    <nav class="navbar navbar-dark bg-dark">
    <a class="navbar-brand" href="#">
        <img src="img/icons-nav/me.svg" class="" alt="..." width="30" height="30">
        <?php 
            echo $login;//." [<span id='hajs'>".$portfel."</span> $]";
        ?>
    </a>
    <button class=" btn btn-outline-light btn-sm" type="submit">Logout</button>
    </nav>

    <svg xmlns="http://www.w3.org/2000/svg" style="display: none;">
        <symbol id="check-circle-fill" fill="currentColor" viewBox="0 0 16 16">
            <path d="M16 8A8 8 0 1 1 0 8a8 8 0 0 1 16 0zm-3.97-3.03a.75.75 0 0 0-1.08.022L7.477 9.417 5.384 7.323a.75.75 0 0 0-1.06 1.06L6.97 11.03a.75.75 0 0 0 1.079-.02l3.992-4.99a.75.75 0 0 0-.01-1.05z"/>
        </symbol>
        <symbol id="info-fill" fill="currentColor" viewBox="0 0 16 16">
            <path d="M8 16A8 8 0 1 0 8 0a8 8 0 0 0 0 16zm.93-9.412-1 4.705c-.07.34.029.533.304.533.194 0 .487-.07.686-.246l-.088.416c-.287.346-.92.598-1.465.598-.703 0-1.002-.422-.808-1.319l.738-3.468c.064-.293.006-.399-.287-.47l-.451-.081.082-.381 2.29-.287zM8 5.5a1 1 0 1 1 0-2 1 1 0 0 1 0 2z"/>
        </symbol>
        <symbol id="exclamation-triangle-fill" fill="currentColor" viewBox="0 0 16 16">
            <path d="M8.982 1.566a1.13 1.13 0 0 0-1.96 0L.165 13.233c-.457.778.091 1.767.98 1.767h13.713c.889 0 1.438-.99.98-1.767L8.982 1.566zM8 5c.535 0 .954.462.9.995l-.35 3.507a.552.552 0 0 1-1.1 0L7.1 5.995A.905.905 0 0 1 8 5zm.002 6a1 1 0 1 1 0 2 1 1 0 0 1 0-2z"/>
        </symbol>
    </svg>

    <div class="container py-5 my-5 h-100">
        <div class="row d-flex justify-content-center h-100">
        <div class="col-12 col-md-8 col-lg-6 col-xl-5">
            <div class="card bg-dark text-white" style="border-radius: 1rem;">
            <div class="card-body p-5 text-center">
    
                <div class="mb-md-5 mt-md-4 pb-2">
                    <?php 
                        if($portfel>=$cena && $well==true){
                            $portfel-=$cena;
                            $tid = -1;
                            $handle = fopen("TXT/transakcje.txt", "r");
                            while(!feof($handle)){
                                $line = fgets($handle);
                                $tid++;
                            }
                            fclose($handle);
                            $transfile = fopen("TXT/transakcje.txt", "a+") or die("Unable to open file!");
                            $wpis = $tid."   ".$login."   ".$sid."   ".$nazwa."   ".$cena;//."\n";
                            fwrite($transfile, $wpis);
                            fclose($transfile);
                            
                    
                            $fileData = file('TXT/user.txt');
                    
                            $newArray = array();
                            foreach($fileData as $line) {
                                if (substr($line, 0, 1) == $ID_preset) {
                                    $line = $uid."   ".$login."   ".$pass."    ".$score+10*$cena."   ".$portfel."\n";
                                }
                                $newArray[] = $line;
                            }
                        
                            $fp = fopen('TXT/user.txt', 'w');
                            fwrite($fp, implode($newArray));
                            fclose($fp);
                            echo "<h2 class='display-5 mb-3 text-success'>Zakup udany!</h2>";
                            echo "<div class='alert alert-success d-flex align-items-center' role='alert'>";
                            echo "<svg class='bi flex-shrink-0 me-2' width='24' height='24' role='img' aria-label='Success:'><use xlink:href='#check-circle-fill'/></svg>";
                            //echo "<h4 class='alert-heading'>Zakup Udany!</h4>";
                            echo "<div>".$nazwa." za cene ".$cena."$ | SALDO: ".$portfel." </div>";
                            echo "</div>";
                            echo "<a href='main.php'><button type='button' type='submit' class='btn btn-outline-success'>Powrót :)</button></a>";
                        }
                        else{
                            echo "<h2 class='display-5 mb-3 text-danger'>Zakup nieudany!</h2>";
                            echo "<div class='alert alert-danger d-flex align-items-center text-center' role='alert'>";
                            echo "<svg class='bi flex-shrink-0 me-2' width='24' height='24' role='img' aria-label='Danger:'><use xlink:href='#exclamation-triangle-fill'/></svg>";
                            //echo "<h4 class='alert-heading'>Zakup Nieudany!</h4>";
                            echo "<div>Błąd transakcji | SALDO: ".$portfel."</div>";
                            echo "</div>";
                            echo "<a href='main.php'><button type='button' type='submit' class='btn btn-outline-danger'>Powrót :(</button></a>";
                        }
                    
                    ?>
                    
            </div>
            </div>
        </div>
        </div>
    </div>
</body>
</html>