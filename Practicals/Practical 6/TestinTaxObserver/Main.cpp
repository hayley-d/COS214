#include "Building.h"
#include "Citizen.h"
#include "TaxAuthority.h"
#include "BuildingIterator.h"
#include "BuildingCollection.h"
#include "TaxStrategy.h"
#include "FlatTaxStrategy.h"
int main() {
    std::shared_ptr<TaxAuthority> taxAuth = std::make_shared<TaxAuthority>();
    
    // Create Buildings
    std::shared_ptr<Building> b1 = std::make_shared<Building>(100,taxAuth); 
    taxAuth->registerBuilding(b1);
    std::shared_ptr<Building> b2 = std::make_shared<Building>(100,taxAuth);
    taxAuth->registerBuilding(b2);
    std::shared_ptr<Building> b3 = std::make_shared<Building>(100,taxAuth);
    taxAuth->registerBuilding(b3);
    std::shared_ptr<Building> b4 = std::make_shared<Building>(100,taxAuth);
    taxAuth->registerBuilding(b4);
    taxAuth->collectTaxes();

    return 0;
}
