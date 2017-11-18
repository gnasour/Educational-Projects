<?php
session_start();

if(!empty($_POST)){
    $conn = "mysql:host=localhost; dbname=tsarbucks";
try{
   $db = new PDO($conn, "root",  null,[PDO::ATTR_PERSISTENT => true]);
}
catch(PDOException $e){
    die("Could not connect: " . $e -> getMessage());
}


$username = $_POST["username"];
$password = $_POST["password"];
$stmt = $db->prepare("SELECT password FROM users WHERE username= ?");
$stmt->execute(["$username"]);
$result = $stmt->fetchAll();
if(!empty($result))
    $got_username=true;
else
    $got_username=false;
if($got_username&&$password == $result[0][0]){
     if($username == 'barista'){
        $stmt = $db->prepare("SELECT * FROM users WHERE username= ?");
        $stmt->execute(["$username"]);
        $session_results = $stmt->fetchAll();
        $_SESSION['username'] = $session_results[0][1];
        $_SESSION['user_id'] = $session_results[0][0];
        $_SESSION['display_name'] = $session_results[0][3];
        header("Location: barista.php");
         exit();
    }
     elseif($username == 'customer'){
        $stmt = $db->prepare("SELECT * FROM users WHERE username= ?");
        $stmt->execute(["$username"]);
        $session_results = $stmt->fetchAll();
        $_SESSION['username'] = $session_results[0][1];
        $_SESSION['user_id'] = $session_results[0][0];
        $_SESSION['display_name'] = $session_results[0][3];
     header("Location: customer.php");
     exit();
     }
     $db = null;
     $stmt = null;
     exit;
 }
else{
echo "Wrong Password or Username";
}
}
?>
<!doctype html>
<html lang="en">

<head>
    <title>Login</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/css/bootstrap.min.css" integrity="sha384-PsH8R72JQ3SOdhVi3uxftmaW6Vc51MKb0q5P2rRUpPvrszuE4W1povHYgTpBfshb"
        crossorigin="anonymous">
</head>

<body>
    <div class="container">
        <nav class="navbar navbar-light bg-light">
            <a class="navbar-brand" href="login.php">
        <img src="lardlad.png" width="75" height="75" class="d-inline-block" alt="">
        Lard Lad Coffee
      </a>

            <ul class="navbar-nav">
                <li class="nav-item">
                    <a class="nav-link" href="index.php">Home </a>
                </li>
                <li class="nav-item">
                    <span>Login</span>
                </li>
            </ul>
        </nav>
        <h1>Login</h1>
        <?php
            
    ?>
        <form method="POST" action="login.php">
            <div class="form-group">
                <label for="username"><b>User Name</b></label>
                <input type="text"  id="username" name="username" placeholder="Username">
            </div>
            <div class="form-group">
                <label for="password"><b>Password</b></label>
                <input type="password"  id="password" name="password" placeholder="Password">
            </div>
            <button type="submit" class="btn btn-primary">Submit</button>
        </form>
        
    </div>

    



    <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN"
        crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.3/umd/popper.min.js" integrity="sha384-vFJXuSJphROIrBnz7yo7oB41mKfc8JzQZiCq4NCceLEaO4IHwicKwpJf9c9IpFgh"
        crossorigin="anonymous"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/js/bootstrap.min.js" integrity="sha384-alpBpkh1PFOepccYVYDB4do5UnbKysX5WZXm3XxPqe5iKTfUKjNkCk9SaVuEZflJ"
        crossorigin="anonymous"></script>
</body>

</html>
