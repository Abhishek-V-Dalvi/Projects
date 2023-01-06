import java.text.SimpleDateFormat;
import java.lang.*;
import java.net.*;
import java.io.*;

class Server
{
	public static void main (String arg[]) throws Exception
	{
		System.out.println("Server application is running...");
		String s1,s2,filename;
		
		ServerSocket ss = new ServerSocket(1100);
		Socket s = ss.accept();
		
		System.out.println("Connection Successful");

		String timeStamp = new SimpleDateFormat("yyyy.MM.dd.HH.mm.ss").format(new java.util.Date());
		filename = ("Chatlog_"+timeStamp+".log");
		
		FileWriter myWriter = new FileWriter(filename);

		BufferedReader brK = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
		PrintStream ps = new PrintStream(s.getOutputStream());
		while((s1 = br.readLine())!=null)
		{
			System.out.println("Client says : "+s1);	
			myWriter.write("client -> "+s1+"\n");
			System.out.println("Enter message for client : ");
			s2 = brK.readLine();
			ps.println(s2);
      		myWriter.write("server -> "+s2+"\n");
		}
		s.close();
		ss.close();
		br.close();
		brK.close();
		ps.close();
		myWriter.close();
	}
}