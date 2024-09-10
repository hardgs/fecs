#ifndef FECS_HTTP_REQUEST_H
#define FECS_HTTP_REQUEST_H

#define APP_FORM_TYPE "application/x-www-form-urlencoded"

#include <Fecs/socket.h>
#include <Fecs/map.h>
#include <string.h>

struct request
{
	Socket _socket;
	socketInfo _info;
	map headers;
};
typedef struct request request;

struct responseData
{
	int status;
	char* content;
	map headers;
};
typedef struct responseData responseData;

int initRequest(request* r);
responseData requestGET(request* r,char* _url);
responseData requestPOST(request* r,char* _url,char* body);

static map parseResponse(char* content)
{
    int size = strlen(content);
    char* text = (char*)malloc(1);
    if (text == NULL) {
        fprintf(stderr, "ERROR: MEMORY ALLOCATION FAILED\n");
        return;
    }
    text[0] = '\0'; // Initialize text to an empty string

    int index = 0;
    int isEndLine = 0;

    for (int i = 0; i < size; i++) {
        // Check for end of headers (double CRLF)
        if (content[i] == '\r' && content[i + 1] == '\n' && content[i + 2] == '\r' && content[i + 3] == '\n') {
            break; // End of headers
        }

        // Collect lines
        if (content[i] == '\n') {
            isEndLine = 1;
        } else if (content[i] != '\r') { // Ignore carriage return
            // Resize text to accommodate the new character
            char* newText = (char*)realloc(text, index + 2); // +1 for new char, +1 for null terminator
            if (newText == NULL) {
                fprintf(stderr, "ERROR: MEMORY REALLOCATION FAILED\n");
                free(text);
                return;
            }
            text = newText;
            text[index++] = content[i]; // Add the character
            text[index] = '\0'; // Null-terminate the string
        }

        // If we reached the end of a line
        if (isEndLine) {
            if (text[0] != '\0') {
				// Parse Header
                printf("[%s]\n", text); // Print the collected line
            }
            // Reset for the next line
            index = 0;
            isEndLine = 0;
        }
    }

    // Free allocated memory
    free(text);
}

#endif