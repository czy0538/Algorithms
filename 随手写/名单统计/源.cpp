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
		cout << "����ѧ���ļ���:";
		cin >> idFile;
		cout << "���������ļ���:";
		cin >> dataFile;

	}
};