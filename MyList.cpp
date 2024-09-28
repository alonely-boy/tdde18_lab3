#include "MyLinkList.h"
#include "MyNode.cpp"
using namespace std;

MyLinkList::MyLinkList(int val)
{
  firstNode = new MyNode(val);
}
// deep clone
MyLinkList::MyLinkList(MyLinkList const &L1)
{
  firstNode = deepClone(L1.firstNode);
}
MyNode *MyLinkList::deepClone(MyNode *a_node)
{
  if (a_node == nullptr)
  {
    return nullptr;
  }
  if (a_node->getNext() == nullptr)
  {
    return new MyNode(a_node->getValue());
  }
  MyNode *first = new MyNode(a_node->getValue());
  first->setNext(deepClone(a_node->getNext()));
  return first;
}
void MyLinkList::print()
{
  MyNode *current = firstNode;
  while (current->getNext() != nullptr)
  {
    cout << "val:" << current->getValue() << " -> ";
    current = current->getNext();
  }
  cout << "val:" << current->getValue();
}
void MyLinkList::insertNode(int val)
{
  MyNode *m = new MyNode(val);
  if (val < firstNode->getValue())
  {
    // insert to the front, return the function
    m->setNext(firstNode);
    firstNode = m;
    return;
  }
  MyNode *current = firstNode, *previous;
  while (val > current->getValue())
  {
    if (current->getNext() == nullptr)
    {
      // insert to the last, and return the function
      current->setNext(m);
      m->setNext(nullptr);
      return;
    }
    previous = current;
    current = current->getNext();
  }
  // insert inbetween
  previous->setNext(m);
  m->setNext(current);
}

void MyLinkList::remove(int val)
{
  if (firstNode == nullptr)
    return;                        // can't remove if it's empty
  if (val < firstNode->getValue()) // no node is bigger than val
    return;
  MyNode *currentNode = firstNode, *previous = nullptr;
  while (currentNode != nullptr)
  {
    if (currentNode->getValue() == val)
    {
      MyNode *temp = currentNode->getNext();
      if (previous == nullptr)
      {
        // delete the first Node
        delete currentNode;
        firstNode = temp; // move first to next
        return;
      }
      else
      {
        delete currentNode;
        previous->setNext(temp);
        return;
      }
    }
    previous = currentNode;
    currentNode = currentNode->getNext();
  }
}
int main()
{
  MyLinkList l1{10};
  l1.insertNode(19);
  l1.insertNode(11);
  l1.insertNode(15);
  l1.insertNode(8);
  // l1.print();
  MyLinkList l2{l1};
  l2.remove(8);
  l2.remove(11);
  l2.remove(19);
  l2.print();
  cout << "\n";
  l1.print();
}