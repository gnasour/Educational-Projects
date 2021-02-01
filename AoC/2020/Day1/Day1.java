import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.io.File;
import java.io.FileNotFoundException;

class Main{
    public static void main(String [] args){
        Scanner scanner = null;
        final int TARGET = 2020;
        int num1 = 0, num2 = 0, num3 = 0;
        List <Integer> numList = new ArrayList<Integer>();
        try{
            scanner = new Scanner(new File("Day1.txt"));
            while(scanner.hasNext()){
                numList.add(Integer.parseInt(scanner.next()));
            }
        }catch(FileNotFoundException fnf){
            System.out.println(fnf.toString());
        }
        Integer[] intNumList = new Integer[numList.size()];
        intNumList = numList.toArray(intNumList);
        int pointer1 = 0;
        int pointer2 = 1;
        int pointer3 = 2;
        int iteration = 0;
        int iteration2 = 0;
        while((num1+num2+num3) != TARGET){
            
            if(pointer2 == intNumList.length){
                pointer2 = 0;
            }
            if(pointer3 == intNumList.length){
                pointer3 = 0;
            }
            num1 = intNumList[pointer1];
            num2 = intNumList[pointer2];
            num3 = intNumList[pointer3];
            pointer3++;
            iteration2++;
            if(iteration == intNumList.length){
                iteration = 0;
                pointer1++;
            }
            if(iteration2 == intNumList.length){
                iteration2 = 0;
                pointer2++;
                iteration++;
            }

            
        }
        System.out.println(num1*num2*num3);
    }
}