# Const

## Const member functions
A non-static member function can be declared with a const, volatile,
or const volatile qualifier (this qualifier appears after the parameter list
in the function declaration).
Differently cv-qualified functions have different types and so may overload each other.

In the body of a cv-qualified function, the this pointer is cv-qualified,
e.g. in a const member function, only other const member functions
may be called normally.

When a function is declared as const, it can be called on any type of object,
const object as well as non-const objects.
The idea of const functions is not to allow them to modify the members
of the object on which they are called.
This means that, inside a const function, it is not possible to modify
any variables which will change the state of objects.
It is recommended the practice to make as many functions const as possible so that accidental changes to objects are avoided.
The const keyword is part of the functions signature which means that you can implement two similar methods,
one which is called when the object is const, and one that isn't.

```cpp
int getValue() const {return value;}
```

## Resources

[Geeksforgeeks](https://www.geeksforgeeks.org/const-member-functions-c/)
