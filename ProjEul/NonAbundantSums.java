import java.util.Arrays;
import java.util.HashSet;

class NonAbundantSums{


    public static void main(String [] args){
        long timeStart = System.currentTimeMillis();
        long timeEnd;
        final int MAX_ABUNDANT_SUM = 28123;
        //private HashSet<Integer> setOfAbundantSumNum = new HashSet<Integer>();
        HashSet<Integer> setOfAbundantSum = new HashSet<Integer>();
        int result = 0;
        for(int i = 2; i <= MAX_ABUNDANT_SUM; i++){
            if(AmicableNumbers.findSum(AmicableNumbers.findDivisors(i)) > i){
                setOfAbundantSum.add(i);
            }
        }
        Integer [] setOfAbundantSumArray = new Integer[setOfAbundantSum.size()];
        setOfAbundantSum.toArray(setOfAbundantSumArray);
        Arrays.sort(setOfAbundantSumArray);
        boolean toAdd = true;
        //setOfAbundantSumArray[setOfAbundantSumArray.length-1]=99999;
        for(int i = 25; i < MAX_ABUNDANT_SUM; i++){
            for(int j = 0; setOfAbundantSumArray[j] < i; j++){
//                if(result == 4179871){
//                    System.out.println("Here");
//                }
                if(setOfAbundantSum.contains(i-setOfAbundantSumArray[j])){
                    toAdd = false;
                    break;
                }
            }
            if(toAdd){
                result += i;
            }else{
                toAdd = true;
            }
        }
        timeEnd = System.currentTimeMillis();
        System.out.println(result);

    }
}