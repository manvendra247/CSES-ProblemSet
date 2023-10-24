/*
    ProblemStatement
Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.

Input
The first input line has an integer n: the size of the array.

The second line has n integers x1, x2,..., xn: the array values.
Output
Print one integer: the maximum subarray sum.

Constraints
1 <= n <= 2*1e5
-1e9 <= xi <= 1e9

Example
Input:

8
-1 3 -2 5 3 -5 2 2
Output:

9

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    // kadane's algorithm
    long long max_sum = INT_MIN;
    long long curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (curr_sum < 0)
            curr_sum = 0;
        curr_sum += x[i];
        max_sum = max(max_sum, curr_sum);
    }
    cout << max_sum << endl;
    return 0;
}