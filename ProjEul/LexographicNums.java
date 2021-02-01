public class LexographicNums {

    public static boolean linearDecreasing(int [] numbers){
        
        for(int i = 0; i < numbers.length-1; i++){
            if(numbers[i] < numbers[i+1]){
                return false;
            }
        }
        
        return true;
    }
    public static void main(String [] args){
        int [] numbers = {0,1,2,3,4,5,6,7,8,9};
        int ding = 0;
        int temp = 0;
        for(int i = 0; !linearDecreasing(numbers) && i < 1000000; i++){
            for(int j = 0; j < 9; j++){
                if(numbers[j] > numbers[j+1]){
                    temp = numbers[j+1];
                    numbers[j+1] = numbers[j];
                    numbers[j] = temp;
                }
            }
        }

            
    }
    
}
