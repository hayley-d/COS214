#ifndef FARMITERATOR_H
#define FARMITERATOR_H
#include "Iterator.h"
#include "TraversalStrategy.h"
#include <vector>
class TraversalStrategy;
/**
 * @brief Iterator for traversing a collection of `FarmUnit` objects using a specified traversal strategy.
 *
 * The `FarmIterator` class provides an interface for traversing a collection of `FarmUnit` objects
 * using different traversal strategies, such as Breadth-First Search (BFS) or Depth-First Search (DFS).
 */
class FarmIterator : public Iterator {
    typedef std::shared_ptr<FarmUnit> FarmUnitPtr; ///< Type alias for shared pointer to FarmUnit.
    typedef std::vector<std::shared_ptr<FarmUnit> > FarmUnitPtrVector;
    ///< Type alias for vector of shared pointers to FarmUnit.
public:
    /**
     * @brief Constructor for `FarmIterator` with a specified traversal strategy.
     *
     * @param strategy Pointer to the traversal strategy to use (BFS or DFS).
     * @param farms Vector of shared pointers to `FarmUnit` objects to traverse.
     */
    FarmIterator(std::shared_ptr<TraversalStrategy> strategy, FarmUnitPtrVector *farms);

    /**
      * @brief Constructor for `FarmIterator` with default DFS strategy.
      * @param farms Vector of shared pointers to `FarmUnit` objects to traverse.
      */
    FarmIterator(FarmUnitPtrVector *farms);

    /**
     * @brief Initializes the iterator and returns the first `FarmUnit` in the traversal.
     *
     * @return FarmUnitPtr Shared pointer to the first `FarmUnit` in the traversal.
     */
    FarmUnitPtr firstFarm() override;

    /**
     * @brief Returns the current `FarmUnit` in the traversal.
     *
     * @return FarmUnitPtr Shared pointer to the current `FarmUnit`.
     */
    FarmUnitPtr currentFarm() override;

    /**
     * @brief Checks if the traversal is complete.
     *
     * @return `true` if the traversal is done, `false` otherwise.
     */
    bool isDone() override;

    /**
     * @brief Moves the iterator to the next `FarmUnit` in the traversal.
     *
     * @return FarmUnitPtr Shared pointer to the next `FarmUnit`.
     */
    FarmUnitPtr next() override;

    /**
     * @brief Checks if there is another `FarmUnit` to traverse.
     *
     * @return `true` if there are more `FarmUnit` objects to traverse, `false` otherwise.
     */
    bool hasNext() override;

    /**
      * @brief Pre-increment operator to advance the iterator.
      *
      * @return Reference to the current `FarmIterator` after advancing.
      */
    FarmIterator &operator++();

    /**
     * @brief Post-increment operator to advance the iterator.
     *
     * @param int Unused parameter (int to differentiate from pre-increment).
     * @return FarmIterator Copy of the iterator before advancing.
     */
    FarmIterator operator++(int);

    /**
      * @brief Dereference operator to access the current `FarmUnit`.
      *
      * @return Reference to the current `FarmUnit`.
      */
    FarmUnitPtr &operator*();

    /**
     * @brief Arrow operator to access members of the current `FarmUnit`.
     *
     * @return FarmUnitPtr Pointer to the current `FarmUnit`.
     */
    FarmUnitPtr operator->();

    /**
     * @brief Equality comparison operator.
     *
     * @param other Reference to another `FarmIterator`.
     * @return `true` if the current `FarmIterator` is equal to `other`, `false` otherwise.
     */
    bool operator==(const FarmIterator &other) const;

    /**
      * @brief Inequality comparison operator.
      *
      * @param other Reference to another `FarmIterator`.
      * @return `true` if the current `FarmIterator` is not equal to `other`, `false` otherwise.
      */
    bool operator!=(const FarmIterator &other) const;

    /**
     * @brief Assignment operator to assign another `FarmIterator` to the current one.
     *
     * @param other Reference to another `FarmIterator`.
     * @return Reference to the current `FarmIterator`.
     */
    FarmIterator &operator=(const FarmIterator &other);

    /**
     * @brief Returns an iterator to the beginning of the traversal.
     *
     * @return FarmIterator iterator to the beginning.
     */
    FarmIterator begin();

    /**
     * @brief Returns an iterator to the end of the traversal.
     *
     * @return FarmIterator iterator to the end.
     */
    FarmIterator end();

    ~FarmIterator() override = default;

    FarmIterator(const FarmIterator &other) {
        this->strategy = other.strategy;
        this->farms = other.farms;
        this->current = other.current;
    }

private:
    std::shared_ptr<TraversalStrategy> strategy; ///< Pointer to the traversal strategy (BFS or DFS).
    FarmUnitPtr current; ///< Pointer to the current FarmUnit in the traversal.
    FarmUnitPtrVector *farms; ///< Vector of shared pointers to `FarmUnit` objects.
};

#endif //FARMITERATOR_H
