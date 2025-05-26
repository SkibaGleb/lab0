#pragma once
#include <stdexcept>

using namespace std;

template <typename T>
struct Queue 
{
private:
    T* data = nullptr;
    int capacity = 0;
    int topIndex = -1;

    void resize(int newCapacity) 
    {
        T* newData = new T[newCapacity];
        for (int i = 0; i < topIndex; ++i) 
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    void extraction() 
    {
        T* newData = new T[capacity];
        for (int i = 0; i < capacity; ++i) 
        {
            newData[i] = data[i + 1];
        }
        delete[] data;
        data = newData;
        topIndex--;
    }

    int count_negative() 
    {
        int v{};
        for (int i = 0; i <= topIndex; ++i) 
        {
            if (data[i] < 0) 
            {
                v++;
            }
        }
        return v;
    }

public:
    ~Queue() 
    {
        clear();
    };

    void queue(T elem) 
    {
        if (topIndex + 1 >= capacity) 
        {
            resize(capacity + 10);
        }
        data[++topIndex] = elem;
    }

    T unqueue() 
    {
        T v = data[0];
        if (topIndex < 0) 
        {
            throw std::runtime_error("Stack is empty");
        }
        extraction();
        return v;
    }

    int count() 
    {
        return topIndex + 1;
    }

    void clear() 
    {
        delete[] data;
        data = nullptr;
        topIndex = -1;
        capacity = 0;
    }

    void add1() 
    {
        int v = count_negative();
        topIndex = topIndex + v;
        capacity = capacity + v + 1;
        T* newData = new T[capacity];
        int n = 0;
        for (int i{}; i < topIndex; i++) 
        {
            if (data[i] >= 0) 
            {
                newData[n] = data[i];
                n++;
            }
            else 
            {
                newData[n] = 1;
                n++;
                newData[n] = data[i];
                n++;
            }
        }
        delete[] data;
        data = newData;
    }

    void remove_negative() 
    {
        int v = count_negative();
        T* newData = new T[capacity + 1];
        int n = 0;
        for (int i{}; i <= topIndex; i++) 
        {
            if (data[i] >= 0) 
            {
                newData[n] = data[i];
                n++;
            }
        }
        delete[] data;
        data = newData;
        topIndex = topIndex - v;
    }

    int countof(T elem)
    {
        int v{};
        for (int i = 0; i <= topIndex; ++i) 
        {
            if (data[i] == elem) 
            {
                v++;
            }
        }
        return v;
    }
};