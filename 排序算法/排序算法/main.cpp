#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
using T = vector<int>;

void show(const T&);
void SelectionSort(T);
void Insertion(T);
void InsertionX(T);
void Shell(T);

int main()
{
	vector<int> nums{ 1,5,3,2,6,8,4 };
	show(nums);
	//SelectionSort(nums);
	//Insertion(nums);
	//InsertionX(nums);
	Shell(nums);
	return 0;
}



void show(const T& nums)
{
	for (const auto i : nums)
	{
		cout << i << "	";
	}
	cout << endl;
}


void SelectionSort(T nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		int min = i;
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[j] < nums[min])
				min = j;
		}
		swap(nums[i], nums[min]);
	}
	show(nums);

}

void Insertion(T nums)
{
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j)
			swap(nums[j], nums[j - 1]);
	}
	show(nums);
}

void InsertionX(T nums)
{
	size_t exchanges = 0;
	for (int i = nums.size() - 1; i > 0; --i)
	{
		if (nums[i] < nums[i - 1])
		{
			swap(nums[i], nums[i - 1]);
			++exchanges;
		}
	}
	if (exchanges == 0)
	{
		show(nums);
		return;
	}

	for (int i = 2; i < nums.size(); ++i)
	{
		auto v = nums[i];
		int j = i;
		while (v < nums[j - 1])
		{
			nums[j] = nums[j - 1];
			--j;
		}
		nums[j] = v;
	}
	show(nums);
}

void Shell(T nums)
{
	int h = 1;
	while (h < nums.size() / 3)
		h = h * 3 + 1;
	while (h >= 1)
	{
		for (int i = h; i < nums.size(); i++)
		{
			for (int j = i; j >= h && nums[j] < nums[j - h]; j -= h)
				swap(nums[j], nums[j - h]);
		}
		h /= 3;
	}
	show(nums);
}