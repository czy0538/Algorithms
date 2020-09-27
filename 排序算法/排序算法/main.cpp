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
void Merge(T& a, int, int, int);
void MergeT2D(T&, int, int);
void MergeD2T(T&);
int partition(T&, int, int);
void QSort(T&, int, int);

int main()
{
	T nums{ 1,5,3,2,6,8,4 };
	show(nums);
	//SelectionSort(nums);
	//Insertion(nums);
	//InsertionX(nums);
	//Shell(nums);
	//MergeT2D(nums, 0, nums.size() - 1);
	//MergeD2T(nums);
	QSort(nums, 0, nums.size() - 1);

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
	for (int i = 0; i < nums.size() - 1; i++)
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
			int temp = nums[i];
			int j = i;
			for (; j >= h && nums[j] < nums[j - h]; j -= h)
				nums[j] = nums[j - h];
			nums[j] = temp;
		}

		h /= 3;
	}
	show(nums);
}

void Merge(T& a, int lo, int mid, int hi)
{
	T b = a;
	for (int i = lo, j = mid + 1; i <= hi; ++i)
	{
		if (lo > mid)
			a[i] = b[j++];
		else if (j > hi)
			a[i] = b[lo++];
		else if (b[lo] < b[j])
			a[i] = b[lo++];
		else
			a[i] = b[j++];

	}
	show(a);
}

void MergeT2D(T& a, int lo, int hi)
{
	if (lo >= hi) return;
	int mid = lo + (hi - lo) / 2;
	MergeT2D(a, lo, mid);
	MergeT2D(a, mid + 1, hi);
	Merge(a, lo, mid, hi);
}

void MergeD2T(T& a)
{
	for (int sz = 1; sz < a.size(); sz += sz)
	{
		for (int lo = 0; lo < a.size() - sz; lo += sz + sz)
			Merge(a, lo, lo + sz - 1, min(lo + 2 * sz - 1, (int)a.size() - 1));
	}
}

int partition(T& a, int low, int high)
{
	int i = low;
	int j = high + 1;
	while (i < j)
	{
		while (a[low] >= a[++i]) if (i == high) break;
		while (a[low] <= a[--j])if (j == low) break;
		if (i >= j) break;
		swap(a[i], a[j]);
	}
	swap(a[low], a[j]);
	show(a);
	return j;
}

void QSort(T& a, int low, int high)
{
	if (low >= high)
		return;
	int j = partition(a, low, high);
	QSort(a, low, j - 1);
	QSort(a, j + 1, high);
}

