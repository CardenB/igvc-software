#ifndef ROBOTPOSITION_HPP
#define ROBOTPOSITION_HPP

#include <iostream>

/**
 * @brief Represents the position of the robot.
 */
class RobotPosition
{
public:

    RobotPosition() { }

    RobotPosition(double x, double y, double h) : X(x), Y(y), Heading(h) { }

    /**
     * @brief The horizontal component of the robot's positon
     */
    double X;

    /**
     * @brief The vertical component of the robot's position. Positive Y points North
     */
    double Y;

    /**
     * @brief The direction the robot is facing. (Degrees East of North, ie - clockwise)
     */
    double Heading;

    friend std::ostream &operator << (std::ostream &stream, RobotPosition &pos)
    {
        stream << "(" << pos.X << "," << pos.Y << "," << pos.Heading << ")";
        return stream;
    }
};

#endif // ROBOTPOSITION_HPP
