
#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "LeakedObjectDetector.h"

#include "Car.h"
#include "Motorbike.h"
#include "Lorry.h"

#define CAR_ON_MOTORWAY_COEFF 0.2
#define MOTORBIKE_ON_MOTORWAY_COEFF 0.6
#define LORRY_ON_MOTORWAY_COEFF 0.1

struct Motorway
{
    void addCar(Car* car);
    void addMotorBike(Motorbike* motorbike);
    void addLorry(Lorry* lorry);
    void calculateAndPrintChanceOfAccident();
    
    JUCE_LEAK_DETECTOR(Motorway)

private:
    std::vector<Car> carsArray;
    std::vector<Motorbike> motorbikesArray;
    std::vector<Lorry> lorriesArray;
    double chanceOfAccident;
};



