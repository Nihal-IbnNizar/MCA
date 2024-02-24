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
            String choice = ""; // Initialize choice variable

            while (true) {
                while ((received = sin.readLine()) != null) {
                    System.out.println("Server says: " + received);
                    if (received.startsWith("Enter your choice:")) {
                        System.out.print("Client: ");
                        choice = scanner.nextLine(); // Read user input
                        sout.println(choice); // Send input to server
                        break;
                    }
                }
                if ("quit".equalsIgnoreCase(choice)) {
                    System.out.println("Client is closing...");
                    break;
                }
            }

            as.close();
            scanner.close();
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
