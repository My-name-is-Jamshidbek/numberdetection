#ifndef I_STEPPER_CONTROLLER_H
#define I_STEPPER_CONTROLLER_H

class IStepperController {
public:
    virtual void moveToAngle(int angle) = 0;
    virtual void tick() = 0;
};

#endif // I_STEPPER_CONTROLLER_H