import java.util.Scanner;

public class Nestedfunc_maxno {

    public static void main(String[] args) {
        System.out.println("MUHAMMED NIHAL");

        int num1,num2,num3;
        int result;

        Scanner s = new Scanner(System.in);

        System.out.print("Enter the first number: ");
        num1 = s.nextInt();

        System.out.print("Enter the second number: ");
        num2 = s.nextInt();

        System.out.print("Enter the third number: ");
        num3 = s.nextInt();

        result = findMaxOfThreeNumbers(num1, num2, num3);
        System.out.println("The maximum of three numbers is: " + result);
    }

    public static int findMaxOfTwoNumbers(int a, int b) {
        return (a > b) ? a : b;
    }

    // Function to find the maximum of three numbers using the result from the first function
    public static int findMaxOfThreeNumbers(int num1, int num2, int num3) {
        int maxOfFirstTwo = findMaxOfTwoNumbers(num1, num2);
        return findMaxOfTwoNumbers(maxOfFirstTwo, num3);
    }
}
