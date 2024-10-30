#ifndef EDUCATIONSTATE_H
#define EDUCATIONSTATE_H

#include <string>
#include <iostream>
using namespace std;

/**
 * @brief Abstract class representing the state of education services.
 *
 * AbstractState in the State pattern, defining the interface for various education service states. Concrete states will implement specific behaviors for managing education service operations based on funding levels.
 */
class EducationState {
protected:
    string name;
public:
    /**
     * @brief Constructs a new EducationState object.
     */
    EducationState();

    /**
     * @brief Destroys the EducationState object.
     */
    virtual ~EducationState() = default;

    /**
     * @brief Checks the current state of education services.
     * This method must be implemented by concrete states to provide specific education state information.
     */
    virtual void checkEducationState() = 0;

    /**
     * @brief Gets the quality of education in the current state.
     * This method must be implemented by concrete states to define the quality level of education services.
     * @return int The quality level of education.
     */
    virtual int getEducationQuality() = 0;
    virtual string getName() = 0;
};

#endif // EDUCATIONSTATE_H