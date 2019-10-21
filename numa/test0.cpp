#include <iostream>
#include <vector>
#include <algorithm>
#include <omp.h>
#include <math.h>

int main()
{

    std::size_t N = 1200000000;

    std::cout << "Start: " << N << std::endl;
    
    int* data = new int[N];
    std::cout << "Start: " << N << std::endl;
//    int* res = new int[N];
    
    std::cout << "Before initialization" << std::endl;

//    std::size_t ii;
    
    // initialization with respect to first touch policy
    #pragma omp parallel for schedule(static)
    for (std::size_t i = 0; i < N; ++i)
    {
       data[i] = i;
//       res[i] = 2;
    }

    std::cout << "After initialization: " << data[100000000] << std::endl;

    for (auto a = 0; a < 10000000; a++)
    {
        #pragma omp parallel for schedule(static)
        for (std::size_t i = 0; i < N; ++i)
        {
           data[i] *= sin(i * cos(5));
//           res[i] *= sin(10 * cos(i));
        }
    }

    delete[] data;
//    delete[] res;

   return 0;
}

