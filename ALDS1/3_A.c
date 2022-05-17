#include <stdio.h>
#include <string.h>

#define MAX 100

int top;
int stack[MAX];


void initialize();
int isEmpty();
int isFull();
void push(int);
int pop();

int main(void){
    
}

void initialize(){
    top = 0;
}

int isEmpty(){
    return top == 0;
}

int isFull(){
    return top >= MAX;
}

void push(int n){
    if (isFull()){
        printf("overflow error");
        return;
    }
    stack[top++] = n;
}

int pop(){
    if (isEmpty()){
        printf("empty error");
        return 1;
    }
    return stack[--top];
}