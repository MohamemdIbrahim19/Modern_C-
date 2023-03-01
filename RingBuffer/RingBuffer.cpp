#include <iostream>

#include "RingBuffer.h"

RingBuffer::RingBuffer(uint8_t *buffer, size_t size) :
		buffer(buffer), max(size) {
}

void RingBuffer::ring_buf_put(uint8_t data) {
	if (this->counter == (this->max)) {
		this->head = ((this->head) % (this->max));
		this->counter = this->head;
	}
	this->buffer[this->head] = data;
	this->head++;
	this->counter++;
}

int RingBuffer::ring_buf_get(uint8_t &data) {
	int state = 0;
	if (!ring_buf_empty()) {
		state = 1;
		data = this->buffer[this->tail];
		this->tail = ((this->tail + 1) % (this->max));
		this->full_buff = (this->head == this->tail);
	}
	return state;
}
bool RingBuffer::ring_buf_empty() {
	return ((this->head == this->tail) && !ring_buf_full());
}

bool RingBuffer::ring_buf_full() {
		return this->full_buff;
}

size_t RingBuffer::ring_buf_capacity() {
	return this->max;
}

size_t RingBuffer::ring_buf_size_remain() {
	size_t buff_size = 0;
	if (!ring_buf_full()) {
		if (this->head > this->tail) {
			buff_size = this->head - this->tail;
		} else {
			buff_size = this->max + this->head - this->tail;
		}
	}
	return buff_size;
}
RingBuffer::~RingBuffer() {

}
