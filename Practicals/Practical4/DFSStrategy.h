#ifndef DFSSTRATEGY_H
#define DFSSTRATEGY_H

#include "TraversalStrategy.h"
#include <stack>
/**
 * @brief Implementation of the DFS (Depth-First Search) traversal strategy.
 *
 * This class implements the DFS traversal strategy for traversing FarmUnit objects.
 */
class DFSStrategy : public TraversalStrategy {
public:
    /**
     * @brief Initializes the DFS traversal starting from the root FarmUnit.
     *
     * @param root The root FarmUnit from which DFS should start.
     */
    void initialize(FarmUnit *root) override;

    /**
     * @brief Returns the next FarmUnit in the DFS traversal.
     *
     * @return FarmUnit* Pointer to the next FarmUnit, or nullptr if traversal is done.
     */
    FarmUnit *getNext() override;

    /**
     * @brief Checks if the DFS traversal is complete.
     *
     * @return true if the traversal is done, false otherwise.
     */
    bool isDone() const override;

private:
 std::stack<FarmUnit*> stack; ///< Stack used for DFS traversal
};


#endif //DFSSTRATEGY_H
