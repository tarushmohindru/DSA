#include <iostream>
#include <queue>
using std::queue;

class interleaveQueue
{
private:
    queue<int> q;
    int size;

public:
    interleaveQueue(int s) : size(s) {}

    void enqueue(int value)
    {
        if (q.size() < size)
        {
            q.push(value);
            std::cout << value << " enqueued into queue." << '\n';
        }
        else
        {
            std::cout << "Queue is full" << value << '\n';
        }
    }

    void display()
    {
        if (q.empty())
        {
            std::cout << "Queue is empty" << '\n';
            return;
        }

        queue<int> temp = q;
        std::cout << "Queue elements: ";
        while (!temp.empty())
        {
            std::cout << temp.front() << " ";
            temp.pop();
        }
        std::cout << '\n';
    }

    void interleave()
    {
        if (q.size() % 2 != 0)
        {
            std::cout << "Queue size must be even" << '\n';
            return;
        }

        queue<int> firstHalf, secondHalf;
        int halfSize = q.size() / 2;

        for (int i = 0; i < halfSize; i++)
        {
            firstHalf.push(q.front());
            q.pop();
        }
        while (!q.empty())
        {
            secondHalf.push(q.front());
            q.pop();
        }

        while (!firstHalf.empty() && !secondHalf.empty())
        {
            q.push(firstHalf.front());
            firstHalf.pop();
            q.push(secondHalf.front());
            secondHalf.pop();
        }

        std::cout << "Queue interleaved successfully" << '\n';
    }
};

int main()
{
    int size;
    std::cout << "Enter size of queue: ";
    std::cin >> size;
    if (size % 2 != 0)
    {
        std::cout << "Size must be even" << '\n';
        return 1;
    }

    interleaveQueue iq(size);
    int choice, value;
    do
    {
        std::cout << "\n--- Queue Menu ---" << '\n';
        std::cout << "1. Enqueue" << '\n';
        std::cout << "2. Display" << '\n';
        std::cout << "3. Interleave" << '\n';
        std::cout << "4. Exit" << '\n';
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter value to enqueue: ";
            std::cin >> value;
            iq.enqueue(value);
            break;
        case 2:
            iq.display();
            break;
        case 3:
            iq.interleave();
            break;
        case 4:
            std::cout << "Exiting program." << '\n';
            break;
        default:
            std::cout << "Invalid choice. Please try again." << '\n';
        }
    } while (choice != 4);

    return 0;
}