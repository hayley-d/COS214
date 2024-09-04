#ifndef BFSSTRATEGY_H
#define BFSSTRATEGY_H
#include <memory>
#include <queue>

#include "TraversalStrategy.h"

/**
 * @class BFSStrategy
 * @brief Concrete implementation of the breadth-first search (BFS) traversal strategy for farm units.
 *
 * This class implements the BFS traversal strategy, allowing traversal of farm units in a breadth-first manner.
 * It uses a priority queue to manage the traversal order based on the surface area of the farm units.
 */
class BFSStrategy : public TraversalStrategy {
 typedef std::shared_ptr<FarmUnit> FarmUnitPtr; ///< Type alias for shared pointer to FarmUnit.
 typedef std::vector<std::shared_ptr<FarmUnit>> FarmUnitPtrVector; ///< Type alias for vector of shared pointers to FarmUnit.

public:
    /**
     * @brief Initializes the BFS traversal starting from the root FarmUnit.
     *
     * @param farmUnits The children of the root farm unit. This vector is used to seed the traversal.
     */
    void initialize(FarmUnitPtrVector farmUnits) override;

    /**
     * @brief Returns the next FarmUnit in the BFS traversal.
     *
     * @return FarmUnitPtr Pointer to the next FarmUnit, or nullptr if the traversal is complete.
     */
    FarmUnitPtr getNext() override;

    /**
     * @brief Checks if the BFS traversal is complete.
     *
     * @return true if the traversal is done, false otherwise.
     */
    bool isDone() const override;

    /**
     * @brief Destructor for BFSStrategy.
     *
     * Cleans up resources used by the BFSStrategy instance.
     */
    ~BFSStrategy() override = default;

    /**
     * @brief Checks if there is a next FarmUnit to be traversed.
     *
     * @return true if there is another FarmUnit to be visited, false otherwise.
     */
    bool hasNext() override;

private:
    /**
     * @struct CompareSurfaceArea
     * @brief Comparison function for the priority queue to prioritize farms by surface area.
     *
     * This struct defines the comparison logic for the priority queue to ensure that farm units
     * with smaller surface areas are processed first.
     */
    struct CompareSurfaceArea {
     /**
      * @brief Compares the surface area of two FarmUnits.
      *
      * @param a Pointer to the first FarmUnit.
      * @param b Pointer to the second FarmUnit.
      * @return True if the surface area of the first FarmUnit is smaller than that of the second, false otherwise.
      */
        bool operator()(FarmUnitPtr &a, FarmUnitPtr &b) {
            return a->getSurfaceArea() > b->getSurfaceArea(); // Min-heap: smallest surface area first
        }
    };

 std::priority_queue<FarmUnitPtr, std::vector<FarmUnitPtr>, CompareSurfaceArea> queue; ///< Queue used for BFS Traversal.
};


#endif //BFSSTRATEGY_H
