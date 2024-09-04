#ifndef FARMITERATOR_H
#define FARMITERATOR_H
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
     * @param farms The child nodes to traverse
     */
    FarmIterator(TraversalStrategy *strategy, std::vector<std::shared_ptr<FarmUnit>> farms);

   /**
    * @brief Constructor for FarmIterator with default DFS strategy
    *
    * @param farms The child nodes to traverse
    */
   FarmIterator(std::vector<std::shared_ptr<FarmUnit>> farms);

    /**
     * @brief Initializes the iterator and returns the first FarmUnit in the traversal.
     *
     * @return FarmUnit* Pointer to the first FarmUnit in the traversal.
     */
    std::shared_ptr<FarmUnit> firstFarm() override;

    /**
     * @brief Returns the current FarmUnit in the traversal.
     *
     * @return FarmUnit* Pointer to the current FarmUnit.
     */
    std::shared_ptr<FarmUnit> currentFarm() override;

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
    std::shared_ptr<FarmUnit> next() override;

    /**
     * @brief Checks is the traversal is finished
     *
     * @return Boolean value indicating false if done traversal otherwise true.
     */
     bool hasNext() override;

   /**
    * @brief Pre-increment operator to advance the iterator.
    *
    * @return Reference to the current FarmIterator after advancing.
    */
    FarmIterator & operator++() ;

    /**
     * @brief Post-increment operator to advance the iterator.
     *
     * @return FarmIterator Copy of the iterator before advancing.
     */
    FarmIterator operator++(int);

   /**
    * @brief Dereference operator to access the current FarmUnit.
    *
    * @return Reference to the current FarmUnit.
    */
    FarmUnit & operator*() ;

    /**
     * @brief Arrow operator to access members of the current FarmUnit.
     *
     * @return Pointer to the current FarmUnit.
     */
    std::shared_ptr<FarmUnit> operator->() ;

    /**
     * @brief Equality comparison operator.
     *
     * @param other Reference to another FarmIterator.
     * @return true if the current FarmIterator is equal to other, otherwise false.
     */
    bool operator==(FarmIterator &other) ;

   /**
    * @brief Inequality comparison operator.
    *
    * @param other Reference to another FarmIterator.
    * @return true if the current FarmIterator is not equal to other, otherwise false.
    */
    bool operator!=(FarmIterator &other) ;

    /**
     * @brief Assignment operator to assign another FarmIterator to the current one.
     *
     * @param other Reference to another FarmIterator.
     * @return Reference to the current FarmIterator.
     */
    FarmIterator & operator=(FarmIterator &other) ;

private:
    TraversalStrategy *strategy; ///< Pointer to the traversal strategy (BFS or DFS).
    std::shared_ptr<FarmUnit> current; ///< Pointer to the current FarmUnit in the traversal.
    std::shared_ptr<FarmUnit> root; ///< Root FarmUnit
};

#endif //FARMITERATOR_H
