#include <iostream>

class CircularQueue
{
private:
    int front, rear, size;
    int *arr;

public:
    CircularQueue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            std::cout << "Queue Overflow! Cannot enqueue " << value << '\n';
        }
        else
        {
            if (isEmpty())
                front = 0;
            rear = (rear + 1) % size;
            arr[rear] = value;
            std::cout << value << " enqueued into queue." << '\n';
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue Underflow! Nothing to dequeue." << '\n';
        }
        else
        {
            std::cout << arr[front] << " dequeued from queue." << '\n';
            if (front == rear)
                front = rear = -1;
            else
                front = (front + 1) % size;
        }
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % size == front;
    }

    void peek()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty" << '\n';
        }
        else
        {
            std::cout << "Front element is: " << arr[front] << '\n';
        }
    }

    void display()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty" << '\n';
        }
        else
        {
            std::cout << "Queue elements";
            int i = front;
            while (true)
            {
                std::cout << arr[i] << " ";
                if (i == rear)
                    break;
                i = (i + 1) % size;
            }
            std::cout << '\n';
        }
    }
};
