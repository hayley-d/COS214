/**
 * Product class defines the interface for a Protien product.
 */
class Protien {
public:
    virtual void someFunction() = 0;
};

/**
* Creator class defines the factory method for the concrete factories to implement.
*/
class ProtienFactory {
public:
    virtual Protien* makeProtien() = 0;
};

/**
* Concrete Product vanillaProtien is protien with vanilla flavour.
*/
class VanillaProtien : public Protien{
public:
    void someFunction() override {};
};

/**
* Concrete creator VanillaFactory.
*/
class VanillaProtienFactory : public ProtienFactory{
public:
    Protien* makeProtien() override {
        return new VanillaProtien();
    }
};
