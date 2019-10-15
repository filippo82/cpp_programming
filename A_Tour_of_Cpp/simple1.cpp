#include <iostream>
#include <vector>

void copy_fct()
{
    int v1[10] = {0,1,2,3,4,5,6,7,8,9};
    int v2[10];                 // to become a copy of v1

    for (auto i=0; i!=10; ++i)  // copy elements
    {
        v2[i]=v1[i];
        std::cout << v2[i] << std::endl;
    }
}

void print()
{
    int v[] = {0,1,2,3,4,5,6,7,8,9};

    for (auto x : v)            // for each x in v
        std::cout << x << '\n';

    for (auto x : {10,21,32,43,54,65})
        std::cout << x << '\n';
}

void cpp11_loop1()
{
    std::vector<int> vec {100, 200, 300, 400};
    std::vector<int>::iterator it;
    for (auto v: vec)
        v *= 2;
    for (auto i = 0; i < vec.size(); i++)
        std::cout << vec[i] << std::endl;
    for (it = vec.begin(); it != vec.end(); ++it)
        *it *= 2;
    for (auto i = 0; i < vec.size(); i++)
        std::cout << vec[i] << std::endl;
}

int main()
{
    copy_fct();
    print();
    cpp11_loop1();

    return 0;
}

