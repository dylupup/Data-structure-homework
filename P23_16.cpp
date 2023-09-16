#include <iostream>
using namespace std;



class currency {
public:
	//(1) intput()�ӱ�׼������ж�ȡcurrency��ֵ��Ȼ��ֵ�����ö���
	void input() {
		string sign_string;
		cin >> sign_string >> dollars >> cents;
		if (sign_string == "+")
			sign = plus;
		else
			sign = minus;
	}
	//(2) subtract(x)�ӵ��ö����м�ȥ��������x��ֵ��Ȼ�󷵻ؽ��
	currency sutract(currency& x) {
		currency result;
		if (this->sign == plus && x.sign == plus) {
			//������Ϊ��������Ϊ��
			result.dollars = this->dollars - x.dollars;
			if (this->cents >= x.cents) { 
				result.cents = this->cents - x.cents; 
			}
			else {
				result.dollars--;
				result.cents = this->cents - x.cents + 100;
			}
			if (this->dollars > 0)result.sign = plus;
			else result.sign = minus;
		}
		else if(this->sign==plus&&x.sign==minus){
			//������Ϊ��������Ϊ��
			result.dollars = this->dollars + x.dollars;
			if (this->cents + x.cents > 100) {
				result.dollars++;
				result.cents = this->cents + x.cents - 100;
			}
			else result.cents = this->cents + x.cents;
			result.sign = plus;
		}
		else if (this->sign == minus && x.sign == plus) {
			//������Ϊ��������Ϊ��
			result.dollars = this->dollars + x.dollars;
			if (this->cents + x.cents > 100) {
				result.dollars++;
				result.cents = this->cents + x.cents - 100;
			}
			else result.cents = this->cents + x.cents;
			result.sign = minus;
		}
		else {
			//������Ϊ��������Ϊ��
			result.dollars = this->dollars - x.dollars;
			if (this->cents >= x.cents) {
				result.cents = this->cents - x.cents;
			}
			else {
				result.dollars--;
				result.cents = this->cents - x.cents + 100;
			}
			if (this->dollars > 0)result.sign = minus;
			else result.sign = plus;
		}
		return result;
	}

	//(3)percent(x)����һ��currency��Ķ�������ֵ�ǵ��ö����x%��x����������Ϊdouble
	currency percent(double& x) {
		currency result;
		result.dollars = (unsigned long)this->dollars * x / 100;
		result.cents = (unsigned long)this->dollars * x / 100;
		if ((this->sign == plus && x > 0) || (this->sign == minus && x < 0))
			result.sign = plus;
		else
			result.sign = minus;
		return result;
	}
	//(4)multiply(x)����һ��currency��Ķ�������ֵ�ǵ��ö����double����x�ĳ˻�
	currency multiply(double& x) {
		currency result;
		double all_cents = (static_cast<double>(this->dollars) * 100 + this->cents) * x;
		result.dollars = static_cast<unsigned long>(all_cents / 100);
		result.cents = static_cast<unsigned int>(all_cents) % 100;
		if ((this->sign == plus && x > 0) || (this->sign == minus && x < 0))
			result.sign = plus;
		else
			result.sign = minus;
		return result;
	}

	//(5)divide(x)����һ��currency��Ķ�������ֵ�ǵ��ö������double����x�Ľ��
	currency divide(double& x) {
		currency result;
		double all_cents = (static_cast<double>(this->dollars) * 100 + this->cents) / x;
		result.dollars = static_cast<unsigned long>(all_cents / 100);
		result.cents = static_cast<unsigned int>(all_cents) % 100;
		if ((this->sign == plus && x > 0) || (this->sign == minus && x < 0))
			result.sign = plus;
		else
			result.sign = minus;
		return result;
	}

private:
	enum signType {plus, minus};
	signType sign;//����ķ���
	unsigned long dollars;//��Ԫ������
	unsigned int cents;//���ֵ�����
};


int main() {
	currency c1,x1;
	double x;
	c1.input();
	c1.sutract(x1);
	c1.percent(x);
	c1.multiply(x);
	c1.divide(x);
	return 0;
}