import java.io.*;
public class sum_of_series2 {

    public static void sumOfseries2(int n){
        int i;
        double sum=0,fact=1;
        for(i=1;i<=n;i++){
                fact = fact*i; //finding factorial
                sum = sum + (i/fact); //dividing by factorial
            }
            System.out.println("\nSum of series is = "+sum);
    }
    public static void main(String[] args) {
        System.out.println("\nMuhammed Nihal");
        DataInputStream din;
        din = new DataInputStream(System.in);
        try{
            System.out.println("\nEnter the value of n : ");
            int n = Integer.parseInt(din.readLine());
            sumOfseries2(n);
        }
        catch(Exception e){
            System.out.println("\nError : "+e);
        }
    }
}