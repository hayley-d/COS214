#ifndef TRAVERSALSTRATEGY_H
#define TRAVERSALSTRATEGY_H
#include "FarmUnit.h"

/**
 * @brief Interface for traversal strategies.
 *
 * This class defines the interface for different traversal strategies
 * BFS or DFS that can be used to traverse a collection of FarmUnit objects.
 */
class TraversalStrategy {
public:
    /**
    * @brief Virtual destructor for the TraversalStrategy.
    */
    virtual ~TraversalStrategy() = default;

    /**
     * @brief Initializes the traversal starting from the root FarmUnit.
     *
     * @param root The root FarmUnit from which the traversal should start.
     */
    virtual void initialize(FarmUnit *root) = 0;

    /**
     * @brief Returns the next FarmUnit in the traversal.
     *
     * @return FarmUnit* Pointer to the next FarmUnit, or nullptr if traversal is done.
     */
    virtual FarmUnit *getNext() = 0;

    /**
     * @brief Checks if the traversal is complete.
     *
     * @return true if the traversal is done, false otherwise.
     */
    virtual bool isDone() const = 0;
};

#endif //TRAVERSALSTRATEGY_H
