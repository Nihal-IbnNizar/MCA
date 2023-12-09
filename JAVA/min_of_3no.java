import java.io.*;

public class min_of_3no{
    public static void main(String args[]){
        System.out.println("Muhammed Nihal");
        DataInputStream din;
        int num1,num2,num3,min;
        String s;
        din = new DataInputStream(System.in);
        try{
            System.out.println("\nEnter the first number: ");
            s=din.readLine();
            num1=Integer.parseInt(s);
            System.out.println("\nEnter second number: ");
            s=din.readLine();
            num2=Integer.parseInt(s);
            System.out.println("\nEnter third number: ");
            s=din.readLine();
            num3=Integer.parseInt(s);

            min= num3<(num1<num2?num1:num2)?num3:(num2<num1?num2:num1);
            System.out.println("Minimum number = "+min);   
        }
        catch(Exception e){
            System.out.println("Error : "+e);
        }
        
    }
}