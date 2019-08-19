#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

// Print the waveform to cout
void print(const WaveForm<double> & waveform)
{
    for (auto i: waveform.get_data()) //=waveform.begin(); i!=waveform.end(); ++i)
    {
        cout << i << endl;
        //2.0*M_PI*i/100
    }
    // int v[] = {0,1,2,3,4,5,6,7,8,9};

    // for (auto x : v)            // for each x in v
    //     std::cout << x << '\n';

    // for (auto x : {10,21,32,43,54,65})
    //     std::cout << x << '\n';
}

void print(const WaveForm<float> & waveform)
{
    for (auto i: waveform.get_data()) //=waveform.begin(); i!=waveform.end(); ++i)
    {
        cout << i << endl;
        //2.0*M_PI*i/100
    }
    // int v[] = {0,1,2,3,4,5,6,7,8,9};

    // for (auto x : v)            // for each x in v
    //     std::cout << x << '\n';

    // for (auto x : {10,21,32,43,54,65})
    //     std::cout << x << '\n';
}
