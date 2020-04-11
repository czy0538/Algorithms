#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Activity
{
public:
	int startTime, endTime;
	Activity()
	{
		cin >> startTime >> endTime;
	}
	static bool sort(Activity a, Activity b)
	{
		return (a.endTime < b.endTime);
	}
	void output()
	{
		cout << startTime << " " << endTime << endl;
	}

};

int main()
{
	vector<Activity> activities;
	vector<Activity> chosen;
	int num = 0;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		Activity at;
		activities.push_back(at);
	}
	sort(activities.begin(), activities.end(), Activity::sort);
	int lastEndTime=-1;
	for (auto t : activities)
	{
		if (t.startTime > lastEndTime)
		{
			chosen.push_back(t);
			lastEndTime = t.endTime;
		}
	}
	cout << "最终被选中的活动是" << endl;
	for (auto t : chosen)
	{
		t.output();
	}

	

	return 0;
}
