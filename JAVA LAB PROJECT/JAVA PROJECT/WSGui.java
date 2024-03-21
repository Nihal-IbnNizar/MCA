import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import java.sql.*;

public class WSGui extends JFrame {
    private static final String DB_URL = "jdbc:mysql://localhost:3306/workers_db?characterEncoding=utf8";
    private static final String DB_USER = "root";
    private static final String DB_PASSWORD = "";

    private JTextArea serverLog;

    public WSGui() {
        setTitle("Worker Server");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        serverLog = new JTextArea();
        serverLog.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(serverLog);

        add(scrollPane, BorderLayout.CENTER);

        setVisible(true);

        startServer();
    }

    private void startServer() {
        new Thread(() -> {
            try {
                // Establish database connection
                Class.forName("com.mysql.jdbc.Driver");
                Connection con = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD);
                updateLog("Database connection established.");

                // Start server socket
                ServerSocket ss = new ServerSocket(1234);
                updateLog("Server started. Waiting for a client...");

                while (true) {
                    // Accept client connection
                    Socket as = ss.accept();
                    updateLog("Client connected.");

                    // Set up input and output streams for communication with client
                    BufferedReader sin = new BufferedReader(new InputStreamReader(as.getInputStream()));
                    PrintWriter sout = new PrintWriter(as.getOutputStream(), true);

                    // Menu loop
                    while (true) {
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
                            sout.println("Invalid choice. Please enter a number between 1 and 7.");
                        }
                    }

                    // Close client connection
                    as.close();
                    updateLog("Client connection closed.");
                }

            } catch (IOException | ClassNotFoundException | SQLException e) {
                updateLog("Error: " + e.getMessage());
            }
        }).start();
    }

    private void sendMenuOptions(PrintWriter sout) {
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
        sout.println("\nPlease enter the number corresponding to the worker category:");
    }

    private boolean isValidChoice(String choice) {
        return choice != null && choice.matches("[1-7]");
    }

    private String getJobFromChoice(String choice) {
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

    private void updateLog(String message) {
        SwingUtilities.invokeLater(() -> {
            serverLog.append(message + "\n");
            serverLog.setCaretPosition(serverLog.getDocument().getLength());
        });
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(WSGui::new);
    }
}

