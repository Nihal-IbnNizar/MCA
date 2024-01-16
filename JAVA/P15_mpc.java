import java.io.*;
// class c1{
//     int a;
//     public c1(){
//         a = 10;
//     }
//     public static void disp(){
//         System.out.println(a);
//     }
// }
// class m1{
//     public static void main(String[] args) {
//         c1.disp();
//     }
// }

class pc{
    static int count = 0;
    int a;
    private pc(){
        a = 10;
    }
    public void disp(){
        System.out.println(a);
    }
    public static pc create(){
        count++;
        return new pc();
    }
}
class P15_mpc {
    public static void main(String[] args) {
        pc obj = pc.create();
        pc.obj2 = pc.create();
        obj.disp();
        obj.disp();
        System.out.println(pc.count);
    }
}
