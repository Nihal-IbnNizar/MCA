import java.util.*;


class Personn {
    int age;
    String name;
    public void read(){
        Scanner s = new Scanner(System.in);
        try{
            System.out.println("\nEnter the Name : ");
            name = s.nextLine(); 
            System.out.println("\nEnter the Age : ");
            age = s.nextInt(); 
        }
        catch(Exception e){
            System.out.println("\nError : "+e);
        }
    }

    public void disp(){
        System.out.println("\nName : "+name+"\nAge : "+age);
    }
}

class Student extends Personn {
    String course;
    public void read(){
        super.read();                   //SUPER OBJECT : is used to overcome method overriding
        Scanner s = new Scanner(System.in);
        try{
            System.out.println("\nEnter the course : ");
            course = s.nextLine();
        }
        catch(Exception e){
            System.out.println("\nError : "+e);
        }
    }

    public void disp(){
        super.disp();
        System.out.println("\nCourse : "+course);
    }
}

class Teacherr extends Personn {
    String subj;
    public void read(){
        super.read(); 
        Scanner s = new Scanner(System.in);
        try{
            System.out.println("\nEnter the subject : ");
            subj = s.nextLine();
        }
        catch(Exception e){
            System.out.println("\nError : "+e);
        }
    }

    public void disp(){
        super.disp();
        System.out.println("\nSubject : "+subj);
    }
}


public class MethodOverRiding {
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int ch;
        Student s1 = new Student();
        Teacherr t1 = new Teacherr();
        do{
            System.out.println("\n1.Read and display Student Details.");
            System.out.println("\n2.Read and display Teacherr Details.");
            System.out.println("\nEnter your choice : ");
            ch=s.nextInt();
            switch (ch) {
                case 1:
                    s1.read();
                    s1.disp();
                    break;
                case 2:
                    t1.read();
                    t1.disp();
                    break;
                case 3:
                System.out.println("\nExiting");
                    break;
                default:
                    System.out.println("\nInvalid input.Try again");
                    break;
            }
        }while(ch != 3);
    }
}