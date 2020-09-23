
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

int port = 8052;
int f_listen_fd = 0, f_conn_fd = 0;
char recvBuff[1024];

int main()
{

	struct sockaddr_in serv_addr;
	
    f_listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    printf("%d\n", f_listen_fd);

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    int err = inet_pton(AF_INET, "127.0.0.1",  &(serv_addr.sin_addr.s_addr));
    serv_addr.sin_port = htons(port); 
    //printf("%d Connected!\n", err);

    int d = bind(f_listen_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    printf("%d\n", d); 
    printf("%d\n", errno);

    listen(f_listen_fd, 10000);
    printf("Connected!\n");

    accept(f_listen_fd, (struct sockaddr*)NULL, NULL);

    printf("Connected!\n");

    char str[] = "ROBOT_AWAKE";
    send(f_conn_fd, str, strlen(str), 0);

    //while(true)
    //{
    	//if(read(connfd_1, recvBuff, sizeof(recvBuff)))
    //}

    return 0;
}