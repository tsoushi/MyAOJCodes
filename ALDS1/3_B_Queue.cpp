#include <iostream>
#include <stdlib.h>
#include <string>

template<class Element>
class Queue {
private:
    Element *data;
    const int size;
    int head;
    int tail;
public:
    Queue(int size) : size(size), head(0), tail(0) {
        data = new Element[size];
    }
    ~Queue() {
        delete[] data;
    }

    void enqueue(Element element) {
        if (isFull()) throw "Overflow";
        data[tail] = element;
        tail = (tail + 1) % size;
    }

    Element dequeue() {
        if (isEmpty()) throw "Underflow";
        Element elem = data[head];
        head = (head + 1) % size;
        return elem;
    }

    bool isFull() {
        return head == (tail + 1) % size;
    }

    bool isEmpty() {
        return head == tail;
    }
};

typedef struct {
    std::string name;
    int time;
} Proc;

int main() {
    int length, quantum;
    int currentTime = 0;
    Queue<Proc> queue(100000);

    std::cin >> length >> quantum;
    for (int i = 0; i < length; i++) {
        Proc proc;
        std::cin >> proc.name >> proc.time;
        queue.enqueue(proc);
    }

    while (!queue.isEmpty()) {
        Proc proc = queue.dequeue();
        currentTime += quantum;

        proc.time -= quantum;
        if (proc.time <= 0) {
            currentTime += proc.time;
            std::cout << proc.name << " " << currentTime << std::endl;
        } else {
            queue.enqueue(proc);
        }
    }

    return 0;
}