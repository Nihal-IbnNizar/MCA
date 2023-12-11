import java.io.*;

public class sum_of_series{
    public static void sumOfseries(int n){
        int i=1,currsum=0,sum=0;
        while(i<=n){
            currsum=currsum+i;
            sum=sum+currsum;
            i++;
        }
        System.out.println("Sum of series is : "+sum);
    }
    public static void main(String[] args){
        System.out.println("Muhammed Nihal");
        DataInputStream din;
        din = new DataInputStream(System.in);
        try{
            System.out.println("\nEnter the limit(n) : ");
            int n =Integer.parseInt(din.readLine()); 
            sumOfseries(n);

        }
        catch(Exception e){
            System.out.println("\nError : "+e);
        }
    }
}