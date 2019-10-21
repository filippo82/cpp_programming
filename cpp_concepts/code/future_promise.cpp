#include <iostream>
#include <thread>
#include <future>

// void initiazer(std::promise<int> * promObj)
// {
//   std::cout << "Inside Thread" << std::endl;
//   // Make This Thread sleep for 5 Second
//   std::this_thread::sleep_for(std::chrono::milliseconds(5000));
//   promObj->set_value(35);
// }

void initiazer(std::promise<int> & promObj)
{
  std::cout << "Inside Thread" << std::endl;
  // Make This Thread sleep for 5 Second
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  promObj.set_value(35);
}

int main()
{
  std::promise<int> promiseObj;
  std::future<int> futureObj = promiseObj.get_future();
  // std::thread th(initiazer, &promiseObj);
  std::thread th(initiazer, std::ref(promiseObj));
  std::cout << futureObj.get() << std::endl;
  th.join();

  return 0;
}
