#ifndef FARMITERATOR_H
#define FARMITERATOR_H
#include "BFSStrategy.h"
#include "Iterator.h"
#include "TraversalStrategy.h"
/**
 * @brief Iterator for traversing a collection of FarmUnit objects using a specified traversal strategy.
 *
 * The FarmIterator class provides an interface to traverse a collection of FarmUnit objects
 * using different traversal strategies such as BFS or DFS.
 */
class FarmIterator : public Iterator {
public:
    /**
     * @brief Constructor for FarmIterator.
     *
     * @param strategy Pointer to the traversal strategy to use (BFS or DFS).
     * @param root Root of the composite to traverse
     */
    FarmIterator(TraversalStrategy *strategy, FarmUnit *root);

    /**
     * @brief Initializes the iterator and returns the first FarmUnit in the traversal.
     *
     * @return FarmUnit* Pointer to the first FarmUnit in the traversal.
     */
    FarmUnit *firstFarm() override;

    /**
     * @brief Returns the current FarmUnit in the traversal.
     *
     * @return FarmUnit* Pointer to the current FarmUnit.
     */
    FarmUnit *currentFarm() override;

    /**
     * @brief Checks if the traversal is complete.
     *
     * @return true if the traversal is done, false otherwise.
     */
    bool isDone() override;

    /**
     * @brief Moves the iterator to the next FarmUnit in the traversal.
     *
     * @return FarmUnit* Pointer to the next FarmUnit.
     */
    FarmUnit *next() override;

    /**
    * @brief destructor for the Farm Iterator
    */
    virtual ~FarmIterator() = default;

private:
    TraversalStrategy *strategy; ///< Pointer to the traversal strategy (BFS or DFS).
    FarmUnit *current; ///< Pointer to the current FarmUnit in the traversal.
    FarmUnit *root; ///< Root FarmUnit, initialized elsewhere.
};

#endif //FARMITERATOR_H
