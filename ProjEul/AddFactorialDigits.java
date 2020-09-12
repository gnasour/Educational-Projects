import java.math.BigInteger;

public class AddFactorialDigits {
    
    public static void main(String [] args){
        
        //Value of all the digits in the factorial will be stored
        int addedFactorialDigits = 0;
        
        //Calculating the factorial of 100
        short factorialInput = 100;
        BigInteger factNum = CalculateFactorial(factorialInput);
        
        //Turning the factorial into a string of characters so that each digit is easily
        //calculated
        String factNumChars = String.valueOf(factNum);
        
        //Iterating through the string
        for(int i = 0; i < factNumChars.length(); i++){
            addedFactorialDigits += Integer.parseInt(factNumChars.substring(i,i+1));
        }

        //Print out the result
        System.out.println(addedFactorialDigits);


    }

    /**
     * CalculateFactorial takes in a short integer and returns a BigInteger
     * that holds the value of the factorial calculated from the input.
     * BigInteger needs to be used since numbers greater than 2.1 billion
     * will overflow.
     * 
     * @param input
     * @return BigInteger
     */
    public static BigInteger CalculateFactorial(short input){
        
        BigInteger result = BigInteger.ONE;

        for(int i = 0; i < input; i++){
            result = result.multiply(BigInteger.valueOf(i+1));
        }

        return result;
    }

}
