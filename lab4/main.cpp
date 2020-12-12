#include "stack.h"

void task1()
{

    Stack<double> stack1;
    Stack<double> stack2;
    Stack<double> stack3;
    // for(int i=0; i<3; i++){
    //     double a;
    //     cin>>a;
    //     stack1.push(a);
    //     cin>>a;
    //     stack2.push(a);
    // }

    for(int i=0; i<4; i++){
        stack1.push(i);
        stack2.push(i+1);
    }

    stack1.print();
    stack2.print();
    auto a = stack1.gettop();
    auto b = stack2.gettop();
    while(stack1.getsize() && stack2.getsize()){
        if(a>=b) {
            stack3.push(stack1.pop());
            a = stack1.gettop();
        }
        else {
            stack3.push(stack2.pop());
            b = stack2.gettop();
        }
    }

    while(stack1.getsize()){
        stack3.push(stack1.pop());
    }
    while(stack2.getsize()){
        stack3.push(stack2.pop());
    }

    cout<<endl;
    stack3.print();
}
void task4()
{
    Stack<char> stack1;
    Stack<char> stack2;
    Stack<char> stack3;
    string input = "template<class T>class Stack{ struct Node { T data; Node *next; Node(T _data, Node* top): data(_data), next(top){}; }; Node *top; short size;public: Stack(): top(nullptr), size(0){}; Stack(T data) { top = new Node(data, top); } void push(T data) { if(size == 0) top = new Node(data, nullptr); else { auto node = new Node(data, top); top = node; } size++; } T pop() { if(size){ auto result = top->data; auto temp = top->next; delete top; top = temp; size--; return result; } else { cout << ; } } short getsize() { return size; } void print(){ auto node = top; for(int i=0; i<size; i++){ cout<<node->data<<; node = node->next; } cout<<endl; } T gettop() { if(size) return top->data; }};";
    for(char i: input){
        switch (i) {
            case '{': stack1.push(i); break;
            case '[': stack2.push(i); break;
            case '(': stack3.push(i); break;
            case '}': stack1.pop(); break;
            case ']': stack2.pop(); break;
            case ')': stack3.pop(); break;
        }
    }

    if(stack1.getsize()==0 && stack2.getsize()==0 && stack3.getsize()==0)
        cout<<"correct\n";
    else
        cout<<"there's an error\n";
}

int main() {
//    task1();
    task4();
    return 0;
}
