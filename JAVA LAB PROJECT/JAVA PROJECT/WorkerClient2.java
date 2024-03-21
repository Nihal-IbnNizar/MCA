import java.io.*;
import java.net.*;
import java.util.Scanner;

public class WorkerClient2 {
    public static void main(String args[]) {
        Socket as;
        BufferedReader sin;
        PrintWriter sout;
        try {
            as = new Socket("localhost", 1234); // Change "localhost" to the server's IP address if needed
            System.out.println("Connected to server.");

            sin = new BufferedReader(new InputStreamReader(as.getInputStream()));
            sout = new PrintWriter(as.getOutputStream(), true);

            Scanner scanner = new Scanner(System.in);

            String received;
            String choice;

            while (true) {
                received = sin.readLine();
                if (received != null) {
                    if (received.startsWith("Please enter the number corresponding to the worker category:")) {
                        System.out.println(received);
                        System.out.print("Client: ");
                        choice = scanner.nextLine(); // Read user input
                        sout.println(choice); // Send input to server
                        if ("quit".equalsIgnoreCase(choice)) {
                            System.out.println("Client is closing...");
                            break;
                        }
                    } else if (received.startsWith("Enter your details to register as a worker:")) {
                        System.out.println(received);
                        System.out.print("Name: ");
                        sout.println(scanner.nextLine()); // Send user input to server
                        System.out.print("Age: ");
                        sout.println(scanner.nextLine()); // Send user input to server
                        System.out.print("Gender: ");
                        sout.println(scanner.nextLine()); // Send user input to server
                        System.out.println("Available Worker Categories:");
                        String jobChoice = "";
                        while (!jobChoice.matches("[1-8]")) {
                            System.out.println(received); // Print the job options
                            System.out.print("Client: ");
                            jobChoice = scanner.nextLine(); // Read user input
                        }
                        sout.println(jobChoice); // Send job choice to server
                        System.out.print("Wage/Day: ");
                        sout.println(scanner.nextLine()); // Send user input to server
                        System.out.print("Contact: ");
                        sout.println(scanner.nextLine()); // Send user input to server
                    } else if (received.startsWith("Do you want to try another job? (yes/no):")) {
                        System.out.println(received);
                        System.out.print("Client: ");
                        choice = scanner.nextLine(); // Read user input
                        sout.println(choice); // Send input to server
                        if ("quit".equalsIgnoreCase(choice)) {
                            System.out.println("Client is closing...");
                            break;
                        }
                    } else {
                        // For all other messages, just print
                        System.out.println(received);
                    }
                }
            }

            as.close();
            scanner.close();
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
