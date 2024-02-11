import java.io.*;
class Employee {
    int eno;
    String ename;
    double esal;

    void readDetails() throws IOException {
        DataInputStream dis = new DataInputStream(System.in);
        System.out.println("Enter employee number (eno): ");
        eno = Integer.parseInt(dis.readLine());
        System.out.println("Enter employee name (ename): ");
        ename = dis.readLine();
        System.out.println("Enter employee salary (esal): ");
        esal = Double.parseDouble(dis.readLine());
    }

    void displayDetails() {
        System.out.println("Employee Details:");
        System.out.println("Employee Number (eno): " + eno);
        System.out.println("Employee Name (ename): " + ename);
        System.out.println("Employee Salary (esal): " + esal);
    }
}

public class Employee_main {
    public static void main(String[] args) {
        try {
            DataInputStream dis = new DataInputStream(System.in);
            System.out.println("Enter the number of employees: ");
            int n = Integer.parseInt(dis.readLine());

            Employee[] employees = new Employee[n];

            // Accepting information of n employees
            for (int i = 0; i < n; i++) {
                employees[i] = new Employee();
                employees[i].readDetails();
            }

            // Displaying the details of all employees
            System.out.println("\nDetails of all employees:");
            for (Employee employee : employees) {
                employee.displayDetails();
                System.out.println("----------------------");
            }

            // Searching for an employee using eno
            System.out.println("\nEnter the employee number to search: ");
            int searchEno = Integer.parseInt(dis.readLine());

            boolean found = false;
            for (Employee employee : employees) {
                if (employee.eno == searchEno) {
                    System.out.println("\nEmployee found!");
                    employee.displayDetails();
                    found = true;
                    break;
                }
            }

            if (!found) {
                System.out.println("\nEmployee with eno " + searchEno + " not found.");
            }
        } catch (IOException e) {
            System.out.println("Error: " + e);
        }
    }
}
