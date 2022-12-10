#include <stdio.h>
#include <string.h>

#define MAX 100

int top;
int stack[MAX];

void readStdin();

void initialize();
int isEmpty();
int isFull();
void push(int);
int pop();


int main(void){
    initialize();
    readStdin();
}

void readStdin(){
	char input[1028];
	char *p;
    int buf;

	scanf("%1028[^\n]", &input);

	p = strtok(input, " ");
	while(p != NULL){
        int buf_a, buf_b;
        switch(p[0]){
            case '+':
                push(pop() + pop());
                break;
            case '-':
                buf_a = pop();
                buf_b = pop();
                push(buf_b - buf_a); //なぜか pop()*-1 + pop() だと計算順序が逆になった。
                break;
            case '*':
                push(pop() * pop());
                break;
            default:
    		    sscanf(p, "%d", &buf);
                push(buf);
                break;
        }    

		p = strtok(NULL, " ");
	}

    printf("%d\n", pop());
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