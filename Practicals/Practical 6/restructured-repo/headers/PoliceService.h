#ifndef POLICESERVICE_H
#define POLICESERVICE_H

#include "Service.h"
#include "PoliceState.h"
#include "BuildingType.h"
#include <set>
#include <vector>


/**
 * @brief Represents a police service building.
 *
 * ConcreteProduct participant in the Factory Method pattern. It extends the Service class and represents a specific type of service building that provides police services.
 */
class PoliceService : public Service {
private:
    PoliceState* policeState;  ///< Current state of the police service.
    std::vector<Citizen*> officers;  ///< List of officers in the police service.
    int responseTime;

public:
    /**
     * @brief Constructs a new PoliceService building.
     * @param cost The construction cost of the police service.
     * @param location The location of the police service.
     * @param resources Pointer to the resources the police service uses.
     * @param size The size of the police service.
     * @param owner Pointer to the owner of the police service.
     */
    PoliceService(int cost, std::string& location, Resources *resources, int size, Citizen& owner, int id,BuildingType name);

    /**
     * @brief Destroys the PoliceService building.
     */
    ~PoliceService() override = default;

    /**
     * @brief Gets details about the police service building.
     * @return A string containing details about the police service.
     */
    std::string getDetails() const override;

    /**
     * @brief Pays taxes for the police service building.
     */
    // void payTax(int amount) override;

    /**
     * @brief Sets the state of the police service.
     * @param state Pointer to the new police state.
     */
    void setState(PoliceState* state);

    /**
     * @brief Checks the operational status of the police service.
     */
    void checkOperation();

    /**
     * @brief Pays an officer in the police service.
     * @param officer Pointer to the officer being paid.
     */
    int pay() override;
/*    void employ(Citizen* employee) override;
    void fire(Citizen* employee) override;
    void retire(Citizen* employee) override;
    int getStaff();
    int getMaxStaff();*/
    void responseTimeDec(int by);
    void responseTimeInc(int by);
};

#endif // POLICESERVICE_H
