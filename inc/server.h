#ifndef SERVER_H
#define SERVER_H

#include<pthread.h>
#include<stdbool.h>
#include<stdint.h>
#include<stdlib.h>

#define MAX_THRED_N 16

typedef enum
{
    topic0,
    topic1,
    topic2,
    topic3,
    topic4

}TOPIC;



void server_run(void);



#endif