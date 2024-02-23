import java.util.*;

public class PalindromeChecker {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int i;
        boolean flag = true;
        try {
            System.out.println("\nEnter a string to check for palindrome : ");
            String str = s.nextLine();
            str = str.toLowerCase(); // coverts entered string to lowercase

            // Comparing one character at a time till middle of the string is reached
            for (i = 0; i < (str.length() / 2); i++) {
                if (str.charAt(i) != str.charAt(str.length() - i - 1)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                System.out.println("\nString " + str + " is Palindrome.");
            } else {
                System.out.println("\nString " + str + " is Not a Palindrome.");
            }

        } catch (Exception e) {
            System.out.println("\nError : " + e);
        }
    }
}