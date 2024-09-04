#ifndef ITERATOR_H
#define ITERATOR_H

#include "FarmUnit.h"
#include <memory>

class FarmUnit;

class Iterator {
public:
    /**
    * @brief Initializes the iterator and returns the first FarmUnit in the traversal.
    *
    * @return FarmUnit* Pointer to the first FarmUnit in the traversal.
    */
    virtual std::shared_ptr<FarmUnit> firstFarm() = 0;

    /**
     * @brief Returns the current FarmUnit in the traversal.
     *
     * @return FarmUnit* Pointer to the current FarmUnit.
     */
    virtual std::shared_ptr<FarmUnit> currentFarm() = 0;

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
    virtual std::shared_ptr<FarmUnit> next() = 0;

    /**
     * @brief destructor for the Farm Iterator
     */
    virtual ~Iterator() = default;

    /**
     * @brief Checks is the traversal is finished
     *
     * @return Boolean value indicating false if done traversal otherwise true.
     */
    virtual bool hasNext() = 0;
};

#endif //ITERATOR_H
