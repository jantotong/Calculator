#include <iostream>
#include <string>
#include "Node.h"
#include "HeadNode.h"
#include "Stack.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Calculator.h"

using namespace std;

Calculator::Calculator() {
	expression = "";
}

Calculator::Calculator(string input) {
	 expression = input;
}

string Calculator::InfixToPostfix() {
	Stack<char> *stackptr;
	stackptr = new Stack<char>();
	Queue<char> *queueptr;
	queueptr = new Queue<char>();
	int size = 0;

	//when we get to 'B' we know we are at the Bottom
	stackptr->push('B');
	int len = expression.length();
	
	for (int i = 0; i < len; i++) {
		if (expression[i] == ' ')continue;
		size++;
		if (isOperand(expression[i]) == true) {
			while (precedence(stackptr->stackTop()) >= precedence(expression[i]) && stackptr->stackTop() != '(') {
				queueptr->enqueue(stackptr->stackTop());
				stackptr->pop();
			}
			stackptr->push(expression[i]);
		}
		/*
			else if (expression[i] == ')') {
		while (stackptr->stackTop() != '(') {
		queueptr->enqueue(stackptr->stackTop());
		stackptr->pop();
		}
		stackptr->pop();
		}
		*/
		else {
			queueptr->enqueue(expression[i]);
		}
	}
	
	while (stackptr->stackTop() != 'B') {
		queueptr->enqueue(stackptr->stackTop());
		stackptr->pop();
	}
	for (int i = 0; i < size; i++) {
		output += queueptr->front();
		queueptr->dequeue();
	}

	delete stackptr;
	delete queueptr;
	
	return output;
}

string Calculator::InfixToPrefix() {
	return expression;
}

int Calculator::precedence(char op) {
	switch (op) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	}
		return -1;
}

bool Calculator::isOperand(char chr) {
	switch (chr) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case'^':
		return true;
	}
		return false;
}

string Calculator::reverse() {
	string newE="";
	int len = expression.length();
	for (len; len >= 0; len--) {
		newE += expression[len];
	}
	expression = newE;
	return expression;
}