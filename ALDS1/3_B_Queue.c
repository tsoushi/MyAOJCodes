#include <stdio.h>

#define QUEUE_MAX 100000

typedef struct {
    char name[11];
    int time;
} Proc;

int head;
int tail;
Proc queue[QUEUE_MAX];

void initialize();
void enqueue(Proc);
Proc dequeue();
int isEmpty();
int isFull();

int main() {
    int length, quantum;
    int currentTime = 0;

    scanf("%d %d", &length, &quantum);
    for (int i = 0; i < length; i++) {
        Proc proc;
        scanf("%s %d", proc.name, &proc.time);
        enqueue(proc);
    }


    while (!isEmpty()) {
        Proc proc = dequeue();
        currentTime += quantum;

        proc.time -= quantum;
        if (proc.time <= 0) {
            currentTime += proc.time;
            printf("%s %d\n", proc.name, currentTime);
        } else {
            enqueue(proc);
        }
    }

    return 0;
}



void initialize() {
    head = tail = 0;
}

void enqueue(Proc proc) {
    queue[tail] = proc;
    tail = (tail + 1) % QUEUE_MAX;
}

Proc dequeue() {
    Proc proc = queue[head];
    head = (head + 1) % QUEUE_MAX;
    return proc;
}

int isEmpty() {
    return head == tail;
}