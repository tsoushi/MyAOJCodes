#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

class PriorityQueue {
private:
    vector<int> heap{1};

    int size() {
        return heap.size() - 1;
    }

    static int parent(int i) {
        return i / 2;
    }

    void maxHeapify(int root) {
        int leftIndex = root * 2;
        int rightIndex = root * 2 + 1;
        int largestIndex;

        if (leftIndex <= size() && heap[leftIndex] > heap[root]) largestIndex = leftIndex;
        else largestIndex = root;
        if (rightIndex <= size() && heap[rightIndex] > heap[largestIndex]) largestIndex = rightIndex;

        if (largestIndex != root) {
            // swap
            int buf = heap[root];
            heap[root] = heap[largestIndex];
            heap[largestIndex] = buf;
            maxHeapify(largestIndex);
        }
    }

public:
    void insert(int key) {
        heap.push_back(key);

        int index = heap.size() - 1;
        while (index > 1 && heap[parent(index)] < heap[index]) {
            // swap
            int buf = heap[index];
            heap[index] = heap[parent(index)];
            heap[parent(index)] = buf;
            
            index = parent(index);
        }
    }

    int extractMax() {
        int maxKey = heap[1];
        heap[1] = heap.back();
        heap.pop_back();
        maxHeapify(1);

        return maxKey;
    }
};

int main() {
    PriorityQueue queue;

    while (true) {
        string command;
        cin >> command;
        if (command == "insert") {
            int key;
            cin >> key;
            queue.insert(key);
        } else if (command == "extract") {
            cout << queue.extractMax() << endl;
        } else {
            break;
        }
    }

    return 0;
}
