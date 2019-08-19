#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <sstream> // for std::stringstream
#include <vector>
#include <math.h>

#include "wavetools.h"

using namespace std;

int create_raw_waveform(int n_freq, vector<double> & waveform)
{
    size_t nt {1000};
    waveform.resize(nt);

    // for (auto i=waveform.begin(); i!=waveform.end(); ++i)
    for (auto i=0; i<waveform.size(); ++i)
    {
        //*i = 2.0;
        waveform[i] = 2.0 * M_PI * i / 1000.0;
    }
    // int v1[10] = {0,1,2,3,4,5,6,7,8,9};
    // int v2[10];                 // to become a copy of v1

    // for (auto i=0; i!=10; ++i)  // copy elements
    // {
    //     v2[i]=v1[i];
    //     std::cout << v2[i] << std::endl;
    // }
    cout << "The waveform has been created!" << endl;
    return 0;
}

int save_raw_waveform(const vector<double> & waveform)
{
    ofstream outfile;
    outfile.open("wave.bin", ios::binary | ios::out);
    outfile.write((char*) & waveform[0], waveform.size() * sizeof(double));
    outfile.close();

    cout << "The waveform has been saved to file!" << endl;
    return 0;
}

int read_raw_waveform(string fn, int nt, WaveForm<double> & waveform)
{
    ifstream infile;
    vector<double> temp;
    temp.resize(nt);
    infile.open(fn, ios::binary | ios::in);
    infile.read((char*) & temp[0], nt * sizeof(double));
    infile.close();

    waveform.set_data(temp);

    cout << "The waveform has been loaded!" << endl;
    return 0;
}

int read_raw_waveform(string fn, int nt, WaveForm<float> & waveform)
{
    ifstream infile;
    vector<double> temp;
    
    temp.resize(nt);
    infile.open(fn, ios::binary | ios::in);
    infile.read((char*) & temp[0], nt * sizeof(double));
    infile.close();
    
    vector<float> temp2(temp.begin(), temp.end());
    waveform.set_data(temp2);

    cout << "The waveform has been loaded!" << endl;
    return 0;
}

int read_raw_waveform(int nt, WaveForm<float> & waveform)
{
    ifstream infile;
    vector<double> temp;
    
    temp.resize(nt);
    infile.open("wave.bin", ios::binary | ios::in);
    infile.read((char*) & temp[0], nt * sizeof(double));
    infile.close();
    
    vector<float> temp2(temp.begin(), temp.end());
    waveform.set_data(temp2);

    cout << "The waveform has been loaded!" << endl;
    return 0;
}