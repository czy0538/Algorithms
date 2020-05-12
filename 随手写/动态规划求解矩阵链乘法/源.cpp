#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int fun1(const vector<int>& matrixChain);
int main()
{
	vector<int> matrixChain = { 30,35,15,5,10,20,25 };
	cout << fun1(matrixChain) << endl;
}
int fun1(const vector<int>& matrixChain)
{
	int current = INT_MAX;
	if (matrixChain.size() < 3)
		return 0;
	else if (matrixChain.size() == 3)
	{
		current = 1;
		for (auto i : matrixChain)
		{
			current *= i;
		}
		return current;
	}
	else
	{
		for (int i = 1; i < matrixChain.size() - 1; ++i)
		{
			auto t_matrix = matrixChain;
			int c = matrixChain.at(i - 1) * matrixChain.at(i) * matrixChain.at(i + 1);
			t_matrix.erase(t_matrix.begin() + i);
			int temp = c + fun1(t_matrix);
			if (temp < current)
			{
				current = temp;
			}
		}
		return current;
	}
}