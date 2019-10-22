#include <iostream>
#include <thread>
#include <algorithm>
using namespace std;

void minList(const std::vector<int>& list, int &min)
{
  min = min_element(begin(list), end(list));
}

// Find the minimum value among the lists
//inner: 25M, 2M, 500k, 50M, 75M, 1M... (unsorted)
//outer: 10k
//16 cores
int findMin(const std::vector<std::vector<int>>& vals) {
  
  vector<thread> threadList;
  vector<int> minList;
  
  for (auto i = 0; i < vals.size(); ++i)
  { 
    minList.emplace_back();
    threadList.emplace_back(minList, ref(vals[i]), ref(minList[i]));
  }
  
  for (auto & t: threadList)
  {
    if (t.joinable())
      t.join();
  }
  
  int finalMin;
  minList(minList, &finalMin);
  
  return finalMin;
  
}

// To execute C++, please define "int main()"
int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const string& word : words) {
    cout << word;
  }
  
  // Initalize vals
  // vals
  
  int result;
  result = findMin(vals);
  
  cout << "The min of mins is: " << result << endl;
  
  return 0;
}

