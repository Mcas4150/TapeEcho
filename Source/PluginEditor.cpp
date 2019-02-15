/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TapeDelayAudioProcessorEditor::TapeDelayAudioProcessorEditor (TapeDelayAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    
    setLookAndFeel(&otherLookAndFeel);
    
    mGainSlider     = new Slider (Slider::RotaryHorizontalVerticalDrag,  Slider::TextBoxBelow);
    mTimeSlider     = new Slider (Slider::RotaryHorizontalVerticalDrag,  Slider::TextBoxBelow);
    mFeedbackSlider = new Slider (Slider::RotaryHorizontalVerticalDrag,  Slider::TextBoxBelow);
    
    addAndMakeVisible (mGainSlider);
    addAndMakeVisible (mTimeSlider);
    addAndMakeVisible (mFeedbackSlider);

    
    mGainAttachment     = new AudioProcessorValueTreeState::SliderAttachment (p.getValueTreeState(), TapeDelayAudioProcessor::paramGain, *mGainSlider);
    mTimeAttachment     = new AudioProcessorValueTreeState::SliderAttachment (p.getValueTreeState(), TapeDelayAudioProcessor::paramTime, *mTimeSlider);
    mFeedbackAttachment = new AudioProcessorValueTreeState::SliderAttachment (p.getValueTreeState(), TapeDelayAudioProcessor::paramFeedback, *mFeedbackSlider);
    
    setSize (800, 350);
}

TapeDelayAudioProcessorEditor::~TapeDelayAudioProcessorEditor()
{
    
    setLookAndFeel(nullptr);
   
    mFeedbackAttachment = nullptr;
    mTimeAttachment     = nullptr;
    mGainAttachment     = nullptr;
    
    mFeedbackSlider = nullptr;
    mTimeSlider     = nullptr;
    mGainSlider     = nullptr;
}

//==============================================================================
void TapeDelayAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colour (70, 85, 40));
    
    g.setColour (Colours::silver);
    g.setFont   (24.0f);
    Rectangle<int> box (getX(), getBottom() - 80, getWidth() / 6, 20);
    g.drawFittedText (TRANS ("Gain"), box, Justification::centred, 1);
    box.setX (box.getRight());
    g.drawFittedText (TRANS ("Time"), box, Justification::centred, 1);
    box.setX (box.getRight());
    g.drawFittedText (TRANS ("Feedback"), box, Justification::centred, 1);
}

void TapeDelayAudioProcessorEditor::resized()
{
  
    Rectangle<int> box (getLocalBounds());
    box.setWidth (getWidth() / 6);
    box.setHeight (getHeight() - 80);
    mGainSlider->setBounds (box);
    box.setX (box.getRight());
    mTimeSlider->setBounds (box);
    box.setX (box.getRight());
    mFeedbackSlider->setBounds (box);
}








