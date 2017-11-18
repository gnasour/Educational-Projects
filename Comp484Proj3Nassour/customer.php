<?php
session_start();
$conn = "mysql:host=localhost; dbname=tsarbucks";
try{
    $db = new PDO($conn, "root",  null,[PDO::ATTR_PERSISTENT => true]);
 }
 catch(PDOException $e){
     die("Could not connect: " . $e -> getMessage());
 }

?>
<!doctype html>
<html lang="en">

<head>
  <title>Customer</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/css/bootstrap.min.css" integrity="sha384-PsH8R72JQ3SOdhVi3uxftmaW6Vc51MKb0q5P2rRUpPvrszuE4W1povHYgTpBfshb"
    crossorigin="anonymous">
</head>

<body>

  <div class="container">
    <nav class="navbar navbar-light bg-light">
      <a class="navbar-brand" href="customer.php">
        <img src="lardlad.png" width="75" height="75" class="d-inline-block" alt="">
        Lard Lad Coffee
      </a>
      <span>Home</span>
      <a href="menu.php">Menu</a>
      <a href="order_history.php">My Orders</a>
      <span>Welcome, <?php echo $_SESSION["display_name"];?>!</span>
      <a  href="my_cart.php">My Cart
        <?php
        
        $stmt = $db->prepare("SELECT * FROM cart");
        $stmt->execute();
        $count_result = $stmt->fetchAll();
        
        $quantity = 0;
        if(!empty($count_result)){
        for($i = 0; $i < count($count_result); $i++){
          $quantity += $count_result[$i][1];
        }}
        
            
            echo "<span class='badge badge-pill badge-primary'>".$quantity."</span>";
        ?>
      </a>
      <a  href="logout.php">Logout</a>
    </nav>
    <h1>Home</h1>
    <a href="menu.php">Order Something</a></br> <a href="logout.php">Leave</a>
  </div>
  




  <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN"
    crossorigin="anonymous"></script>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.3/umd/popper.min.js" integrity="sha384-vFJXuSJphROIrBnz7yo7oB41mKfc8JzQZiCq4NCceLEaO4IHwicKwpJf9c9IpFgh"
    crossorigin="anonymous"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/js/bootstrap.min.js" integrity="sha384-alpBpkh1PFOepccYVYDB4do5UnbKysX5WZXm3XxPqe5iKTfUKjNkCk9SaVuEZflJ"
    crossorigin="anonymous"></script>
</body>

</html>