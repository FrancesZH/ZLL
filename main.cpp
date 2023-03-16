#include <iostream>
#include "ZLL.h"
using namespace std;

int main()
{
    // ZLL<int> myzll;
    // ZLL<int> myzllother;

    // myzll.front(3);
    // myzll.back(4);
    // myzll.front(2);
    // myzll.front(1);

    // myzllother.front(13);
    // myzllother.back(12);
    // myzllother.front(15);
    // myzllother.front(20);

    // myzllother.join(myzll);
    // //myzllother+=myzll;

    // myzll.show();
    // myzllother.show();
    // myzllother-=myzll;
    // //myzllother.removeZany();
    // //myzllother.removeNonZany();
    // //myzllother.promoteZany();
    //  myzll.show();
    //  myzllother.show();
     ZLL<int> myzll;
    // populate with some values
    myzll.front(3);
    myzll.back(4);
    myzll.front(2);
    myzll.front(1);
    myzll.front(9);
    myzll.back(7);

     myzll.start();
     int value;
    while (!myzll.done()) 
    {
        value = myzll.getNext();
        cout << "[" << value << "]";
    }
    myzll.show();
}
   
