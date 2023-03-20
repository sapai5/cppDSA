#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <sstream>

/*
* Written by: Sahil Pai
* This is a shunting yard algorithm that puts integers on one side and operators on another side.
* Used the wikipedia linked to help write this.
*/

using namespace std;

//Binary tree
struct Node {
    char op;
    double num;
    Node* left;
    Node* right;
};

//create new node
Node* newNode(char op, double num) {
    Node* node = new Node;
    node->op = op;
    node->num = num;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//check if operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '%' || c == '^' || c == '!');
}

int getPrecedence(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '%' || c == '^' || c == '!') {
        return 1;
    }
    else {
        return 0;
    }
}

void shuntingYard(char input[40]) {
    //make stack
    stack<char> opStack;
    queue<Node*> outputQueue;
    stringstream ss(input);
    string token;
    while (getline(ss, token, ' ')) {
        //if number...
        if (isdigit(token[0])) {
            double num;
            stringstream(token) >> num;
            outputQueue.push(newNode('\0', num));
        }
        //if operator...
        else if (isOperator(token[0])) {
            char op = token[0];
            while (!opStack.empty() && isOperator(opStack.top()) && getPrecedence(op) <= getPrecedence(opStack.top())) {
                outputQueue.push(newNode(opStack.top(), 0));
                opStack.pop();
            }
            opStack.push(op);
        }
    }
    while (!opStack.empty()) {
        outputQueue.push(newNode(opStack.top(), 0));
        opStack.pop();
    }
    stack<Node*> evalStack;
    while (!outputQueue.empty()) {
        Node* node = outputQueue.front();
        outputQueue.pop();
        if (node->op == '\0') {
            evalStack.push(node);
        }
        else {
            Node* right = evalStack.top();
            evalStack.pop();
            Node* left = evalStack.top();
            evalStack.pop();
            node->left = left;
            node->right = right;
            evalStack.push(node);
        }
    }
    //eval postfix
    Node* root = evalStack.top();
    evalStack.pop();
    stack<Node*> printStack;
    printStack.push(root);
    while (!printStack.empty()) {
        Node* node = printStack.top();
        printStack.pop();
        if (node->op == '\0') {
            cout << node->num << " ";
        }
        else {
            cout << node->op << " ";
            printStack.push(node->right);
            printStack.push(node->left);
        }
    }
}

int main() {
    //string input = "3 + 2 + 5 - 4 * 5 - 3 ^ 2 + 5";
    char input[40];
    cout << "Enter your expression, seperating each character with a space." << endl;
    cin.getline(input, 100);
    shuntingYard(input);
    return 0;
}
    