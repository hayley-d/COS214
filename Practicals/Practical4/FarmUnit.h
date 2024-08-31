#ifndef FARMUNIT_H
#define FARMUNIT_H
#include <vector>
#include <memory>
/**
 * @brief Abstract base class representing the component for the composite pattern
 *
 * The FarmUnit class serves as an interface for components of the composite pattern
 * which can have different capacities and surface areas. This class provides
 * a common interface for all farm units and enforces the implementation of
 * key methods in derived classes.
 * The class uses the PImpl (Pointer to Implementation) idiom to hide implementation
 * details and reduce compilation dependencies. The PImpl idiom is used to store
 * private data members and implementation details in a separate structure, which
 * is managed by a unique pointer.
 */
class FarmUnit {
public:
    /**
     * @brief Constructor for the `FarmUnit` class.
     *
     * Initializes a `FarmUnit` with the given total capacity and surface area.
     *
     * @param totalCapacity The total capacity of the farm unit.
     * @param surfaceArea The surface area of the farm unit.
     */
    FarmUnit(int totalCapacity, int surfaceArea);

    /**
     * @brief Gets the total capacity of the farm unit.
     *
     * This is a pure virtual function that must be implemented by derived classes.
     *
     * @return The total capacity of the farm unit.
     */
    virtual int getTotalcapacity() = 0;

    /**
     * @brief Gets the surface area of the farm unit.
     *
     * This is a pure virtual function that must be implemented by derived classes.
     *
     * @return The surface area of the farm unit.
     */
    virtual int getSurfaceArea() = 0;

    /**
     * @brief Gets the list of child farm units (if any exist)
     *
     * This method returns a vector of pointers to the child farm units. If the
     * current farm unit is a leaf node (i.e., has no children), this function
     * should return an empty vector.
     *
     * @return A vector of pointers to the child farm units.
     */
    virtual std::vector<FarmUnit *> getFarms() = 0;

    /**
     * @brief Virtual destructor for the `FarmUnit` class.
     *
     * Ensures proper cleanup of derived classes.
     */
    virtual ~FarmUnit() = default;

private:
    /// The PImpl idiom for managing private implementation details.
    struct pImplFarmUnit;
    /// Unique pointer to the implementation details of the `FarmUnit`.
    std::unique_ptr<pImplFarmUnit> impl;
};
#endif //FARMUNIT_H
