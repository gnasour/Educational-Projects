import java.util.HashMap;

public class AmicableNumbers {
    
    public static void main(String [] args){
        HashMap amicableNum = new HashMap();
        int range = 10000;
        int sumOfAmicableNumbers = 0;
        for(int i = 0; i < range; i++){
            
        }
    }

    public static int [] findDivisors(int num){

    }

    public int findSum(int [] divisors){
        
        int sum = 0;

        for(int i = 0; i < divisors.length; i++){
            sum += divisors[i];
        }

        return sum;
    }
}
