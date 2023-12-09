import java.io.*;

public class array_search{

    public static void lsearch(int a[],int n,int s){

            int i,flag=0;
            for(i=0;i<n;i++){
                if(a[i]==s){
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                System.out.println("\nElement "+s+" found at position "+ (i+1));
            }
            else{
                System.out.println("\nElement Not found!");
            }
            
    }

    public static void main(String args[]){
        System.out.println("Muhammed Nihal");
        DataInputStream din;
        int a[],n,i,s,flag=0;
        din = new DataInputStream(System.in);
        try{
            System.out.println("\nEnter the size of array: ");
            n=Integer.parseInt(din.readLine());
            a =new int[n]; 						//array initialization
            System.out.println("Enter "+n+" values: ");

            for(i=0;i<n;i++){
                a[i]=Integer.parseInt(din.readLine());
            }

            System.out.println("The Array is: ");			//display
            for(i=0;i<n;i++){
                System.out.println(a[i]);
            }

            //Searching
            System.out.println("\nEnter the element to search : ");
            s=Integer.parseInt(din.readLine());
            lsearch(a,n,s); 						//calling function
 
        }
        catch(Exception e){
            System.out.println("Error : "+e);
        }
        
    }
}