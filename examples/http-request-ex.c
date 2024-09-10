#include <Fecs/http/request.h>
#include <Fecs/http/url.h>
#include <Fecs/pointer.h>
#include <conio.h>

int main()
{
	// First Init Below
	initFecsSockets();
	/* Make A Request Object */
	request rq,rq2;
	
	/* Init Request Object */
	if(initRequest(&rq)<0){
		printf("ERROR: Initing Request\n");
	}
	if(initRequest(&rq2)<0){
		printf("ERROR: Inting Request 2\n");
	}
	
	/* Set Headers */
	addKeyValue(&rq.headers,newString("Content-Type"),newString(APP_FORM_TYPE));
	addKeyValue(&rq.headers,newString("Content-Length"),newString("12"));

	/* Request To A basic Server */
	responseData data = requestPOST(&rq,"http://127.0.0.1/","ip=127.0.0.1");
	//printf("Data: %s\n\n\n\n",data.content);
	responseData data2 = requestGET(&rq2,"http://127.0.0.1/dashboard/");
	//printf("Data: %s\n\n\n",data2.content);

	getch();
	return 0;
}