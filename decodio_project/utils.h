#ifndef WAVE_UTILS_H
#define WAVE_UTILS_H

#include <vector>

#include "wavetools.h"

using namespace std;

void print(const WaveForm<float> & waveform, int maxt);
void print(const WaveForm<double> & waveform, int maxt);

#endif