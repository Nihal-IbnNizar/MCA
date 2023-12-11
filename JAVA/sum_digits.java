import java.io.*;
public class sum_digits {

    public static int sumOfdigits(int num){
        int digit,sum=0;
        while(num!=0){
            digit = num%10;
            sum=sum+digit;
            num=num/10;
        }
        return sum;
    }
    public static void main(String[] args){
        System.out.println("Muhammed Nihal");
        DataInputStream din;
        din = new DataInputStream(System.in);
        try{
            System.out.println("\nEnter the number : ");
            int num = Integer.parseInt(din.readLine());
            System.out.println("Sum of digits is : "+sumOfdigits(num));
        }
        catch(Exception e){
            System.out.println("\nError : "+e);
        }    
    }
}