#include <iostream>
using namespace std;

// struct Node;

struct Node {
  int data;
  Node* next;
  Node(int d): data(d), next(nullptr)
  {};
};

class Stack {
private:
  Node* first;
  Node* last;

public:
  // Constructor
  Stack(): first(nullptr), last(nullptr)
  {}

  // Destructor
  ~Stack()
  {
    while (first != nullptr) { pop(); }
  }

  // Push method
  Stack& push(int value)
  {
    Node* temp = new Node(value);
    // temp->data = value;
    // temp->next = 0;

    if (first == nullptr)
    {
      first = temp;
      last = temp;
    }
    else
    {
      last->next = temp;
      last = last->next;
    }

    cout << "Pushed " << value << " on the stack\n";

    // temp = 0;
    return *this;
  }

  Stack& pop()
  {
    if (first == nullptr)
    {
      cout << "No nodes to pop.\n";
    }
    else
    {
      // only one node left
      if (first == last)
      {
        cout << "Popped " << first->data << " off the stack\n";
        delete first;
        first = nullptr;
        last = nullptr;
        return *this;
      }

      Node* temp = first;
      while (temp->next != last)
      {
        temp = temp->next;
      }
      cout << "Popped " << last->data << " off the stack\n";
      delete last;
      last = temp;
      last->next = nullptr;
    }
    return *this;
  }
};

int main()
{
  Stack s;
  s.pop();
  s.push(1);
  s.push(2);
  s.pop();
  s.push(3).push(4);
  s.pop().pop();
  return 0;
}
