/*
    ProblemStatement
You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.

Input
The first input line has two integers n and x: the array size and the target sum.

The second line has n integers a1, a2, ..., an : the array valus.
Output
Print two integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.

Constraints
1 <= n <= 2*1e5
1 <= x, ai <= 1e9

Example
Input:

4 8
2 7 5 1
Output:

2 4

*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<int, int> mp;
    int val1 = -1, val2 = -1;
    for (int i = 0; i < n; i++)
    {
        int rem = x - a[i]; // select the current number and check for smaller number.
        if (mp.count(rem))
        {
            val1 = mp[rem], val2 = i + 1;
            break;
        }
        mp[a[i]] = i + 1;
    }
    if (val1 == -1)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << val1 << " " << val2 << endl;
    return 0;
}