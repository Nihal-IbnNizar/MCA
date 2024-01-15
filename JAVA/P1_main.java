import java.io.*;
class Person {
    int age;
    String name;
    public void setPerson( int a, String n){
        age = a;
        name = n;
    }
    public void dispPerson(){
        System.out.println("Name: " +name + "\t" + "Age: " +age);
    }
}

public class P1_main{
    public static void main(String[] args) {
        Person p,q;
        p = new Person();
        q = new Person();
        p.setPerson(20, "abcd");
        q.setPerson(30,"xyz");
        p.dispPerson();
        q.dispPerson();
    }
}
