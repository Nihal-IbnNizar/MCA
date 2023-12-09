import java.io.*;

public class TwoDarray_sum{

    public static void main(String args[]){
        System.out.println("Muhammed Nihal");
        DataInputStream din;
        din = new DataInputStream(System.in);
        int rows,cols,rowsum,colsum,i,j;
        int a[][];
        a = new int[100][100];
        try{
            //READ 2D array:
            System.out.println("\n2D array-->\nEnter the number of rows (MAX 100): ");
            rows=Integer.parseInt(din.readLine());
            System.out.println("\nEnter the number of columns (MAX 100): ");
            cols=Integer.parseInt(din.readLine());
            for(i=0;i<rows;i++){
                System.out.println("\nEnter values of row "+(i+1));
                for(j=0;j<cols;j++){
                   a[i][j]=Integer.parseInt(din.readLine());
                }
            }
            System.out.println("\nSUM OF ROWS AND COLUMNS-->\n");
            //Calculating SUM of rows and columns:
            for(i=0;i<rows;i++){
                rowsum=0;
                for(j=0;j<cols;j++){
                    rowsum=rowsum+a[i][j];
                }
                System.out.println("Sum of row "+(i+1)+" = "+rowsum);
            }
            
            for(i=0;i<cols;i++){
                colsum=0;
                for(j=0;j<rows;j++){
                    colsum=colsum+a[j][i];
                }
                System.out.println("Sum of column "+(i+1)+" = "+colsum);
            }
        }
        catch(Exception e){
            System.out.println("Error "+e);
        }

    }

}