#include <iostream>
#include <vector>
#include <future>
#include <chrono>
// using namespace std;

// Function
unsigned long long accumulator_function2(const std::vector<int> &v,
                            unsigned int beginIndex, unsigned int endIndex)
{
    unsigned long long acm = 0;
    for (unsigned int i = beginIndex; i < endIndex; ++i)
    {
        acm += v[i];
    }

    return acm;
};

// Functor
class CAccumulatorFunctor3
{
  public:
    void operator()(const std::vector<int> &v,
      unsigned int beginIndex, unsigned int endIndex)
    {
      _acm = 0;
      for (unsigned int i = beginIndex; i < endIndex; ++i)
      {
        _acm += v[i];
      }
    }
    unsigned long long _acm;
};

int main(int argc, char * argv[])
{
  unsigned int c = std::thread::hardware_concurrency();
  std::cout << "Number of available cores: " << c << std::endl;

  std::vector<int> v;
  v.resize(1000000000, 2);

  std::size_t pos;
  int choice = std::stoi(argv[1], &pos);

  // Record start time
  auto start = std::chrono::high_resolution_clock::now();

  switch (choice)
  {
    case 0:
    {
      // Serial
      unsigned long long acm;
      acm = accumulator_function2(v, 0, v.size());
      std::cout << "The sum of all elements is " << acm << std::endl;
      break;
    }
    case 1:
    {
      // Function
      unsigned long long acm1 = 0;
      unsigned long long acm2 = 0;
      auto t1 = std::async(accumulator_function2, std::ref(v), 0, v.size() / 2);
      auto t2 = std::async(accumulator_function2, std::ref(v), v.size() / 2, v.size());
      acm1 = t1.get();
      acm2 = t2.get();
      std::cout << "The sum of all elements is " << acm1 + acm2 << std::endl;
      break;
    }
  }

  // Record end time
  auto finish = std::chrono::high_resolution_clock::now();
  // Duration
  std::chrono::duration<double> elapsed = finish - start;
  std::cout << "Elapsed time: " << elapsed.count() << " s" << std::endl;

  return 0;
}
