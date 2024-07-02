/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class AIDegradingPluginAudioProcessorEditor : public juce::AudioProcessorEditor,
    public juce::Slider::Listener
{
public:
    AIDegradingPluginAudioProcessorEditor(AIDegradingPluginAudioProcessor&);
    ~AIDegradingPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint(juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged(juce::Slider* slider) override; // Added sliderValueChanged

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AIDegradingPluginAudioProcessor& audioProcessor;

    juce::Slider gainSlider;       // Added gainSlider
    juce::Slider noiseSlider;      // Added noiseSlider

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AIDegradingPluginAudioProcessorEditor)
};

