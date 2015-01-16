/* 
 * File:   main.cpp
 * Author: ssi
 *
 * Created on 25 Сентябрь 2014 г., 12:44
 */

#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>



using namespace std;

int main(int argc, char** argv)
{

//	int bytes_read;
//	int a = socket(AF_INET, SOCK_STREAM, 0);
//	char message[] = "POST http://31.211.8.244/index.php HTTP/1.1\r\nHost: 31.211.8.244\r\nContent-Type: application/x-www-form-urlencoded; charset=utf-8\r\nContent-length:22\r\n\r\nuser=user&message=hi!";
//	char message[] = "POST http://31.211.8.244/index.php HTTP/1.1\r\nHost: 31.211.8.244\r\nContent-Type: application/x-www-form-urlencoded; charset=utf-8\r\nContent-length:22\r\n\r\nuser=user&message=hi!";
	//char message[] = "POST http://31.211.8.244\r\nHost: 31.211.8.244\r\nuser=user&message=hi!";

//	printf("%s", message);
//	printf("\n");
//	in_addr_t myIp = 0x1fd308f4;
//	//in_addr_t myIp = 0xc0a8083f;
//	char buf[1024] = {0};
//	if (a < 0)
//	{
//		cout << "socket";
//		exit(1);
//	}
//	//
//	struct sockaddr_in addr;
//	addr.sin_family = AF_INET;
//	addr.sin_port = htons(80);
//	addr.sin_addr.s_addr = htonl(myIp);
//	addr.sin_addr.s_addr = inet_addr("31.211.8.244");
//	//
//	while (true)
//	{
//		if (connect(a, (sockaddr*) & addr, sizeof (addr)) < 0)
//		{
//			cout << "connect";
//			exit(2);
//		}
//		send(a, message, sizeof (message), 0);
//		recv(a, buf, sizeof (buf), 0);
//
//		printf(buf);
//	}
	
	int *p = new int(0);
	
	cout << p << endl << p + 1 << endl;
	
	int size = static_cast<int> (p);
	
	cout << size << endl;
	
	return 0;
}

