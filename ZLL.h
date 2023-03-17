#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *prev = nullptr;
    Node *next = nullptr;
};

template <typename T>
class ZLL
{
public:
    Node<T> *head;
    Node<T> *tail;
    Node<T> *tracker;
    ZLL();
    ~ZLL();
    bool front(const T &);
    bool back(const T &);
    bool join(ZLL &other);
    ZLL &operator+=(const ZLL &other);
    ZLL &operator-=(const ZLL &other);
    int removeZany();
    int removeNonZany();
    bool promoteZany();
    void show();
    bool start();
    bool done();
    T getNext();
    void remove(Node<T> *nodeToDelete);
    bool empty();
    bool isEmpty();
};
#include "ZLL.cpp"
