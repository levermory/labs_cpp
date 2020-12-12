//
// Created by levermory on 10/11/20.
//

#ifndef LAB3_CLASSTREE_H
#define LAB3_CLASSTREE_H


#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class T>
class Tree
{
public:
    struct Node
    {
        T info;
        Node* left;
        Node* right;

        Node() = delete;
        explicit Node(T data): info(data), left(nullptr), right(nullptr){};
        void push(T data)
        {
            if(data < this->info){
                if(this->left)
                    left->push(data);
                else
                    left = new Node(data);
            }
            else {
                if (this->right)
                    right->push(data);
                else
                    right = new Node(data);
            }
        }
        void print(char delim)
        {
            if(this){
                cout<<info<<delim;
                left->print(delim);
                right->print(delim);
            }
        }
        Node* search(T data)
        {
            if(this){
                if (info == data)
                    return this;
                else if (info < data)
                    left->search(data);
                else
                    right->search(data);
            }
            else
                cout<<"not found"; return nullptr;
        }
        T get_info()
        {
            return info;
        }
    };
    size_t size;
    Node* root;
public:
    Tree(): root(nullptr), size(0){};
    explicit Tree(T data){
        root = new Node(data);
        size++;
    };
    void push(T data)
    {
        if(root)
            root->push(data);
        else
            root = new Node(data);
        size++;
    };
    void print(char delim=' ')
    {
        root->print(delim);
    }
    Node* find(T data)
    {
        if(root->info<data)
            root->left.find(data);
    }
    Node* get_root()
    {
        return root;
    }

};

struct Date
{
    int day;
    int month;
    int year;

    Date(string date)
    {
        int pos;
        string delimeter = "./_";

        pos=date.find_first_of(delimeter);
        day=stoi(date.substr(0, pos));
        date.erase(0, pos+1);

        pos=date.find_first_of(delimeter);
        month=stoi(date.substr(0, pos));
        date.erase(0, pos+1);

        year=stoi(date);
    }
    void show_date()
    {
        cout<<day<<"."<<month<<"."<<year;
    }
    bool operator>=(Date date){
        return(day+month*30+year*365 >= date.day+date.month*30+date.year*365);
    }
    bool operator<=(Date date){
        return(day+month*30+year*365 <= date.day+date.month*30+date.year*365);
    }
    bool operator<(Date date){
        return(day+month*30+year*365 < date.day+date.month*30+date.year*365);
    }
    bool operator>(Date date){
        return(day+month*30+year*365 > date.day+date.month*30+date.year*365);
    }
    bool operator==(Date date){
        return(day+month*30+year*365 == date.day+date.month*30+date.year*365);
    }
    bool operator!=(Date date){
        return(day+month*30+year*365 != date.day+date.month*30+date.year*365);
    }

};

struct plane_ticket
{
    string flight_date;
    int flight_num;
    string passenger_name;
    string destination;

    plane_ticket(int num, string date, string name, string dest) :
    flight_num(num), flight_date(date), passenger_name(name), destination(dest){};

    plane_ticket()
    {
        cout<<"enter flight num: ";
        cin>>flight_num;
        cout<<"enter date: ";
        cin>>flight_date;
        cout<<"enter passenger name: ";
        cin>>passenger_name;
        cout<<"enter destination: ";
        cin>>destination;
    }

    bool operator>=(plane_ticket ticket){
        if(Date(flight_date) >= Date(ticket.flight_date))
            return true;
        else if(destination>=ticket.destination)
            return true;
        else if (passenger_name >= ticket.passenger_name)
            return true;
        else
            return false;
    }
    bool operator<=(plane_ticket ticket){
        if(Date(flight_date) <= Date(ticket.flight_date))
            return true;
        else if(destination<=ticket.destination)
            return true;
        else if (passenger_name <= ticket.passenger_name)
            return true;
        else
            return false;
    }
    bool operator<(plane_ticket ticket){
        if(Date(flight_date) < Date(ticket.flight_date))
            return true;
        else if(destination<ticket.destination)
            return true;
        else if (passenger_name < ticket.passenger_name)
            return true;
        else
            return false;
    }
    bool operator>(plane_ticket ticket){
        if(Date(flight_date) > Date(ticket.flight_date))
            return true;
        else if(destination>ticket.destination)
            return true;
        else if (passenger_name > ticket.passenger_name)
            return true;
        else
            return false;
    }
    bool operator==(plane_ticket ticket){
        if(Date(flight_date) == Date(ticket.flight_date))
            return true;
        else if(destination==ticket.destination)
            return true;
        else if (passenger_name == ticket.passenger_name)
            return true;
        else
            return false;
    }
    bool operator!=(plane_ticket ticket){
        if(Date(flight_date) != Date(ticket.flight_date))
            return true;
        else if(destination!=ticket.destination)
            return true;
        else if (passenger_name != ticket.passenger_name)
            return true;
        else
            return false;
    }

//    plane_ticket operator=(plane_ticket ticket){
//        flight_date = ticket.flight_date;
//        flight_num = ticket.flight_num;
//        passenger_name = ticket.passenger_name;
//        destination = ticket.destination;
//        return *this;
//    }

    void show()
    {
        cout<<"num:  "<<flight_num<<endl;
        cout<<"date: "; Date(flight_date).show_date(); cout<<endl;
        cout<<"dest: "<<destination<<endl;
        cout<<"name: "<<passenger_name<<endl;
    }

    friend ostream& operator <<(ostream&, plane_ticket);

    
};

ostream& operator <<(ostream& out, plane_ticket ticket) {
    ticket.show();
    return out;
}


#endif //LAB3_CLASSTREE_H
