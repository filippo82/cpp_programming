#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
// using namespace std;

void accumulator_function2(const std::vector<int> &v, unsigned long long &acm,
                            unsigned int beginIndex, unsigned int endIndex)
{
    acm = 0;
    for (unsigned int i = beginIndex; i < endIndex; ++i)
    {
        acm += v[i];
    }
};

int main()
{
  unsigned int c = std::thread::hardware_concurrency();
  std::cout << "Number of available cores: " << c << std::endl;

  unsigned long long acm;
  std::vector<int> v;
  v.resize(1000000000, 2);

  // Record start time
  auto start = std::chrono::high_resolution_clock::now();
  // accumulator_function2(v, acm, 0, v.size());

  unsigned long long acm1 = 0;
  unsigned long long acm2 = 0;
  // std::thread t1(accumulator_function2, std::ref(v), std::ref(acm1), 0, v.size() / 2);
  // std::thread t2(accumulator_function2, std::ref(v), std::ref(acm2), v.size() / 2, v.size());

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

  // Record end time
  auto finish = std::chrono::high_resolution_clock::now();
  // Duration
  std::chrono::duration<double> elapsed = finish - start;
  std::cout << "Elapsed time: " << elapsed.count() << " s" << std::endl;

  // std::cout << "The sum of all elements is " << acm << std::endl;
  std::cout << "The sum of all elements is " << acm1 + acm2 << std::endl;

  return 0;
}
