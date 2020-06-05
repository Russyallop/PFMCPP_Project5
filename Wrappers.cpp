
#include "Wrappers.h"

#include "Car.h"
#include "Motorbike.h"
#include "Lorry.h"
#include "Motorway.h"


    
CarWrapper::CarWrapper( Car* carPtr_) : carPtr( carPtr_) {}
CarWrapper::~CarWrapper()
{
    delete carPtr;
}

MotorbikeWrapper::MotorbikeWrapper( Motorbike* MotorbikePtr_) : motorbikePtr( MotorbikePtr_) {}MotorbikeWrapper::~MotorbikeWrapper()
{
    delete motorbikePtr;
}

LorryWrapper::LorryWrapper( Lorry* LorryPtr_) : lorryPtr( LorryPtr_) {}
LorryWrapper::~LorryWrapper()
{
    delete lorryPtr;
}

MotorwayWrapper::MotorwayWrapper(Motorway* motorwayPtr_) : motorwayPtr(motorwayPtr_) {}
MotorwayWrapper::~MotorwayWrapper()
{
    delete motorwayPtr;
}

