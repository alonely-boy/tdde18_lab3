#include "MyList.h"

using namespace std;

MyList::MyList() {}
MyList::MyList(int val)
{
  value = val;
  next = nullptr;
}
MyList::MyList(MyList &n)
{
  next = &n;
}
MyList::MyList(int val, MyList &n)
{
  value = val;
  next = &n;
}
void MyList::setNext(MyList *n)
{
  next = n;
}
void MyList::setValue(int val)
{
  value = val;
}
MyList* MyList::getNext() const
{
  // dereference, return the
  return next;
}
int MyList::getValue() const
{
  return value;
}
bool MyList::isLastNode() const
{
  return next == nullptr;
}

int value;
MyList *next;

ostream &operator<<(ostream &os, MyList &myList)
{
  const MyList *current{&myList};
  while (current != nullptr)
  {
    os << " val -> " << current->getValue() << " ";
    current = current->getNext();
  }
  return os;
}

int main()
{
  MyList m1{10};
  MyList m2{11, m1};
  MyList m3{12, m2};
  cout << m3 << endl;
  return 0;
}