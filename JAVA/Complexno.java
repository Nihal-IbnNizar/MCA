import java.io.*;
import java.util.*;

class Complex{
    double r; 
    double i; 

    public void read(){
        Scanner s = new Scanner(System.in);
        try{
            System.out.println("\nEnter the real part : ");
            r = s.nextDouble();
            System.out.println("\nEnter the imaginary part : ");
            i = s.nextDouble();
        }
        catch(Exception e){
            System.out.println("\nError : "+e);
        }
    }

    public void disp(){
        System.out.println("\n" + r + " + " + i + "i");
    }

    public Complex add(Complex cp2){
        Complex t=new Complex();
        t.r=r+cp2.r;
        t.i=i+cp2.i;
        return t;

    }

    public Complex mult(Complex cp2){
        Complex t2 = new Complex();
        t2.r = (r*cp2.r) - (i*cp2.i) ;
        t2.i = (r*cp2.i) + (i*cp2.r) ;
        return t2;
    }


}
public class Complexno {
    public static void main(String args[]){
        Complex cp1,cp2,s,z;
        cp1 = new Complex();
        cp2 = new Complex();

        System.out.println("\n--- Enter the first complex number ---");
        cp1.read();
        System.out.println("\n--- Enter the second complex number --- ");
        cp2.read();
    
        System.out.println("\nEntered complex numbers are : ");
        cp1.disp();
        cp2.disp();

        s = cp1.add(cp2);
        System.out.println("\nSum of complex numbers : ");
        s.disp();

        z = cp1.mult(cp2);
        System.out.println("\nProduct of complex numbers : ");
        z.disp();


    }
}
