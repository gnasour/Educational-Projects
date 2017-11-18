<?php
session_start();
$conn = "mysql:host=localhost; dbname=tsarbucks";
try{
   $db = new PDO($conn, "root",  null,[PDO::ATTR_PERSISTENT => true]);
}
catch(PDOException $e){
    die("Could not connect: " . $e -> getMessage());
}

if(count($_POST)>=1){
    $prod_id = $_POST['product_id'];
    $stmt = $db->prepare("SELECT * FROM cart WHERE product_id = $prod_id");
    $stmt->execute();
    $result = $stmt->fetchAll();
    if(empty($result)){
      $stmt = $db->prepare("INSERT INTO cart VALUES($prod_id, 1)");
      $stmt->execute();
    }
    else{
      $stmt = $db->prepare("UPDATE cart SET quantity = quantity + 1 WHERE product_id = $prod_id");
      $stmt->execute();
    }
  
  
}
?>
<!doctype html>
<html lang="en">

<head>
  <title>Menu</title>
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
      <a href="customer.php">Home</a>
      <span>Menu</span>
      <a href="order_history.php">My Orders</a>
      <span>Welcome, <?php echo $_SESSION["display_name"];?> </span>
      <a  href="my_cart.php">My Cart
        <?php
            $stmt = $db->prepare("SELECT * FROM cart");
            $stmt->execute();
            $count_result = $stmt->fetchAll();
            $quantity = 0;
            for($i = 0; $i < count($count_result); $i++){
              $quantity += $count_result[$i][1];
            }
            
                
                echo "<span class='badge badge-pill badge-primary'>".$quantity."</span>";
            
        ?>
      </a>
      <a  href="logout.php">Logout</a>
    </nav>
    <?php
         
            $stmt = $db->prepare("SELECT * FROM products");
            $stmt->execute();
            $result = $stmt->fetchAll();
            echo "<h2>Menu</h2>";
            echo "<table class='table table-bordered'>";
            echo "<thead>";
            echo "<tr>";
            echo "<th scope='col'>Product Name</th>";
            echo "<th scope='col'>Size (oz)</th>";
            echo "<th scope='col'>Price</th>";
            echo "<th scope='col'></th>";
            echo "</tr>";
            echo "<tbody>";
            for($i=0; $i < count($result); $i++){
                echo "<tr>";
                echo "<th scope='row'>".$result[$i][1]."</th>";
                echo "<td>".$result[$i][3]."</td>";
                echo "<td>".$result[$i][2]."</td>";
                echo "<td><form action='menu.php' method='POST'>
                <button type='submit' name='product_id' value='".$result[$i][0]."' class = 'btn btn-primary'>Add to Cart</button>
                </form></td>";
                echo "</tr>";
                
            }
            echo "</tbody>";
            echo "</thead>";
            echo "</table>";
            
    ?>
    <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN"
    crossorigin="anonymous"></script>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.3/umd/popper.min.js" integrity="sha384-vFJXuSJphROIrBnz7yo7oB41mKfc8JzQZiCq4NCceLEaO4IHwicKwpJf9c9IpFgh"
    crossorigin="anonymous"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/js/bootstrap.min.js" integrity="sha384-alpBpkh1PFOepccYVYDB4do5UnbKysX5WZXm3XxPqe5iKTfUKjNkCk9SaVuEZflJ"
    crossorigin="anonymous"></script>
</body>

</html>