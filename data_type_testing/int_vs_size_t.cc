#include <iostream>
#include <memory>   // needed for std::shared_ptr
#include <sstream>
#include <limits>

using namespace std;

int main(int argc, char** argv) {

    size_t size1;
    int int1, int2;
    size_t n1, n2, n3;

    size_t intmax {numeric_limits<int>::max()};
    size_t sizetmax {numeric_limits<size_t>::max()};

    n1 = 5999;
    n2 = 1200;
    n3 = 300;

    size1 = n1 * n2 * n3;
//    size1 = sizetmax + 11;

    cout << "INT_MAX is: " << intmax << endl;
    cout << "ULONG_MAX is: " << sizetmax << endl;
    cout << "size1 is: " << size1 << endl;

    return 0;
}

