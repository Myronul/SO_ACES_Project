#include"server.h"

static bool threadBool[MAX_THRED_N];      /*buffer containing all the id of threads*/
static pthread_t threadTAB[MAX_THRED_N];  /*buffer containinf all the threads*/

static uint8_t threadCounter = 0;

typedef struct TCP
{
    uint8_t id;  /*msg id*/
    TOPIC topic; /*mqtt topic*/
    char* data;   /*data received*/

}TCP;


static void server_init(void);
static void* server_thread_function(void* arg);
void server_run(void);


static void server_init(void)
{
    /*
    * Function to init the server. It will generate
    * the threads to manage the clients.
    * Input: void
    * Output: void
    */

    for(uint8_t i=0; i<MAX_THRED_N; i++)
    {

        threadBool[i] = 0;
        pthread_create(&threadTAB[i], NULL, server_thread_function, NULL);
    }

}


static void* server_thread_function(void* arg)
{
    /*
    * Function for the thread running
    * a certain topic.
    * Input: argument void*
    * Output: void
    */


    while(1)
    {

    }


    return NULL;
}


void server_run(void)
{
    int server_fd;
    struct sockaddr_in serverAddr; /*structure for IPv4 addresses*/
    struct sockaddr_in clientAddr;
    socklen_t addrLen;
    char buffer[1024];

    //server_init();

    server_fd = socket(AF_INET, SOCK_STREAM, 0); /*creates IPV4 and TCP stream*/
    serverAddr.sin_family = AF_INET; 
    serverAddr.sin_port = htons(8080); /*bytes order to big endian*/
    serverAddr.sin_addr.s_addr = INADDR_ANY; /*listen to any addresses interface*/
    bind(server_fd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)); /*bind the TPC socket with the serverAddr*/
    listen(server_fd, 3);

    addrLen = sizeof(clientAddr);


    while(1)
    {
        int clientSock = accept(server_fd, (struct sockaddr*)&clientAddr, &addrLen); /*wait for client*/
        
        if(clientSock < 0)
        {
            printf("Error...");
            usleep(1000);
            continue;
        }

        int bytes = read(clientSock, buffer, sizeof(buffer)-1);
        buffer[bytes] = '\0';
        printf("%s", buffer);

        close(clientSock);
    }
}

