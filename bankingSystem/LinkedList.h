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

    void insertAtEnd(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if(head == nullptr)
        {
            head = newNode;
            return;
        }
        Node<T> *temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    Node<T>* getHead(){return head;}
};

#endif // LINKEDLIST_H
