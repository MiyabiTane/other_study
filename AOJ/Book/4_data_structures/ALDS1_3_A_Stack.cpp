#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
int top=-1;
int stack[10000];

void push(int x){
    top += 1;
    stack[top] = x;
}

int pop(){
    int num;
    num = stack[top];
    top -= 1;
    //cout << num << endl;
    return num;
}

bool isEmpty(){
    if (top==-1) return true;
    return false;
}

void traceStack(){
    int i;
    if (top>=0){
        for (i=0; i<=top; i++){
            if (i==top) printf("%d\n", stack[i]);
            else printf("%d ", stack[i]);
        }
    }
}

int main(){
    int a, b;
    char s[100];
    while (scanf("%s", s)){
        //traceStack();
        if (isdigit(s[0])) push(atoi(s));
        else{
            b = pop(); a = pop();
            if (s[0] == '+') push(a+b);
            else if (s[0] == '-') push(a-b);
            else if (s[0] == '*') push(a*b);
            else if (s[0] == '/') push(a/b);
        }
        if (getchar() == '\n'){
            cout << pop() << endl;
            return 0;
        }
    }
}