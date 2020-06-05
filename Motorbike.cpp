#include "Motorbike.h"

#include <iostream>

Motorbike::Motorbike(std::string name_, double speed_, unsigned long passengers_) : name(name_), speed(speed_), passengers(passengers_)
{
    for(size_t i = 0; i < passengers; ++i)
    {
        passengerRiskArray.push_back(0);
    }
}
    
    
void Motorbike::memberFunc()
{
    std::cout << "\nMotorbike [Motorbike name]: " << this->name << ", traveling at [Motorbike getSpeed()]:" << this->getSpeed() << "mph, has the following risk report when carrying [Motorbike passengers]: " << this->passengers << " passengers: \n" << std::endl;
    this->calculateAndPrintRisk();
}

double Motorbike::getSpeed()
{
    return speed;
}

void Motorbike::calculateAndPrintRisk()
{
    for(size_t i = 0; i < passengerRiskArray.size(); ++i)
    {
        passengerRiskArray[i] = riskCoeffArray[i] * speed * passengerRiskArray.size() * PASSENGER_COEFF;
        std::cout << "Risk to passenger " << i + 1 << " is: " << passengerRiskArray[i] << " measured in fatalities per million journeys\n"<< std::endl;
    }
}
std::string Motorbike::getName()
{
    return name;
}

unsigned long Motorbike::getPassengers()
{
    return passengers;
}
