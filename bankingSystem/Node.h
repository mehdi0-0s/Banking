#ifndef NODE_H
#define NODE_H


template<typename T>
class Node{
private:
    T data;
    Node<T> *next;

public:
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

#endif // NODE_H
