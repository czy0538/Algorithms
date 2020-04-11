#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
int calculate(vector<int> num, int comp)
{
	if (comp != 1 && comp != 0)
	{
		throw "use wrong compare type";
	}
	while (num.size() > 2)
	{
		vector<int>::iterator itr;
		int t1, t2;
		switch (comp)
		{
		case 0:
			itr = max_element(num.begin(), num.end());
			t1 = *itr;
			num.erase(itr);
			itr = max_element(num.begin(), num.end());
			t2 = *itr;
			num.erase(itr);
			break;
		case 1:
			itr = min_element(num.begin(), num.end());
			t1 = *itr;
			num.erase(itr);
			itr = min_element(num.begin(), num.end());
			t2 = *itr;
			num.erase(itr);
			break;
		}

		num.push_back(t1 * t2 + 1);
	}
	return num.at(0) * num.at(1) + 1;
}
int main()
{
	vector<int> num = { 1,2,3,4 };
	try
	{
		cout << calculate(num, 1) - calculate(num, 0) << endl;
	}
	catch (const char* e)
	{
		cerr << e << endl;
	}
	
	return 0;
}