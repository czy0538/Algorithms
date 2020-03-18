#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
using namespace std;
void BigMultiplication()
{
	
	//ÊäÈë
	string a_t, b_t;
	getline(cin, a_t);
	getline(cin, b_t);
	//·­×ª
	a_t.reserve();
	b_t.reserve();
	//×ª»»
	vector<int> a, b;
	for (auto i : a_t)
	{
		a.push_back(i - '0');
	}
	for (auto i : b_t)
	{
		b.push_back(i - '0');
	}
	vector<int> ans (a.size()+b.size()+1,0);
	int len = a.size() - 1;
	for (int i = 0; i < b.size(); ++i)
	{
		int d = 0,sum;
		for (int j = 0; j < a.size(); ++j)
		{
			int temp = a[j] * b[i] + d;
			sum = ans[i + j] + temp % 10;
			ans[i + j] = sum % 10;
			d = temp / 10 + sum / 10;
		}
		len = i + a.size() - 1;
		if (d)
		{
			++len;
			ans[len] += d;
		}
	}
	for (int i = 0; i <= len; ++i)
	{
		cout << ans[i];
	}
	cout << endl;
	
}
int main()
{
	BigMultiplication();
}
