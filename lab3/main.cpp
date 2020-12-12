//Построить класс для работы с бинарным деревом, узел которого содержит
//информацию о заявках на авиабилеты (в последовательности, используемой
//для упорядочения заявок): желаемую дату вылета, номер рейса, фамилию
//и инициалы пассажира, пункт назначения.

//Программа должна обеспечивать: хранение всех заявок в виде
//бинарного дерева, добавление заявок, удаление заявок, вывод заявок
//по заданному номеру рейса и дате вылета, вывод всех заявок.

#include "classTree.h"

using namespace std;

void test()
{
    Tree<int> tree;
    for (int i = 0; i < 5; ++i) {
        tree.push(rand() % 10);
    }
    tree.push(15);
    for (int i = 0; i < 5; ++i) {
        tree.push(rand() % 10);
    }
    tree.print();

    cout<<endl;
}

void find_ticket(Tree<plane_ticket> tree)
{
    cout<<"enter number of flight and date: ";
    int number;
    string date;
    cin>>number;
    cin>>date;
    plane_ticket test_ticket(number, date, "@", "@");
    auto curr_ticket = tree.get_root();
    if(test_ticket.flight_num == curr_ticket->get_info().flight_num && Date(test_ticket.flight_date)==Date(curr_ticket->get_info().flight_date))
        curr_ticket->print('\n');
    else if(curr_ticket->info < test_ticket)
        curr_ticket = curr_ticket->right;
}

int main() {
    Tree<plane_ticket> tree;
    for(int i=0; i<2; i++){
        plane_ticket ticket;
        tree.push(ticket);
    }
    find_ticket(tree);
//    test();
    return 0;
}




