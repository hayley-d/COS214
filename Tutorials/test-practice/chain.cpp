/**
* Handler Interface.
*/
class CommandHandler {
public:
    CommandHandler* successor;

    CommandHandler(CommandHandler* s) : successor(s){}

    virtual void execute(const std::string& command){
        if(successor) {
            successor->execute(command);
        } else {
            std::cout << "Command not available\n";
        }
    }; 
};

/**
* Concrete Handler
*/
class LsCommand : public CommandHandler{
public:
    LsCommand(CommandHandler* s) : CommandHandler(s) {}

    void execute(const std::string& command) override {
        if(command == "ls") {
            std::cout << "executing\n";
        } else if(successor) {
            successor->execute(command);
        } else {
            std::cout << "Command not available\n";
        }
    }

};

/**
* Concrete Handler
*/
class cdCommand : public CommandHandler{
public:
    cdCommand(CommandHandler* s) : CommandHandler(s) {}

    void execute(const std::string& command) override {
        if(command == "cd") {
            std::cout << "executing\n";
        } else if(successor) {
            successor->execute(command);
        } else {
            std::cout << "Command not available\n";
        }
    }

};
