#include<iostream>
#include<vector>
using namespace std;
void Init(vector<vector<double> >& A)
{
    A.clear();
    int n;
    cout << "���뷽����Ľ���:";
    cin >> n;
    if (n <= 1)
    {
        cout << "������Ľ����������1" << endl;
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        vector<double> temp(n + 1);
        for (int j = 0; j < n + 1; j++)
        {
            cout << "�����" << i << "�����̵ĵ�" << j << "��ϵ��:";
            double a = 0.0;
            cin >> a;
            temp[j] = a;
        }
        A.push_back(temp);
        temp.clear();
    }
}


void DisplaySolver(const vector<double>& solve)
{
    int n = solve.size();
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i << " = " << solve[i] << endl;
    }
}

bool Gauss(const vector<vector<double> >& A, vector<double>& x)
{
    //�������뺯���Ѿ���֤��ϵ�������ǶԵģ��Ͳ����A��
    int n = A.size();
    int m = A[0].size();
    x.resize(n);
    //����ϵ�����󣬷�ֹ�޸�ԭ����
    vector<vector<double> > Atemp(n);
    for (int i = 0; i < n; i++)
    {
        vector<double> temp(m);
        for (int j = 0; j < m; j++)
        {
            temp[j] = A[i][j];
        }
        Atemp[i] = temp;
        temp.clear();
    }
    //��һ����Ԫ
    for (int i = 1; i < n; i++)
    {
        double l = Atemp[i][0] / Atemp[0][0];
        for (int j = 0; j < m; j++)
        {
            Atemp[i][j] = Atemp[i][j] - l * Atemp[0][j];
        }
    }
    //ʣ�����Ԫ
    for (int k = 1; k < n - 1; k++)
    {
        for (int i = k + 1; i < n; i++)
        {
            if (Atemp[k][k] == 0)
            {
                x.clear();
                return false;
            }
            double l = Atemp[i][k] / Atemp[k][k];
            for (int j = k; j < m; j++)
            {
                Atemp[i][j] = Atemp[i][j] - l * Atemp[k][j];
            }
        }
    }
    //�ش�
    x[n - 1] = Atemp[n - 1][m - 1] / Atemp[n - 1][m - 2];
    for (int k = n - 2; k >= 0; k--)
    {
        double s = 0.0;
        for (int j = k + 1; j < n; j++)
        {
            s += Atemp[k][j] * x[j];
        }
        x[k] = (Atemp[k][m - 1] - s) / Atemp[k][k];
    }
    return true;
}

int main()
{
    vector <vector<double>> A;
    vector<double> x;
    Init(A);
    Gauss(A, x);
    DisplaySolver(x);
    return 0;
}