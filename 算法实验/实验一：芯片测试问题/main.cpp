#include<iostream>
#include"Chip.h"
#include<vector>
#include<random>
using namespace std;
//оƬ����
void createData(vector<Chip>& chips, size_t n);
//������
void forceMethod(vector<Chip>& chips);
//����ż���ж�,��������true
bool isOdd(size_t n);
//�����㷨
Chip Divide_Conquer(vector<Chip> chips);
void DC(vector<Chip>& chips);
int main()
{
	vector<Chip> chips;
	createData(chips, 1000);
	Chip c(true);
	//��֤���ݼ�����ȷ��
	/*cout << chips.size() << endl;
	for (auto i : chips)
	{
		if (c.test(i))
			cout << "true" << endl;
		else cout << "false" << endl;
	}*/
	forceMethod(chips);
	DC(chips);
	return 0;
}

void createData(vector<Chip>& chips, size_t n)
{
	size_t bad = n / 3;//��оƬ
	size_t good = n - bad + 1;//��оƬ
	size_t bad_count = 0, good_count = 0;//оƬ����

	//���ȷֲ����������������
	mt19937 rd;
	rd.seed(std::random_device()());
	uniform_int_distribution<mt19937::result_type> num(1, n);
	//����оƬ���ɣ�˳����ȫ���
	for (size_t i = 0; i < n; ++i)
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

void forceMethod(vector<Chip>& chips)
{
	vector<size_t> good, bad;
	size_t good_door, bad_door;
	//����ż���úû���׼
	bool flag = isOdd(chips.size());
	if (flag)
	{
		good_door = (chips.size() - 1) / 2;
		bad_door = (chips.size() + 1) / 2;
	}
	else
	{
		good_door = chips.size() / 2;
		bad_door = chips.size() / 2 + 1;
	}
	flag = false;
	for (size_t i = 0; i < chips.size(); ++i)
	{
		if (flag)//����Ѿ��кõ�оƬ�˾�����Ƭ����ʣ��оƬ
		{
			if (chips[good[0]].test(chips[i]))
				good.push_back(i);
			else
			{
				bad.push_back(i);
			}
		}
		else
		{
			size_t good_count = 0, bad_count = 0;
			for (size_t j = 0; j < chips.size(); ++j)//�����Լ������Լ�
			{
				if (j == i)
					continue;
				if (chips[j].test(chips[i]))
				{
					++good_count;
				}
				else
				{
					++bad_count;
				}
				if (bad_count >= bad_door)
				{
					bad.push_back(i);
					break;
				}
				else if (good_count >= good_door)
				{
					flag = true;
					good.push_back(i);
					break;
				}
			}
		}
	}
	cout << "�õ�оƬ��" << good.size() << endl;
	cout << "����оƬ��" << bad.size() << endl;
}

bool isOdd(size_t n)
{
	if (n % 2 == 0)
		return false;
	else
		return true;
}

Chip Divide_Conquer(vector<Chip> chips)
{
	vector<Chip> temp;
	size_t k = chips.size();
	while (k > 3)
	{
		for (size_t i = 0; i < k - 1; i += 2)
		{
			if (chips.at(i).test(chips.at(i + 1)) and chips.at(i + 1).test(chips.at(i)))
				temp.push_back(chips.at(i));//��Ƭ��������һƬ
		}
		if (isOdd(k))//�������
		{
			int good_count = 0, bad_count = 0;
			int good_door = (chips.size() - 1) / 2;
			int bad_door = (chips.size() + 1) / 2;

			for (size_t j = 0; j < k - 1; ++j)
			{
				if (chips[j].test(chips[k - 1]))
				{
					++good_count;
				}
				else
				{
					++bad_count;
				}
				if (bad_count >= bad_door)
				{
					break;//��оƬ��̭
				}
				else if (good_count >= good_door)
				{
					return chips.at(k - 1);//��оƬֱ�ӷ���
				}
			}
		}
		chips = temp;
		k = chips.size();
	}
	if (k == 3)
	{
		if (chips.at(0).test(chips.at(1)) and chips.at(1).test(chips.at(0)))
		{
			return chips.at(0);
		}
		else
		{
			return chips.at(2);
		}
	}
	else
	{
		return chips.at(0);
	}
}

void DC(vector<Chip>& chips)
{
	auto c = Divide_Conquer(chips);
	vector<size_t> good, bad;
	for (size_t i = 0; i < chips.size(); ++i)
	{
		if (c.test(chips[i]))
		{
			good.push_back(i);
		}

		else
		{
			bad.push_back(i);
		}
	}
	cout << "�õ�оƬ��" << good.size() << endl;
	cout << "����оƬ��" << bad.size() << endl;
}