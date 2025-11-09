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

    int server_fd = socket(AF_INET, SOCK_STREAM, 0); /*creates IPV4 and TCP stream*/
    
    struct sockaddr_in serverAddr; /*structure for IPv4 addresses*/
    serverAddr.sin_family = AF_INET; 
    serverAddr.sin_port = htons(8080); /*bytes order to big endian*/
    serverAddr.sin_addr.s_addr = INADDR_ANY; /*listen to any addresses interface*/

    bind(server_fd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)); /*bind the TPC socket with the serverAddr*/
    listen(server_fd, 3);

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


static TCP server_check_for_client(void)
{
    /*
    * Funciton that will be listen to the local port
    * for MQTT clients
    * Input: void
    * Output: MQTT buffer data
    */



}

void server_run(void)
{
    server_init();

    while(1)
    {
        /*check connection*/
    }
}

