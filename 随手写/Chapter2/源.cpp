#include<iostream>
#include<vector>
using namespace std;

//2-11,方阵乘法
void fun2_11();

int main()
{
	fun2_11();
	return 0;
}

void fun2_11()
{
	vector<vector<int>> A = { {1,2,3},{4,5,6},{7,8,9} };
	vector<vector<int>> B = { {1,0,0},{0,1,0},{0,0,1} };
	vector<vector<int>> C(3);
	
	if (A.size() == B.size())
	{
		for (int i = 0; i < A.size(); ++i)
		{
			for (int j = 0; j < A.size(); ++j)
			{
				C[i].push_back(0);//vector处理手法上和数组不同
				for (int k = 0; k < A.size(); ++k)
				{
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
	}
	else
		return;
	for (auto i : C)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
}