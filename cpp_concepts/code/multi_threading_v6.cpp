#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <atomic>
#include <random>
#include <numeric>

void workerThreadFunction(const std::vector<int> &v, std::atomic<unsigned long long> &acm, unsigned int beginIndex, unsigned int endIndex)
{
        unsigned long long _acm = 0;
        for (unsigned int i = beginIndex; i < endIndex; ++i)
        {
          _acm += v[i];
        }
        acm += _acm;
};

int main()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0, 99);
    std::vector<int> v;
    v.resize(100000);
    // for (auto& item: v)
    // {
    //     item = dis(gen);
    // }
    auto gen2 = [&dis, &gen](){return dis(gen);};

    generate(begin(v), end(v), gen2);
    std::cout << v[10] << std::endl;
    std::cout << v[100] << std::endl;
    std::cout << v[1000] << std::endl;
    std::cout << v[10000] << std::endl;
    // std::cout << v[100000] << std::endl;

    std::atomic<unsigned long long> result(0);

    size_t nthreads = 20;

    size_t stride = v.size() / nthreads;
    std::cout << "stride is: " << stride << std::endl;

    std::vector<std::thread> threadList;
    for(unsigned int i = 0; i < nthreads; ++i)
    {
        std::cout << i << " begin: " << i * stride << " end: " << (i + 1) * stride << std::endl;
        threadList.emplace_back(workerThreadFunction, std::ref(v), std::ref(result), i * stride, (i + 1) * stride);
    }
    // Now wait for all the worker thread to finish i.e.
    // Call join() function on each of the std::thread object
    std::cout << "wait for all the worker thread to finish" << std::endl;
    // std::for_each(threadList.begin(), threadList.end(), std::mem_fn(&std::thread::join));
    for(auto& entry: threadList)
    {
        if (entry.joinable())
            entry.join();
    }
    std::cout << "Exiting from Main Thread" << std::endl;
    std::cout << "The result is " << result / v.size() << std::endl;
    std::cout << "The result is " << std::accumulate(begin(v), end(v), 0) / v.size() << std::endl;

    return 0;
}
