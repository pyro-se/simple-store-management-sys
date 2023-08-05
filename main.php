
<?php
    /*
    if($_POST) {
        if(isset($_POST['insert'])) {
            insert();
        }elseif(isset($_POST['submit'])) {
            select();
        }
        else{
            test();
        }
    }

    function select()
    {
    echo "The select function is called.";
    }
    function test()
    {
    echo "adsdasdsadsadsad.";
    }*/

    class Sklep{
        private $sub_id, $nazwa, $cena;
        private function show(){
            echo "<p>".$sub_id." ".$nazwa." ".$cena."$</p>";
        }
        public function scan($plik){
            $lines = file($plik);
            foreach($lines as $key => $value){
                $data = explode("   ",$value);
                echo "<tr>";
                //echo "<td><input type='radio' name='dot' value='".$data[0]."'/></td>";
                //echo "<td><input type='submit' class='zak' name='zakup' value='' /></td>";
                
                echo "<th scope='row'>".$data[0]."</th>";
                echo "<td>".$data[1]."</td>";
                echo "<td>$ ".$data[2]."</td>";
                echo "<td><input class='form-check-input' type='radio' name='dot' id='c".$data[0]."' value='".$data[0]."' onclick='compare(".$data[2].")'/></td>";
                echo "</tr>";

            }
            //var_dump($lines);
        }

    }
$usr = file("TXT/user.txt");
foreach($usr as $key => $value){
    $data = explode("   ",$value);
    if($data[0]=="0"){
        $login=$data[1];
        $portfel=$data[4];
        break;
    }
}
?>

<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Sklep</title>
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
    <script type="text/javascript">
        function compare(cena){
            var monis = document.getElementById("hajs").innerHTML;
            var divek = document.getElementById("butt");
            //class="btn btn-outline-light btn-lg px-5"
            //danger / success
            if(parseInt(cena)>parseInt(monis)){
                if(document.getElementById("butt").classList.contains('btn-outline-success')){
                    document.getElementById("butt").classList.remove('btn-outline-sucess');
                    document.getElementById("butt").classList.add('btn-outline-light');
                }
                document.getElementById("butt").classList.remove('btn-outline-light');
                document.getElementById("butt").classList.add('btn-outline-danger');
            }
            else{
                if(document.getElementById("butt").classList.contains('btn-outline-danger')){
                    document.getElementById("butt").classList.remove('btn-outline-danger');
                    document.getElementById("butt").classList.add('btn-outline-light');
                }
                document.getElementById("butt").classList.remove('btn-outline-light');
                document.getElementById("butt").classList.add('btn-outline-success');
            }
            
        }
        
        
    </script>
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
            echo $login." [<span id='hajs'>".$portfel."</span> $]";
        ?>
    </a>
    <button class=" btn btn-outline-light btn-sm" type="submit">Logout</button>
    </nav>

    <div class="container py-5 my-5 h-100">
        <div class="row d-flex justify-content-center h-100">
        <div class="col-12 col-md-8 col-lg-6 col-xl-5">
            <div class="card bg-dark text-white" style="border-radius: 1rem;">
            <div class="card-body p-3 text-center">
                <div class="mb-md-5 mt-md-4 pb-1">
                
    
                <h2 class="display-5 mb-3">Sklep</h2>
                <form name="zakup" action="zakup.php" method="POST">
                    <table class="table table-dark table-hover text-light pb-4">
                        <caption>Shop list</caption>
                        <thead>
                            <tr>
                                <th scope="col">id</th>
                                <th scope="col">Product.</th>
                                <th scope="col">Cena</th>
                                <th scope="col"></th>
                            </tr>
                        </thead>
                        <tbody>
                            <?php
                                $s = new Sklep;
                                $s->scan("TXT/sklep.txt");
                            ?>
                        </tbody>
                    </table>
                    <input type="submit" id="butt" name="submit" value="🛒" class="btn btn-outline-light btn-lg px-5" />
                </form>
            </div>
            </div>
        </div>
        </div>
    </div>
</body>
</html>