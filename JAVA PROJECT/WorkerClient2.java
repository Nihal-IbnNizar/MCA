import java.io.*;
import java.net.*;

public class WorkerClient2 {
    public static void main(String[] args) {
        Socket socket = null;
        try {
            // Connect to the server
            socket = new Socket("localhost", 1234);
            System.out.println("Connected to server.");

            // Set up input and output streams for communication with the server
            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);

            // Display initial options to the user
            BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("Welcome to Worker Search System!");
            System.out.println("1. Register as a worker");
            System.out.println("2. Search for a worker");
            System.out.print("Enter your choice: ");

            // Get user choice for worker category
            String choice = userInput.readLine();
            writer.println(choice); // Send the user's choice to the server

            // Handle registration or searching based on user choice
            if ("1".equals(choice)) {
                // Handle worker registration
                registerAsWorker(reader, writer);
            } else if ("2".equals(choice)) {
                // Handle searching for a worker
                searchForWorker(socket, reader);
            } else {
                System.out.println("Invalid choice. Please enter 1 or 2.");
            }

            // Close the socket
            socket.close();
            System.out.println("Connection closed.");
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
            try {
                if (socket != null) {
                    socket.close();
                }
            } catch (IOException ex) {
                System.out.println("Error closing socket: " + ex.getMessage());
            }
        }
    }

    private static void registerAsWorker(BufferedReader reader, PrintWriter writer) throws IOException {
        // Display registration message from server
        String registrationMessage = reader.readLine();
        System.out.println(registrationMessage);

        // If registration is successful, no further action is needed from client side
        // If registration fails, client can choose to try again or exit
    }

    private static void searchForWorker(Socket socket, BufferedReader reader) throws IOException {
        // Display available worker categories received from server
        String categoryMessage;
        while ((categoryMessage = reader.readLine()) != null && !categoryMessage.isEmpty()) {
            System.out.println(categoryMessage);
        }

        // Receive user input for worker category
        BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter your choice: ");
        String choice = userInput.readLine();

        // Send user's choice to the server
        PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);
        writer.println(choice);

        // Display worker information received from server
        String workerInfo;
        while ((workerInfo = reader.readLine()) != null && !workerInfo.isEmpty()) {
            System.out.println(workerInfo);
        }
    }
}
