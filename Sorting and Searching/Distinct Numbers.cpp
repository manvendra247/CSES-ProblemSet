/*
Problem Statement.

You are given a list of n integers, and your task is to calculate the number of distinct values in the list.

Input:
The first input line has an integer n: the number of values.
The second line has n integers x1, x2, x3,.... , xn.

Output
Print one integers: the number of distinct values.

Constraints
1 ≤ n ≤ 2⋅10^5
1 ≤ xi ≤ 10

Example
Input:
5
2 3 2 2 3

Output:
2
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<int> v;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        v.insert(el);
    }
    cout << v.size() << endl;
    return 0;
}