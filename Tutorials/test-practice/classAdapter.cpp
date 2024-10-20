
class OldSystem {
public:
     void legacyOperation() {
        //do something
    }
};

class NewSystem {
public:
    virtual void newOperation() {
        // do something new
    }
};

class OldToNewAdapter : public OldSystem, public NewSystem {
public:
    void newOperation() override {
        legacyOperation();
    }
};

