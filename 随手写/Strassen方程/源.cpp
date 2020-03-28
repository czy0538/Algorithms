#include<iostream>
#include<vector>
using namespace std;

vector<int> operator+(const vector<int>& a, const vector<int>& b)
{
	size_t num = a.size();
	vector<int> c(num, 0);
	for (int i = 0; i < num; ++i)
		c[i] = a[i] + b[i];
	return c;
}
vector<int> operator-(const vector<int>& a, const vector<int>& b)
{
	size_t num = a.size();
	vector<int> c(num, 0);
	for (int i = 0; i < num; ++i)
		c[i] = a[i] - b[i];
	return c;
}
vector<int> mul(vector<int> a, vector<int> b, int n)
{
	int i, j, k;
	if (n == 1)
	{
		vector<int> c;
		c.push_back(a[0] * b[0]);
		return c;
	}
	else if (n == 2)
	{
		vector<int> c(4, 0);
		c[0] = a[0] * b[0] + a[1] * b[2];
		c[1] = a[0] * b[1] + a[1] * b[3];
		c[2] = a[2] * b[0] + a[3] * b[2];
		c[3] = a[2] * b[1] + a[3] * b[3];
		return c;
	}
	else
	{
		vector<int> c(n * n, 0);
		int s = n / 2;
		int v = s * s;
		vector<int> a00(v, 0), a01(v, 0), a10(v, 0), a11(v, 0);
		vector<int> b00(v, 0), b01(v, 0), b10(v, 0), b11(v, 0);
		int i, j;
		for (i = 0; i < s; ++i)
			for (j = 0; j < s; ++j)
			{
				a00[i * s + j] = a[i * n + j];
				a01[i * s + j] = a[i * n + j + s];
				a10[i * s + j] = a[s * n + i * n + j];
				a11[i * s + j] = a[s * n + i * n + j + s];
				b00[i * s + j] = b[i * n + j];
				b01[i * s + j] = b[i * n + j + s];
				b10[i * s + j] = b[s * n + i * n + j];
				b11[i * s + j] = b[s * n + i * n + j + s];
			}

		vector<int> m1 = mul(a00 + a11, b00 + b11, s);
		vector<int> m2 = mul(a10 + a11, b00, s);
		vector<int> m3 = mul(a00, b01 - b11, s);
		vector<int> m4 = mul(a11, b10 - b00, s);
		vector<int> m5 = mul(a00 + a01, b11, s);
		vector<int> m6 = mul(a10 - a00, b00 + b01, s);
		vector<int> m7 = mul(a01 - a11, b10 + b11, s);

		vector<int> c00 = m1 + m4 + m7 - m5;
		vector<int> c01 = m3 + m5;
		vector<int> c10 = m2 + m4;
		vector<int> c11 = m1 + m3 + m6 - m2;

		for (i = 0; i < s; ++i)
			for (j = 0; j < s; ++j)
			{
				c[i * n + j] = c00[i * s + j];
				c[i * n + j + s] = c01[i * s + j];
				c[s * n + i * n + j] = c10[i * s + j];
				c[s * n + i * n + j + s] = c11[i * s + j];
			}
		return c;
	}
}


int main()
{
	vector<int> a, b;
	vector<int> c;
	int i, j;
	int n;
	cin >> n;
	int temp;
	cout << "请输入第一个方阵：" << endl;
	for (int i = 0; i < n * n; ++i)
	{
		cin >> temp;
		a.push_back(temp);
	}
	cout << "请输入第二个方阵：" << endl;
	for (int i = 0; i < n * n; ++i)
	{
		cin >> temp;
		b.push_back(temp);
	}

	c = mul(a, b, n);
	cout << "运算结果" << endl;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
			cout << c[i * n + j] << " ";
		cout << endl;
	}
	return 0;
}
