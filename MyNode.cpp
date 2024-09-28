#include "MyLinkList.h"

using namespace std;

MyNode::MyNode() {}
MyNode::MyNode(int val)
{
  value = val;
  next = nullptr;
}
MyNode::MyNode(MyNode &n)
{
  next = &n;
}
MyNode::MyNode(int val, MyNode &n)
{
  value = val;
  next = &n;
}
void MyNode::setNext(MyNode *n)
{
  next = n;
}
void MyNode::setValue(int val)
{
  value = val;
}
MyNode *MyNode::getNext() const
{
  // dereference, return the
  return next;
}
int MyNode::getValue() const
{
  return value;
}

// int main()
// {
//   MyNode m1{22};
//   MyNode m2{16, m1};
//   MyNode m3{12, m2};
//   return 0;
// }