
#include "Lorry.h"

Lorry::Lorry(std::string name_, double speed_, unsigned long passengers_) : name(name_), speed(speed_), passengers(passengers_)
{
    for(size_t i = 0; i < passengers; ++i)
    {
        passengerRiskArray.push_back(0);
    }
        
}   
    
void Lorry::memberFunc()
{
    std::cout << "\nLorry [Lorry name]: " << this->name << ", traveling at [Lorry getSpeed()]:" << this->getSpeed() << "mph, has the following risk report when carrying [Lorry passengers]: " << this->passengers << " passengers: \n" << std::endl;
    this->calculateAndPrintRisk();
}

double Lorry::getSpeed()
{
    return speed;
}

void Lorry::calculateAndPrintRisk()
{
    for(size_t i = 0; i < passengerRiskArray.size(); ++i)
    {
        passengerRiskArray[i] = riskCoeffArray[i] * speed * passengerRiskArray.size() * PASSENGER_COEFF;
        std::cout << "Risk to passenger " << i + 1 << " is: " << passengerRiskArray[i] << " measured in fatalities per million journeys\n"<< std::endl;
    }
}
std::string Lorry::getName()
{
    return name;
}

unsigned long Lorry::getPassengers()
{
    return passengers;
}
