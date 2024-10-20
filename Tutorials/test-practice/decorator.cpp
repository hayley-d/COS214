/**
* Component defines a interface for text.
*/
class Text {
public:
    std::string text;

    virtual void addText(std::string& t) = 0;
    virtual void displayText() = 0;
};

/**
* Concrete Component.
*/
class TypedText : public Text {
public:
    void addText(std::string& t) override {
        this->text += t;
    }

    void displayText() override {
        std::cout << text;
    }
};

/**
* Decorator for the text class
*/
class TextDecorator : public Text{
protected:
    Text* text;
public:
    virtual void addStyle() = 0;
};

class BoldTextDecorator : public TextDecorator{
public:
    void addText(std::string& t) override {
        this->text->addText(t); 
    }

    void displayText() override {
        std::cout << "<strong>" << text << "</strong>";
    }

    void addStyle() override{
        std::cout << "Making text bold\n";
    }
};
