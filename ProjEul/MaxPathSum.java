import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

import java.util.ArrayList;
import java.util.StringTokenizer;
import java.lang.IndexOutOfBoundsException;

class MaxPathSum{

   public static void main(String [] args){
      Scanner scanner = null;
      ArrayList<int[]> numInput = new ArrayList<int[]>();
      StringTokenizer numLine;
      int [][] dynamic_num = new int[15][15];
      
      try{
         scanner = new Scanner(new File("MaxPathSum.txt"));
      }catch(FileNotFoundException fnf){

      }
      int k = 0;
      while(scanner.hasNext()){
         
         numLine = new StringTokenizer(scanner.nextLine());
         //int[] lineTok = new int[numLine.countTokens()];
            for(int i = 0; i <= numLine.countTokens(); i++){
               //lineTok[i] = Integer.parseInt(numLine.nextToken());
               dynamic_num[k][i] = Integer.parseInt(numLine.nextToken());
            }
          k++;
         //numInput.add(lineTok);
      }
      scanner.close();
      
      //dynamic_num = new int[numInput.size()][numInput.size()];
      
      for(int i = 0; i < numInput.size(); i++){
         //int [] lineNum = numInput.get(i);
         for(int j = 0; j < numInput.get(i).length; j++){
            
            try{
            
               if(dynamic_num[i-1][j-1] > dynamic_num[i-1][j]){
                  dynamic_num[i][j] += dynamic_num[i-1][j-1];
               }else{
                  dynamic_num[i][j] += dynamic_num[i-1][j];
               }
            }catch(IndexOutOfBoundsException iob){}
         
         }
         
      }   

      for(int i = 0; i < dynamic_num[0].length; i++){
         System.out.print(dynamic_num[dynamic_num.length-1][i] + " ");
      }

   
   }
}