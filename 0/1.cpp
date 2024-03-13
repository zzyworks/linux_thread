/***********************************************************
  > File Name: 1.cpp
  > Author: Aklzzz
  > Mail: 2429605732@qq.com
  > Created Time: Wed 13 Mar 2024 05:01:50 PM CST
  > Modified Time:Wed 13 Mar 2024 05:01:50 PM CST
 *******************************************************/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* func(void* arg) {
	for(int i = 0; i != 30; ++i) {
		sleep(1);
		printf("sleep 1s ok.\n");
	}
	return static_cast<void*>(0);
}

int main(void) {
	pthread_t pth_id = 0;
	if(pthread_create(&pth_id, nullptr, func, nullptr)) {
		printf("create failed.\n");
		return -1;
	}
	pthread_join(pth_id, nullptr);
}
