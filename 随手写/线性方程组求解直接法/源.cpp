#include<iostream>
#include<vector>
using namespace std;
void Init(vector<vector<double> >& A)
{
    A.clear();
    int n;
    cout << "输入方程组的阶数:";
    cin >> n;
    if (n <= 1)
    {
        cout << "方程组的阶数必须大于1" << endl;
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        vector<double> temp(n + 1);
        for (int j = 0; j < n + 1; j++)
        {
            cout << "输入第" << i << "个方程的第" << j << "个系数:";
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
    //由于输入函数已经保证了系数矩阵是对的，就不检查A了
    int n = A.size();
    int m = A[0].size();
    x.resize(n);
    //复制系数矩阵，防止修改原矩阵
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
    //第一次消元
    for (int i = 1; i < n; i++)
    {
        double l = Atemp[i][0] / Atemp[0][0];
        for (int j = 0; j < m; j++)
        {
            Atemp[i][j] = Atemp[i][j] - l * Atemp[0][j];
        }
    }
    //剩余的消元
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
    //回代
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