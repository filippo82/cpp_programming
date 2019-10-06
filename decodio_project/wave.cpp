#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <sstream> // for std::stringstream
#include <vector>
#include <math.h>

#include "wavetools.h"
#include "utils.h"

using namespace std;

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
    std::stringstream convert {argv[1]};
    // do the conversion
	// if (!(convert >> n_freq))
    // {
    //     std::cerr << "Usage: " << argv[0] << " number_of_sinusoids" << std::endl;
	// 	n_freq = 0; // if conversion fails, set n_freq to a default value
    //     return 1;
    // }

    Config config{read_config(argv[1])};

    // Print the number of frequencies:
    std::cout << "The created waveform will consists of " << config.nf << " frequencies!" << std::endl;    

    // Create the raw waveform vector
    vector<double> raw_waveform;

    // Create the waveform vector
    WaveForm<float> waveform(0, config.nf);

    int result {0};
    result = create_raw_waveform(config.nf, raw_waveform);
    result = save_raw_waveform(raw_waveform);

    std::stringstream fn {"wave.bin"};

    result = read_raw_waveform(config.nt, waveform);
    print(waveform, 20);

    return 0;
}
