#include<iostream>
#include<vector>
using namespace std;

//例3-1 杨辉三角
void fun1();
//例3-2 内存移动问题
void fun2();

int main()
{
	//fun1();
	fun2();
	return 0;
}

void fun1()
{
	vector<vector<int>> num;
	//初始化
	num.push_back(vector<int>(1));
	num.push_back(vector<int>(2, 1));
	int n;
	cin >> n;
	if (n < 2)
	{
		cout << "error" << endl;
		return;
	}
	for (int i = 2; i < n; ++i)
	{
		vector<int> layer;
		layer.push_back(1);
		num.push_back(layer);
		for (int j = 1; j < i; ++j)
		{
			num[i].push_back(num[i - 1][j - 1] + num[i - 1][j]);
		}
		num[i].push_back(1);
	}

	for (auto i : num)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
}

//3.2
int gcd(int a, int b)
{
	int m;
	while (b != 0)
	{
		m = a % b;
		a = b;
		b = m;
	}
	return a;
}

void memory_move(int k, vector<int>& a)
{
	int n = a.size();
	int Q = gcd(n, k);
	int last, now;
	int index;
	for (int i = 0; i < Q; ++i)
	{
		last = a[i];
		index = i;
		for (int j = 0; j < n / Q; ++j)
		{
			index = (index + k) % n;
			now = a[index];
			a[index] = last;
			last = now;
		}
	}
}

void show(const vector<int>& col)

{
	for (auto i : col)
	{
		cout << i << " ";
	}
}
void fun2()
{
	vector<int> col = { 1,2,3,4,5,6,7,8,9,10 };
	memory_move(5, col);
	show(col);
}