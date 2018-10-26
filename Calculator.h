#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
using namespace std;
class Calculator {
	protected:

	public:
		Calculator();
		Calculator(string input);
		int precedence(char op);
		bool isOperand(char chr);
		string InfixToPostfix();
		string reverse();
		string InfixToPrefix();
		string output;
		string expression;
};
#endif
