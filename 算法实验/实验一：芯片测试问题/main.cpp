#include<iostream>
#include"Chip.h"
#include<vector>
#include<random>
using namespace std;
//оƬ����
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
	int bad = n / 3;//��оƬ
	int good = n - bad + 1;//��оƬ
	int bad_count = 0, good_count = 0;//оƬ����

	//���ȷֲ����������������
	mt19937 rd;
	rd.seed(std::random_device()());
	uniform_int_distribution<mt19937::result_type> num(1, n);
	//����оƬ���ɣ�˳����ȫ���
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
