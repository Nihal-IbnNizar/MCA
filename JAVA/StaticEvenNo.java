import java.io.*;
public class StaticEvenNo {

    static void displayEvenNumbers(int n) {
        System.out.print("Even numbers up to " + n + ": ");
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }
    public static void main(String[] args) {
        try {
            DataInputStream dis = new DataInputStream(System.in);
            System.out.println("Enter the value of n: ");
            int n = Integer.parseInt(dis.readLine());
            displayEvenNumbers(n);
        } 
        catch (Exception e) {
            System.out.println("Error: " + e);
        }
    }
}

