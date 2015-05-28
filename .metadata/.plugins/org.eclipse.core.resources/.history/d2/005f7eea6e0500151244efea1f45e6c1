package simpleClient;
import java.net.*;
import java.nio.charset.Charset;
import java.nio.charset.CharsetEncoder;
import java.nio.charset.spi.CharsetProvider;
import java.io.*;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
	}
	private void createSocket(int port, String host){
		Socket con = null;
		try{
			con =  new Socket(host, port);
			Writer send = new OutputStreamWriter(con.getOutputStream(), Charset.forName("UTF-8"));
			BufferedInputStream buffer = new BufferedInputStream(con.getInputStream());
			InputStreamReader recieve = new InputStreamReader(buffer, "UTF-8");
		}
		catch(UnknownHostException e){
			System.err.println(e);
		}
		catch(IOException e){
			System.err.println(e);
		}
		finally{
			try{
				if(con!=null) con.close();
			}
			catch(IOException e){}
			}
		}
	
}
