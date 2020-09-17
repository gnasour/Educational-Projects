class test {
    int x = 0;
    public test(){

    }

    public void replace (int x){
        this.x = x;
    }
}

class Main{
    public static void main(String [] args){
        test t = new test();
        System.out.println(t.x);
        t.replace(5);
        System.out.println(t.x);
    }
}

