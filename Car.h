#pragma once


#include <vector>
#include <string>
#include "LeakedObjectDetector.h"

#define PASSENGER_COEFF 0.5

struct Car
{
    Car(std::string name_, double speed_, unsigned long passengers_);

    void memberFunc();
    double getSpeed();
    void calculateAndPrintRisk();
    std::string getName();
    unsigned long getPassengers();
    
    JUCE_LEAK_DETECTOR(Car)
    
private:
    std::string name;
    double speed{0};
    unsigned long passengers;
    std::vector<double> passengerRiskArray;
    std::vector<double> riskCoeffArray = {0.5, 0.7, 0.8, 0.8, 0.9};
};

