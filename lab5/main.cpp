// 16. Расширить возможности класса Stack,
// чтобы можно было выводить время последнего
// сеанса работы со стеком.

#include <iostream>
#include "timestack.h"

int main() {
    Stack<int> stack1;
    TimeStack<int> stack2;
    for (int i=0; i<7; i++){
        stack1.push(i);
        stack2.push(i);
    }
    cout<<stack1.gettop()<<endl
        <<stack1.getsize()<<endl;
    cout<<stack2.gettop()<<endl
        <<stack2.getsize()<<endl;
    stack2.getlog();

    return 0;
}
