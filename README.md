Write a templated doubly-linked list C++ class, called ZLL, with head and tail pointers (or first and last if you prefer), that stores items whose type is specified as a template parameter T, and which supports the following public interface:

bool isEmpty() NEW

Returns true if the ZLL is empty (i.e. contains no elements), false if it is not empty.

bool empty() NEW

Empties out the ZLL by deleting all of its elements. Basically does what the destructor should do, but allows it to be called from the public interface. You would have to do this anyway in the constructor, but now you should put it in the public member function, and your destructor can simply call this empty() function.

bool front(const T &)

Adds a copy of the item passed as a parameter to the front of the list (that is, the side of the list pointed to by head). Returns false if the item cannot be added to the list. This function should work in constant time (O(1)) and should allow duplicate elements to be added to the list.

bool back(const T &)

Adds a copy of the item passed as a parameter to the back of the list (that is, the side of the list pointed to by tail). Returns false if the item cannot be added to the list. This function should operate in constant time and should allow duplicate elements to be added to the list.

bool join(ZLL &other)

Adds the values of the ZLL passed (by reference) as a parameter, to the end of the list, leaving "other" empty. Returns true. Should operate in constant time. If an object is joined into itself, then the function should not take any action.

ZLL &operator+=(const ZLL &other)

Adds copies of the values of the ZLL passed (by reference) as a parameter, to the end of the list, leaving "other" intact. Returns a reference to the current object (i.e. the object that is called... use "return *this;"). Calling "list += list;" cannot both add the list to the left hand side and leave that same list in tact, so this operation should instead leave list unchanged. You may simply implement this as "if (this == &other) return *this;" 

ZLL &operator-=(const ZLL &other)

Removes all values that are contained in other, from the list that is called, leaving other intact. Returns a reference to the current object (i.e. the object that is called). Passing an object to its own -= operator should not change the object (because it cannot simultaneously remove elements from the list and leave that same list intact.)

int removeZany()

Removes all the items from the ZLL that are zany, leaving only non-zany items. Returns a count of the number of items that were removed.

int removeNonZany()

Removes all the items from the ZLL that are not zany, leaving only zany items. Returns a count of the number of items that were removed.

bool promoteZany()

Moves all zany items (if any) to the front of the list, so that the list contains all of its zany items first, then it's non-zany items. 

What is Zany?

int's are zany if they are odd. Strings are zany if they are non-empty and begin with a capital letter. In general, an item of type T is zany if isZany(const T &) returns true for that item, and is not zany if that function returns false. These functions are provided for int and std::string in a file called zany.h:

#include<string>
#include<iostream>

bool isZany(int a) {return (a % 2);}
bool isZany(std::string a) {
   return ((a.length() > 0) && isupper(a[0]));
}

Your code for ZLL should assume that every type T (including classes, of course) that it is instantiated with has a function called isZany(const T &) that takes a single argument of that type and returns true or false. Note that isZany() is not a member function of T, it is a global function that takes an instance of T as its lone argument.

Finally, your DLL should support the concept (but only the concept) of an "iterator", via the following operations.

bool start()

Sets a "pointer" within the object to the first node of the linked list. This operation returns true if the list is non-empty, and false otherwise.

bool done()

Returns true if there are "no more" items to go through in the list, false if there are more items.

T getNext()

Returns a copy of the "next" object from the linked list. So a call to start() followed by a call to getNext() returns a copy of the first element of a (non-empty) ZLL. Subsequent calls to getNext() return the subsequent items in the list. When it becomes true that the last item was returned on the previous call to getNext(), and no subsequent "start()" is performed, then getNext() should return an item created with its default constructor.

Thus, the following loop allows a ZLL user to print the items in the ZLL instantiated with int:

ZLL<int> myzll;
// populate with some values
myzll.start();
int value;
while (!myzll.done()) {
   value = myzll.getNext())
   cout << "[" << value << "]";
}

The internal pointer to values should be maintained across all of the operations above, and should always be made to point to the next value.

