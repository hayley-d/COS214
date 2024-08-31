#ifndef BFSSTRATEGY_H
#define BFSSTRATEGY_H

#include <queue>

#include "TraversalStrategy.h"

class BFSStrategy : public TraversalStrategy {
public:
    /**
     * @brief Initializes the BFS traversal starting from the root FarmUnit.
     *
     * @param root The root FarmUnit from which BFS should start.
     */
    void initialize(FarmUnit *root) override;

    /**
     * @brief Returns the next FarmUnit in the BFS traversal.
     *
     * @return FarmUnit* Pointer to the next FarmUnit, or nullptr if traversal is done.
     */
    FarmUnit *getNext() override;

    /**
     * @brief Checks if the BFS traversal is complete.
     *
     * @return true if the traversal is done, false otherwise.
     */
    bool isDone() const override;

    /**
    * @brief destructor for BFS Strategy
    */
    ~BFSStrategy() override = default;

private:
    /**
      * @brief Comparison function for the priority queue to prioritize farms by surface area.
      */
    struct CompareSurfaceArea {
        /**
         * @brief Compares the surface area of two FarmUnits.
         *
         * @param a Pointer to the first FarmUnit.
         * @param b Pointer to the second FarmUnit.
         * @return True if the first FarmUnit has a larger surface area than the second.
         */
        bool operator()(FarmUnit *a, FarmUnit *b) {
            return a->getSurfaceArea() > b->getSurfaceArea(); // Min-heap: smallest surface area first
        }
    };


    std::priority_queue<FarmUnit *> queue; ///< Queue used for BFS Traversal
};


#endif //BFSSTRATEGY_H
