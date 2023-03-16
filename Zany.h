#ifndef ZANY_H
#define ZANY_H
#include <iostream>
using namespace std;
bool isZany(int a)
{
    return (a % 2);
}
bool isZany(string a)
{
    return ((a.length() > 0) && isupper(a[0]));
}
#endif