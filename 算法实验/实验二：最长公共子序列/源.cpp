#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <ctime>

using namespace std;
using Time = chrono::system_clock::time_point;
using microseconds = chrono::microseconds;
constexpr int Min = 100;    //序列最小长度
constexpr int Max = 100;   //序列最大长度
constexpr int Num = 10;    //每个序列个数
constexpr int Times = 1; //测试次数

int longestCommonSubsequence(string text1, string text2);
void RecursionLCS(const string& str1, const string& str2, string& lcs);
double timeMeasure(Time start, Time end);

int main()
{
	//随机数产生
	random_device rd;  // 将用于为随机数引擎获得种子
	mt19937 gen(rd()); // 以播种标准 mersenne_twister_engine
	uniform_int_distribution<> dis(1, 4);
	vector<string> data;
	//产生序列
	for (int i = Min; i < Max+1; ++i)
	{
		for (int j = 0; j < Num; ++j)
		{
			string s;
			for (int n = 0; n < i; ++n)
			{
				switch (dis(gen))
				{
				case 1:
					s += "A";
					break;
				case 2:
					s += "G";
					break;
				case 3:
					s += "C";
					break;
				case 4:
					s += "T";
					break;
				}
			}
			data.push_back(s);
		}
	}

	uniform_int_distribution<> r(0, data.size() - 1);
	double t1 = 0, t2 = 0;
	for (int i = 0; i < Times; ++i)
	{
		string text1 = data[r(gen)];
		string text2 = data[r(gen)];
		cout << "第" << i << "次测试，两个序列分别为" << endl
			<< "s1=" << text1 << endl
			<< "s2=" << text2 << endl;

		auto start = chrono::system_clock::now();
		cout << longestCommonSubsequence(text1, text2) << endl;
		auto end = chrono::system_clock::now();
		cout << "动态规划算法时间：" << endl;
		t1 += timeMeasure(start, end);
		start = chrono::system_clock::now();
		string ans;
		RecursionLCS(text1, text2, ans);
		cout << ans.size() << endl;
		end = chrono::system_clock::now();
		cout << "暴力算法时间：" << endl;
		t2 += timeMeasure(start, end);
		cout << "动态规划算法总计消耗时间：" << t1 << endl;
		cout << "暴力算法总计消耗时间：" << t2 << endl;
	}

	return 0;
}
int longestCommonSubsequence(string text1, string text2)
{
	//初始化
	vector<vector<int>> dp;
	for (int i = 0; i < text1.size(); i++)
	{
		vector<int> t;
		t.resize(text2.size(), 0);
		dp.push_back(t);
	}

	for (int i = 0; i < text1.size(); i++)
	{
		for (int j = 0; j < text2.size(); j++)
		{
			if (text1[i] == text2[j])
			{
				if (i == 0 || j == 0)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				if (i == 0 && j == 0)
					dp[i][j] = 0;
				else if (i == 0)
					dp[i][j] = dp[i][j - 1];
				else if (j == 0)
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	return dp[text1.size() - 1][text2.size() - 1];
}

string GetLongestString(string a, string b, string c)
{
	string longest;
	if (a.size() > b.size())
	{
		longest = a;
	}
	else
	{
		longest = b;
	}
	if (longest.size() > c.size())
		return longest;
	else
		return c;
}
void RecursionLCS(const string& str1, const string& str2, string& lcs)
{
	if (str1.size() == 0 || str2.size() == 0)
		return;
	if (str1[0] == str2[0])
	{
		lcs += str1[0];
		RecursionLCS(str1.substr(1), str2.substr(1), lcs);
	}
	else
	{
		string strTmp1, strTmp2, strTmp3;
		RecursionLCS(str1.substr(1), str2, strTmp1);
		RecursionLCS(str1, str2.substr(1), strTmp2);
		RecursionLCS(str1.substr(1), str2.substr(1), strTmp3);
		lcs += GetLongestString(strTmp1, strTmp2, strTmp3);
	}
}
double timeMeasure(Time start, Time end)
{
	auto duration = chrono::duration_cast<microseconds>(end - start);
	double t = double(duration.count()) * microseconds::period::num / microseconds::period::den;
	cout << "花费了"
		<< t
		<< "秒" << endl;
	return t;
}