#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#include "LauncherBarComponent.h"
#include "PageStackComponent.h"

class LauncherComponent;

class LaunchSpinnerTimer : public Timer {
public:
  LaunchSpinnerTimer() {};
  void timerCallback();
  LauncherComponent* launcherComponent;
  int i = 0;
};

class LauncherComponent : public Component, private Button::Listener {
public:
  ScopedPointer<LauncherBarComponent> botButtons;
  ScopedPointer<LauncherBarComponent> topButtons;
  ScopedPointer<ImageComponent> launchSpinner;
  Array<Image> launchSpinnerImages;
  LaunchSpinnerTimer launchSpinnerTimer;
  Component* defaultPage;
 

  OwnedArray<Component> pages;
  ScopedPointer<PageStackComponent> pageStack;
  HashMap<String, Component *> pagesByName;

  bool resize = false;

  StretchableLayoutManager categoryButtonLayout;

  LauncherComponent(const var &configJson);
  ~LauncherComponent();

  void paint(Graphics &) override;
  void resized() override;
  
  void showLaunchSpinner();
  void hideLaunchSpinner();

private:
  Colour bgColor;

  void buttonClicked(Button *) override;
  
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LauncherComponent)
};
