import java.util.Scanner;
import java.util.StringTokenizer;
import java.io.*;

class Day2{
    public static void main(String [] args){
        StringTokenizer st = null;
        Scanner scanner = null;
        int correctPasswords = 0;
        try{
            scanner = new Scanner(new File("Day2.txt"));
        }catch(FileNotFoundException fnf){
            System.out.println(fnf.toString());
        }
        while(scanner.hasNext()){
            st = new StringTokenizer(scanner.nextLine());
            String minMax = st.nextToken();
            String letterMatch = st.nextToken();
            String keyWord = st.nextToken();
            int hyphen = minMax.indexOf("-");
            int min = Integer.parseInt(minMax.substring(0,hyphen));
            int max = Integer.parseInt(minMax.substring(hyphen+1,minMax.length()));
            if(keyWord.charAt(min-1) == letterMatch.charAt(0) && keyWord.charAt(max-1) != letterMatch.charAt(0)){
                correctPasswords++;
            }else if(keyWord.charAt(min-1) != letterMatch.charAt(0) && keyWord.charAt(max-1) == letterMatch.charAt(0)){
                correctPasswords++;
            }
            
            
        }
        System.out.println(correctPasswords);
    }
}