// Forward declaration
class Plane;

/**
* Mediator component that defines an AirTrafficControlTower that relays messages from planes.
*/
class AirTrafficControlTower {
public:
    std::vector<Plane*> planes;

    void requestTakeOff(Plane* p) {
        p->notify(true);
    }

    void requestLanding(Plane* p) {
        p->notify(true);
    }
};

class Plane {
public:
    AirTrafficControlTower* tower;

    void requestTakeOff() {
        tower->requestTakeOff(this);
    }

    void requestLanding() {
        tower->requestLanding(this);
    }

    bool notify(bool response) {
        return response;
    }
};

class CommercialPlane : public Plane {
};
