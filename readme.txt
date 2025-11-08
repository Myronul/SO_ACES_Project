MQTT Server Project – Operating Systems Master Course, ACES UNSTPB ETTI

                        Project Overview

This is the final project for the Operating Systems course at the ACES Master program, ETTI, UNSTPB. The goal of this project is the development of 
an MQTT server in C running on Linux, capable of handling multiple clients and topics concurrently.
The server uses 16 default polling threads, each associated with a topic received by the server. Multiple clients and topics are supported simultaneously.

Server Architecture:
*On initialization, the server creates 16 threads ready to handle incoming topics.
For each client:
*If no thread is associated with a topic, an available thread is assigned.
*If all threads are busy, requests are managed using FIFO queuing or alternative scheduling strategies, such as priority queues.
*If a thread is already assigned to the topic, the message is forwarded to that thread.
*Messages follow a predefined application-level format. Commands can communicate between threads or access a shared data area, protected by a mutex or 
semaphore to ensure safe concurrent access.

Functionality:
*Real-time display of all data handled by threads.
*Simulation of sensor parameters (temperature, humidity, etc.) across multiple locations, with each location mapped to a topic.
*Thread-safe handling of concurrent client messages and topic updates.

Technologies Used:
*C language for server development.
*POSIX Threads (pthreads) for concurrency.
*Linux for compilation and execution.
*Mutexes and Semaphores for thread synchronization.

Key Features:
*Multi-client support with multiple topics.
*Efficient thread allocation and message scheduling.
*Thread-safe shared memory for inter-thread communication.
*Real-time simulation and display of sensor data per topic.
*Flexible message handling with an extensible application-level protocol.