import java.io.*;
class PDEDemo{
    public static void main(String[] args) {
        int a,b,c;
        DataInputStream din= new DataInputStream(System.in);
        String s;
        try{
            System.out.println("Enter the first number: ");
            s = din.readLine();
            a = Integer.parseInt(s);
            System.out.println("Enter the second number: ");
            s = din.readLine();
            b = Integer.parseInt(s);
            c = a/b;
            System.out.println("c = " +c);
        }
        catch(IOException e1){
            System.out.println("Unable to read from IOI device!" +e1);
        }
        catch(NumberFormatException e2){
            System.out.println("Input string not a number!" +e2);
        }
        catch(ArithmeticException e3){
            System.out.println("Derivative is zero!" +e3);
        }
        catch(Exception e4){
            System.out.println("Unknown Error!" +e4);
        }
    }
}