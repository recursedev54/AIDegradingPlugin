/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AIDegradingPluginAudioProcessorEditor::AIDegradingPluginAudioProcessorEditor (AIDegradingPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    addAndMakeVisible(gainSlider);
    gainSlider.setRange(0.0, 2.0, 0.01);
    gainSlider.setValue(1.0);
    gainSlider.addListener(this);

    //NoiseSlider
    addAndMakeVisible(noiseSlider);
    noiseSlider.setRange(0.0, 1.0, 0.01);
    noiseSlider.addListener(this);

    setSize (400, 300);
}

AIDegradingPluginAudioProcessorEditor::~AIDegradingPluginAudioProcessorEditor()
{
}

//==============================================================================
void AIDegradingPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f); //Set the font size directly
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void AIDegradingPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    gainSlider.setBounds(10, 10, getWidth() - 20, 20);
    noiseSlider.setBounds(10, 40, getWidth() - 20, 20);
}

void AIDegradingPluginAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &gainSlider)
        audioProcessor.gain = gainSlider.getValue();
    else if (slider == &noiseSlider)
        audioProcessor.noiseTemperature = noiseSlider.getValue();
}
