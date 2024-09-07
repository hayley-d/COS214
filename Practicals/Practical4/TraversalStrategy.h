#ifndef TRAVERSALSTRATEGY_H
#define TRAVERSALSTRATEGY_H
#include "FarmUnit.h"
#include <vector>
class FarmUnit;

/**
 * @brief Abstract base class for traversal strategies.
 *
 * This class defines the interface for various traversal strategies, such as
 * Breadth-First Search (BFS) or Depth-First Search (DFS), that can be used
 * to traverse a collection of `FarmUnit` objects.
 */
class TraversalStrategy {
    typedef std::shared_ptr<FarmUnit> FarmUnitPtr; ///< Type alias for shared pointer to FarmUnit.
    typedef std::vector<std::shared_ptr<FarmUnit> > FarmUnitPtrVector;
    ///< Type alias for vector of shared pointers to FarmUnit.

public:
    /**
    * @brief Virtual destructor for the `TraversalStrategy` class.
    *
    * Ensures proper cleanup of derived classes.
    */
    virtual ~TraversalStrategy() = default;

    /**
     * @brief Initializes the traversal starting from the root `FarmUnit`.
     *
     * @param farmUnits A vector of shared pointers to the children of the root `FarmUnit`.
     */
    virtual void initialize(FarmUnitPtrVector* farmUnits) = 0;

    /**
     * @brief Returns the next `FarmUnit` in the traversal.
     *
     * @return FarmUnitPtr A shared pointer to the next `FarmUnit`, or `nullptr` if traversal is complete.
     */
    virtual FarmUnitPtr getNext() = 0;

    /**
     * @brief Checks if the traversal is complete.
     *
     * @return `true` if the traversal is done, `false` otherwise.
     */
    virtual bool isDone() const = 0;

    /**
    * @brief Checks if there is another `FarmUnit` to traverse.
    *
    * @return `true` if there are more `FarmUnit` objects to traverse, `false` otherwise.
    */
    virtual bool hasNext() = 0;
};

#endif //TRAVERSALSTRATEGY_H
