#include<iostream>

struct linked_list{
    linked_list* next;
    double value;
};

void append(linked_list* first, linked_list* last){
    linked_list* iterator = first;
    while(iterator->next != NULL){
        iterator = iterator->next;
    }
    iterator->next = last;
}

void print(linked_list* const l){
    linked_list* iterator = l;
    while(iterator){
        std::cout<<iterator->value<<' ';
        iterator = iterator->next;
    }
    std::cout<<std::endl;
}

int main(){
    linked_list* l1;
    linked_list* l2;

    l1 = new linked_list;
    l1->value = 0;
    l1->next = NULL;

    l2 = new linked_list;
    l2->value = 10;
    l2->next = new linked_list;
    l2->next->value = 15;
    l2->next->next = NULL;

    append(l1, l2);

    print(l1);

    delete l1;
    delete l2->next;
    delete l2;
}