#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
//string转换为int

int strint(const string& s)
{
	int num;
	stringstream ss(s);
	ss >> num;
	return num;
}
//int转换为string
string intstr(const int& num)
{
	string s;
	stringstream ss;
	ss << num;
	ss >> s;
	return s;
}

//前置0 ，因为大数的长度必须要为2^n的倍数，才能划分

void removePrezero(string& s)
{
	if (s.length() == 1)
		return;
	int k = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '0')
			k++;
		else break;
	}
	if (k == s.length())
		s = "0";
	else 
		s = s.substr(k);
	return;
}
//大数相加
string add(string s1, string s2)
{
	string s = "";
	removePrezero(s1);	//去掉前置0
	removePrezero(s2);
	reverse(s1.begin(), s1.end()); //先把字符串颠倒，方便相加
	reverse(s2.begin(), s2.end());
	int c = 0;
	for (int i = 0; c || i < max(s1.length(), s2.length()); i++)
	{
		int t = c;
		if (i < s1.length())t += s1[i] - '0';
		if (i < s2.length())t += s2[i] - '0';
		int d = t % 10;
		s.insert(0, intstr(d));
		c = t / 10;
	}
	return s;
}
//大数相减
string subtra(string& s1, string& s2)
{
	string s = "";
	string flag;
	removePrezero(s1);	//去掉前置0
	removePrezero(s2);
	int len1 = s1.length();
	int len2 = s2.length();
	int len = len1 > len2 ? len1 : len2;
	if (len1 < len2)flag = "-";
	else if (len1 > len2)flag = "+";
	else
	{
		int i;
		for (i = 0; i < len1; i++)
		{
			if (s1.at(i) > s2.at(i))
			{
				flag = "+";	 break;
			}
			else if (s1.at(i) < s2.at(i))
			{
				flag = "-"; break;
			}
		}
		if (i == len1)s == "0";
	}
	int* num = (int*)malloc(sizeof(int) * len);
	reverse(s1.begin(), s1.end());	//方便相减
	reverse(s2.begin(), s2.end());
	int c = 0;
	for (int j = 0; j < len; j++)
	{
		int n1 = j < len1 ? s1[j] - '0' : 0;
		int n2 = j < len2 ? s2[j] - '0' : 0;
		if (flag == "+")num[c++] = n1 - n2;
		else num[c++] = n2 - n1;
	}
	for (int j = 0; j < c; j++)
	{
		if (num[j] < 0)
		{
			num[j] += 10; num[j + 1] -= 1;
		}
	}
	c--;
	while (num[c] == 0)c--;
	for (int j = 0; j <= c; j++)
	{
		s.insert(0, intstr(num[j]));
	}
	if (flag == "-")return flag + s;
	else return s;
}
//增加前置0
void addPrezero(string& s, int L)
{
	for (int i = 0; i < L; i++)
	{
		s = s.insert(0, "0");
	}
		
}
//增加后置0，大数*10^n	相当于在数的后面加n个0
string addLastzero(string s, int L)
{
	string s1 = s;
	for (int i = 0; i < L; i++)
		s1 += "0";
	return s1;
}
//大数相乘
string multi(string& s1, string& s2)
{
	bool flag1 = false, flag2 = false;
	string sign;	 //作用是判断结果是正数还是负数
	if (s1.at(0) == '-')
	{
		flag1 = true; s1 = s1.substr(1);
	}
	if (s1.at(0) == '-')
	{
		flag2 = true; s2 = s2.substr(1);
	}
	if (flag1 && flag2)sign = "+";
	else if (flag1 || flag2) sign = "-";
	else sign = "+";
	int L = 4;	 //将数前置若干个0，使其长度为2^n的倍数
	if (s1.length() > 2 || s2.length() > 2)
	{
		if (s1.length() >= s2.length())
		{
			while (L < s1.length())L *= 2;
			if (L != s1.length())
				addPrezero(s1, L - s1.length());
			addPrezero(s2, L - s2.length());
		}
		else
		{
			while (L < s2.length())L *= 2;
			if (L != s2.length())
				addPrezero(s2, L - s2.length());
			addPrezero(s1, L - s1.length());
		}
	}
	if (s1.length() == 1)addPrezero(s1, 1);
	if (s2.length() == 1)addPrezero(s2, 1);

	int n = s1.length();
	string result, a0, a1, b0, b1;
	if (n > 1)
	{
		a1 = s1.substr(0, n / 2);
		a0 = s1.substr(n / 2, n);
		b1 = s2.substr(0, n / 2);
		b0 = s2.substr(n / 2, n);
	}
	if (n == 2)
	{
		int x1 = strint(a1);
		int x2 = strint(a0);
		int y1 = strint(b1);
		int y2 = strint(b0);
		int num = (x1 * 10 + x2) * (y1 * 10 + y2);
		result = intstr(num);
	}
	else
	{
		string c2 = multi(a1, b1);
		string c0 = multi(a0, b0);
		string temp1 = add(a0, a1);
		string temp2 = add(b1, b0);
		string temp3 = add(c2, c0);
		string temp_c1 = multi(temp1, temp2);
		string c1 = subtra(temp_c1, temp3);
		string s1 = addLastzero(c1, n / 2);
		string s2 = addLastzero(c2, n);
		result = add(add(s1, s2), c0);
	}
	if (sign == "-")result.insert(0, sign);
	return result;
}
int main()
{
	//text
	string s1 = "579521", s2 = "12348976543";
	cout << multi(s1, s2);
}