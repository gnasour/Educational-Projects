public class CountSundays {

        static final int CENTURY = 100;

        static boolean leapYear = false;
        //Jan 1901 Starts on a Tuesday
        static int day = 2;
        static int numOfFirstSundays = 0;



    public static void main(String [] args){


        for(int i = 1901; i < CENTURY+1901; i++){
            leapYear = (i % 100 == 0 && i % 400 == 0) || (i % 4 == 0);
            for(int j = 0; j < 12; j++){
                int daysToIterate = 0;
                switch(j){
                    case 3:
                    case 5:
                    case 8:
                    case 10:
                        daysToIterate = 30;
                        break;
                    case 1:
                        if(leapYear){
                            daysToIterate = 29;
                        }else{
                            daysToIterate = 28;
                        }
                        break;
                    default:
                        daysToIterate = 31;
                        break;
                }
                if(day == 0){
                    numOfFirstSundays++;
                }
                for(int k = 0; k < daysToIterate; k++){
                    
                    //Count the next day
                    day++;

                    //Week resets on Sunday
                    day%=7;

                    //System.out.println(days[day]);
                }
            }
            
        }

        System.out.println(numOfFirstSundays);

    }

    

}
