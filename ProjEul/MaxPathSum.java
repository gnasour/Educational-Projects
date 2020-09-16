import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.StringTokenizer;

class MaxPathSum{

   public static void main(String [] args){
      
      //Processing input file
      Scanner scanner = null;

      //Tokenize the strings in the text files
      StringTokenizer numLine;

      //Array to hold the results of the dynamic algorithm
      int [][] dynamic_num = new int[15][15];
      
      //Buffer the text file using Scanner
      try{
         scanner = new Scanner(new File("MaxPathSum.txt"));
      }catch(FileNotFoundException fnf){

      }

      //Populate the dynamic array with the initial values
      int k = 0;
      while(scanner.hasNext()){
         
         numLine = new StringTokenizer(scanner.nextLine(), " ");
         int numOfTokens = numLine.countTokens();
         for(int i = 0; i < numOfTokens; i++){
            dynamic_num[k][i] = Integer.parseInt(numLine.nextToken());
         }

          k++;

      }

      //Efficient use of resources
      scanner.close();
           
      for(int i = 0; i < dynamic_num.length; i++){
         for(int j = 0; j < dynamic_num[0].length && dynamic_num[i][j] != 0; j++){
            
            try{
            
               if(dynamic_num[i-1][j-1] > dynamic_num[i-1][j]){

                  dynamic_num[i][j] = dynamic_num[i-1][j-1] + dynamic_num[i][j];

               }else{

                  dynamic_num[i][j] = dynamic_num[i-1][j] + dynamic_num[i][j];

               }
            }catch(IndexOutOfBoundsException iob){
   
               if(i > 0)
                  dynamic_num[i][j] = dynamic_num[i-1][j] + dynamic_num[i][j];

            }
         
         }
         
      }   

      int max = 0;
      for(int i = 0; i < dynamic_num[0].length; i++){
 
         if(max < dynamic_num[dynamic_num.length-1][i]) {
        	 max = dynamic_num[dynamic_num.length-1][i];
         }
 
      }

      System.out.println(max);

   
   }
}