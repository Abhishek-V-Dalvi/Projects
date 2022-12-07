//Check the status of a perticular bit position provided by user by creating mask dynamically
import java.lang.*;
import java.util.*;

class Bitwise
{
	public boolean CheckBit(int iNo, int iBit)
	{
		int iMask = 1;
		int iResult = 0;
		
		for(int iCnt = 1; iCnt < iBit; iCnt++)
		{
			iMask = iMask * 2;
		}
		
		iResult = iNo & iMask;
		
		if (iResult == 0)
		{
			return false;	
		}
		else
		{ 
			return true;
		}
	}
}

class CheckBitStatus3
{
	public static void main(String arg[])
	{
		Scanner sobj = new Scanner(System.in);
		
		System.out.println("Enter number");
		int value = sobj.nextInt();
		System.out.println("Enter bit position");
		int value1 = sobj.nextInt();
		
		Bitwise bobj = new Bitwise();
		boolean bret = bobj.CheckBit(value, value1);
		
		if (bret == true)
		{
			System.out.println("Bit is on");
		}
		else
		{
			System.out.println("Bit is off");
		}
	}
}

