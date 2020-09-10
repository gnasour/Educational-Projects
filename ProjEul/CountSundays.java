public class CountSundays {
    

        static final int DAYS_IN_YEAR = 365;
        static final int DAYS_IN_LEAP_YEAR = 366;
        static final int CENTURY = 100;

        static boolean leapYear = false;
        static int month = 0;
        //Jan 1901 Starts on a Tuesday
        static int day = 1;
        static int numOfFirstSundays = 0;

        static String[] days = {"S", "M", "T", "W", "Th", "F", "Sa"};

    public static void main(String [] args){


        for(int i = 1901; i < CENTURY+1901; i++){
            if((i % 100 == 0 && i % 400 == 0) || (i % 4 == 0)){
                leapYear = true;
            }else{
                leapYear = false;
            }
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
                    day++;
                    if(day == 7)
                        day = 0;
                    //System.out.println(days[day]);
                }
            }
            
        }

        System.out.println(numOfFirstSundays);

    }

    

}
