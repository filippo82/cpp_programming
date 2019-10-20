#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
// using namespace std;

// Function
void accumulator_function2(const std::vector<int> &v, unsigned long long &acm,
                            unsigned int beginIndex, unsigned int endIndex)
{
    acm = 0;
    for (unsigned int i = beginIndex; i < endIndex; ++i)
    {
        acm += v[i];
    }
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
      accumulator_function2(v, acm, 0, v.size());
      std::cout << "The sum of all elements is " << acm << std::endl;
      break;
    }
    case 1:
    {
      // Function
      unsigned long long acm1 = 0;
      unsigned long long acm2 = 0;
      std::thread t1(accumulator_function2, std::ref(v), std::ref(acm1), 0, v.size() / 2);
      std::thread t2(accumulator_function2, std::ref(v), std::ref(acm2), v.size() / 2, v.size());
      t1.join();
      t2.join();
      std::cout << "The sum of all elements is " << acm1 + acm2 << std::endl;
      break;
    }
    case 2:
    {
      // Functor
      CAccumulatorFunctor3 accumulator1 = CAccumulatorFunctor3();
      CAccumulatorFunctor3 accumulator2 = CAccumulatorFunctor3();
      std::thread t1(std::ref(accumulator1), std::ref(v), 0, v.size() / 2);
      std::thread t2(std::ref(accumulator2), std::ref(v), v.size() / 2, v.size());
      t1.join();
      t2.join();
      std::cout << "The sum of all elements is " << accumulator1._acm + accumulator2._acm << std::endl;
      break;
    }
    case 3:
    {
      // Lambda function
      unsigned long long acm1 = 0;
      unsigned long long acm2 = 0;
      // Two ways for using lambda functions
      // First case: parameters are passed using std::ref()
      std::thread t1([](std::vector<int> &v, unsigned long long &acm){
        for (unsigned int i = 0; i < v.size() / 2; ++i)
        {
          acm += v[i];
        }
      }, std::ref(v), std::ref(acm1));
      // Second case: parameters are captured
      std::thread t2([&acm2, &v](){
        for (unsigned int i = v.size() / 2; i < v.size(); ++i)
        {
          acm2 += v[i];
        }
      });
      t1.join();
      t2.join();
      std::cout << "The sum of all elements is " << acm1 + acm2 << std::endl;
      break;
    }
  }

  // std::thread t1([&acm1, &v](){
  //   for (unsigned int i = 0; i < v.size() / 2; ++i)
  //   {
  //     acm1 += v[i];
  //   }
  // });
  // std::thread t2([&acm2, &v](){
  //   for (unsigned int i = v.size() / 2; i < v.size(); ++i)
  //   {
  //     acm2 += v[i];
  //   }
  // });

  // Record end time
  auto finish = std::chrono::high_resolution_clock::now();
  // Duration
  std::chrono::duration<double> elapsed = finish - start;
  std::cout << "Elapsed time: " << elapsed.count() << " s" << std::endl;

  return 0;
}
