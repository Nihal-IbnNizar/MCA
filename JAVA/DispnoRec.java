import java.util.Scanner;

public class DispnoRec {

    public static void main(String[] args) {
        System.out.println("MUHAMMED NIHAL");

        Scanner s = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = s.nextInt();

        System.out.println("Displaying numbers from " + n + " to 1:");
        dispNum(n);

        System.out.println("\nDisplaying numbers from 1 to " + n + ":");
        dispNumFrom1(n);
    }

    // Function to display numbers from n to 1 recursively
    public static void dispNum(int n) {
        if (n >= 1) {
            System.out.print(n + " ");
            dispNum(n - 1);
        }
    }

    // Function to display numbers from 1 to n recursively
    public static void dispNumFrom1(int n) {
        if (n >= 1) {
            dispNumFrom1(n - 1);
            System.out.print(n + " ");
        }
    }
}
