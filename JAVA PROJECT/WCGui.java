import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;

public class WCGui extends JFrame {
    private JTextArea clientLog;
    private JTextField userInput;

    private Socket as;
    private BufferedReader sin;
    private PrintWriter sout;

    public WCGui() {
        setTitle("Worker Client");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        clientLog = new JTextArea();
        clientLog.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(clientLog);

        userInput = new JTextField();
        userInput.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                sendMessage();
            }
        });

        JPanel inputPanel = new JPanel(new BorderLayout());
        inputPanel.add(new JLabel("Client:"), BorderLayout.WEST);
        inputPanel.add(userInput, BorderLayout.CENTER);

        add(scrollPane, BorderLayout.CENTER);
        add(inputPanel, BorderLayout.SOUTH);

        setVisible(true);

        connectToServer();
    }

    private void connectToServer() {
        try {
            as = new Socket("localhost", 1234);
            clientLog.append("Connected to server.\n");

            sin = new BufferedReader(new InputStreamReader(as.getInputStream()));
            sout = new PrintWriter(as.getOutputStream(), true);

            new Thread(() -> {
                try {
                    String received;
                    while ((received = sin.readLine()) != null) {
                        clientLog.append(received + "\n");
                        if (received.startsWith("Please enter") || received.startsWith("Do you want")) {
                            userInput.setEditable(true);
                        }
                        if (received.equals("quit")) {
                            break;
                        }
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }).start();

        } catch (IOException e) {
            clientLog.append(e.toString());
        }
    }

    private void sendMessage() {
        String message = userInput.getText();
        if (!message.isEmpty()) {
            userInput.setText("");
            userInput.setEditable(false);
            sout.println(message);
            clientLog.append("Client: " + message + "\n");
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(WCGui::new);
    }
}

