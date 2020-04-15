#include "Chip.h"
#include<random>

bool test(Chip chip)
{
	if (chip.tag)
		return true;
	else
	{
		//��Ŭ���ֲ���ģ�⻵оƬ�������оƬ�ĺû�
		std::random_device rd;
		std::mt19937 gen(rd());
		// 1/2 ʱ����� "true"
		// 1/2 ʱ����� "false"
		std::bernoulli_distribution d(0.5);
		return d(gen);
	}
}

Chip::Chip(bool tag)
{
	this->tag = tag;
}
