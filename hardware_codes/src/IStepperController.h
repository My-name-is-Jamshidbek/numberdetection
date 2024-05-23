#ifndef I_STEPPER_CONTROLLER_H
#define I_STEPPER_CONTROLLER_H

// Interface for StepperController
class IStepperController {
public:
    // Pure virtual function to move stepper to a specified angle
    virtual void moveToAngle(int angle) = 0;

    // Pure virtual function for tick to update the stepper state
    virtual void tick() = 0;
};

#endif // I_STEPPER_CONTROLLER_H
