//Program to check if the inputis directory or file

import java.io.File;

class DirOrFile {
    File f = new File("D:\\testt");

    if(f.isDirectory() == true){
        System.out.println("It is a directory!");
    }
    else{
        System.out.println("It is a file!");
    }
}
