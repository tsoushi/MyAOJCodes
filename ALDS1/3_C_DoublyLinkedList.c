#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *prev;
    struct node *next;
} Node;

Node *nil;

void initialize() {
    nil = (Node*)malloc(sizeof(Node));
    nil->prev = nil;
    nil->next = nil;
}

void printList() {
    Node *cur = nil->next;

    while (1) {
        if (cur == nil) break;
        if (cur->prev != nil) printf(" ");
        printf("%d", cur->key);
        cur = cur->next;
    }
    printf("\n");
}

void deleteNode(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;

    free(node);
}

void deleteFirst() {
    if (nil->next != nil) deleteNode(nil->next);
}

void deleteLast() {
    if (nil->prev != nil) deleteNode(nil->prev);
}

void deleteByKey(int key) {
    for (Node *p = nil->next; p != nil; p = p->next) {
        if (p->key == key) {
            deleteNode(p);
            break;
        }
    }
}

void insert(int key) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->key = key;
    
    node->prev = nil;
    node->next = nil->next;
    nil->next->prev = node;
    nil->next = node;
}


int main() {
    int num;

    initialize();

    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        int key;
        char command[20];
        
        scanf("%s %d", command, &key);
        if (command[0] == 'i') insert(key);
        else if(command[0] == 'd') {
            if (command[6] == '\0') deleteByKey(key);
            else if (command[6] == 'F') deleteFirst();
            else if(command[6] == 'L') deleteLast();
        }
    }

    printList();

    return 0;
}