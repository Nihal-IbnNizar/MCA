import java.io.*;
public class Swapno
{
	public static void main(String args[])
	{
		DataInputStream din;
		int num1;
		int num2;
		String s;
		din= new DataInputStream(System.in);

		try
		{
			System.out.println("MUHAMMED NIHAL");
			System.out.println("Enter the first number:");
			s=din.readLine();
			num1=Integer.parseInt(s);
			System.out.println("Enter the second number:");
			s=din.readLine();
			num2=Integer.parseInt(s);

			System.out.println("Before swapping:");
        		System.out.println("First Number: " + num1);
        		System.out.println("Second Number: " + num2);

			int temp = num1;
        		num1 = num2;
        		num2 = temp;

			System.out.println("After swapping:");
        		System.out.println("First Number: " + num1);
        		System.out.println("Second Number: " + num2);
		}
		catch(Exception e)
		{
			System.out.println("Error:" +e);
		}

	}
}
