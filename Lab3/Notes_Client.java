import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Notes_Client {
	public static void main(String[] args){
		//Note stuff
		String inputName="MegamanEXE", inputData="Play Dota";
		Note someNote = new Note(inputName, inputData);
		
		//Networking stuff
		String serverName = "localhost";
		int port = 9008;
		
		try{
			Socket sSocket = new Socket(serverName, port);
			DataOutputStream toServer_string = new DataOutputStream(sSocket.getOutputStream());
			
			InputStream fromServer = sSocket.getInputStream();
			OutputStream toServer = sSocket.getOutputStream();
			DataInputStream in = new DataInputStream(fromServer);
			ObjectOutputStream oos = new ObjectOutputStream(toServer);
			
			Scanner cin = new Scanner(System.in);
			System.out.print("Download Notes(0) or archive to server(1): ");
			String choice = cin.nextLine();
			
			if(choice.equals("0")){
			//Download Notes
				System.out.println("Enter username: ");
				String uName = cin.nextLine();
				
				toServer.write(0); //Tell server that we're downloading
				toServer_string.writeUTF(uName);
				//For checking
				try {
					  Thread.sleep(1000);
					} catch (InterruptedException ie) {
					}
				
				System.out.println("Received: ");
				System.out.println(in.readUTF());
				
			}else if(choice.equals("1")){
				System.out.println("Enter username: ");
				String uname = cin.nextLine();
				
				System.out.println("Enter note: ");
				String noteData = cin.nextLine();
				toServer.write(1); //Tell server that we're archiving
				Note tempNote = new Note(uname,noteData);
				oos.writeObject(tempNote);
				
			}else{
				System.out.println("Invalid Choice");
			}
			
			//toServer.writeUTF("Sup, I'm a client");
			//System.out.println("Server says: " +in.readUTF());
			
			sSocket.close();
		}catch(IOException e){
			e.printStackTrace();
		}
	}
}
