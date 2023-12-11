import java.io.*;
public class reverse_number{

    public static void reverseNum(int num){
        int digit,rev=0;
        while(num!=0){
            digit = num%10;
            rev=(rev*10)+digit;
            num=num/10;
        }
        System.out.println("\nReverse of given number is : "+rev);
    }
    public static void main(String[] args){
        System.out.println("Muhammed Nihal");
        DataInputStream din;
        din = new DataInputStream(System.in);
        try{
            System.out.println("\nEnter the number : ");
            int num = Integer.parseInt(din.readLine());
            reverseNum(num);
        }
        catch(Exception e){
            System.out.println("\nError : "+e);
        }
    }
}