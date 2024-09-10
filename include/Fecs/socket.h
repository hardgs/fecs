#ifndef FECS_SOCKET_H
#define FECS_SOCKET_H

#include <stdio.h>

#ifdef _WIN32
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib");

WSADATA _fecs_wsa;
static inline int initFecsSockets()
{
	if(WSAStartup(MAKEWORD(2, 2),&_fecs_wsa))
		return -1;
	return 1;
}
typedef unsigned int Socket;
static inline int closeSocket(Socket sock)
{
	return closesocket(sock);
}
#endif

#ifdef __unix__
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
static inline int initFecsSockets()
{
	return 1;
}
typedef int Socket;
static inline int closeSocket(Socket sock)
{
	return close(sock);
}
#endif

typedef struct sockaddr_in socketInfo;
typedef struct sockaddr socketFullInfo;

static inline socketInfo getSocketInfo(int family,int port,char* ip)
{
	socketInfo tmp;
	tmp.sin_family = family;
	tmp.sin_port = htons(port);
	tmp.sin_addr.s_addr = inet_addr(ip);
	return tmp;
}
#endif