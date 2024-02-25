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

                // Menu loop
                while (true) {
                    // Send menu options to client
                    sendMenuOptions(sout);

                    // Receive client's choice
                    String choice = sin.readLine();
                    if ("8".equals(choice)) {
                        registerWorker(sin, sout, con);
                    } else if (isValidChoice(choice)) {
                        String job = getJobFromChoice(choice);
                        if (job != null) {
                            String query = "SELECT * FROM workers WHERE job = ?";
                            try (PreparedStatement preparedStatement = con.prepareStatement(query)) {
                                preparedStatement.setString(1, job);
                                ResultSet resultSet = preparedStatement.executeQuery();
                                // Send worker information to the client
                                sout.println("\nMatching Workers for " + job + ":");
                                sout.println("NAME\t\t\tAGE\tGENDER\t\tWAGE/DAY\tCONTACT");
                                while (resultSet.next()) {
                                    String name = resultSet.getString("name");
                                    int age = resultSet.getInt("age");
                                    String gender = resultSet.getString("gender");
                                    double wage = resultSet.getDouble("wage");
                                    String contact = resultSet.getString("contact");

                                    // Format worker details with proper spacing
                                    String formattedInfo = String.format("%-20s\t%-5d\t%-10s\t%-10s\t%-15s",
                                            name, age, gender, "INR " + wage, contact);
                                    sout.println(formattedInfo);
                                }
                            }

                            // After sending worker details, ask if the client wants to try another job
                            sout.println("\nDo you want to try another job? (yes/no):");
                            String continueChoice = sin.readLine();
                            if ("no".equalsIgnoreCase(continueChoice)) {
                                sout.println("quit");
                                break; // Break out of the menu loop
                            }
                        } else {
                            sout.println("Invalid choice.");
                        }
                    } else {
                        sout.println("Invalid choice. Please enter a number between 1 and 8.");
                    }
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
        sout.println("8. Register as a Worker");
        sout.println("\nPlease enter the number corresponding to the worker category:");
    }
    private static void sendOptions(PrintWriter sout) {
        sout.println("\nAvailable Worker Categories:");
        sout.println("1. Carpenter");
        sout.println("2. Plumber");
        sout.println("3. Electrician");
        sout.println("4. Mechanic");
        sout.println("5. Mason");
        sout.println("6. Welder");
        sout.println("7. Maintenance Worker");
        sout.println("\nPlease enter the number corresponding to the worker category:");
    }

    private static boolean isValidChoice(String choice) {
        return choice != null && choice.matches("[1-8]");
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
            case "8":
                return null;
            default:
                return null;
        }
    }

    private static void registerWorker(BufferedReader sin, PrintWriter sout, Connection con) throws IOException, SQLException {
        sout.println("\nEnter your details to register as a worker:");
        sout.println("Name:");
        String name = sin.readLine();
        sout.println("Age:");
        int age = Integer.parseInt(sin.readLine());
        sout.println("Gender:");
        String gender = sin.readLine();
        sout.println("Job:");
        sendOptions(sout);
        String job = getJobFromChoice(sin.readLine());
        sout.println("Wage/Day:");
        double wage = Double.parseDouble(sin.readLine());
        sout.println("Contact:");
        String contact = sin.readLine();

        // Insert the worker's details into the database
        String query = "INSERT INTO workers (name, age, gender, job, wage, contact) VALUES (?, ?, ?, ?, ?, ?)";
        try (PreparedStatement preparedStatement = con.prepareStatement(query)) {
            preparedStatement.setString(1, name);
            preparedStatement.setInt(2, age);
            preparedStatement.setString(3, gender);
            preparedStatement.setString(4, job);
            preparedStatement.setDouble(5, wage);
            preparedStatement.setString(6, contact);
            int rowsInserted = preparedStatement.executeUpdate();
            if (rowsInserted > 0) {
                sout.println("Registration successful. You are now registered as a worker.");
            } else {
                sout.println("Registration failed. Please try again.");
            }
        }
    }
}
