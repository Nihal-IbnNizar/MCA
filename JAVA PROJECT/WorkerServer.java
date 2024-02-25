import java.io.*;
import java.net.*;
import java.sql.*;

public class WorkerServer {
    private static final String DB_URL = "jdbc:mysql://localhost:3306/workers_db?characterEncoding=utf8";
    private static final String DB_USER = "root";
    private static final String DB_PASSWORD = "";

    public static void main(String args[]) {
        try {
            // Establish database connection
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD);
            System.out.println("Database connection established.");

            // Start server socket
            ServerSocket ss = new ServerSocket(1234);
            System.out.println("Server started. Waiting for a client...");

            while (true) {
                // Accept client connection
                Socket as = ss.accept();
                System.out.println("Client connected.");

                // Set up input and output streams for communication with client
                BufferedReader sin = new BufferedReader(new InputStreamReader(as.getInputStream()));
                PrintWriter sout = new PrintWriter(as.getOutputStream(), true);

                // Send menu options to client
                sendMenuOptions(sout);

                // Receive client's choice
                String choice = sin.readLine();
                if (isValidChoice(choice)) {
                    String job = getJobFromChoice(choice);
                    if (job != null) {
                        String query = "SELECT * FROM workers WHERE job = ?";
                        try (PreparedStatement preparedStatement = con.prepareStatement(query)) {
                            preparedStatement.setString(1, job);
                            ResultSet resultSet = preparedStatement.executeQuery();
                            // Send worker information to the client
                            sout.println("\nMatching Workers for " + job + ":");
                            while (resultSet.next()) {
                                String workerInfo = resultSet.getString("name") + ", " +
                                                    resultSet.getInt("age") + " years old, " +
                                                    resultSet.getString("gender") + ", " +
                                                    "earning INR " + resultSet.getDouble("wage") + " per day, " +
                                                    "contact: " + resultSet.getString("contact");
                                sout.println(workerInfo);
                            }
                        }
                    } else {
                        sout.println("Invalid choice.");
                    }
                } else {
                    sout.println("Invalid choice. Please enter a number between 1 and 7.");
                }

                // Close client connection
                as.close();
                System.out.println("Client connection closed.");
            }

        } catch (IOException | ClassNotFoundException | SQLException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    private static void sendMenuOptions(PrintWriter sout) {
        sout.println("=================================================================");
        sout.println("\t\tWelcome to Worker Search System!");
        sout.println("=================================================================");
        sout.println("\nAvailable Worker Categories:");
        sout.println("1. Carpenter");
        sout.println("2. Plumber");
        sout.println("3. Electrician");
        sout.println("4. Mechanic");
        sout.println("5. Mason");
        sout.println("6. Welder");
        sout.println("7. Maintenance Worker");
        //sout.println("Enter your choice:");

        sout.println("\nPlease enter the number corresponding to the worker category:");
        // sout.println("=================================================================");
    }

    private static boolean isValidChoice(String choice) {
        return choice != null && choice.matches("[1-7]");
    }

    private static String getJobFromChoice(String choice) {
        switch (choice) {
            case "1":
                return "Carpenter";
            case "2":
                return "Plumber";
            case "3":
                return "Electrician";
            case "4":
                return "Mechanic";
            case "5":
                return "Mason";
            case "6":
                return "Welder";
            case "7":
                return "Maintenance Worker";
            default:
                return null;
        }
    }
}
