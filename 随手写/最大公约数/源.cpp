#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int fun1(int a, int b)
{
	int count = 0;
	int r;
	if (a < b)
	{
		r = a;
	}
	else
	{
		r = b;
	}
	while (0 != a % r || 0 != b % r)
	{
		--r;
		++count;
	}
	//cout << "f1:" << count << endl;
	return count;
}

int fun2(int a, int b)
{
	if (a < b)
	{
		swap(a, b);
	}
	int r = a % b;
	int count=0;
	while (r)
	{
		a = b;
		b = r;
		r = a % b;
		++count;
	}
	//cout << "f2:" << count << endl;
	return count;
}

int fun3()
{
	vector<int> num;
	while (!cin.eof())
	{
		int temp;
		cin >> temp;
		num.push_back(temp);
	}
	switch (num.size())
	{
	case 1:
	case 0:
		cerr << "ÊäÈë´íÎó" << endl;
		break;
	default:
		int t;
		t = fun2(num[0], num[1]);
		for (int i = 2; i < num.size()&&t!=1; ++i)
		{
			t = fun2(t, num[i]);
		}
		cout << t << endl;
		break;
	}
}
int main()
{
	int f1Count = 0, f2Count = 0;
	for (int i = 3; i < 14; ++i)
	{
		for (int j = 2; j < i; ++j)
		{
			f1Count += fun1(i, j);
			f2Count += fun2(i, j);
		}
	}
	cout << "f1:" << f1Count << endl;
	cout << "f2:" << f2Count << endl;
	return 0;
}