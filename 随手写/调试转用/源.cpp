#include<iostream>
#include<string>
#include<vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs)
{
	string ans = "";
	int p = 0;
	while (true)
	{
		for (int i = 0; i < strs.size(); ++i)
		{
			if (p >= strs[i].size())
			{
				return ans;
			}
			if (p < strs[(i + 1) % strs.size()].size() && strs[i].at(p) == strs[(i + 1) % strs.size()].at(p))
				continue;
			else
				return ans;
		}
		ans.push_back(strs[0].at(p));
		++p;
	}
	return ans;
}
int main()
{
	vector<string> strs = { "flower","flow","flight" };
	cout << longestCommonPrefix(strs)<<endl;
	return 0;
}