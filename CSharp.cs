using System;
using System.Net;
using System.Net.Sockets;

class Connect
{
    public static void Main()
    {
        bool isOn = true;
        while (isOn)
        {
            Console.WriteLine("Enter the address to connect to: ");
            string address = Console.ReadLine();
            Console.WriteLine("Enter the port to connect to: ");
            int port = int.Parse(Console.ReadLine());

            try
            {
                TcpClient client = new TcpClient(address, port);
                Console.WriteLine("Connected to {0}:{1}", address, port);
                client.Close();
            }
            catch (ArgumentNullException e)
            {
                Console.WriteLine("ArgumentNullException: {0}", e);
                isOn = false;
            }
            catch (SocketException e)
            {
                Console.WriteLine("SocketException: {0}", e);
                isOn = false;
            }
        }
    }
}
