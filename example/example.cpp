/*

Simple example of applying to single 512 buffer 

*/

#include "Compressor.h" 

#include <vector>
#include <random>
#include <numeric>
#include <iostream>

int main() {
 
    std::mt19937 rng(std::random_device{}());                  // Random Generator
    std::uniform_real_distribution<float> dist(-1.0f, 1.0f);   // distribute within [-1,1]

  
    std::vector<float> inputBuffer(512);
    for (float& sample : inputBuffer) {
        sample = dist(rng);
    }
    std::vector<float> outputBuffer(512);



    Compressor compressor(44100.0f, 20.0f, true); // Create compressor with sampleRate = 44.1kHz and Threshhold of 20dB (applies *-1 in algorithm)
                                                  // set to false to disable smoothing

    for (size_t i = 0; i < inputBuffer.size(); ++i) {
        outputBuffer[i] = compressor.process(inputBuffer[i]); // Process each sample
    }

    // Calculate average absolute value 

    float inputAvgAbs = std::accumulate(inputBuffer.begin(), inputBuffer.end(), 0.0f,
        [](float sum, float val) { return sum + std::abs(val); }) / inputBuffer.size();

    float outputAvgAbs = std::accumulate(outputBuffer.begin(), outputBuffer.end(), 0.0f,
        [](float sum, float val) { return sum + std::abs(val); }) / outputBuffer.size();


    std::cout << "\nInput signal average compressed from: " << inputAvgAbs << " to " << outputAvgAbs << "\n\n";

    return 0;
}

