//��дһ��ģ�庯��mismatch������ֵ��ʹ����ʽa[i]!=b[i]��������С����i��0<=i<n
#include<iostream>

using namespace std;
template<typename T>//ģ������
int mismatch(const T *a,const T*b,int n) {//��constʹ��������ȫ
	for (int i=0; i < n; i++)
		if (a[i] != b[i])
			return i;
	return -1;//�����

}

int main() {
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,3,0,5 };
	int n = sizeof(arr1) / sizeof(arr1[0]);//���������Ԫ�ظ���n
	int index = mismatch(arr1, arr2, n);
	cout << index;
	return 0;
}