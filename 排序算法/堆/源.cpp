#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using T = int;
class MaxPQ
{
private:
	vector<T> pq{ 0 };
	void swim(T k);
	void sink(T k);
public:
	MaxPQ() = default;
	MaxPQ(vector<T> nums) 
	{
		for (const auto& i : nums)
		{
			insert(i);
		}
	}
	void insert(T v);
	int delMax();
	void show();
};

void MaxPQ::swim(T k)
{
	while (k > 1 && pq[k] > pq[k / 2])
	{
		swap(pq[k], pq[k / 2]);
	}
}

void MaxPQ::sink(T k)
{
	while (2 * k < pq.size())
	{
		int j = 2 * k;
		if (j < pq.size() - 1 && pq[j] < pq[j + 1]) j++;//两个儿子挑个大的
		if (pq[k] > pq[j]) break;//不用下沉
		swap(pq[k], pq[j]);
		k = j;
	}
}

void MaxPQ::insert(T v)
{
	pq.push_back(v);
	swim(pq.size() - 1);
}

int MaxPQ::delMax()
{
	auto max = pq[1];
	swap(pq[1], pq[pq.size() - 1]);
	pq.erase(pq.end() - 1);
	sink(1);
	return max;
}

void MaxPQ::show()
{
	for (const auto& i : pq)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<T> nums{ 1,2,4,5,6,7};
	MaxPQ pq(nums);
	pq.show();
	pq.insert(3);
	pq.show();
	pq.insert(10);
	pq.show();
	return 0;
}