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
		stack<char> operatorStack;//������ջ
		string postfix;//��¼��׺���ʽ
		
		for (int i = 0; i < infix.length(); i++) {
			char c = infix[i];
			if (c == ' ') {
				// �����ո��ַ�
				continue;
			}
			if (isdigit(c)) {//�����֣�ֱ�Ӽ����׺���ʽ
				postfix += c;
			}
			else if (c == '(') {//'('ֱ����ջ
				operatorStack.push(c);
			}
			else if (c == ')') {
				while (!operatorStack.empty() && operatorStack.top() != '(') {//�������ڵķ���ȫ������
					postfix += operatorStack.top();
					operatorStack.pop();
				}
				
				if (!operatorStack.empty() && operatorStack.top() == '(') {
					operatorStack.pop(); // ���� '('
				}
				else {

					cout << "���Ų�ƥ��" << endl;
					exit(1);
				}
			}
			
			else {//�ǼӼ��˳�
				while (!operatorStack.empty() && Precedence(operatorStack.top()) >= Precedence(c)) {
					postfix += operatorStack.top();
					operatorStack.pop();
				}
				operatorStack.push(c);
			}
		}

		while (!operatorStack.empty()) {
			if (operatorStack.top() == '(' || operatorStack.top() == ')') {
				cout << "���Ų�ƥ��" << endl;
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
	cout << "��׺���ʽ: " << infixExpression << endl;
	cout << "��׺���ʽ: " << postfixExpression << endl;
}

