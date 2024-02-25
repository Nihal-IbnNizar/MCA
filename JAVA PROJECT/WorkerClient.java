import java.io.*;
import java.net.*;
import java.util.Scanner;

public class WorkerClient {
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
                    System.out.println(received);
                    if (received.startsWith("Please enter the number corresponding to the worker category:")) {
                        System.out.print("Client: ");
                        choice = scanner.nextLine(); // Read user input
                        sout.println(choice); // Send input to server
                        if ("quit".equalsIgnoreCase(choice)) {
                            System.out.println("Client is closing...");
                            break;
                        }
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
