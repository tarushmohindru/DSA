#include <iostream>

class queue
{
private:
    int front, rear, size;
    int *arr;

public:
    queue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    ~queue()
    {
        delete[] arr;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            std::cout << "Queue is full" << value << '\n';
        }
        else
        {
            if (front == -1)
                front = 0;
            rear++;
            arr[rear] = value;
            std::cout << value << " enqueued into queue." << '\n';
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty" << '\n';
        }
        else
        {
            std::cout << arr[front] << " dequeued from queue." << '\n';
            front++;
            if (front > rear)
                front = rear = -1;
        }
    }

    bool isEmpty()
    {
        return front == -1 || front > rear;
    }

    bool isFull()
    {
        return rear == size - 1;
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
            std::cout << "Queue is empty." << '\n';
        }
        else
        {
            std::cout << "Queue elements (front to rear): ";
            for (int i = front; i <= rear; i++)
            {
                std::cout << arr[i] << " ";
            }
            std::cout << '\n';
        }
    }
};

int main()
{
    int size;
    std::cout << "Enter size of queue: ";
    std::cin >> size;
    queue q(size);
    int choice, value;
    do
    {
        std::cout << "\n--- Queue Menu ---" << '\n';
        std::cout << "1. Enqueue" << '\n';
        std::cout << "2. Dequeue" << '\n';
        std::cout << "3. Peek" << '\n';
        std::cout << "4. Display" << '\n';
        std::cout << "5. Check if Empty" << '\n';
        std::cout << "6. Check if Full" << '\n';
        std::cout << "7. Exit" << '\n';
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter value to enqueue: ";
            std::cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            if (q.isEmpty())
                std::cout << "Queue is empty." << '\n';
            else
                std::cout << "Queue is not empty." << '\n';
            break;
        case 6:
            if (q.isFull())
                std::cout << "Queue is full." << '\n';
            else
                std::cout << "Queue is not full." << '\n';
            break;
        case 7:
            std::cout << "Exiting program." << '\n';
            break;
        default:
            std::cout << "Invalid choice! Please try again." << '\n';
        }
    } while (choice != 7);
}