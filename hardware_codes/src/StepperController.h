#ifndef STEPPER_CONTROLLER_H
#define STEPPER_CONTROLLER_H

#include <Arduino.h>
#include "GyverStepper2.h"
#include "IStepperController.h"

class StepperController : public IStepperController {
private:
    GStepper2<STEPPER4WIRE>& stepper;

public:
    StepperController(GStepper2<STEPPER4WIRE>& stepper) : stepper(stepper) {
        stepper.setMaxSpeed(300);
        stepper.setAcceleration(0);
        stepper.enable();
    }

    void moveToAngle(int angle) override {
        stepper.setTargetDeg(angle, ABSOLUTE);
    }

    void tick() override {
        stepper.tick();
    }
};

#endif // STEPPER_CONTROLLER_H