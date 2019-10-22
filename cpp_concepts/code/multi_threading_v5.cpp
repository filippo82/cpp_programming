#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

class WorkerThread
{
    public:
        // WorkerThread(int val): _acm(val) {}
        void operator()(const std::vector<int> &v, unsigned int beginIndex, unsigned int endIndex)
        {
            // std::cout << "Worker Thread " << std::this_thread::get_id() << " is Executing" << std::endl;
            _acm = 4;
            for (unsigned int i = beginIndex; i < endIndex; ++i)
            {
              _acm += v[i];
            }
            std::cout << "Worker Thread " << std::this_thread::get_id() << " is Executing. Sum: " << _acm << std::endl;
        }
        unsigned long long _acm;
};

void workerThreadFunction(const std::vector<int> &v, unsigned long long &acm, unsigned int beginIndex, unsigned int endIndex)
{
        unsigned long long _acm = 0;
        for (unsigned int i = beginIndex; i < endIndex; ++i)
        {
          _acm += v[i];
        }
        // std::cout << "Worker Thread " << std::this_thread::get_id() << " is Executing. Sum: " << acm << std::endl;
        acm = _acm;
};

int main()
{
    std::vector<int> v;
    v.resize(1000000, 2);

    size_t nthreads = 4;

    size_t stride = v.size() / nthreads;
    std::cout << "stride is: " << stride << std::endl;

    // std::vector<WorkerThread> workerList;
    std::vector<std::thread> threadList;
    std::vector<unsigned long long> acmList;
    for(int i = 0; i < nthreads; i++)
    {
        // WorkerThread worker;
        // workerList.push_back(worker);
        // workerList.emplace_back();
        acmList.emplace_back();
        std::cout << i << " xxxxxxxxxx acm: " << acmList[i] << std::endl;
        std::cout << i << " begin: " << i * stride << " end: " << (i + 1) * stride << std::endl;
        // threadList.push_back(std::thread(std::ref(workerList[i]), std::ref(v), i * stride, (i + 1) * stride));
        threadList.emplace_back(workerThreadFunction, std::ref(v), std::ref(acmList[i]), i * stride, (i + 1) * stride);
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
    std::cout << "acmList.size() is " << acmList.size() << std::endl;
    // for (auto worker: workerList)
    // {
    //     unsigned long long result = worker._acm;
    //     std::cout << "CIAONE: " << result << std::endl;
    // }
    // std::for_each(threadList.begin(),threadList.end(), std::mem_fn(&std::thread::join));

    return 0;
}
