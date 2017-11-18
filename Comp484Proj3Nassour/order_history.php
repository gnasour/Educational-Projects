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
  <title>Order History</title>
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
      <a href="menu.php">Menu</a>
      <span>My Orders</span>
      <span>Welcome, <?php echo $_SESSION["display_name"];?></span>
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
    <?php
         
        $stmt = $db->prepare("SELECT * FROM orders WHERE user_id = ?");
        $stmt->execute(["".$_SESSION['user_id'].""]);
        $result = $stmt->fetchAll();
        
        
        $previous_order_id = 0;
        $current_order = 1;
        $none = true;
        for ($iterate_over_products = 0; $iterate_over_products < count($result); $iterate_over_products++){
          $cost_of_all_orders=0;
            if ($previous_order_id != $result[$iterate_over_products][0]){
              
              
          
              $previous_order_id = $result[$iterate_over_products][0];
              
              echo "<h2> Order $previous_order_id</h2>";
              echo "<table class='table table-bordered'>";
              echo "<thead>";
              echo "<tr>";
              echo "<th scope='col'>Product Name</th>";
              echo "<th scope='col'>Size (oz)</th>";
              echo "<th scope='col'>Quantity</th>";
              echo "<th scope='col'>Price</th>";
              echo "<th scope='col'>Status</th>";
              echo "</tr>";
              echo "<tbody>";
              
              for($i=0; $i < count($result); $i++){
                if($previous_order_id == $result[$i][0]){
                  $product_id = $result[$i][2];
                  $stmt = $db->prepare("SELECT * FROM products WHERE product_id = ?");
                  $stmt->execute(["$product_id"]);
                  $drinks_result = $stmt->fetchAll();
                  //Drink Name
                  $product_name=$drinks_result[0][1];
                  //Size of drink
                  $size_oz=$drinks_result[0][3];
                  //Quantity ordered
                  $stmt2 = $db->prepare("SELECT quantity FROM orders WHERE product_id = ? AND order_id=?");
                  $stmt2->execute(["$product_id","$previous_order_id"]);
                  $drinks_result2 = $stmt2->fetchAll();
                  $quantity=$drinks_result2[0][0];
                  //Price of drink
                  $price=$drinks_result[0][2];
                  $cost_of_all_orders += $price * $quantity;
                  echo "<tr>";
                  echo "<th scope='row'>$product_name</th>";
                  echo "<td>$size_oz</td>";
                  echo "<td>$quantity</td>";
                  echo "<td>$price</td>";
                  if($result[$i][4]!= 1){
                    echo "<td><span class='badge badge-pill badge-secondary'>Pending</span></td>";
                  }else{
                    echo "<td><span class='badge badge-pill badge-success'>Completed</span></td>";
                  }
                  echo "</tr>";
                  
                }
              }
              
              
              echo "</tbody>";
              echo "</thead>";
              echo "</table>";
              $formatted_cost=number_format($cost_of_all_orders, 2, ".", "");
              echo "Total Cost:$".$formatted_cost;
           
            }
            
        }
        $stmt = null;
        $stmt2 = null;
        $conn = null;
       
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