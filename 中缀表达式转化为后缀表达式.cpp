#include <iostream>
#include <stack>
#include <string>
using namespace std;
template<typename T>class Evaluate
{private:
	int Precedence(char op) {
		if (op == '+' || op == '-') {
			return 1;
		}
		if (op == '*' || op == '/') {
			return 2;
		}
		return 0;
	}
public:
	string infixToPostfix(const string& infix) {
		stack<char> operatorStack;//操作符栈
		string postfix;//记录后缀表达式
		
		for (int i = 0; i < infix.length(); i++) {
			char c = infix[i];
			if (c == ' ') {
				// 跳过空格字符
				continue;
			}
			if (isdigit(c)) {//是数字，直接加入后缀表达式
				postfix += c;
			}
			else if (c == '(') {//'('直接入栈
				operatorStack.push(c);
			}
			else if (c == ')') {
				while (!operatorStack.empty() && operatorStack.top() != '(') {//将括号内的符号全部弹出
					postfix += operatorStack.top();
					operatorStack.pop();
				}
				
				if (!operatorStack.empty() && operatorStack.top() == '(') {
					operatorStack.pop(); // 弹出 '('
				}
				else {

					cout << "括号不匹配" << endl;
					exit(1);
				}
			}
			
			else {//是加减乘除
				while (!operatorStack.empty() && Precedence(operatorStack.top()) >= Precedence(c)) {
					postfix += operatorStack.top();
					operatorStack.pop();
				}
				operatorStack.push(c);
			}
		}

		while (!operatorStack.empty()) {
			if (operatorStack.top() == '(' || operatorStack.top() == ')') {
				cout << "括号不匹配" << endl;
				exit(1);
			}
			postfix += operatorStack.top();
			operatorStack.pop();
		}
		return postfix;

	}
};
int main()
{
	Evaluate<int> eint;
	string infixExpression = "3+5*(2-6)";
	string postfixExpression = eint.infixToPostfix(infixExpression);
	cout << "中缀表达式: " << infixExpression << endl;
	cout << "后缀表达式: " << postfixExpression << endl;
}

