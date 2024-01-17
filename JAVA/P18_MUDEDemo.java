import java.util.*;
class MyEx extends Exception{
    String strError;
    public MyEx(String s){
        super();
        strError = s;
    }
    public void disp(){
        System.out.println("Error: " +strError);
    }
}
class P18_MUDEDemo {
    public static void main(String[] args) {
        int a,b,c;
        Scanner s = new Scanner(System.in);
        try{
            System.out.println("Enter two numbers: ");
            a = s.nextInt();
            b = s.nextInt();
            if(b == 0){
                throw new MyEx("Derivative is zero, DIVISION NOT POSSIBLE!");
            }
            c = a/b;
            System.out.println("c = " +c);
        }
        catch(MyEx m){
            m.disp();
        }
        catch(Exception e){
            System.out.println(e);
        }
    }
}
