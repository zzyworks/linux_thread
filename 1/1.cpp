/***********************************************************
  > File Name: 1.cpp
  > Author: Aklzzz
  > Mail: 2429605732@qq.com
  > Created Time: Wed 13 Mar 2024 05:49:11 PM CST
  > Modified Time:Wed 13 Mar 2024 05:49:11 PM CST
 *******************************************************/

// 线程使用传递参数

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void* func1(void* arg) {
	sleep(1);
	printf("func1 ok.(%d)\n", (int)(long)arg);
	pthread_exit(0);
}

void* func2(void* arg) {
	sleep(1);
	printf("func1 ok.(%d)\n", (int)(long)arg);
	pthread_exit(0);
}

void* func3(void* arg) {
	sleep(1);
	printf("func1 ok.(%d)\n", (int)(long)arg);
	pthread_exit(0);
}

void* func4(void* arg) {
	sleep(1);
	printf("func1 ok.(%d)\n", (int)(long)arg);
	pthread_exit(0);
}

void* func5(void* arg) {
	sleep(1);
	printf("func1 ok.(%d)\n", (int)(long)arg);
	pthread_exit(0);
}

int main(void) {
	pthread_t pth_id1(0), pth_id2(0), pth_id3(0), pth_id4(0), pth_id5(0);
	int val = 0;
	if(pthread_create(&pth_id1, nullptr, func1, (void*)(long)val) != 0) { printf("create failed.\n"); return -1; }
	++val;
	if(pthread_create(&pth_id2, nullptr, func2, (void*)(long)val) != 0) { printf("create failed.\n"); return -1; }
	++val;
	if(pthread_create(&pth_id3, nullptr, func3, (void*)(long)val) != 0) { printf("create failed.\n"); return -1; }
	++val;
	if(pthread_create(&pth_id4, nullptr, func4, (void*)(long)val) != 0) { printf("create failed.\n"); return -1; }
	++val;
	if(pthread_create(&pth_id5, nullptr, func5, (void*)(long)val) != 0) { printf("create failed.\n"); return -1; }
	++val;
	pthread_join(pth_id1, nullptr);
	pthread_join(pth_id2, nullptr);
	pthread_join(pth_id3, nullptr);
	pthread_join(pth_id4, nullptr);
	pthread_join(pth_id5, nullptr);
	return 0;
}
