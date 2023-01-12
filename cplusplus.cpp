#include <iostream>
#include <string>
#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32.lib")

int main()
{
    bool isOn = true;
    while (isOn) {
        std::string address;
        std::cout << "Enter the address to connect to: ";
        std::getline(std::cin, address);
        int port;
        std::cout << "Enter the port to connect to: ";
        std::cin >> port;

        WSADATA data;
        WORD version = MAKEWORD(2, 2);
        int wsOk = WSAStartup(version, &data);
        if (wsOk != 0)
        {
            std::cerr << "Can't start Winsock!" << std::endl;
            return 1;
        }

        SOCKET in = socket(AF_INET, SOCK_STREAM, 0);
        if (in == INVALID_SOCKET)
        {
            std::cerr << "Can't create a socket!" << std::endl;
            return 1;
        }

        sockaddr_in hint;
        hint.sin_family = AF_INET;
        hint.sin_port = htons(port);
        inet_pton(AF_INET, address.c_str(), &hint.sin_addr);

        int connResult = connect(in, (sockaddr*)&hint, sizeof(hint));
        if (connResult == SOCKET_ERROR)
        {
            std::cerr << "Can't connect to server!" << std::endl;
            return 1;
        }

        std::cout << "Connected to " << address << ":" << port << std::endl;
        closesocket(in);
        WSACleanup();
        isOn = false;
    }
    return 0;
}
