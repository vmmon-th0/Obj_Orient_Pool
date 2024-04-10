#ifndef CAR_HPP
#define CAR_HPP

#include "carInfos.hpp"
#include <climits>

class Car
{
  public:
    Car() : _gear(NEUTRAL), _speed(0), _wheelAngle(2), _carName("Batmobile")
    {
    }

    ~Car()
    {
    }

    void start()
    {
        std::cout << "vroummm..." << std::endl;
    }

    void stop()
    {
        std::cout << "Brmmm..." << std::endl;
    }

    void accelerate(int speed)
    {
        if (speed + _speed > MAX_BATMOBILE_SPEED)
        {
            std::cout << "MAX_BATMOBILE_SPEED reached" << std::endl;
            return;
        }
        else if (speed <= 0)
        {
            std::cout << "Zero and negative values do not affect speed." << std::endl;
            return;
        }
        _speed += speed;
        std::cout << "Batmobile speed: " << _speed << " km/h" << std::endl;
    }

    void shift_gears_up()
    {
        if (gear == FIFTH_GEAR)
        {
            std::cout << "max gear reached" << std::endl;
            return;
        }
        else if (gear == REVERSE)
        {
            std::cout << "cannot gear up in REVERSE mode" << std::endl;
            return;
        }
        _gear++;
    }

    void shift_gears_down()
    {
        if (gear == NEUTRAL)
        {
            std::cout << "min gear reached" << std::endl;
            return;
        }
        else if (gear == REVERSE)
        {
            std::cout << "cannot gear down in REVERSE mode" << std::endl;
            return;
        }
        _gear--;
    }

    void reverse()
    {
        if (gear == REVERSE)
        {
            std::cout << "already in REVERSE mode" << std::endl;
            return;
        }
        else if (gear != NEUTRAL)
        {
            std::cout << "It's strongly recommended to set NEUTRAL gear before REVERSE" << std::endl;
            return;
        }
        gear = REVERSE;
    }

    void turn_wheel(int angle)
    {
        if (angle > MAX_ WHEEL_ANGLE)
        {
            angle = MAX_WHEEL_ANGLE;
            std::cout << "Maximum wheel angle reached." << std::endl;
        }
        else if (angle < -MAX_WHEEL_ANGLE)
        {
            angle = -MAX_WHEEL_ANGLE;
            std::cout << "Minimum wheel angle reached." << std::endl;
        }
        _wheelAngle = angle;
        std::cout << "Turning wheel " << (angle > 0 ? "right" : "left") << " by " << std::abs(angle) << " degrees."
                  << std::endl;
    }

    void straighten_wheels()
    {
        if (_wheelAngle == 0)
        {
            std::cout << "Wheels are already straighten" << std::endl;
            return;
        }
        _wheelAngle = 0;
    }

    void apply_force_on_brakes(int force)
    {
        _speed = std::max(0, _speed - force);
        if (_speed == 0)
        {
            std::cout << "Car has stopped." << std::endl;
        }
        else
        {
            std::cout << "Braking... Car speed: " << _speed << " km/h" << std::endl;
        }
    }

    void apply_emergency_brakes()
    {
        apply_emergency_brakes(INT_MAX);
    }

  private:
    int _gear;
    int _speed;
    int _wheelAngle;

    std::string _carName;
}

#endif