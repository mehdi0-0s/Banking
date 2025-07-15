#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template<typename T>
class LinkedList{
private:
    Node<T> *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    ~LinkedList()
    {
        Node<T> *current = head;
        Node<T> *nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

    Node<T>* getHead(){return head;}
};

#endif // LINKEDLIST_H
