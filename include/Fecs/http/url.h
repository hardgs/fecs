#ifndef FECS_HTTP_URL_H
#define FECS_HTTP_URL_H

#include <stdio.h>
#include <string.h>

struct url
{
	char* type;
	char* location;
	char* path;
	char* port;
};
typedef struct url url;

/*
 * Don't Enter URL LIke 127.0.0.1:80/index?google=true
 * you Must Enter http:// or https://
 * Good.
*/
static url parseURL(char* link)
{
	url tmp;
	tmp.type = "http";
	tmp.path = "/";
	tmp.port = "80";
	tmp.location = NULL;
	
	char isLocation = 0;
	char isType = 0;
	char isPath = 0;
	char isPort = 0;
	
	char* text = (char*)malloc(1);
	int size=0;
	for(int i=0;link[i]!='\0';i++){
		size++;
		if(link[i]==':'){
			if(isType==0 && isLocation==0){
				i+=2;
				tmp.type = text;
				isType = 1;
				text = (char*)malloc(1);
				size=0;
			}
			else if(isType==1 && isPort==0){
				tmp.location = text;
				isLocation==1;
				isPort=2;
				text = (char*)malloc(1);
				size=0;
			}else{
				text = (char*)realloc(text,size);
				text[size-1] = link[i];
				text[size] = '\0';
			}
		}
		else if(link[i]=='/'){
			if(isPort==2){
				tmp.port = text;
				isPort=1;
				text = (char*)malloc(2);
				text[0] = '/';
				text[1] = '\0';
				size=1;
			}else if(isPort==0 && isLocation==0){
				tmp.location = text;
				isLocation=1;
				text = (char*)malloc(2);
				text[0] = '/';
				text[1] = '\0';
				size=1;
			}else{
				text = (char*)realloc(text,size);
				text[size-1] = link[i];
				text[size] = '\0';	
			}
		}
		else{
			text = (char*)realloc(text,size);
			text[size-1] = link[i];
			text[size] = '\0';
		}
	}
	// Handle End Part
	if(isPath==0 && isPort==2){
		tmp.port = text;
		isPort = 1;
	}
	else if(isPath==0 && isPort!=2){
		tmp.path = text;
	}
	return tmp;
}
#endif