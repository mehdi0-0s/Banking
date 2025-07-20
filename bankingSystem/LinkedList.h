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
            delete current->data;
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

    bool deleteNode(T data)
    {
        Node<T>* current = head;
        Node<T>* previous = nullptr;

        while (current != nullptr && !(*(current->data) == *data))
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            return false;
        }

        if (previous == nullptr)
        {
            head = current->next;
        }
        else
        {
            previous->next = current->next;
        }
        delete current->data;
        delete current;
        return true;
    }

    Node<T>* findNode(T data)
    {
        Node<T>* current = head;

        while(current != nullptr)
        {
            if(*(current->data) == *data)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    Node<T>* getHead(){return head;}

    int size()
    {
        int count = 0;
        Node<T>* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

#endif // LINKEDLIST_H
