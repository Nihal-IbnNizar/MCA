import java.io.*;
class Person{
    int age;
    String name;
    public Person(){
        age = 0;
        name = "";
    }
    public Person(int a, String n){
        age = a;
        name = n;
    }
    public void disp(){
        System.out.println("Name: " +name + "Age: " +age);
    }
}

class P4_MPerson {
    public static void main(String[] args) {
        Person p,q;
        p = new Person();
        q = new Person(22,"Nihal");
        p.disp();
        q.disp();
    }
}
