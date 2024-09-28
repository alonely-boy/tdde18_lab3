#ifndef My_Link_List
#define My_Link_List

#include <iostream>

class MyNode
{
public:
  MyNode();
  MyNode(int val);
  MyNode(MyNode &n);
  MyNode(int val, MyNode &n);
  void setNext(MyNode *n);
  MyNode *getNext() const;
  void setValue(int val);
  int getValue() const;

private:
  int value;
  MyNode *next;
};

class MyLinkList
{
public:
  MyLinkList(int val);
  MyLinkList(MyLinkList const& L1);
  void insertNode(int val);
  void print();
  MyNode* deepClone(MyNode* a_node);
  void remove(int val);
private:
  MyNode *firstNode;
};

#endif