//猜数字
/*
一群人坐在一起，每人猜一个 100 以内的数，谁的数字最接近大家平均数的一半就赢。本题就要求你找出其中的赢家。

输入格式：
输入在第一行给出一个正整数N（≤10
​4
​​ ）。随后 N 行，每行给出一个玩家的名字（由不超过8个英文字母组成的字符串）和其猜的正整数（≤ 100）。

输出格式：
在一行中顺序输出：大家平均数的一半（只输出整数部分）、赢家的名字，其间以空格分隔。题目保证赢家是唯一的。

输入样例：
7
Bob 35
Amy 28
James 98
Alice 11
Jack 45
Smith 33
Chris 62
输出样例：
22 Amy
*/
#include <bits/stdc++.h>

using namespace std;

typedef struct people
{
    char name[9];
    short int num;
} people;

int n, total = 0;
people *p;

int main()
{
    cin >> n;
    p = new people[n];

    for (int i = 0; i < n; i++)
    {
        cin >> p[i].name >> p[i].num;
        total += p[i].num;
    }

    int m = total / (2 * n);
    int pla = 0, dis = 0;

    if (n > 0)
    {
        dis = abs(m - p[0].num);

        for (int i = 0; i < n; i++)
        {
            if (abs(m - p[i].num) < dis)
            {
                pla = i;
                dis = abs(m - p[i].num);
            }
        }
        cout << m << " " << p[pla].name;
    }

    return 0;
}