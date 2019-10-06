#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "utils.h"

using namespace std;

// Print the waveform to cout
void print(const WaveForm<double> & waveform, int maxt)
{
    // for (auto i: waveform.get_data()) //=waveform.begin(); i!=waveform.end(); ++i)
    for (auto i = 0; i < waveform.get_data().size(); ++i)
    {
        cout << waveform.get_data()[i] << endl;
        //2.0*M_PI*i/100
        if (i > maxt) break;
    }
    // int v[] = {0,1,2,3,4,5,6,7,8,9};

    // for (auto x : v)            // for each x in v
    //     std::cout << x << '\n';

    // for (auto x : {10,21,32,43,54,65})
    //     std::cout << x << '\n';
}

void print(const WaveForm<float> & waveform, int maxt)
{
    // for (auto i: waveform.get_data()) //=waveform.begin(); i!=waveform.end(); ++i)
    for (auto i = 0; i < waveform.get_data().size(); ++i)
    {
        cout << waveform.get_data()[i] << endl;
        //2.0*M_PI*i/100
        if (i > maxt) break;
    }
    // int v[] = {0,1,2,3,4,5,6,7,8,9};

    // for (auto x : v)            // for each x in v
    //     std::cout << x << '\n';

    // for (auto x : {10,21,32,43,54,65})
    //     std::cout << x << '\n';
}

Config read_config(string fn)
{
    ifstream config_file {fn};

    if (!config_file.is_open())
    {
        cerr << "Could not open the configuration file!" << endl;
    }

    int nt;
    int nf;
    vector<int> freqs;

    std::istringstream temp;
    string line;
    // Read nt
    getline(config_file, line);
    temp.str(line);
    if (!(temp >> nt))
        cout << "Something is wrong with nt" << endl;
    // Read nf
    getline(config_file, line);
    istringstream().swap(temp); // Clears the iss
    temp.str(line);
    if (!(temp >> nf))
        cout << "Something is wrong with nf" << endl;
    // Read freqs
    freqs.resize(nf);
    getline(config_file, line);
    istringstream().swap(temp); // Clears the iss
    temp.str(line);
    for (auto i=0; i < freqs.size(); ++i)
    {
        if (!(temp >> freqs[i]))
           cout << "Something is wrong with nf" << endl;
    }

    // Print values
    cout << "nt: " << nt << endl;
    cout << "nf: " << nf << endl;
    for (auto i=0; i < freqs.size(); ++i)
    {
        cout << "freqs[" << i << "] is: " << freqs[i] << endl;
    }

    Config config;

    config.nt = nt;
    config.nf = nf;
    config.freqs = freqs;

    // // config_file.read();
    // stringstream buffer;
    // // buffer << config_file.rdbuf();
    // cout << config_file.rdbuf();
    // // std::string contents(buffer.str());
    config_file.close();

    return config;
}