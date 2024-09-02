#ifndef ITERATOR_H
#define ITERATOR_H

#include "FarmUnit.h"

class FarmUnit;

class Iterator {
public:
    /**
    * @brief Initializes the iterator and returns the first FarmUnit in the traversal.
    *
    * @return FarmUnit* Pointer to the first FarmUnit in the traversal.
    */
    virtual FarmUnit *firstFarm() = 0;

    /**
     * @brief Returns the current FarmUnit in the traversal.
     *
     * @return FarmUnit* Pointer to the current FarmUnit.
     */
    virtual FarmUnit *currentFarm() = 0;

    /**
     * @brief Checks if the traversal is complete.
     *
     * @return true if the traversal is done, false otherwise.
     */
    virtual bool isDone() = 0;

    /**
     * @brief Moves the iterator to the next FarmUnit in the traversal.
     *
     * @return FarmUnit* Pointer to the next FarmUnit.
     */
    virtual FarmUnit *next() = 0;

    /**
     * @brief destructor for the Farm Iterator
     */
    virtual ~Iterator() = default;


};

#endif //ITERATOR_H
