/***********************************************************
  > File Name: 0.cpp
  > Author: Aklzzz
  > Mail: 2429605732@qq.com
  > Created Time: Wed 13 Mar 2024 05:36:53 PM CST
  > Modified Time:Wed 13 Mar 2024 05:36:53 PM CST
 *******************************************************/

// 传递的参数不可以使用全局变量

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int var = 0;

void* func1(void* arg) {
	sleep(1);
	printf("func1 ok.(%d)\n", var);
	pthread_exit(0);
}

void* func2(void* arg) {
	sleep(1);
	printf("func1 ok.(%d)\n", var);
	pthread_exit(0);
}

void* func3(void* arg) {
	sleep(1);
	printf("func1 ok.(%d)\n", var);
	pthread_exit(0);
}

void* func4(void* arg) {
	sleep(1);
	printf("func1 ok.(%d)\n", var);
	pthread_exit(0);
}

void* func5(void* arg) {
	sleep(1);
	printf("func1 ok.(%d)\n", var);
	pthread_exit(0);
}

int main(void) {
	pthread_t pth_id1(0), pth_id2(0), pth_id3(0), pth_id4(0), pth_id5(0);
	if(pthread_create(&pth_id1, nullptr, func1, nullptr) != 0) { printf("create failed.\n"); return -1; }
	++var;
	if(pthread_create(&pth_id2, nullptr, func2, nullptr) != 0) { printf("create failed.\n"); return -1; }
	++var;
	if(pthread_create(&pth_id3, nullptr, func3, nullptr) != 0) { printf("create failed.\n"); return -1; }
	++var;
	if(pthread_create(&pth_id4, nullptr, func4, nullptr) != 0) { printf("create failed.\n"); return -1; }
	++var;
	if(pthread_create(&pth_id5, nullptr, func5, nullptr) != 0) { printf("create failed.\n"); return -1; }
	++var;
	pthread_join(pth_id1, nullptr);
	pthread_join(pth_id2, nullptr);
	pthread_join(pth_id3, nullptr);
	pthread_join(pth_id4, nullptr);
	pthread_join(pth_id5, nullptr);
	return 0;
}
