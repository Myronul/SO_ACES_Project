#include"server.h"

static bool threadBool[MAX_THRED_N];      /*buffer containing all the id of threads*/
static pthread_t threadTAB[MAX_THRED_N];  /*buffer containinf all the threads*/

static uint8_t threadCounter = 0;

typedef struct MQDATA
{
    uint8_t id;  /*msg id*/
    TOPIC topic; /*mqtt topic*/
    int* data;   /*data received*/

}MQDATA;


static void server_init(void)
{
    for(uint8_t i=0; i<MAX_THRED_N; i++)
    {
        threadBool[i] = 0;
    }
}

void server_run(void)
{
    server_init();

    while(1)
    {
        
    }
}