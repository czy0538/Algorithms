#include "Chip.h"
#include<random>

bool Chip::test(Chip chip)
{
	if (this->tag)
		return chip.tag;
	else
	{
		//伯努利分布，模拟坏芯片随机给出芯片的好坏
		std::random_device rd;
		std::mt19937 gen(rd());
		// 1/2 时间给出 "true"
		// 1/2 时间给出 "false"
		std::bernoulli_distribution d(0.5);
		return d(gen);
	}
}

Chip::Chip(bool tag)
{
	this->tag = tag;
}