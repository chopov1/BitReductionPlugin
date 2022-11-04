# BitReductionPlugin
 using bitshift for the algorithm
'''c++
 for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        for (int sample = 0; sample < buffer.getNumSamples(); sample++) {
            
            temp = channelData[sample];
            temp2 = temp * Multiplier;
            temp2 = temp2>>Shifter;
            temp = ((float)temp2) / Multiplier;
            channelData[sample] = temp;
        }
    }
'''
