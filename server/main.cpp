/* 
 * File:   main.cpp
 * Author: ssi
 *
 * Created on 24 Сентябрь 2014 г., 16:14
 */

#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
	//cout << AF_INET;
	char buf[1024];
	char answer[] = "Hi, Client!\n";
    int bytes_read;
	int a = socket(AF_INET, SOCK_STREAM, 0);
	
	//in_addr_t myIp = 0x1fd308f4;
	
	//cout << a;

	if (a < 0)
	{
		cout << "socket";
		exit(1);
	}

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);
	addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	if (bind(a, (sockaddr *) & addr, sizeof (addr)) < 0)
	{
		cout << "bind";
		exit(2);
	}
	listen(a, 1);

	while (true)
	{
		int newSock = accept(a, NULL, NULL);
		if (newSock < 0)
		{	
			cout << "accept";
			exit(3);
		}
		
		while (true)
		{
			bytes_read = recv(newSock, buf, 1024, 0);
			if (bytes_read <= 0)
				break;
			printf(buf);
			send(newSock, answer, sizeof(answer), 0);
		}
		
		close(newSock);
		
	}

	return 0;
}

