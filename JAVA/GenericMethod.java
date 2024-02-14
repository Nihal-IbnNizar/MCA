//use online compiler since "Integer(int) in Integer has been deprecated and marked for removal" in line 11

class Test {
    public <T> void disp (T a, T b) {
        System.out.println(" " + a + b);
    }
}

public class GenericMethod {
    public static void main(String[] args) {
        Integer i1 = new Integer(10);
        Integer i2 = 20;
        String s1 = "Hello";
        String s2 = new String("World");

        Test obj = new Test();
        obj.disp(i1,i2);
        obj.disp(s1,s2);
    }
}
