#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

template <typename T>
class BinarySearch
{
public:
    BinarySearch(){};
    BinarySearch(const vector<T> &t, T target)
    {
        binarySearch(t, target);
    }

    int binarySearch(const vector<T> t, T target)
    {
        int left = 0;
        int right = t.size() - 1;//一定要为右边边
        int mid = (left + right) / 2;
        while (left <= right)
        {


            if (t[mid] > target)
            {
                right = mid - 1;
            }
            else if (t[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }

            mid = left + ((right - left) >> 1);//>>的级别比+低

        }
        return -1;
    }
};

int main()
{
    default_random_engine e;
    e.seed(time(0));
    uniform_int_distribution<int> r(1, 50);
    vector<int> t;
    for (int i = 0; i < 10; ++i)
    {
        t.push_back(r(e));
    }
    t.push_back(233);
    sort(t.begin(), t.end());
    for (const auto &i : t)
    {
        cout << i << endl;
    }
    BinarySearch<int> test;
    cout << test.binarySearch(t, 33);
}
