#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

//例3-1 杨辉三角
void fun1();
//例3-2 内存移动问题
void fun2();
//
void fun3();

int main()
{
	//fun1();
	//fun2();
	fun3();
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

//大数阶乘,有问题版本，进位问题，即当进位d>9时会出现进位错误
void fun3()
{
	size_t n;
	cin >> n;
	string num="1";
	for (size_t i = 1; i <= n; ++i)
	{
		int d = 0;
		queue<int> up;
		for (size_t j = 0; j <num.size(); ++j)
		{
			int t = num[j] - '0';
			if (!up.empty())
			{
				d = up.front();
				up.pop();
			}
			
			t = t * i+d;
			d = t/10;
			while (d != 0)
			{
				int u=d % 10;
				up.push(u);
				d /= 10;

			}
			t %= 10;
			num[j] = t + '0';
		}
		
		if (!up.empty())
		{
			d = up.front();
			up.pop();
			num.push_back(d + '0');
		}
	}
	cout << num << endl;
	for (auto i = num.cend() - 1; i != num.cbegin(); --i)
	{
		cout << *i;
	}
	cout << num[0] << endl;
}