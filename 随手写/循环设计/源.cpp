//ppt 第一章循环设计部分
#include<iostream>
#include<vector>
#include<random>
using namespace std;

//例题1.3
void fun1();
//例题1.4
void fun2();

int main()
{
	fun1();
	return 0;
}

void fun1()
{
	int num[3][3];
	int temp = 0;
	//测试数据生成
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
	//输出下三角形矩阵
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cout << num[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//按照主对角线输出
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
	int n = 10;
	long double num = 0;
	unsigned long long temp = 1.0;
	int sign = 1;
	for (int i = 2; i <= n; i+=2)
	{
			
	}


}