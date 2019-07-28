#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <sstream> // for std::stringstream
#include <vector>
#include <math.h>

using namespace std;

int create_waveform(int n_freq, vector<double> & waveform)
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
    return 0;
}

int save_waveform(const vector<double> & waveform)
{
    ofstream outfile;
    outfile.open("wave.bin", ios::binary | ios::out);
    outfile.write((char*) & waveform, waveform.size() * sizeof(double));
    outfile.close();

    return 0;
}

int read_waveform(vector<double> & waveform)
{
    ifstream infile;
    infile.open("wave.bin", ios::binary | ios::in);
    infile.read((char*) & waveform, waveform.size() * sizeof(double));
    infile.close();

    return 0;
}

void print(const vector<double> & waveform)
{
    for (auto i: waveform) //=waveform.begin(); i!=waveform.end(); ++i)
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

int main(int argc, char* argv[])
{

    // Check the number of parameters
    if (argc < 2) {
        // Tell the user how to run the program
        std::cerr << "Usage: " << argv[0] << " number_of_sinusoids" << std::endl;
        /* "Usage messages" are a conventional way of telling the user
         * how to run a program if they enter the command incorrectly.
         */
        return 1;
    }
    
    // Read in the number of frequencies
	int n_freq;
    // set up a stringstream variable named convert, initialized with the input from argv[1]
    std::stringstream convert(argv[1]); 
	if (!(convert >> n_freq)) // do the conversion
        std::cerr << "Usage: " << argv[0] << " number_of_sinusoids" << std::endl;
		n_freq = 0; // if conversion fails, set myint to a default value

    // Print the number of frequencies:
    std::cout << "The created waveform will consists of " << n_freq << " frequencies!" << std::endl;

    // Create the waveform vector
    vector<double> waveform;

    int result {0};
    result = create_waveform(n_freq, waveform);
    save_waveform(waveform);
    read_waveform(waveform);
    print(waveform);

    return 0;
}
