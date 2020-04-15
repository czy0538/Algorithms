#include<iostream>
#include"Chip.h"
#include<vector>
#include<random>
using namespace std;
//芯片产生
void createData(vector<Chip>& chips, int n);
int main()
{
	Chip c(false);
	long long t = 0, f = 0;
	for (int i = 0; i < 10000; ++i)
	{
		if (test(c))
			t++;

		else
			f++;
	}
	cout << t << " " << f << endl;
	vector<Chip> chips;
	createData(chips, 10000);
	cout << chips.size() << endl;
	return 0;
}

void createData(vector<Chip>& chips, int n)
{
	int bad = n / 3;//坏芯片
	int good = n - bad + 1;//好芯片
	int bad_count = 0, good_count = 0;//芯片计数

	//均匀分布随机数发生器创建
	mt19937 rd;
	rd.seed(std::random_device()());
	uniform_int_distribution<mt19937::result_type> num(1, n);
	//测试芯片生成，顺序完全随机
	for (int i = 0; i < n; ++i)
	{
		if (num(rd) < bad && bad_count < bad)
		{
			bad_count++;
			chips.push_back(Chip(false));
		}
		else if (good_count < good)
		{
			good_count++;
			chips.push_back(Chip(true));
		}
		else
		{
			--i;
		}
	}

	cout << "the number of good chips:" << good_count << endl;
	cout << "the number of bad chips:" << bad_count << endl;

}
