/**
 * Enum defining different colours for the sheep
 */
enum Colour {
    Pink,
    Blue,
    Brown,
    White,
    Green
};

/**
 * Prototype class that defines the clone method of different sheep on the farm.
*/
class Sheep {
    std::string name;
public:
    virtual Sheep* clone() = 0;
    void setName(std::string& name) {
        this->name = name;
    }

    std::string& getName() {
        return this->name;
    }
};

/**
 * Concrete prototype class defining a pink sheep.
*/
class PinkSheep : public Sheep {
protected:
    std::string name;
    int age;
    int weight;
    double woolQuality;
    Colour colour = Pink;

public:
    PinkSheep(PinkSheep& sheep){
        this->name = sheep.name;
        this->age = sheep.age;
        this->weight = sheep.weight;
        this->woolQuality = sheep.woolQuality;
        this->colour = sheep.colour;
    }

    PinkSheep* clone() override {
        return new PinkSheep(*this);
    }


};

class BlueSheep : public Sheep {
protected:
    std::string name;
    int age;
    int weight;
    double woolQuality;
    Colour colour = Pink;

public:
    BlueSheep(BlueSheep& sheep){
        this->name = sheep.name;
        this->age = sheep.age;
        this->weight = sheep.weight;
        this->woolQuality = sheep.woolQuality;
        this->colour = sheep.colour;
    }

    BlueSheep* clone() override {
        return new BlueSheep(*this);
    }
};


