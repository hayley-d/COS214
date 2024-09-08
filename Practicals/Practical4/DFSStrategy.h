#ifndef DFSSTRATEGY_H
#define DFSSTRATEGY_H
#include "TraversalStrategy.h"
#include <stack>
#include <memory>
#include <vector>
class FarmUnit;

/**
 * @class DFSStrategy
 * @brief Concrete implementation of the depth-first search (DFS) traversal strategy for farm units.
 *
 * This class implements the DFS traversal strategy, allowing traversal of farm units in a depth-first manner.
 * It uses a stack to manage the traversal.
 */
class DFSStrategy : public TraversalStrategy {
    typedef std::shared_ptr<FarmUnit> FarmUnitPtr; ///< Type alias for shared pointer to FarmUnit.
    typedef std::vector<std::shared_ptr<FarmUnit> > FarmUnitPtrVector;
    ///< Type alias for vector of shared pointers to FarmUnit.
public:
    DFSStrategy() = default;

    /**
     * @brief Initializes the DFS traversal starting from the root FarmUnit.
     *
     * @param farmUnits The children of the root farm unit. This vector is used to seed the traversal.
     */
    void initialize(FarmUnitPtrVector* farmUnits) override;

    /**
     * @brief Returns the next FarmUnit in the DFS traversal.
     *
     * @return FarmUnitPtr Pointer to the next FarmUnit, or nullptr if the traversal is complete.
     */
    FarmUnitPtr getNext() override;

    /**
     * @brief Checks if the DFS traversal is complete.
     *
     * @return true if the traversal is done, false otherwise.
     */
    bool isDone() const override;

    /**
     * @brief Destructor for DFSStrategy.
     *
     * Cleans up resources used by the DFSStrategy instance.
     */
    ~DFSStrategy() override = default;

    /**
     * @brief Checks if there is a next FarmUnit to be traversed.
     *
     * @return true if there is another FarmUnit to be visited, false otherwise.
     */
    bool hasNext() override;


   private:
    std::stack<FarmUnitPtr> stack; ///< Stack used for DFS traversal
};


#endif //DFSSTRATEGY_H
