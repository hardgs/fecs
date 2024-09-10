#include <Fecs/http/request.h>
#include <Fecs/http/url.h>
#include <Fecs/pointer.h>
#include <Fecs/types.h>
#include <stdio.h>
#include <string.h>

int initRequest(request* r)
{
	initMap(&r->headers);
	addKeyValue(&r->headers,newString("Connection"),newString("close"));
	addKeyValue(&r->headers,newString("User-Agent"),newString("Fecs/1.0"));
	return (r->_socket = socket(AF_INET,SOCK_STREAM,0));
}
responseData requestGET(request* r,char* _url)
{
	responseData respone;
	respone.content = NULL;
	url link = parseURL(_url);
	
	r->_info = getSocketInfo(AF_INET,strToInt(link.port),link.location);// Need Convert Port String To Number. 
	
	/* Initing And Send Headers */
	char* send_buf=(char*)malloc(512);
	snprintf(send_buf,512,"GET %s HTTP/1.1\r\nHost: %s",link.path,link.location);
	/* Headers Loop */
	node* tmp = r->headers.keys.first;
	node* tmpV = r->headers.values.first;
	while(1){
		snprintf(send_buf,512,"%s\r\n%s: %s",send_buf,(char*)tmp->value,(char*)tmpV->value);
		if(tmp->next!=NULL){
			tmp = tmp->next;
			tmpV = tmpV->next;
		}
		else
			break;
	}
	snprintf(send_buf,512,"%s\r\n\r\n",send_buf);
	
	/* Connect To Server*/
	if(connect(r->_socket,(socketFullInfo*)&r->_info,sizeof(r->_info))<0){
		printf("ERROR: Can't Connect To Server\n");
		respone.content = NULL;
		return respone;
	}
	
	/* Send Our Request To Server*/
	send(r->_socket,send_buf,512,0);
	free(send_buf);
	
	/* Initing And Recv Loop */
	int rcvbufSize = 4096;
	char* res_buf = (char*)malloc(rcvbufSize);
	int rcvBytes = 0;
	int totalBufSize = 0;
	
	/* Recv Loop*/
	while((rcvBytes = recv(r->_socket,res_buf+totalBufSize,4096,0))>0)
	{
		rcvbufSize*=2;
		totalBufSize+=rcvBytes;
		res_buf = (char*)realloc(res_buf,rcvbufSize);
		if(!res_buf){
			printf("ERROR: Memory\n");
			free(res_buf);
			return respone;
		}
	}
	
	/* Check If We Have Error */
	if(rcvBytes<0){
		printf("ERROR: Recvied Error\n");
		return respone;
	}
	
	/* Complete Result */
	res_buf[totalBufSize] = '\0';
	parseResponse(res_buf);
	respone.content = res_buf;
	
	closeSocket(r->_socket);
	return respone;
}
responseData requestPOST(request* r,char* _url,char* body)
{
	responseData respone;
	respone.content = NULL;
	/* Parse URL */
	url link = parseURL(_url);
	
	/* Initing Socket Info */
	r->_info = getSocketInfo(AF_INET,strToInt(link.port),link.location);
	
	/* Initing And Send Headers */
	char* send_buf=(char*)malloc(512);
	snprintf(send_buf,512,"POST %s HTTP/1.1\r\nHost: %s",link.path,link.location);
	
	/* Headers Loop */
	node* tmp = r->headers.keys.first;
	node* tmpV = r->headers.values.first;
	while(1){
		snprintf(send_buf,512,"%s\r\n%s: %s",send_buf,(char*)tmp->value,(char*)tmpV->value);
		if(tmp->next!=NULL){
			tmp = tmp->next;
			tmpV = tmpV->next;
		}
		else
			break;
	}
	//if(body!=NULL)
		snprintf(send_buf,512,"%s\r\n\r\n%s",send_buf,body);
	//else
	//	snprintf(send_buf,512,"%s\r\n\r\n",send_buf);
	
	
	/* Connect To Server*/
	if(connect(r->_socket,(socketFullInfo*)&r->_info,sizeof(r->_info))<0){
		printf("ERROR: Failed Connect\n");
		respone.content = NULL;
		return respone;
	}
	
	/* Send Our Request To Server*/
	send(r->_socket,send_buf,512,0);
	free(send_buf);
	
	/* Initing And Recv Loop */
	int rcvbufSize = 4096;
	char* res_buf = (char*)malloc(rcvbufSize);
	int rcvBytes = 0;
	int totalBufSize = 0;
	
	/* Recv Loop*/
	while((rcvBytes = recv(r->_socket,res_buf+totalBufSize,4096,0))>0)
	{
		rcvbufSize*=2;
		totalBufSize+=rcvBytes;
		res_buf = (char*)realloc(res_buf,rcvbufSize);
		if(!res_buf){
			printf("ERROR: Memory\n");
			free(res_buf);
			return respone;
		}
	}
	
	/* Check If We Have Error */
	if(rcvBytes<0){
		printf("ERROR: Recvied Error\n");
		return respone;
	}
	
	/* Complete Result */
	res_buf[totalBufSize] = '\0';
	respone.content = res_buf;
	
	closeSocket(r->_socket);
	return respone;
}
