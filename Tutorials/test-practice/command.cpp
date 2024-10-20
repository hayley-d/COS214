/**
 * Reciever -Car recieves commands from buttons pushed.
 */
class Car {
public:
    void turnOn() {
        std::cout << "Turned car on\n";
    }

    void turnOff() {
        std::cout << "Turn car off\n";
    }

    void startEngine() {
        std::cout << "Starting engine\n";
    }
};

class Button {
public:
    Car* tesla;

    virtual void execute() = 0;
};

class OnButton : public Button {
public:
    void execute() {
        tesla->turnOn();
    }
};

class OffButton : public Button {
public:
    void execute() override {
        tesla->turnOff();
    }
};

class EngineButton : public Button {
public:
    void execute() override {
        tesla->startEngine();
    }
};

/**
* Invoker - The user of the commands.
*/
class Remote {
public:
    Button* on;
    Button* engine;
    Button* off;

    Remote() {
        on = new OnButton();
        off = new OffButton();
        engine = new EngineButton();
    }
    void turnOn() {
        on->execute();
    }

    void turnEngineOn() {
        engine->execute();
    }

    void turnOff() {
        off->execute();
    }
};
