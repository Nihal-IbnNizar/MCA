<<<<<<< HEAD
import java.io.*;
import java.util.*;
import java.sql.*;

class DBDelete {

   public static void main(String args[]) {
	Connection con;
	Statement st;
	int no;
	Scanner s = new Scanner(System.in);
	try {
	  Class.forName("com.mysql.jdbc.Driver");
	  con = DriverManager.getConnection("jdbc:mysql://localhost:3306/ems_db?characterEncoding=utf8","root","");
	  st = con.createStatement();
	  System.out.println("Enter no to be deleted");
	  no = s.nextInt();
	  String str = "delete from emp where eno=" + no;
	  System.out.println(str);
	  st.executeUpdate(str);
	  System.out.println("One Record is Deleted..");
 	}
	catch(Exception e) {
		System.out.println("Error " + e);
	}
  }
}
=======
import java.io.*;
import java.util.*;
import java.sql.*;

class DBDelete {

   public static void main(String args[]) {
	Connection con;
	Statement st;
	int no;
	Scanner s = new Scanner(System.in);
	try {
	  Class.forName("com.mysql.jdbc.Driver");
	  con = DriverManager.getConnection("jdbc:mysql://localhost:3306/ems_db?characterEncoding=utf8","root","");
	  st = con.createStatement();
	  System.out.println("Enter no to be deleted");
	  no = s.nextInt();
	  String str = "delete from emp where eno=" + no;
	  System.out.println(str);
	  st.executeUpdate(str);
	  System.out.println("One Record is Deleted..");
 	}
	catch(Exception e) {
		System.out.println("Error " + e);
	}
  }
}
>>>>>>> 206f68cff34891f990a614afb259de80a9fc2562
