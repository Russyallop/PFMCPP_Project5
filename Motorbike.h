

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "LeakedObjectDetector.h"

#define PASSENGER_COEFF 0.5

struct Motorbike
{
    Motorbike(std::string name_, double speed_, unsigned long passengers_);
    
    void memberFunc();
    double getSpeed();
    void calculateAndPrintRisk();
    std::string getName();
    unsigned long getPassengers();
    
    JUCE_LEAK_DETECTOR(Motorbike)
    
private:
    std::string name;
    double speed{0};
    unsigned long passengers;
    std::vector<double> passengerRiskArray;
    std::vector<double> riskCoeffArray = { 1.85, 1.95};
};

