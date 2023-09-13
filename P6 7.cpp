//编写一个模板函数mismatch，返回值是使不等式a[i]!=b[i]成立的最小索引i，0<=i<n
#include<iostream>

using namespace std;
template<typename T>//模板声明
int mismatch(const T *a,const T*b,int n) {//加const使函数更安全
	for (int i=0; i < n; i++)
		if (a[i] != b[i])
			return i;
	return -1;//都相等

}

int main() {
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,3,0,5 };
	int n = sizeof(arr1) / sizeof(arr1[0]);//计算数组的元素个数n
	int index = mismatch(arr1, arr2, n);
	cout << index;
	return 0;
}