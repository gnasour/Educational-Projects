import java.util.Scanner;
import java.util.StringTokenizer;
import java.io.*;

class Day3{
    public static void main(String [] args){
        Scanner scanner = null;
        final String byr = "byr";
        final String iyr = "iyr";
        final String eyr = "eyr";
        final String hgt = "hgt";
        final String hcl = "hcl";
        final String ecl = "ecl";
        final String pid = "pid";
        final String cid = "cid";
        try{
            scanner = new Scanner(new File("Day3.txt"));
        }catch(FileNotFoundException fnf){
            System.out.println(fnf.toString());
        }
        while(scanner.hasNext()){

        }
    }
}