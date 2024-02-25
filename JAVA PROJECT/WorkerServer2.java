import java.io.*;
import java.net.*;
import java.sql.*;

public class WorkerServer2 {
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

                // Send initial options to client
                sout.println("Welcome to Worker Search System!");
                sout.println("1. Register as a worker");
                sout.println("2. Search for a worker");

                // Receive client's choice
                String choice = sin.readLine();
                if ("1".equals(choice)) {
                    // Handle worker registration
                    registerWorker(sin, sout, con);
                } else if ("2".equals(choice)) {
                    // Handle searching for a worker
                    searchForWorker(sin, sout, con);
                } else {
                    sout.println("Invalid choice. Please enter 1 or 2.");
                }
            }

        } catch (IOException | ClassNotFoundException | SQLException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    private static void registerWorker(BufferedReader sin, PrintWriter sout, Connection con) throws IOException, SQLException {
        sout.println("You have chosen to register as a worker. Please provide the following information:");
    
        sout.println("Enter your name:");
        String name = sin.readLine();
    
        sout.println("Enter your age:");
        int age = Integer.parseInt(sin.readLine());
    
        sout.println("Enter your gender:");
        String gender = sin.readLine();
    
        sout.println("Enter your job:");
        String job = sin.readLine();
    
        sout.println("Enter your wage per day:");
        double wage = Double.parseDouble(sin.readLine());
    
        sout.println("Enter your contact:");
        String contact = sin.readLine();
    
        // Insert worker information into the database
        String query = "INSERT INTO workers (name, age, gender, job, wage, contact) VALUES (?, ?, ?, ?, ?, ?)";
        try (PreparedStatement preparedStatement = con.prepareStatement(query)) {
            preparedStatement.setString(1, name);
            preparedStatement.setInt(2, age);
            preparedStatement.setString(3, gender);
            preparedStatement.setString(4, job);
            preparedStatement.setDouble(5, wage);
            preparedStatement.setString(6, contact);
            int rowsAffected = preparedStatement.executeUpdate();
            if (rowsAffected > 0) {
                sout.println("Registration successful. You are now registered as a worker.");
            } else {
                sout.println("Registration failed. Please try again.");
            }
        }
    }
    

    private static void searchForWorker(BufferedReader sin, PrintWriter sout, Connection con) throws IOException, SQLException {
        // Send available worker categories to the client
        sout.println("You have chosen to search for a worker. Please select a worker category:");
        sout.println("1. Carpenter");
        sout.println("2. Plumber");
        sout.println("3. Electrician");
        sout.println("4. Mechanic");
        sout.println("5. Mason");
        sout.println("6. Welder");
        sout.println("7. Maintenance Worker");
        sout.println(); // Add an extra newline to indicate the end of the category list
    
        // Receive client's choice of worker category
        String choice = sin.readLine();
        if (isValidChoice(choice)) {
            String job = getJobFromChoice(choice);
            if (job != null) {
                // Display worker information for the chosen category
                displayWorkerInfo(sout, job, con);
            } else {
                sout.println("Invalid choice. Please enter a number between 1 and 7.");
            }
        } else {
            sout.println("Invalid choice. Please enter a number between 1 and 7.");
        }
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
    
    private static void displayWorkerInfo(PrintWriter sout, String job, Connection con) throws SQLException {
        sout.println("Displaying worker information for " + job + ":");
        String query = "SELECT * FROM workers WHERE job = ?";
        try (PreparedStatement preparedStatement = con.prepareStatement(query)) {
            preparedStatement.setString(1, job);
            ResultSet resultSet = preparedStatement.executeQuery();
    
            // Send worker information to the client
            sout.println("\nMatching Workers for " + job + ":");
            sout.println("NAME\t\t\tAGE\tGENDER\tWAGE/DAY\tCONTACT");
            while (resultSet.next()) {
                String name = resultSet.getString("name");
                int age = resultSet.getInt("age");
                String gender = resultSet.getString("gender");
                double wage = resultSet.getDouble("wage");
                String contact = resultSet.getString("contact");
    
                sout.printf("%-20s %-5d %-8s INR %-10.2f %s%n", name, age, gender, wage, contact);
            }
        }
    }
    
}
