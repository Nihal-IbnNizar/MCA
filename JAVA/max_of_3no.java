import java.io.*;

public class max_of_3no{
    public static void main(String args[]){
        System.out.println("Muhammed Nihal");
        DataInputStream din;
        int num1,num2,num3;
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

            if(num1>num2 && num1>num3){
                System.out.println("Maximum number = "+num1);
            }
            else if(num2>num1 && num2>num3){
                System.out.println("Maximum number = "+num2);
            }
            else{
                System.out.println("Maximum number = "+num3);
            }        
        }
        catch(Exception e){
            System.out.println("Error : "+e);
        }
        
    }
}