/**
* The parent class that defines the template method, invariant method and variant methods for how drinks are prepared.
*/
 class Drink {
public:
    void makeDrink() {
        boilWater();
        addMilk();
        stir();
        addSugar();
        addSnack();
    };

    void boilWater(); // invariant method
    virtual void addMilk(); //optional method
    void stir();
    virtual void addSugar() = 0;
    virtual void addSnack() = 0;
 };

class Tea : public Drink {
public:
    std::string type;

    void addMilk() override {
        std::cout << "You don't add milk to tea...\n";
    };

    void addSugar() override {
       if(type == "Floral") {
            std::cout << "No sugar is needed for floral tea\n";
        } else {
            std::cout << "Sugar is added\n";
        }
    }

    void addSnack() override {
        std::cout << "Tea is had with a scone\n";
    }
};

class Coffee : public Drink {
public:

    void addSugar() override {
        std::cout << "Sugar is added\n";
    }

    void addSnack() override {
        std::cout << "Coffee is had with a slice of cake\n";
    }
};
