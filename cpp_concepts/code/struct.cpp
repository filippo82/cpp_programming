#include <iostream>
using namespace std;

struct Node {
  int data;
  Node(int d): data(d)
  {};
};

int main()
{
  Node s(42);
  cout << "The data is: " <<  s.data << endl;
  return 0;
}
