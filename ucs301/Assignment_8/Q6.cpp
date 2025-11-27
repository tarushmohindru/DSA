#include <iostream>
#include <vector>

class PriorityQueue
{
    std::vector<int> heap;
    bool minHeap;

    bool compare(int child, int parent) const
    {
        return minHeap ? (child < parent) : (child > parent);
    }

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (compare(heap[index], heap[parent]))
            {
                std::swap(heap[index], heap[parent]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    void heapifyDown(int index)
    {
        int n = heap.size();
        while (true)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int target = index;

            if (left < n && compare(heap[left], heap[target]))
            {
                target = left;
            }
            if (right < n && compare(heap[right], heap[target]))
            {
                target = right;
            }
            if (target == index)
            {
                break;
            }
            std::swap(heap[index], heap[target]);
            index = target;
        }
    }

public:
    explicit PriorityQueue(bool isMinHeap = false) : minHeap(isMinHeap) {}

    void insert(int value)
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    bool isEmpty() const
    {
        return heap.empty();
    }

    int peek() const
    {
        if (heap.empty())
        {
            throw std::runtime_error("Queue is empty");
        }
        return heap.front();
    }

    int extract()
    {
        if (heap.empty())
        {
            throw std::runtime_error("Queue is empty");
        }
        int root = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
        {
            heapifyDown(0);
        }
        return root;
    }
};

void processQueue(bool useMinHeap)
{
    PriorityQueue pq(useMinHeap);
    std::cout << (useMinHeap ? "Min" : "Max") << "-priority queue: inserting 5, 1, 9, 3\n";
    pq.insert(5);
    pq.insert(1);
    pq.insert(9);
    pq.insert(3);

    std::cout << "Extracting elements: ";
    while (!pq.isEmpty())
    {
        std::cout << pq.extract() << " ";
    }
    std::cout << '\n';
}

int main()
{
    processQueue(true);
    processQueue(false);
    return 0;
}
