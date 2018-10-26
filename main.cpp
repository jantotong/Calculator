	#include <iostream>
	#include <string>
	#include "Calculator.h"

	//Group Members: Haddar Goldstein and Jan To Tong

	int main()
	{
		Calculator calc("6/8-6*5-7*7+2"); //Input expression here
		cout << "Infix:" << endl;
		cout << calc.expression << endl;
		cout << "Infix to Postfix:" << endl;
		calc.InfixToPostfix();
		cout << calc.output << endl;
		system("pause");
	};
