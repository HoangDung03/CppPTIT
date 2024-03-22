#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>

#define DEFAULT_BUFLEN 512

using namespace std;

int main(int argc, char** argv) {
    WSADATA wsaData;

    int iResult;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        cout << "WSAStartup failed with error: " << iResult << endl;
        return 1;
    }
    cout << "WSAStartup OK" << endl;

    SOCKET sc = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sc == INVALID_SOCKET) {
        cout << "socket failed with error: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }
    cout << "ConnectSocket = socket OK" << endl;

    int port = 8080;
    const char* IP = "127.0.0.1";
    SOCKADDR_IN svrAddr;
    int svrAddrLen = sizeof(svrAddr);
    svrAddr.sin_family = AF_INET;
    svrAddr.sin_port = htons(port);
    svrAddr.sin_addr.s_addr = inet_addr(IP); 

    if (connect(sc, reinterpret_cast<SOCKADDR*>(&svrAddr), svrAddrLen) == SOCKET_ERROR) {
        cout << "\nCLIENT: Connection failed" << endl;
        system("pause");
        WSACleanup();
        return 0;
    } else {
        cout << "\nCLIENT: Connection success" << endl;
        cout << "-----------------------------------------------------------------------" << endl;
    }

    // Send data
    int n;
    char a[10000];

    // Input
    cout << "\nInput n: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    send(sc, a, n, 0);

    char connectedClient[256];
    int dodai = recv(sc, connectedClient, sizeof(connectedClient), 0);
    if (dodai > 0) connectedClient[dodai] = '\0';
    cout << "\nRecv from server: " << connectedClient << "\n size=" << dodai;

    cin >> n;

    closesocket(sc);
    WSACleanup();
    getchar();
    return 0;
}

