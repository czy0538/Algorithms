#pragma once
class Chip
{
private:
	bool tag;
public:
	friend bool test(Chip chip);
	Chip(bool tag);
};
bool test(Chip chip);