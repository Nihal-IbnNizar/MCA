import java.util.*;
import java.io.*;

class Emp {
    int no;
    String name;

    public Emp (int n, String nn){
        no = n;
        name = nn;
    }

    public void disp() {
        System.out.println(no + " ; " + name);
    }

    public String toString() {
        return no + " >< " + name;
    }
}
public class Collection_UDC {
    public static void main(String[] args) {
        List list = new ArrayList();
        Integer I = 12; // Autoboxing
        String str = "Test";
        Float f = 132.5F; // Autoboxing
        Emp e = new Emp(10, "sss");
        list.add(I);
        list.add(str);
        list.add(e);
        list.add(f);

        Integer IR;
        String SR;
        Float FR;
        Emp ee;

        Iterator i = list.iterator();

        while (i.hasNext()) {
            Object obj = i.next();
            if (obj instanceof Integer) {
                IR = (Integer)obj;
                System.out.println(IR.intValue());
            }
            else if (obj instanceof String) {
                SR = (String)obj;
                System.out.println(SR);
            }
            else if (obj instanceof Float) {
                FR = (Float)obj;
                System.out.println(FR);
            }
            else if (obj instanceof Emp) {
                ee = (Emp)obj;
                System.out.println(ee);
            }
        }
    }
}