#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int d, Node* n): data(d), next(n)
  {};
};

class Stack {
private:
  Node* top;
  int size;

public:
  // Constructor
  Stack(): top(nullptr), size(0)
  {}

  // Destructor
  ~Stack()
  {
    cout << "*** Destructor in action ***" << endl;
    while (top != nullptr)
    {
      pop();
    }
  }

  // Push method
  Stack& push(int value)
  {
    top = new Node(value, top);
    cout << "Pushed " << value << " on the stack\n";
    size++;
    return *this;
  }

  // Pop method
  Stack& pop()
  {
    if (top == nullptr)
    {
      cout << "No nodes to pop\n";
    }
    else
    {
      Node* temp = top;
      top = top->next;
      cout << "Popped " << temp->data << " off the stack\n";
      size--;
      delete temp;
    }
    return *this;
  }

  // Push method
  void is_empty()
  {
    if (top == nullptr)
    {
      cout << "The stack is empty\n";
    }
    else
    {
      cout << "The stack is not empty\n";
    }
  }

  // Push method
  int get_size()
  {
    return size;
  }
};

int main()
{
  Stack s;
  s.pop();
  s.is_empty();
  s.push(1);
  s.push(2);
  cout << "The size is: " << s.get_size() << endl;
  s.is_empty();
  s.pop();
  s.push(3).push(4);
  cout << "The size is: " <<  s.get_size() << endl;
  s.pop().pop();
  s.is_empty();
  s.push(32);
  cout << "The size is: " <<  s.get_size() << endl;
  return 0;
}
