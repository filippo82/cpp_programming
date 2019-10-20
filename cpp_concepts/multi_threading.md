
## Resources
* [Learn C++ Multi-Threading in 5 Minutes](https://hackernoon.com/learn-c-multi-threading-in-5-minutes-8b881c92941f)

* [C++11 Multithreading](https://thispointer.com//c-11-multithreading-part-1-three-different-ways-to-create-threads/)

# Threads

```cpp
std::thread t1(fn, std::ref(v), std::ref(acm1), beg, end);
t1.join();
```

* `std::thread` creates a new thread.
The first parameter is the name of the function pointer.

* The rest of the parameters passed to the `std::thread` constructor
are the parameters that we need to pass to the function `fn`.
All parameters passed to `fn` are passed by value unless they wrapped in `std::ref`.

* Threads created by `std::thread` do not have return values.
If we want to return something, we need to store it in one of the parameters passed by reference.

* Each thread starts as soon as it gets created.

* We use join() function to wait for a thread to finish

## Tasks
* Tasks are defined and created using `std::async`.

* The returned value from `std::async` is called a `std::future`.
It means `t1` is a variable whose value will be assigned to in the future.
We get its values by calling `t1.get()`.

* If the future values are not ready upon calling get(),
the main thread blocks until the future value becomes ready.

* The function that we pass to `std::async` returns a value.
This value is passed through a type called `std::promise`.

* By default, each task starts as soon as it is created.
