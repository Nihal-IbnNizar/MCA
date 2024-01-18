//Program to read the contents of a directory.

import java.io.*;
import java.io.File;

class CFile {
    public static void main(String[] args) {
        File f;
        String s[];
        int i;
        try{
            f = new File("D:\\");
            s = f.list();
            for(i=0; i<s.length; i++){
                System.out.println(s[i]);
            }
        }
        catch(Exception e){
            System.out.println(e);
        }
    }
}
