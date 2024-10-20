//forward declaration
class Channel;

class Subscriber {
public:
    Channel* channel;
    Subscriber(Channel* c) : channel(c) {}
    void notify() {
        std::cout << "Channel uploaded new video\n";
    }
};

/**
* subject class defines the interface for the subject.
*/
class Channel {
public:
    std::vector<Subscriber*> subs;

    void addSubscriber(Subscriber* sub) {
        subs.push_back(sub);
    }

    void removeSubscriber(Subscriber* sub) {
        //logic to remove
    }

    void notify() {
        for(Subscriber* s : subs) {
            s->notify();
        }
    }
};


/**
* Concrete subject class.
*/
class YouTubeChannel : public Channel {
public:
    YouTubeChannel() : Channel() {}
    void uploadVideo() {
        this->notify();
    }
};


