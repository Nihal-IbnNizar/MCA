import java.io.*;
interface i1{
    public void disp();
    public void print();
}
class c1 implements i1{
    public void disp(){
        System.out.println("Inteface disp");
    }
    public void print(){
        draw();
        System.out.println("Interface print");
    }
    private void draw(){
        System.out.println("Draw not in interface");
    }
}
class P9_interface3 {
    public static void main(String[] args) {
        i1 obj;
        obj = new c1();
        obj.disp();
        obj.print();
        //obj.draw()     No need of this
    }
}


