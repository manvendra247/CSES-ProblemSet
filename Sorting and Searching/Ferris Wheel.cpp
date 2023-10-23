/*
    ProblemSatement
There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.

Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x.
You know the weight of every child.

What is the minimum number of gondolas needed for the children?

Input
The first input line contains two integers n and x: the number of children and the maximum allowed weight.

The next line contains n integers p1, p2, ...., pn : the weight of each child.

Output
Print one integer: the minimum number of gondolas.

Constraints
1 <= n <= 2*1e5
1 <= x <= 1e9
1 <= pi <= x

Example
Input:

4 10
7 2 3 9
Output:

3


*/

/* IMPORTANT
    Each gondola may have only 1 or 2 children.
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    multiset<int> p;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        p.insert(el);
    }
    int cnt = 1; // number of gondola's required.
    int cg = x;  // size of current gondola we are filling.
    int cc = 0;  // count of children of current gondola.
    while (!p.empty())
    {
        auto temp = p.upper_bound(cg);
        if (temp == p.begin() || cc == 2)
        { // there's not enough space for any children
            cg = x;
            cnt++;
            cc = 0;
        }
        else
        {
            --temp; // the heviest child who can come in this gondola.
            cg -= (*temp);
            p.erase(temp);
            cc++;
        }
    }
    cout << cnt << endl;
    return 0;
}