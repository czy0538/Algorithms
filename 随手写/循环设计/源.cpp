//ppt ��һ��ѭ����Ʋ���
#include<iostream>
#include<vector>
#include<random>
using namespace std;

//����1.3
void fun1();
//����1.4
void fun2();
//����1.6�������������
void fun3(int m, int n,vector<int>& num);
void fun3_1();
int main()
{
	fun3_1();

	return 0;
}

void fun1()
{
	int num[3][3];
	int temp = 0;
	//������������
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			num[i][j] = temp++;
			cout << num[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//����������ξ���
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cout << num[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//�������Խ������
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3 - i; ++j)
		{
			cout << num[i + j][j] << " ";
		}
		cout << endl;
	}

}

void fun2()
{
	int n = 5;
	long double num = 0;
	unsigned long long temp = 1.0;
	int sign = -1;
	for (int i = 3; i <= n; i += 2)
	{
		temp = temp * (i - 1) * i;
		num += 1.0 / temp * sign;
		sign *= -1;
	}
	cout << num << endl;

}


void fun3(int m,int n,vector<int>& num)
{
	
	for (int i = m; i >= n; i--)
	{
		num[n] = i;
		if (n > 1)
		{
			fun3(i - 1, n - 1, num);
		}
		else
		{
			for (int j = num[0]; j > 0; --j)
			{
				cout << num[j] << " ";
			}
			cout << endl;
		}
	}
	
}

void fun3_1()
{
	vector<int> num;
	int m, n;
	cin >> m >> n;
	num.resize(n + 1, 0);
	num[0] = n;
	fun3(m, n, num);
}
