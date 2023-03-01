#include <iostream>
#include <stdio.h>

#include "RingBuffer.h"

int main() {
	unsigned char arr[10];
	unsigned int buff_size = 10;
	unsigned char data;
	unsigned int i = 0;

	RingBuffer ring(arr, buff_size);

	for (i = 0; i < buff_size; i++) {
		ring.ring_buf_put(i);
	}

	for (i = 0; i < buff_size; i++) {
		ring.ring_buf_get(data);
		//std::cout << data;
		printf("%d ", data);
	}

	std::cout << std::endl << ring.ring_buf_size_remain();
}
