#pragma once
#include <stdexcept>

template <typename T>
struct Stack {
private: 
	T* data = nullptr;
	int capacity = 0;
	int topIndex = -1;

	void resize(int newCapacity) {
		T* newData = new T[newCapacity];
		for (int i = 0; i < topIndex; ++i) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		capacity = newCapacity;
	}

public:
	~Stack() {
		delete[] data;
	}
	void push(T elem) {
		if (topIndex + 1 >= capacity) {
			resize(capacity + 10);
		}
		data[++topIndex] = elem;
	}
	T pop() {
		if (topIndex < 0) {
			throw std::runtime_error("Stack is empty");
		}
		return data[topIndex--];
	}
	T peek(){
		if (topIndex < 0) {
			throw std::runtime_error("Stack is empty");
		}
		return data[topIndex];
	}
	int count() {
		return topIndex + 1;
	}
	void clear() {
		delete[] data;
		data = nullptr;
		topIndex = -1;
		capacity = 0;
	}
};