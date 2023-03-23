#include <iostream>
#include <vector> 
#include <cassert>
#include "ZLL.h"
#include "Thing.h"
#include "Course.h"
using namespace std;
template <typename T>
void reportZany(const T &param) 
{
	cout << param << " is ";
	if (!isZany(param)) cout << "not ";
	cout << "zany" << endl;
}

int main() 
{
    int one = 1;
	int two = 2;
	string one_str = "one";
	string two_str = "Two";
	reportZany(one);
	reportZany(two);
	reportZany(one_str);
	reportZany(two_str);
	Thing one_thing("Grape", "purple");
	Thing two_thing("Blueberry", "blue");
	Course one_course("CS220","Frances");
	Course two_course("CS240","Jiahui");

	reportZany(one_thing);
	reportZany(two_thing);
	
	reportZany(one_course);
	reportZany(two_course);

	ZLL<int> zll1;
	ZLL<string> zll2;
	ZLL<Thing> zll3;
	ZLL<Course> zll4;


	zll1.back(1);
	zll2.back("two");
	zll3.back(one_thing);
	zll4.back(one_course);
	zll4.back(two_course);
}

