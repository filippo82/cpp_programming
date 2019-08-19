#ifndef WAVE_TOOLS_H
#define WAVE_TOOLS_H

#include <vector>

using namespace std;

template<typename T>
class WaveForm
{
    public:
        WaveForm(int type, int n_freq):
            _type {type},
            _n_freq {n_freq}
            {};
        ~WaveForm() {};

        // Getter
        vector<T> const & get_data() const { return _data; }

        // Setter
        void set_data(vector<T> raw) { _data=std::move(raw); }

    private:
        int _type;
        int _n_freq;
        vector<T> _data;
};

int create_raw_waveform(int n_freq, vector<double> & waveform);

int save_raw_waveform(const vector<double> & waveform);

int read_raw_waveform(int nt, WaveForm<float> & waveform);
int read_raw_waveform(string fn, int nt, WaveForm<float> & waveform);
int read_raw_waveform(string fn, int nt, WaveForm<double> & waveform);

#endif