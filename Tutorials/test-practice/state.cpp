/**
* The State interface that defines the state method.
*/
class Mood {
    public:
        virtual void interact() = 0;
        virtual ~Mood() = default;
};

/**
* The concrete state of the Mood.
* Defines how the mood handles a given situation.
*/
class HangryMood : public Mood {
public:
    void interact() override {
        std::cout << "I'm HANRGY!\n";
    }
};

class HappyMood : public Mood {
public:
    void interact() override {
        std::cout << "I'm so happy :)\n";
    }
};

/**
* The context class is the class that the mood is applied to.
*/
class Person {
private:
    Mood* mood;
public:
    Person(Mood* mood) : mood(mood){}

    void setMood(Mood* mood) {
        delete this->mood;
        this->mood = mood;
    }

    void interact() {
        this->mood->interact();
    }
};
