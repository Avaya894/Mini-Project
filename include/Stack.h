#pragma once
template <typename T>
class Stack
{
public:
    virtual bool push(const T element) = 0;
    virtual bool isFull() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool pop() = 0;
    virtual T top() const = 0;
};

template <typename T>
class ArrayStack : public Stack<T>
{
private:
    T *data;
    int topIndex;
    int size;

public:
    ArrayStack(int size);
    virtual bool isFull() const;
    virtual bool isEmpty() const;
    virtual bool push(const T element);
    virtual bool pop();
    virtual T top() const;
    ~ArrayStack();
};

template <typename T>
ArrayStack<T>::ArrayStack(int size)
    : size(size - 1), topIndex(-1), data(new T[size - 1]) {}

template <typename T>
bool ArrayStack<T>::isFull() const
{
    return (topIndex >= size);
}

template <typename T>
bool ArrayStack<T>::isEmpty() const
{
    return (topIndex < 0);
}
template <typename T>
bool ArrayStack<T>::push(const T element)
{
    if (!isFull())
    {
        topIndex++;
        data[topIndex] = element;

        return true;
    }
    else
    {
        std::cout << "Array is Full" << std::endl;
        return false;
    }
}
template <typename T>
bool ArrayStack<T>::pop()
{
    if (!isEmpty())
    {

        topIndex--;
        return true;
    }
    else
    {
        std::cout << "List is Empty !!!" << std::endl;
        return false;
    }
}

template <typename T>
T ArrayStack<T>::top() const
{
    if (isEmpty())
    {
        return "List is empty ";
    }
    else
    {
        return data[topIndex];
    }
}
template <typename T>
ArrayStack<T>::~ArrayStack()
{
    delete data;
}