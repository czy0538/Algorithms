/*
author:曹志远
data:2020年3月31日12:10:40
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int MaxSequence(int left, int right, const vector<int>& num)
{
	int mid = 0;
	if (left > right)
		return 0;
	else if (left == right)
		return num[left];
	else mid = (left + right) / 2;

	//求中间子列和左半部分
	int lmax = num[mid];
	int ltemp = 0;
	for (int i = mid; i >= left; --i)
	{
		ltemp += num[i];
		if (ltemp > lmax)
			lmax = ltemp;
	}

	//求中间子列和右半部分
	int rmax = num[mid + 1];
	int rtemp = 0;
	for (int i = mid + 1; i <= right; ++i)
	{
		rtemp += num[i];
		if (rtemp > rmax)
			rmax = rtemp;
	}
	return max(max(MaxSequence(left, mid, num), MaxSequence(mid + 1, right, num)), rmax + lmax);
}
int main()
{
	vector<int> num = { -2,11,-4,13,-5,-2 };
	int ans = MaxSequence(0, num.size() - 1, num);
	if (ans < 0)
		cout << 0 << endl;
	else
		cout << ans << endl;
	return 0;
}