import java.util.Scanner;
import java.util.StringTokenizer;
import java.io.*;

class Day3{
    public static void main(String [] args){
        String [] map = new String [323];
        Scanner scanner = null;
        int maxLine = 31;
        int jump = 1;
        int tree = 0;
        try{
            scanner = new Scanner(new File("Day3.txt"));
        }catch(FileNotFoundException fnf){
            System.out.println(fnf.toString());
        }
        for(int i = 0; scanner.hasNextLine(); i++){
            map[i] = scanner.nextLine();
        }
        for(int i = 1; i < map.length; i+=2){
            if(map[i].charAt(jump) == '#'){
                tree++;
            }
            jump+=1;
            if(jump >= maxLine){
                jump -= maxLine;
            }
        }
        System.out.println(tree);
    }
}