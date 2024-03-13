/***********************************************************
  > File Name: 3.cpp
  > Author: Aklzzz
  > Mail: 2429605732@qq.com
  > Created Time: Wed 13 Mar 2024 05:27:08 PM CST
  > Modified Time:Wed 13 Mar 2024 05:27:08 PM CST
 *******************************************************/

// 线程的退出方式


#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int var = 0;

void* func1(void* arg) {
	for(int i = 0; i != 5; ++i) {
		++var;
		sleep(1);
		printf("func1 ok.(%d)\n", var);
	}
	// exit(0); // error
	pthread_exit(0);
	return static_cast<void*>(0);
}

void* func2(void* arg) {
	for(int i = 0; i != 30; ++i) {
		++var;
		sleep(1);
		printf("func2 ok.(%d)\n", var);
	}
	return static_cast<void*>(0);
}

int main(void) {
	pthread_t pth_id1(0), pth_id2(0);
	if(pthread_create(&pth_id1, nullptr, func1, nullptr) != 0) { printf("create failed.\n"); return -1; }
	if(pthread_create(&pth_id2, nullptr, func2, nullptr) != 0) { printf("create failed.\n"); return -1; }
	pthread_join(pth_id1, nullptr);
	pthread_join(pth_id2, nullptr);
	return 0;
}
