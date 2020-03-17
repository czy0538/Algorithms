#include<iostream>
#include<stack>
#include<iomanip> 
using namespace std;
struct num
{
	int data;
	num* next;
};

void Bigdigital(int n)
{
	num* head = new num;
	num* pos = new num;
	head->next =pos;
	pos->data = 1;
	pos->next = nullptr;
	int len = 1;

	for (int i = 2; i <= n; ++i)
	{
		int d = 0;
		pos = head->next;
		num* temp=nullptr;
		for (int j = 1; j <= len; ++j)
		{
			int b = pos->data * i + d;
			pos->data = b % 1000000;
			d = b / 1000000;
			temp = pos;
			pos = pos->next;
		}
		if (0 != d)
		{	
			temp->next = new num;
			pos = temp->next;
			pos->data = d;
			pos->next = nullptr;
			++len;
		}
	}
	pos = head->next;
	stack<int> sum;
	while (pos)
	{
		sum.push(pos->data);
		pos = pos->next;
	}
	cout << sum.top()<<" ";
	sum.pop();
	cout << setiosflags(ios::right) << setw(6);
	cout << setfill('0');
	for(int i=0;i<sum.size();++i)
	{
		cout << sum.top() << " ";
		sum.pop();
	}
	
	
}
int main()
{
	Bigdigital(1000);
	return 0;
}