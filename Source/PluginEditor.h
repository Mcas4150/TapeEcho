/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/


class FloorComponent   : public Component
{
public:
    FloorComponent() {}
    
    ~FloorComponent() {}
    
    void paint (Graphics& g) override
    {
        g.setColour (Colours::green);
        g.drawLine (0, getHeight() / 2, getWidth(), getHeight() / 2, 5);
    }
    
private:
    //==============================================================================
    
};

class OtherLookAndFeel : public LookAndFeel_V4
{
public:
    OtherLookAndFeel()
    {
        setColour (Slider::thumbColourId, Colours::red);
    }
    
    
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override
    {
        auto radius = jmin (width / 2, height / 2) - 4.0f;
        auto centreX = x + width  * 0.5f;
        auto centreY = y + height * 0.5f;
        auto rx = centreX - radius;
        auto ry = centreY - radius;
        auto rw = radius * 2.0f;
        auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        
        // fill
        g.setColour (Colour(191, 191, 191));
        g.fillEllipse (rx, ry, rw, rw);
        // outline
        g.setColour (Colours::black);
        g.drawEllipse (rx, ry, rw, rw, 5.0f);
        
        Path p;
        auto pointerLength = radius * 0.25f;
        auto pointerThickness = 3.0f;
        p.addRectangle (-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
        p.applyTransform (AffineTransform::rotation (angle).translated (centreX, centreY));
        
        g.setColour (Colours::black);
        g.fillPath (p);
        
    }
    
};


class TapeDelayAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    TapeDelayAudioProcessorEditor (TapeDelayAudioProcessor&);
    ~TapeDelayAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    TapeDelayAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TapeDelayAudioProcessorEditor)
    OtherLookAndFeel otherLookAndFeel;
    ScopedPointer<Slider> mGainSlider;
    ScopedPointer<Slider> mTimeSlider;
    ScopedPointer<Slider> mFeedbackSlider;
    
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mGainAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mTimeAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mFeedbackAttachment;


};



//class MainContentComponent   : public Component
//{
//public:
//    MainContentComponent()
//    {
//        addAndMakeVisible (TapeDelayEditor);
//        setSize (600, 400);
//    }
//
//    ~MainContentComponent() {}
//
//    void paint (Graphics&) override {}
//
//    void resized() override
//    {
//        TapeDelayEditor.setBounds (0, 0, getWidth(), getHeight());
//    }
//
//private:
//    TapeDelayAudioProcessorEditor TapeDelayEditor;
//
//    //==============================================================================
//    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
//};
