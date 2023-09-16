#include <iostream>
using namespace std;



class currency {
public:
	//(1) intput()从标准输出流中读取currency的值，然后赋值给调用对象
	void input() {
		string sign_string;
		cin >> sign_string >> dollars >> cents;
		if (sign_string == "+")
			sign = plus;
		else
			sign = minus;
	}
	//(2) subtract(x)从调用对象中减去参数对象x的值，然后返回结果
	currency sutract(currency& x) {
		currency result;
		if (this->sign == plus && x.sign == plus) {
			//被减数为正，减数为正
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
			//被减数为正，减数为负
			result.dollars = this->dollars + x.dollars;
			if (this->cents + x.cents > 100) {
				result.dollars++;
				result.cents = this->cents + x.cents - 100;
			}
			else result.cents = this->cents + x.cents;
			result.sign = plus;
		}
		else if (this->sign == minus && x.sign == plus) {
			//被减数为负，减数为正
			result.dollars = this->dollars + x.dollars;
			if (this->cents + x.cents > 100) {
				result.dollars++;
				result.cents = this->cents + x.cents - 100;
			}
			else result.cents = this->cents + x.cents;
			result.sign = minus;
		}
		else {
			//被减数为负，减数为负
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

	//(3)percent(x)返回一个currency类的对象，它的值是调用对象的x%。x的数据类型为double
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
	//(4)multiply(x)返回一个currency类的对象，它的值是调用对象和double型数x的乘积
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

	//(5)divide(x)返回一个currency类的对象，它的值是调用对象除以double型数x的结果
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
	signType sign;//对象的符号
	unsigned long dollars;//美元的数量
	unsigned int cents;//美分的数量
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