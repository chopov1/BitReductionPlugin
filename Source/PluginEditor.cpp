/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MessAroundInProcessBlockAudioProcessorEditor::MessAroundInProcessBlockAudioProcessorEditor (MessAroundInProcessBlockAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    multiplierSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    multiplierSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 100, 25);
    bitshiftSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    bitshiftSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 100, 25);
    multiplierSlider.setRange(10, 200);
    multiplierSlider.setValue(120);
    bitshiftSlider.setRange(0, 16);
    bitshiftSlider.setValue(1);
    multiplierSlider.addListener(this);
    bitshiftSlider.addListener(this);
    addAndMakeVisible(multiplierSlider);
    addAndMakeVisible(bitshiftSlider);
}

MessAroundInProcessBlockAudioProcessorEditor::~MessAroundInProcessBlockAudioProcessorEditor()
{
}

//==============================================================================
void MessAroundInProcessBlockAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

   
}

void MessAroundInProcessBlockAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    /*juce::Rectangle<int> bounds = getLocalBounds();
    juce::Rectangle<int> slider1 = juce::Rectangle<int>(bounds.getX()/2, bounds.getY()/2);
    juce::Rectangle<int> slider2 = juce::Rectangle<int>(bounds.getX()/2, bounds.getY() / 2);*/
    multiplierSlider.setBounds(getWidth()/2, getHeight()/2, 100, 100);
    bitshiftSlider.setBounds(getWidth() / 4, getHeight() / 4, 100, 100);
    //bitshiftSlider.setBounds(slider2);
}

void MessAroundInProcessBlockAudioProcessorEditor::sliderValueChanged(juce::Slider *slider) {
    if (slider == &multiplierSlider) {
        audioProcessor.Multiplier = multiplierSlider.getValue();
    }
    if (slider == &bitshiftSlider) {
        audioProcessor.Shifter = bitshiftSlider.getValue();
    }
}