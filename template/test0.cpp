#include <iostream>
#include <vector>
#include <algorithm>

template<typename Container>
void print(Container & vec)
{
    for (auto x : vec)            // for each x in v
        std::cout << x << '\n';
}

// This is a variadic function template
template<typename T,                // type of object to create
         typename... Ts>            // types of arguments to use
T doSomeWork(Ts&&... params)
{
    T vec{std::forward<Ts>(params)...};
    
    return vec;
}

int main()
{
    // Hello
    std::cout << "Hello! This is a tutorial on variadic template functions." << std::endl;

    // Create the containers
    std::vector<int> vec0;

    vec0 = std::move(doSomeWork<std::vector<int>>(10, 20, 30));

    // Print the containers
    print(vec0);

    return 0;
}

