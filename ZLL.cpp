#include <iostream>
#include "Zany.h"
using namespace std;
// template class ZLL<string>;
// template class ZLL<int>;

template <typename T>
ZLL<T>::ZLL()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->tracker = nullptr;
}
template <typename T>
ZLL<T>::~ZLL()
{
    Node<T> *curr = this->head;
    while (curr != nullptr)
    {
        Node<T> *temp = curr->next;
        delete curr;
        curr = temp;
    }
    head = nullptr;
    tail = nullptr;
    cout << "testing" << endl;
}
template <typename T>
bool ZLL<T>::front(const T &dataToAdd)
{
    Node<T> *toAdd = new Node<T>();
    toAdd->data = dataToAdd;
    if (this->head == nullptr)
    {
        this->head = toAdd;
        this->tail = toAdd;
        return true;
    }
    else
    {
        toAdd->next = this->head;
        this->head->prev = toAdd;
        this->head = toAdd;
        return true;
    }
    return false;
}
template <typename T>
bool ZLL<T>::back(const T &dataToAdd)
{
    Node<T> *toAdd = new Node<T>();
    toAdd->data = dataToAdd;
    if (this->tail == nullptr)
    {
        this->head = toAdd;
        this->tail = toAdd;
        return true;
    }
    else
    {
        toAdd->prev = this->tail;
        this->tail->next = toAdd;
        this->tail = toAdd;
        return true;
    }
    return false;
}
template <typename T>
bool ZLL<T>::join(ZLL &other)
{
    if (this == &other)
    {
        return true;
    }
    else if (this->head == nullptr)
    {
        this->head = other.head;
        this->tail = other.tail;
    }
    else if (other.head != nullptr)
    {
        this->tail->next = other.head;
        other.head->prev = this->tail;
        this->tail = other.tail;
    }
    other.head = nullptr;
    other.tail = nullptr;
    return true;
}
template <typename T>
ZLL<T> &ZLL<T>::operator+=(const ZLL<T> &other)
{
    Node<T> *currentNode = other.head;
    if (this == &other)
    {
        return *this;
    }
    else
    {
        while (currentNode != nullptr)
        {
            back(currentNode->data);
            currentNode = currentNode->next;
        }
    }
    return *this;
}

template <typename T>
ZLL<T> &ZLL<T>::operator-=(const ZLL<T> &other)
{
    if (this == &other)
    {
        return *this;
    }
    Node<T> *currentNodeO = other.head;
    while (currentNodeO != nullptr)
    {
        Node<T> *currentNodeT = this->head;
        while (currentNodeT != nullptr)
        {
            if (currentNodeT->data == currentNodeO->data)
            {
                Node<T> *nodeToDelete = currentNodeT;
                currentNodeT = currentNodeT->next;
                remove(nodeToDelete);
            }
            else
            {
                currentNodeT = currentNodeT->next;
            }
        }
        currentNodeO = currentNodeO->next;
    }
    return *this;
}

template <typename T>
int ZLL<T>::removeZany()
{
    int ZanyCount = 0;
    Node<T> *targetNode = this->head;
    while (targetNode != nullptr)
    {
        if (isZany(targetNode->data))
        {
            remove(targetNode);
            ZanyCount++;
        }
        targetNode = targetNode->next;
    }
    return ZanyCount;
}

template <typename T>
int ZLL<T>::removeNonZany()
{
    int nonZanyCount = 0;
    Node<T> *targetNode = this->head;
    while (targetNode != nullptr)
    {
        if (!isZany(targetNode->data))
        {
            remove(targetNode);
            nonZanyCount++;
        }
        targetNode = targetNode->next;
    }
    return nonZanyCount;
}
template <typename T>
bool ZLL<T>::promoteZany()
{
    Node<T> *next = nullptr;
    Node<T> *targetNode = this->head;
    while (targetNode != nullptr)
    {
        Node<T> *next = targetNode->next;
        if (isZany(targetNode->data))
        {
            Node<T> *tempNode = targetNode;
            targetNode = targetNode->next;
            tempNode->prev->next = tempNode->next->prev;
            tempNode->next->prev = tempNode->prev->next;
            front(tempNode->data);
            remove(tempNode);
        }
        else
        {
            targetNode = targetNode->next;
        }
    }
    return true;
}
template <typename T>
bool ZLL<T>::start()
{
    tracker = this->head;
    if (tracker != nullptr)
    {
        return true;
    }
    return false;
}
template <typename T>
bool ZLL<T>::done()
{
    if (tracker == nullptr)
    {
        delete tracker; //???
        return true;
    }
    return false;
}
template <typename T>
T ZLL<T>::getNext()
{
    T val;
    if (tracker != nullptr)
    {
        val = tracker->data;
        tracker = tracker->next;
        return val;
    }
    return 0;
}

template <typename T>
void ZLL<T>::show()
{
    Node<T> *tempNode = this->head;
    while (tempNode != nullptr)
    {
        cout << tempNode->data << " ";
        tempNode = tempNode->next;
    }
    cout << endl;
}

template <typename T>
void ZLL<T>::remove(Node<T> *nodeToDelete)
{
    if (nodeToDelete == this->head && nodeToDelete == this->tail)
    {
        head = nullptr;
        tail = nullptr;
        delete (nodeToDelete);
        return;
    }
    else if (nodeToDelete == head)
    {
        head = head->next;
        head->prev = nullptr;
    }
    else if (nodeToDelete == tail)
    {
        tail = tail->prev;
        nodeToDelete->prev = nullptr;
        tail->next = nullptr;
    }
    else
    {
        if (nodeToDelete->next != nullptr)
        {
            nodeToDelete->next->prev = nodeToDelete->prev;
        }
        if (nodeToDelete->prev != nullptr)
        {
            nodeToDelete->prev->next = nodeToDelete->next;
        }
    }
    delete (nodeToDelete);
}
