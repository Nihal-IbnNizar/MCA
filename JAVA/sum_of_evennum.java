import java.io.*;
public class sum_of_evennum {
    
     public static int sumOfeven(){
        DataInputStream din;
        din = new DataInputStream(System.in);
        int i,n,sum=0;
        try{
            System.out.println("\nEnter the limit(n) : ");
            n = Integer.parseInt(din.readLine());
            for(i=1;i<=n;i++){
                if(i%2==0){
                    sum=sum+i;
                }
            }
            return sum;
        }
        catch(Exception e){
            System.out.println("\nError : "+e);
        }    
        return 0;
    }
    public static void main(String[] args){
        System.out.println("Muhammed Nihal");
        System.out.println("Sum = "+sumOfeven());
        
    }
}