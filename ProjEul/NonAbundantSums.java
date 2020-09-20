import java.util.HashSet;

class NonAbundantSums{


    public static void main(String [] args){
        
        final int MAX_ABUNDANT_SUM = 28123;
        //private HashSet<Integer> setOfAbundantSumNum = new HashSet<Integer>();
        HashSet<Integer> setOfAbundantSum = new HashSet<Integer>();
        int result = 0;
        for(int i = 1; i < MAX_ABUNDANT_SUM; i++){
            if(AmicableNumbers.findSum(AmicableNumbers.findDivisors(i)) > i){
                setOfAbundantSum.add(i);
            }
        }
        Integer [] setOfAbundantSumArray = new Integer[setOfAbundantSum.size()];
        setOfAbundantSum.toArray(setOfAbundantSumArray);
        boolean add = true;
        for(int i = 1; i <= MAX_ABUNDANT_SUM; i++){
            for(int k = 0; k < setOfAbundantSumArray.length; k++) {
                for (int j = 0; j < setOfAbundantSumArray.length; j++) {
                    int temp = setOfAbundantSumArray[i];
                    if (temp + setOfAbundantSumArray[j] == i) {
                        add = false;
                        break;
                    } else {

                    }
                }
                if (add) {
                    result += i;
                }
            }
            }

        System.out.println(result);

    }
}