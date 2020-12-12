#include <iostream>
#include <fstream>
#include "fraction.h"
#include "stack.h"

void ref()
{
    int n = 10;
//    cin>>n;
    auto *array = new Fraction[n];
//    for(int i=0; i<n; i++) cin>>array[i];
    for(int i=0; i<n; i++) array[i] = Fraction(rand()%10, rand()%10);
    for(int i=0; i<n; i++) cout<<array[i]<<" ";
    cout<<endl;
    change(array, n);
    for(int i=0; i<n; i++) cout<<array[i]<<" ";
}
void task()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    Stack<Fraction> stack;
    if(!fin) throw "failed to open in-file-stream";
    if(!fout) throw "failed to open out-file-stream";
    while(!fin.eof()){
        string frac;
        fin>>frac;
        stack.push(Fraction(frac));
    }
    auto node = stack.gettop();
    while(stack.getsize()){
        if(stack.getsize()%2 == 0){
            node = node + stack.gettop();
            fout<<node<<" ";
        }
        else {
            node = stack.gettop();
            fout<<node<<" ";
        }
        stack.pop();
    }
}
int main() {
//    ref();
    try {
        task();
    }
    catch (char const* error) {
        cerr<<error;
    }

    return 0;
}
