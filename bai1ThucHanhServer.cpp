#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <iostream>

#define DEFAULT_BUFLEN 512
using namespace std;

int main() {
    cout << "Hello";
    int iResult = 0;

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cout << "\nWINSOCK: Khoi tao that bai\n";
        WSACleanup();
        return 0;
    } else {
        cout << "\nWINSOCK: Khoi tao thanh cong\n";
    }

    SOCKET ListenSocket = INVALID_SOCKET;

    ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ListenSocket == INVALID_SOCKET) {
        printf("Error at socket(): %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    u_short port = 8080;
    const char *IP = "127.0.0.1";
    SOCKADDR_IN svrAddr, cliAddr; 
    int cliAddrLen = sizeof(cliAddr); 
    int svrAddrLen = sizeof(svrAddr);
    svrAddr.sin_family = AF_INET;
    svrAddr.sin_port = htons(port);
    svrAddr.sin_addr.s_addr = inet_addr(IP);
    
    iResult = bind(ListenSocket, (SOCKADDR *)&svrAddr, svrAddrLen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    cout << "ListenSocket: " << ListenSocket << endl;

    if (listen(ListenSocket, 5) == SOCKET_ERROR) {
        printf("Listen failed with error: %ld\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    cout << "Listening ... " << endl;
    do {
       
        SOCKET sa = accept(ListenSocket, (SOCKADDR *)&cliAddr, &cliAddrLen);
        cout << "Nhan du lieu tu IP:" << inet_ntoa(cliAddr.sin_addr) << " port: " << ntohs(cliAddr.sin_port) << endl;

        if (sa == INVALID_SOCKET) {
            printf("accept failed: %d\n", WSAGetLastError());
            closesocket(sa);
            WSACleanup();
            return 1;
        }

        char recvbuf[DEFAULT_BUFLEN];
        int iSendResult;
        int recvbuflen = DEFAULT_BUFLEN;
        iResult = recv(sa, recvbuf, recvbuflen, 0);

        string s = recvbuf;
        char a[s.length()];
        char k = s[0];
        char tmp;

        for (int i = 0; i < s.length(); i++) {
            a[i] = (int)s[i];
        }

        if (iResult > 0) {
            recvbuf[iResult] = '\0';
            cout << "Array: " << recvbuf << endl;
            cout << "Bytes received: " << iResult << endl;

            for (int i = 0; i < s.length() - 1; i++) {
                for (int j = i; j < s.length(); j++) {
                    if (a[j] < a[i]) {
                        tmp = a[j];
                        a[j] = a[i];
                        a[i] = tmp;
                    }
                }
            }

            for (int i = 0; i < s.length(); i++) {
                cout << a[i];
            }

            iSendResult = send(sa, a, s.length(), 0);
            if (iSendResult == SOCKET_ERROR) {
                printf("send failed: %d\n", WSAGetLastError());
                closesocket(sa);
                WSACleanup();
                return 1;
            }
            cout << "Bytes sent: " << iSendResult << endl;
        }

        iResult = shutdown(sa, SD_SEND);
        if (iResult == SOCKET_ERROR) {
            printf("shutdown failed: %d\n", WSAGetLastError());
            closesocket(sa);
            WSACleanup();
            return 1;
        }

        closesocket(sa);
    } while (1);

    closesocket(ListenSocket);
    WSACleanup();
    getchar();
    return 0;
}

