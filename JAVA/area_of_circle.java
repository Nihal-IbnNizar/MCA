import java.io.*;
public class area_of_circle {

    public static void areaOfcircle(){
        DataInputStream din;
        din = new DataInputStream(System.in);
        double area;
        try{
            System.out.println("\nEnter the radius of circle : ");
            int r = Integer.parseInt(din.readLine());
            area=3.14*(r*r);
            System.out.println("\nArea of circle =  "+area);
        }
        catch(Exception e){
            System.out.println("\nError : "+e);
        }
    }
    public static void main(String[] args){
        System.out.println("\nMuhammed Nihal");
        areaOfcircle(); 
        
    }
}