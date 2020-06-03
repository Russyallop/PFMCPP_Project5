

#pragma once

#include "Car.h"
#include "Motorbike.h"
#include "Lorry.h"
#include "Motorway.h"

struct CarWrapper
{
    CarWrapper( Car* carPtr_);
    ~CarWrapper();

    Car* carPtr = nullptr;
};

struct MotorbikeWrapper
{
    MotorbikeWrapper( Motorbike* MotorbikePtr_);
    ~MotorbikeWrapper();

    Motorbike* motorbikePtr = nullptr;
};

struct LorryWrapper
{
    LorryWrapper( Lorry* LorryPtr_);
    ~LorryWrapper();
    
    Lorry* lorryPtr = nullptr;
};

struct MotorwayWrapper
{
    MotorwayWrapper(Motorway* motorway_);
    ~MotorwayWrapper();
    
    Motorway* motorwayPtr;
};
