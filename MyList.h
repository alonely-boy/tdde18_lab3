#ifndef My_List
#define My_List

#include <iostream>
class MyList
{
public:
  MyList();
  MyList(int val);
  MyList(MyList &n);
  MyList(int val, MyList &n);
  void setNext(MyList *n);
  MyList* getNext() const;
  void setValue(int val);
  int getValue() const;
  bool isLastNode() const;

private:
  int value;
  MyList *next;
};

std::ostream &operator<<(std::ostream &os,  MyList &myList);

#endif