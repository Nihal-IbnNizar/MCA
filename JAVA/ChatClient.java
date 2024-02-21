import java.io.*;
import java.util.*;
import java.net.*;

public class ChatClient {
    public static void main(String args[]){
        Socket as;
        DataInputStream sin;
        DataOutputStream sout;
        try {
            as = new Socket("localhost",1234);
            System.out.println("\nConnected to Server.");
            sin = new DataInputStream(as.getInputStream());
            sout = new DataOutputStream(as.getOutputStream());
            Scanner s = new Scanner(System.in);
            
            String received;
            String toSend;

            while(true){
                System.out.print("\nClient : ");
                toSend = s.nextLine();
                sout.writeUTF(toSend);
                if(toSend.equals("quit")){
                    System.out.println("\nClient is closing......");
                    break;
                }

                received = sin.readUTF();
                System.out.println("\nServer says : "+received);
                if(received.equals("quit")){
                    System.out.println("\nServer is stopping......");
                    break;
                }
            }
            as.close();
            s.close();

        } catch (Exception e) {
            System.out.println("\nError : "+e);
        }
    }    
}