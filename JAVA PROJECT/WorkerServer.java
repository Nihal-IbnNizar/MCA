import java.io.*;
import java.net.*;
import java.util.Scanner;

public class WorkerServer {
    public static void main(String args[]) {
        ServerSocket ss;
        Socket as;
        DataInputStream sin;
        DataOutputStream sout;
        try {
            ss = new ServerSocket(1234);
            System.out.println("Server started. Waiting for a client...");

            as = ss.accept();
            System.out.println("Client connected.");

            sin = new DataInputStream(as.getInputStream());
            sout = new DataOutputStream(as.getOutputStream());

            Scanner scanner = new Scanner(System.in);

            int choice;

            while (true) {
                sout.writeUTF("Welcome to the Worker Registration System.\n1. Register as a worker\n2. Find worker\nEnter your choice:");
                choice = sin.readInt(); // Read integer choice from client
                System.out.println("Client says: " + choice);

                if (choice == 1) {
                    // Register as a worker
                    sout.writeUTF("Enter name:");
                    // Similarly, read other details like age, gender, job, contact details
                } else if (choice == 2) {
                    // Find worker
                    sout.writeUTF("What type of worker do you require?\n1. Carpenter\n2. Plumber\n3. Cleaner\nEnter your choice:");
                    // Similarly, handle the logic for finding worker based on the client's choice
                } else if (choice == -1) {
                    // If client requests to quit
                    System.out.println("Client is closing...");
                    break;
                } else {
                    sout.writeUTF("Invalid choice.");
                }
            }

            as.close();
            ss.close();
            scanner.close();
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
