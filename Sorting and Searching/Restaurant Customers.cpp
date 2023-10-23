/*
    ProblemStatement
You are given the arrival and leaving times of n customers in a restaurant.

What was the maximum number of customers in the restaurant at any time?

Input
The first input line has an integer n: the number of customers.

After this, there are n lines that describe the customers. Each line has two integers a and b: the arrival and leaving times of a customer.

You may assume that all arrival and leaving times are distinct.

Output
Print one integer: the maximum number of customers.

Constraints
1 <= n <= 2*1e5
1 <= a < b <= 1e9

Example
Input:

3
5 8
2 4
3 9
Output:

2

*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arrival(n), leaving(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arrival[i] >> leaving[i];
    }
    sort(arrival.begin(), arrival.end());
    sort(leaving.begin(), leaving.end());
    int max_customers = 0;
    for (int i = 0; i < n; i++)
    {
        int people_came = upper_bound(arrival.begin(), arrival.end(), leaving[i]) - arrival.begin();
        max_customers = max(max_customers, people_came - i);
    }
    cout << max_customers << endl;
    return 0;
}