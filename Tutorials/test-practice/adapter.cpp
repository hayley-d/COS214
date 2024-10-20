/**
 * Windows game is the target interface.
 */
class WindowsGame {
public:
    virtual void playGame(){
        std::cout << "Playing game\n";
    }

    virtual void updateGame() {
        std::cout << "Updating game\n";
    }
};

/**
 * Adaptee of the system.
 */
class LinuxGame {
public:
    virtual void play() {
        std::cout << "Playing game with difficulty";
    }

    virtual void update() {
        std::cout << "update game\n";
    }
};

class WindowsGameAdapter : public WindowsGame {
public:
    LinuxGame* linux;

    WindowsGameAdapter() {
        linux = new LinuxGame();
    }
    void playGame() override {
        linux->play();
    }

    void updateGame() override {
        linux->update();
    }
};


/**
* Client of the pattern.
*/
class Player {
public:
    WindowsGame* game;
    Player() {
        game = new WindowsGameAdapter();
    }
    void playGame() {
        game->playGame();
    }

};
