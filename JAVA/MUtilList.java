import java.util.*;
class MUtilList {
    public static void main(String[] args) {
        List l;
        l = new ArrayList();

        l.add(10);
        l.add(20);
        l.add(30);

        for(Iterator c = l.iterator(); c.hasNext(); ){
            System.out.println(c.next());
        }
    }
}