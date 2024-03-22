#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>

#define DEFAULT_BUFLEN 512

using namespace std;

int main(int argc, char **argv) 
{
    WSADATA wsaData;

    char recvbuf[DEFAULT_BUFLEN];
    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;
    char connectedClient[256];
    

    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }
	cout<<"WSAStartup OK"<<endl;
    SOCKET sc = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sc == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
	cout<<"ConnectSocket = socket OK"<<endl;


	int port=8080;
	const char *IP="127.0.0.1"; 
	SOCKADDR_IN svrAddr;
	int svrAddrLen = sizeof(svrAddr);
	svrAddr.sin_family = AF_INET;
	svrAddr.sin_port = htons(port);
	svrAddr.sin_addr.s_addr = inet_addr(IP);

	if (connect(sc, (SOCKADDR*) &svrAddr, svrAddrLen) == SOCKET_ERROR) {
		printf ("\nCLIENT: Connection failed\n");
		system("pause");
		WSACleanup();
		return 0;
	}else{
		printf("\nCLIENT: COnnection success\n");
		printf("-----------------------------------------------------------------------\n");
	}
	//Send data
    string myName;
    int n;
	char a[10000];
	//Input
	cout << "\nInput n: ";
	cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
	
	send(sc, a, n, 0);
		
	int dodai=recv(sc,connectedClient,sizeof(connectedClient),0);
	if(dodai>0) connectedClient[dodai]='\0';
	cout << "\nRecv from server: "<<connectedClient<<"\n size="<<dodai;

    cin >> n;

    closesocket(sc);
    WSACleanup();
	getchar();
    return 0;
}
