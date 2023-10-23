/*
    ProblemStatement

In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you can watch entirely?

Input
The first input line has an integer n: the number of movies.

After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending times of a movie.

Output
Print one integer: the maximum number of movies.

Constraints
1 <= n <= 2*1e5
1 <= a < b <= 1e9

Example
Input:

3
3 5
4 9
5 8
Output:

2

*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++)
    {
        cin >> movies[i].first >> movies[i].second;
    }
    sort(movies.begin(), movies.end(), [](pair<int, int> &a, pair<int, int> &b)
         {
             return a.second < b.second; // sort with the non-decreasing ending time.
         });
    int cnt = 0;
    int prev_ending = 0;
    for (int i = 0; i < n; i++)
    {
        if (prev_ending <= movies[i].first)
        {
            cnt++;
            prev_ending = movies[i].second;
        }
    }
    cout << cnt << endl;
    return 0;
}