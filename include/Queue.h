#pragma once
template <typename T>
class Queue
{
public:
    virtual bool enqueue(const T element) = 0;
    virtual bool isFull() const = 0;
    virtual bool isEmpty() const = 0;
    virtual T dequeue() = 0;
    virtual bool front() const = 0;
    virtual bool back() const = 0;
};

template <typename T>
class ArrayQueue : public Queue<T>
{
private:
    T *data;
    int top;
    int bottom;
    int size;

public:
    ArrayQueue(int size);
    virtual bool enqueue(const T element);
    virtual bool isFull() const;
    virtual bool isEmpty() const;
    virtual T dequeue();
    virtual bool front() const;
    virtual bool back() const;
    ~ArrayQueue();
};

template <typename T>
ArrayQueue<T> :: ~ArrayQueue()
{
    delete data;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(int size)
    : size(size), top(0), bottom(0), data(new T[size]) {}

template <typename T>
bool ArrayQueue<T>::isFull() const
{
    return (top == (bottom + 1) % size);
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const
{
    return (top == bottom);
}

template <typename T>
bool ArrayQueue<T>::enqueue(const T element)
{
    if (!isFull())
    {
        bottom = (bottom + 1) % size;
        data[bottom] = element;
        std::cout << "Successfully enqueued: " << data[bottom] << std::endl;
        return true;
    }
    else
    {
        std::cout << "Array is Full" << std::endl;
        return false;
    }
}
template <typename T>
T ArrayQueue<T>::dequeue()
{
    if (!isEmpty())
    {

        top = (top + 1) % size;
        return data[top];
    }
    else
    {
        std::cout << "List is Empty !!!" << std::endl;
        return false;
    }
}

template <typename T>
bool ArrayQueue<T>::front() const
{
    if (isEmpty())
    {
        std::cout << "List is empty " << std::endl;
        return false;
    }
    else
    {
        std::cout << "Front ::" << data[top + 1] << std::endl;
        return true;
    }
}

template <typename T>
bool ArrayQueue<T>::back() const
{
    if (isEmpty())
    {
        std::cout << "List is empty " << std::endl;
        return false;
    }
    else
    {
        std::cout << "Rear:: " << data[bottom] << std::endl;
        return true;
    }
}