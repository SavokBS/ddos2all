import java.net.*;
import java.io.*;
import java.util.Scanner;

public class Connect {
    public static void main(String[] args) throws IOException {
        boolean isOn = true;
        while (isOn) {
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter the address to connect to: ");
            String address = sc.nextLine();
            System.out.println("Enter the port to connect to: ");
            int port = sc.nextInt();
            try {
                Socket socket = new Socket(address, port);
                System.out.println("Connected to " + address + ":" + port);
                socket.close();
            } catch (UnknownHostException e) {
                System.out.println("Unknown host " + address);
                isOn = false;
            } catch (IOException e) {
                System.out.println("Couldn't get I/O for the connection to " + address + ". " + e);
                isOn = false;
            }
        }
    }
}
