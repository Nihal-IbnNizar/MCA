import java.io.File;

class CFileDir {
    public static void main(String[] args) {
        File f;
        String s[];
        int i;
        try{
            f = new File("D:\\MCA_Programs\\");
            s = f.list();
            for(i=0; i<s.length; i++){
                File ff = new File("D:\\MCA_Programs\\" +s[i]);
                if(ff.isDirectory()){
                    System.out.println(s[i]);
                }
            }
        }
        catch(Exception e){
            System.out.println("Error: " +e);
        }
    }
}
