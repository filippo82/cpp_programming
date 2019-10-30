#include <stdio.h>

struct Node {
  int data;
};
typedef struct Node Node1;

/* This is equivalent for the declaration and typedef above */
typedef struct Node2 {
  int data;
} Node2;

int main()
{
  struct Node s0;
  Node1 s1;
  Node2 s2;
  s0.data = 40;
  s1.data = 41;
  s2.data = 42;
  printf("s0.data is %d\n", s0.data);
  printf("s1.data is %d\n", s1.data);
  printf("s2.data is %d\n", s2.data);
  return 0;
}
