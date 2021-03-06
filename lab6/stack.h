//
// Created by levermory on 10/27/20.
//

#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template<class T>
class Stack
{
    struct Node
    {
        T data;
        Node *next;
        Node(T _data, Node* top): data(_data), next(top){};
    };
    Node *top;
    short size;
public:
    Stack(): top(nullptr), size(0){};
    Stack(T data)
    {
        top = new Node(data, top);
    }
    void push(T data)
    {
        if(size == 0)
            top = new Node(data, nullptr);
        else {
            auto node = new Node(data, top);
            top = node;
        }
        size++;
    }
    T pop()
    {
        if(size){
            auto result = top->data;
            auto temp = top->next;
            delete top;
            top = temp;
            size--;
            return result;
        }
        else {
            throw "empty stack";
        }
    }
    short getsize()
    {
        return size;
    }
    void print(){
        auto node = top;
        for(int i=0; i<size; i++){
            cout<<node->data<<' ';
            node = node->next;
        }
        cout<<endl;
    }
    T gettop()
    {
        if(size)
            return top->data;
        else
            throw "empty stack";
    }
};

#endif //STACK_H
