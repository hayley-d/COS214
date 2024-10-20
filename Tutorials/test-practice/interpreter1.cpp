/**
 * Context contains information needed for the interpretation of the grammar.
 */
class Context {
    // non for this example
};

/**
 * Abstract expression defines a common interface for the expressions.
 */
class Expression{
public:
    virtual int interpret(Context* c) = 0;
};

/**
 * Terminal expression defines the mosr basic expressions.
 */
class NumberExpression : public Expression {
    int number;
public:
    NumberExpression(int num) : number(num) {}
    int interpret(Context* c) override {
        return number;
    }
};

/**
 * Non-terminal expression defines more complex expressions.
 */
class AdditionExpression : public Expression {
    Expression* left;
    Expression* right;
public:
    AdditionExpression(Expression* left, Expression* right) : left(left), right(right) {}

    int interpret(Context* c) override {
        return left->interpret(c) + right->interpret(c);
    }
};

/**
 * Non-terminal expression defines more complex expressions.
 */
class MultiplicationExpression : public Expression {
    Expression* left;
    Expression* right;
public:
    MultiplicationExpression(Expression* left, Expression* right) : left(left), right(right) {}

    int interpret(Context* c) override {
        return left->interpret(c) * right->interpret(c);
    }
};

/**
 * Interpreter class.
 */
class Interpreter {
public:
    Context* context;
    Interpreter(Context* c) : context(c) {}

    int interpret(std::string& expression) {
        Expression* expressionTree = buildExpressionTree(expression);
        return expressionTree->interpret(context);
    }

    Expression* buildExpressionTree(std::string& expression) {
        return new AdditionExpression(new NumberExpression(2),new MultiplicationExpression(new NumberExpression(3),new NumberExpression(4)));
    }
};

/**
* Client provides the input to interact with the interpreter.
*/
class Client {
    int main() {
        std::string expression = "2 + 3 * 4";

        Context* context = new Context();
        Interpreter* interpreter = new Interpreter(context);

        int result = interpreter->interpret(expression);
    }
};
