#ifndef NODE_H
#define NODE_H


template<typename T>
class Node{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

#endif // NODE_H
