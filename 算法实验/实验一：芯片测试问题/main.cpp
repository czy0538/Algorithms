#include<iostream>
#include"Chip.h"
#include<vector>
#include<random>
#include<chrono>
using namespace std;
using Time = chrono::system_clock::time_point;
using microseconds = chrono::microseconds;
//芯片产生
void createData(vector<Chip>& chips, size_t n);
//蛮力法
void forceMethod(vector<Chip>& chips);
//奇数偶数判断,奇数返回true
bool isOdd(size_t n);
//分治算法
Chip Divide_Conquer(vector<Chip> chips);
void DC(vector<Chip>& chips);
//时间测试结果
void timeMeasure(Time start,Time end );
int main()
{
	vector<Chip> chips;
	createData(chips, 10086);
	Chip c(true);
	//验证数据集的正确性
	/*cout << chips.size() << endl;
	for (auto i : chips)
	{
		if (c.test(i))
			cout << "true" << endl;
		else cout << "false" << endl;
	}*/
	auto start = chrono::system_clock::now();
	forceMethod(chips);
	auto end = chrono::system_clock::now();
	timeMeasure(start, end);
	start = chrono::system_clock::now();
	DC(chips);
	end = chrono::system_clock::now();
	timeMeasure(start, end);
	return 0;
}

void createData(vector<Chip>& chips, size_t n)
{
	size_t bad = n / 4;//坏芯片
	size_t good = n - bad + 1;//好芯片
	size_t bad_count = 0, good_count = 0;//芯片计数

	//均匀分布随机数发生器创建
	mt19937 rd;
	rd.seed(std::random_device()());
	uniform_int_distribution<mt19937::result_type> num(1, n);
	//测试芯片生成，顺序完全随机
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
	//分奇偶设置好坏标准
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
		if (flag)//如果已经有好的芯片了就用这片测试剩余芯片
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
			for (size_t j = 0; j < chips.size(); ++j)//不能自己测试自己
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
	cout << "好的芯片共" << good.size() << endl;
	cout << "坏的芯片共" << bad.size() << endl;
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
				temp.push_back(chips.at(i));//两片都好任留一片
		}
		if (isOdd(k))//奇数情况
		{
			size_t good_count = 0, bad_count = 0;
			size_t good_door = (k - 1) / 2;
			size_t bad_door = (k + 1) / 2;

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
					break;//坏芯片淘汰
				}
				else if (good_count >= good_door)
				{
					return chips.at(k - 1);//好芯片直接返回
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
	cout << "好的芯片共" << good.size() << endl;
	cout << "坏的芯片共" << bad.size() << endl;
}

void timeMeasure(Time start, Time end)
{
	auto duration = chrono::duration_cast<microseconds>(end - start);
	cout << "花费了"
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den
		<< "秒" << endl;
}
