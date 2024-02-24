import java.io.*;
import java.net.*;
import java.sql.*;
import java.util.HashMap;
import java.util.Map;

public class WorkerServer {
    private static final String DB_URL = "jdbc:mysql://localhost:3306/workers_db?characterEncoding=utf8";
    private static final String DB_USER = "root";
    private static final String DB_PASSWORD = "";

    public static void main(String args[]) {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD);

            ServerSocket ss = new ServerSocket(1234);
            System.out.println("Server started. Waiting for a client...");

            while (true) {
                Socket as = ss.accept();
                System.out.println("Client connected.");

                BufferedReader sin = new BufferedReader(new InputStreamReader(as.getInputStream()));
                PrintWriter sout = new PrintWriter(as.getOutputStream(), true);

                sout.println("What worker are you searching for?");
                sout.println("1. Carpenter");
                sout.println("2. Plumber");
                sout.println("3. Electrician");
                sout.println("4. Mechanic");
                sout.println("5. Mason");
                sout.println("6. Welder");
                sout.println("7. Maintenance Worker");
                sout.println("Enter your choice:");

                String choice = sin.readLine();
                if (choice != null && choice.matches("[1-7]")) {
                    String job = getJobFromChoice(choice);
                    if (job != null) {
                        String query = "SELECT * FROM workers WHERE job = ?";
                        try (PreparedStatement preparedStatement = con.prepareStatement(query)) {
                            preparedStatement.setString(1, job);
                            ResultSet resultSet = preparedStatement.executeQuery();
                            // Send worker information to the client
                            while (resultSet.next()) {
                                String workerInfo = resultSet.getString("name") + ", " +
                                                    resultSet.getInt("age") + ", " +
                                                    resultSet.getString("gender") + ", " +
                                                    resultSet.getDouble("wage") + ", " +
                                                    resultSet.getString("contact");
                                sout.println(workerInfo);
                            }
                        }
                    } else {
                        sout.println("Invalid choice.");
                    }
                } else {
                    sout.println("Invalid choice.");
                }

                as.close();
            }

        } catch (IOException | ClassNotFoundException | SQLException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    private static String getJobFromChoice(String choice) {
        Map<String, String> jobMap = new HashMap<>();
        jobMap.put("1", "Carpenter");
        jobMap.put("2", "Plumber");
        jobMap.put("3", "Electrician");
        jobMap.put("4", "Mechanic");
        jobMap.put("5", "Mason");
        jobMap.put("6", "Welder");
        jobMap.put("7", "Maintenance Worker");
        return jobMap.get(choice);
    }
}
