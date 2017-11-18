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
  if(isset($_POST['delete'])){
    $stmt = $db->prepare("DELETE FROM cart WHERE product_id = ".$_POST['delete']);
    $stmt->execute();
  }
  else if (isset($_POST['submit'])){
    $stmt = $db->prepare("SELECT * FROM cart");
    $stmt->execute();
    $cart_result = $stmt->fetchAll();
    $stmt = $db->prepare("SELECT MAX(order_id) FROM orders");
    $stmt->execute();
    $biggest_order_number = $stmt->fetchAll();
    $order_id = $biggest_order_number[0][0]+1; 
    for($j = 0; $j<count($cart_result); $j++){
      $drink = $cart_result[$j][0];
      $quantity_of_drink = $cart_result[$j][1];
      $user_id = $_SESSION['user_id'];
      $stmt = $db->prepare("INSERT INTO orders(order_id, user_id, product_id ,quantity, completed) 
      VALUES ($order_id, $user_id, $drink, $quantity_of_drink,0)");
      $stmt->execute();
    }
    $stmt = $db->prepare("DELETE FROM cart");
    $stmt->execute();
  }

}
?>

<!doctype html>
<html lang="en">

<head>
  <title>Cart</title>
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
      <a  href="customer.php">Home</a>
      <a href="menu.php">Menu</a>
      <a href="order_history.php">My Orders</a>
      <span>Welcome, <?php echo $_SESSION["display_name"];?> </span>
      <span>My Cart
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
      </span>
      <a  href="logout.php">Logout</a>
    </nav>
    <h1></h1>
    <?php
         
         $stmt = $db->prepare("SELECT * FROM cart");
         $stmt->execute();
         $result = $stmt->fetchAll();
         $total_cost=0;
         $total_size=0;
         if(!empty($result)){
         echo "<h2>My Cart</h2>";
         echo "<table class='table table-bordered'>";
         echo "<thead>";
         echo "<tr>";
         echo "<th scope='col'>Product Name</th>";
         echo "<th scope='col'>Size (oz)</th>";
         echo "<th scope='col'>Price</th>";
         echo "<th scope='col'>Quantity</th>";
         echo "<th scope='col'></th>";
         echo "</tr>";
         
         
         for($i = 0; $i<count($result); $i++){
          $stmt = $db->prepare("SELECT * FROM products WHERE product_id =".$result[$i][0]);
          $stmt->execute();
          $result_from_product = $stmt->fetchAll();
          echo "<tr>";
          echo "<th scope='row'>".$result_from_product[0][1]."</th>";
          echo "<td>".$result_from_product[0][3]."</td>";
          echo "<td>".$result_from_product[0][2]."</td>";
          echo "<td>".$result[$i][1]."</td>";
          echo "<td><form action='my_cart.php' method='POST'>
          <button type='submit' name='delete' value='".$result[$i][0]."' class = 'btn btn-danger'>Remove From Cart</button>
          </form></td>";
          echo "</tr>";
         }
         echo "</thead>";
         echo "</table>";
         
         echo "<form action='my_cart.php' method='POST'>
         <button type='submit' name='submit' value='' class = 'btn btn-primary'>Submit Order</button>
         </form>";
        }
        else
        
          echo "Cart Empty, Buy something you cheap bastard";
    ?>
  </div>
  


  <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN"
    crossorigin="anonymous"></script>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.3/umd/popper.min.js" integrity="sha384-vFJXuSJphROIrBnz7yo7oB41mKfc8JzQZiCq4NCceLEaO4IHwicKwpJf9c9IpFgh"
    crossorigin="anonymous"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/js/bootstrap.min.js" integrity="sha384-alpBpkh1PFOepccYVYDB4do5UnbKysX5WZXm3XxPqe5iKTfUKjNkCk9SaVuEZflJ"
    crossorigin="anonymous"></script>
</body>

</html>