import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;

public class WorkerClient extends JFrame {
    private Socket as;
    private BufferedReader sin;
    private PrintWriter sout;
    private JTextArea outputArea;
    private JTextField userInputField;

    public WorkerClient() {
        super("Worker Client");

        // Create the text area for displaying messages
        outputArea = new JTextArea(10, 30);
        outputArea.setEditable(false);
        outputArea.setLineWrap(true);
        JScrollPane scrollPane = new JScrollPane(outputArea);

        // Create the text field for user input
        userInputField = new JTextField(20);
        userInputField.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                sendMessage();
            }
        });

        // Create the button to send messages
        JButton sendButton = new JButton("Send");
        sendButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                sendMessage();
            }
        });

        // Create a panel for user input and send button
        JPanel inputPanel = new JPanel();
        inputPanel.setLayout(new BorderLayout());
        inputPanel.add(userInputField, BorderLayout.CENTER);
        inputPanel.add(sendButton, BorderLayout.EAST);

        // Create a panel for holding text area and user input/send button panel
        JPanel contentPanel = new JPanel();
        contentPanel.setLayout(new BorderLayout());
        contentPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        contentPanel.add(scrollPane, BorderLayout.CENTER);
        contentPanel.add(inputPanel, BorderLayout.SOUTH);

        // Add the content panel to the frame
        add(contentPanel);

        // Configure frame properties
        setSize(400, 300);
        setLocationRelativeTo(null); // Center the frame on the screen
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);

        connectToServer();
    }

    private void connectToServer() {
        try {
            as = new Socket("localhost", 1234);
            //outputArea.append("Connected to server.\n");
            sin = new BufferedReader(new InputStreamReader(as.getInputStream()));
            sout = new PrintWriter(as.getOutputStream(), true);
            receiveMessages();
        } catch (IOException e) {
            outputArea.append("Error connecting to server.\n");
            e.printStackTrace();
        }
    }

    private void sendMessage() {
        String message = userInputField.getText();
        sout.println(message);
        userInputField.setText("");
    }

    private void receiveMessages() {
        new Thread(new Runnable() {
            public void run() {
                String received;
                try {
                    while ((received = sin.readLine()) != null) {
                        outputArea.append(received + "\n");
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }).start();
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                try {
                    UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
                } catch (ClassNotFoundException | InstantiationException | IllegalAccessException | UnsupportedLookAndFeelException e) {
                    e.printStackTrace();
                }
                new WorkerClient();
            }
        });
    }
}
