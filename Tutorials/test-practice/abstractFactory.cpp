/**
 * Abstract product class for a Button.
 */
class Button {
public:
    Button() {}
};

class LightModeButton : public Button{
};

class DarkModeButton : public Button {
};

class Background {
public:
    Background(){}
};

class LightModeBackground : public Background {
};

class DarkModeBackground : public Background {
};

/**
* Abstract factory class defines the factory methods for the related components.
*/
class UiFactory {
public:
    virtual Button* makeButton() = 0;
    virtual Background* makeBackground() = 0;
};

/**
* Concrete factory that defines how to make a class of related objects for a light mode ui.
*/
class LightModeUiFactory : public UiFactory {
public:
    Button* makeButton() override {
        return new LightModeButton();
    }

    Background* makeBackground() override {
        return new LightModeBackground();
    }
};

/**
* Concrete factory that defines how to make a class of related objects for a light mode ui.
*/
class DarkModeUiFactory : public UiFactory {
public:
    Button* makeButton() override {
        return new DarkModeButton();
    }

    Background* makeBackground() override {
        return new DarkModeBackground();
    }
};
