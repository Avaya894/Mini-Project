#pragma once

class Stack
{
public:
    virtual bool push(const std::string element) = 0;
    virtual bool isFull() const = 0;
    virtual bool isEmpty() const = 0;
    virtual std::string pop() = 0;
    virtual std::string top() const = 0;
};

class ArrayStack : public Stack
{
private:
    std::string *data;
    int topIndex;
    int size;

public:
    ArrayStack(int size);
    virtual bool isFull() const;
    virtual bool isEmpty() const;
    virtual bool push(const std::string element);
    virtual std::string pop();
    virtual std::string top() const;
    ~ArrayStack();
};

ArrayStack::ArrayStack(int size)
    : size(size - 1), topIndex(-1), data(new std::string[size - 1]) {}

bool ArrayStack::isFull() const
{
    return (topIndex >= size);
}

bool ArrayStack::isEmpty() const
{
    return (topIndex < 0);
}

bool ArrayStack::push(const std::string element)
{
    if (!isFull())
    {
        topIndex++;
        data[topIndex] = element;
        std::cout << "Pushed:" << element << std::endl;

        return true;
    }
    else
    {
        std::cout << "Array is Full" << std::endl;
        return false;
    }
}

std::string ArrayStack::pop()
{
    if (!isEmpty())
    {
        return  data[topIndex--];

    }
    else
    {
       throw "List is Empty !!!";
        
    }
}

std::string ArrayStack::top() const
{
    if (isEmpty())
    {
        throw "List is empty ";
    }
    else
    {
        return data[topIndex];
    }
}

ArrayStack::~ArrayStack()
{
    delete data;
}