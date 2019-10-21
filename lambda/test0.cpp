#include <iostream>
#include <vector>
#include <algorithm>

template<typename Container>
void print(Container & vec)
{
    for (auto x : vec)            // for each x in v
        std::cout << x << '\n';
}

template<typename Container,
         typename Size,
         typename Coeff>
void init(Container & vec, const Size size, const Coeff coeff)
{
    // Resize the container
    vec.resize(size);

    // Initialize its content
    for (auto i = 0; i < vec.size(); i++)
        vec[i] = i * coeff;
}

int main()
{
    // Hello
    std::cout << "Hello! This is a tutorial on lambda functions." << std::endl;

    // Create the containers
    std::vector<int> vec0;
    std::vector<int> vec1;

    // Initialize the containers
    std::size_t size {10};
    init(vec0, size, 2);
    init(vec1, size, 4);

    //vec1.resize(size);
    //int coeff {4};
    //auto init_lambda = [] (auto & elem, auto coeff) {*elem = coeff;};
    //auto init_lambda = [coeff] (auto & elem) {elem = coeff;};
    //std::for_each(vec1.begin(), vec1.end(), init_lambda);

    // Print the containers
    print(vec0);
    print(vec1);

    return 0;
}

