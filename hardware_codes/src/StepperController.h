#ifndef STEPPER_CONTROLLER_H
#define STEPPER_CONTROLLER_H

#include <Arduino.h>
#include "GyverStepper2.h"
#include "IStepperController.h"

// StepperController class implementing IStepperController
class StepperController : public IStepperController {
private:
    GStepper2<STEPPER4WIRE>& stepper;  // Reference to the stepper motor object

public:
    // Constructor to initialize StepperController with a stepper motor
    StepperController(GStepper2<STEPPER4WIRE>& stepper) : stepper(stepper) {
        stepper.setMaxSpeed(300);
        stepper.setAcceleration(0);
        stepper.enable();
    }

    // Function to move stepper to a specified angle
    void moveToAngle(int angle) override {
        stepper.setTargetDeg(angle, ABSOLUTE);
    }

    // Function to update the stepper state
    void tick() override {
        stepper.tick();
    }
};

#endif // STEPPER_CONTROLLER_H
