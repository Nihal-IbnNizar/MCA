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
            String input;

            while (true) {
                received = sin.readLine();
                System.out.println("Server says: " + received);

                if (received.equals("Enter your choice:")) {
                    System.out.print("Client: ");
                    input = scanner.nextLine(); // Read user input
                    sout.println(input); // Send input to server
                } else if (received.startsWith("Worker Details:")) {
                    System.out.println(received);
                } else if (received.equalsIgnoreCase("quit")) {
                    System.out.println("Server is closing...");
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
