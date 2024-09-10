#include <Fecs/socket.h>
#include <stdio.h>

int main()
{
	// Initing Fecs Socket
	if(initFecsSockets()){
		printf("Inited Socketing\n");
	}else{
		printf("Error In Initing Socketing\n");
	}
	
	int chose;
	printf("[1]: Server Mode [2]: Client Mode\n[?]:");
	scanf("%d",&chose);
	if(chose==1)
	{
		Socket server,cli;
		socketInfo serverInfo = getSocketInfo(AF_INET,8080,"127.0.0.1");
		socketInfo cliInfo;
		unsigned int cli_length,ser_length;
		char buffer[1024];
		
		if((server = socket(AF_INET,SOCK_STREAM,0))==INVALID_SOCKET){
			printf("ERROR: Inting Socket\n");
			return -1;
		}
		
		ser_length = sizeof(serverInfo);
		
		if(bind(server,(socketFullInfo*)&serverInfo,ser_length)==SOCKET_ERROR){
			printf("ERROR: Bind Socket\n");
			return -1;
		}
		if(listen(server,5)<0){
			printf("ERROR: Listen Socket\n");
			return -1;
		}
		while(1){
			cli_length = sizeof(cliInfo);
			if((cli = accept(server, (socketFullInfo*)&cliInfo, &cli_length)) < 0){
				printf("ERROR: Accepting Connection\n");
				return -1;
			}
			printf("New Connection.\n");
			while(1){
				memset(buffer, 0, sizeof(buffer));
				int bytesReceived = recv(cli, buffer, sizeof(buffer), 0);
				if(bytesReceived <= 0){
					printf("Connection closed or error occurred\n");
					break;
				}
				printf("%s\n", buffer);
			}
			closeSocket(cli);
		}
	}
	else
	{
		Socket client;
		socketInfo clientInfo = getSocketInfo(AF_INET,8080,"127.0.0.1");
		if((client = socket(AF_INET,SOCK_STREAM,0))==SOCKET_ERROR){
			printf("ERROR: SOCKET INIT\n");
			return -1;
		}

		if(connect(client,(socketFullInfo*)&clientInfo,sizeof(clientInfo))<0){
			printf("ERROR: Connect...\n");
			return -1;
		}
		
		while(1){
			char message[256];
			fgets(message,256,stdin);
			if(send(client,message,strlen(message),0)<0){
				printf("ERROR: Send Message\n");
				return -1;
			}
		}
		
		closeSocket(client);
	}
	return 0;
}