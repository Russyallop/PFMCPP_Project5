#include "Car.h"

Car::Car(std::string name_, double speed_, unsigned long passengers_) : name(name_), speed(speed_), passengers(passengers_)
{
    for(size_t i = 0; i < passengers; ++i)
    {
        passengerRiskArray.push_back(0);
    }       
}
    
void Car::memberFunc()
{
    std::cout << "\nCar [Car name]: " << this->name << ", traveling at [Car getSpeed()]:" << this->getSpeed() << "mph, has the following risk report when carrying [Car passengers]: " << this->passengers << " passengers: \n" << std::endl;
    this->calculateAndPrintRisk();
}

double Car::getSpeed()
{
    return speed;
}

void Car::calculateAndPrintRisk()
{
    for(size_t i = 0; i < passengerRiskArray.size(); ++i)
    {
        passengerRiskArray[i] = riskCoeffArray[i] * speed * passengerRiskArray.size() * PASSENGER_COEFF;
        std::cout << "Risk to passenger " << i + 1 << " is: " << passengerRiskArray[i] << " measured in fatalities per million journeys\n"<< std::endl;
    }
}

std::string Car::getName()
{
    return name;
}

unsigned long Car::getPassengers()
{
    return passengers;
}

