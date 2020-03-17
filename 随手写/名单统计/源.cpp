#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
using ll = long long;
using namespace std;
class Statistics
{
public:
	ifstream inID, dataFile;
	ofstream outRight, outWrong;
	vector<ll> list;
	string idFile;
	string dataFile;
	Statistics()
	{
		cout << "输入学号文件名:";
		cin >> idFile;
		cout << "输入数据文件名:";
		cin >> dataFile;

	}
};