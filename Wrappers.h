

#pragma once

// #include "Car.h"
// #include "Motorbike.h"
// #include "Lorry.h"
#include "Motorway.h" FIXME you're not using this here. don't include it

struct Car;
struct Motorbike;
struct Lorry;
struct Motorway;

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
    MotorwayWrapper(Motorway* motorwayPtr_);
    ~MotorwayWrapper();
    
    Motorway* motorwayPtr = nullptr;
};
