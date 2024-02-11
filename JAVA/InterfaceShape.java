import java.util.*;

interface Shape{
    public void disp();
    public double calc();
}
class Circlee implements Shape{
    double r;

    public Circlee(double r){        //constructor
        this.r = r;
    }
    public void disp(){
        System.out.println("\nThis is a Circle.");
    }
    public double calc(){
        return (3.14)*r*r;          
    }

}
class Rectanglee implements Shape{

    double l,w; 

    public Rectanglee(double l,double w){        //constructor
        this.l = l;
        this.w = w;

    }
    public void disp(){
        System.out.println("\nThis is a Rectangle.");
    }
    public double calc(){
        return l*w; 
    }
}


public class InterfaceShape {
    public static void main(String args[]){
        Shape shape1 = null;
        int ch;
        Scanner s = new Scanner(System.in);
        try{

                System.out.println("\nSelect a shape :\n1.Circle.\n2.Rectangle.");
                ch=s.nextInt();
                switch(ch){
                    case 1:
                        double r;
                        System.out.println("\nEnter the radius of circle : ");
                        r = s.nextDouble();
                        shape1 = new Circlee(r);
                        break;
                    case 2:
                        double l,w;
                        System.out.println("\nEnter length and width of rectangle : ");
                        l = s.nextDouble();
                        w = s.nextDouble();
                        shape1 = new Rectanglee(l,w);
                        break;
                        
                    default:
                        System.out.println("\nInvalid Input.Try again : ");

                }

            if(shape1 != null){
                shape1.disp();
                System.out.println("Area : " +shape1.calc());
            }
        }
        catch(Exception e){
            System.out.println("\nError "+e);
        }
        s.close();
    }
}