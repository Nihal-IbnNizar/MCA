import java.io.*;
import java.util.*;

class FRead {
    public static void main(String[] args) {
        FileInputStream fin;
        Scanner s = new Scanner(System.in);
        String fname;
        try{
            System.out.println("Enter file name: ");
            fname = s.nextLine();
            fin = new FileInputStream(fname);
            int ch;
            ch = fin.read();
            while(ch != -1){
                System.out.println((char)ch);
                ch = fin.read();
            }
            fin.close();
        }
        catch(Exception e){
            System.out.println("Error: " +e);
        }
    }
}    

//if the file that we want to open is not in the same drive as this program is,
//then, we need to give the path of the file. [D:\\abc.txt]