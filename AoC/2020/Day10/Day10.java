import java.util.*;
import java.io.*;

class Day10{

    public static void main(String [] args){
        Scanner scanner = null;
        ArrayList <Integer> adapters = new ArrayList <Integer>();
        int offByOne = 0, offByThree = 1;
        int currentAdapter = 0;
        int combinatorial = 0;
        int combMinOne = 0;
        int oneRepeat = 0;
        try{
            scanner = new Scanner(new File("Day10.txt"));
        }catch(FileNotFoundException fnf){
            System.out.println(fnf.toString());
        }
        while(scanner.hasNext()){
            adapters.add(Integer.parseInt(scanner.nextLine()));
        }
        Collections.sort(adapters);
        adapters.add(0,0);
        adapters.add(adapters.size(), adapters.get(adapters.size()-1)+3);
        for(int i = 1; i < adapters.size()-2; i++){
            // switch(i-currentAdapter){
            //     case 1:
            //         offByOne++;
            //         combinatorial++;
            //         break;
            //     case 2:
            //         continue;                    
            //     case 3:
            //         offByThree++;
            //         break;
            // }
            // currentAdapter = i;
            int value = adapters.get(i+1) - adapters.get(i-1);
            if(value < 4){
                if(value == 2){
                    oneRepeat++;
                    if(oneRepeat == 3){
                        oneRepeat = 0;
                        combMinOne++;
                    }
                }else{
                    oneRepeat = 0;
                    combinatorial++;
                }
            }else if(oneRepeat > 0){
                combinatorial += oneRepeat;
                oneRepeat = 0;
            }
        }
        combinatorial += oneRepeat;
        oneRepeat = 0;
        //System.out.println(offByOne*offByThree);
        System.out.println(Math.round((Math.pow(2,combinatorial))*(Math.pow(7,combMinOne))));
    }
}