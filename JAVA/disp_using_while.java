import java.io.*;

public class disp_using_while{
    public static void disp(int m,int n){
        int i=m;
        System.out.println("\nDisplaying numbers from "+m+" To "+n+" : \n");
        while(i<=n){
            System.out.println(i);
            i++;
        }
    }
    public static void main(String[] args){
        System.out.println("Muhammed Nihal");
        DataInputStream din;
        din = new DataInputStream(System.in);
        int m,n;
        try{
            System.out.println("\nEnter value for m : ");
            m = Integer.parseInt(din.readLine());
            System.out.println("\nEnter value for n : ");
            n= Integer.parseInt(din.readLine());
            disp(m,n);
        }
        catch(Exception e){
            System.out.println("\nError : "+e);
        }
    }

}