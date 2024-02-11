//polymorphism - One object is behaving different forms in different situations. 

import java.util.*;

interface ishape{
    public double area();

}
class Triangle implements ishape{
    
    double b; 
    double h; 

    public Triangle(double b,double h){     //constrcutor
        this.b = b;
        this.h = h;
    }
    public double area(){
        return (0.5* b * h); 
    }
}

public class PolyMorph_Triangle {
    public static void main(String args[]){

        ishape obj[];
        int n,i;
        Scanner s = new Scanner(System.in);
        try{
            System.out.println("\nEnter no.of Triangle : ");
            n = s.nextInt();
            obj = new ishape[n]; // creates an array that can hold references to objects of classes that implement the ishape interface.
            for(i=0;i<n;i++){
                double b,h;
                System.out.println("\n\nEnter the base of Triangle "+(i+1)+" : ");
                b = s.nextDouble();
                System.out.println("\nEnter the height of Triangle "+(i+1)+" : ");
                h = s.nextDouble();
                obj[i]=new Triangle(b,h);
                System.out.println("\nArea of Triangle "+(i+1)+" = " + obj[i].area());
            }
            
        }
        catch(Exception e){
            System.out.println("\nError "+e);
        }
        s.close();
    }
}

