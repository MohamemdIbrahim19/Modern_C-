#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

// Ring buffer Class buffering a data stream
class RingBuffer {
private:
	uint8_t *buffer;
	uint8_t counter = 0;
	size_t head = 0;
	size_t tail = 0;
	size_t max;
	bool full_buff = false;

public:

	explicit RingBuffer() = default;

	RingBuffer(uint8_t *buffer, size_t size);

	void ring_buf_put(uint8_t data);

	int ring_buf_get(uint8_t &data);

	bool ring_buf_empty();

	bool ring_buf_full();

	size_t ring_buf_capacity();

	size_t ring_buf_size_remain();

	~RingBuffer();

};

#endif /* RINGBUFFER_H_ */
