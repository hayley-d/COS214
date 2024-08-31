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

private:
 std::queue<FarmUnit *> queue; ///< Queue used for BFS Traversal
};


#endif //BFSSTRATEGY_H
