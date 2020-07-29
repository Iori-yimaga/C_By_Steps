//
// Created by jokermss on 2020/7/29.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//read方法需要的头文件
#include <unistd.h>
//socket方法需要用的头文件
#include <sys/socket.h>
#include <sys/types.h>
//htonl方法需要的头文件
#include <netinet/in.h>
//inet_ntop方法需要的头文件
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>

#define MAXLINE 100
#define SERV_PORT 8000
#define BACKLOGSIZE 100

int main(int agrc, char *argv[]) {
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddr_len;
    int listenfd, connfd;
    char buf[MAXLINE], first_line[MAXLINE], left_line[MAXLINE], method[MAXLINE], version[MAXLINE];
    char str[INET_ADDRSTRLEN];
    char filename[MAXLINE];
    long n;
    int i, pid;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    //初始化myaddr参数
    bzero(&servaddr, sizeof(servaddr));   //结构体清零
    //对servaddr结构体进行赋值
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    listen(listenfd, BACKLOGSIZE);

    while (1) {
        accept(listenfd, (struct sockaddr *) &cliaddr, &cliaddr_len);

    }
}