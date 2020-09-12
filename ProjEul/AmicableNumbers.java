import java.util.HashSet;

public class AmicableNumbers {
    
    public static void main(String [] args){
     
        HashSet<Integer> amicableNum = new HashSet<Integer>();
        int range = 10000;
        int sumOfAmicableNumbers = 0;
        for(int i = 1; i < range; i++){
            if(!amicableNum.contains(i)){
                int amicableNumCandidate = findSum(findDivisors(i));
                if(findSum(findDivisors(amicableNumCandidate)) == i && amicableNumCandidate != i){
                    amicableNum.add(i);
                    amicableNum.add(amicableNumCandidate);
                }
            }else{
                continue;
            }
        }

        for(int i: amicableNum){
            sumOfAmicableNumbers += i;
        }

        System.out.println(sumOfAmicableNumbers);
        
    }


    //Finding divisors using the square root method
    public static int [] findDivisors(int num){

        //This object will keep a unique set of proper factors of the input
        HashSet<Integer> properFactors = new HashSet<Integer>();

        //We will turn the HashSet into an integer array
        //so that the function findSum can process it
        int[] properFactorsArray;

        //One will always be a proper factor. We can just add it as a general
        //statement to reduce logical complexity in our loop.
        properFactors.add(1);

        //This loop will iterate over the square root of our input 
        //and find all of its proper factors.
        for(int i = 2; i < Math.sqrt(num); i++){
            
            //If our input is cleanly divided by i, add the divisor and dividend
            //to the set of all proper factors of the input
            if(num % i == 0){
                properFactors.add(num/i);
                properFactors.add(i);
            }

        }

        //Create an array the size of the HashSet
        properFactorsArray = new int[properFactors.size()];
        
        //Place all the values from the set to the array
        int j = 0; //Position of the array
        for(int i: properFactors){
            properFactorsArray[j++] = i;
        }

        //End of execution, return the array
        return properFactorsArray;
    }

    public static int findSum(int [] divisors){
        
        int sum = 0;

        for(int i = 0; i < divisors.length; i++){
            sum += divisors[i];
        }

        return sum;
    }
}
