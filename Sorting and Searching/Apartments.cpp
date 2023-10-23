/*
    ProblemStatement
There are n applicants and m free apartments. Your task is to distribute the apartments so that as many applicants as possible will get an apartment.

Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.

Input
The first input line has three integers n, m, and k: the number of applicants, the number of apartments, and the maximum allowed difference.

The next line contains n integers a1, a2,..…,an : the desired apartment size of each applicant.
If the desired size of an applicant is x, he or she will accept any apartment whose size is between x−k and x+k.

The last line contains m integers b1, b2,.., bn : the size of each apartment.

Output
Print one integer: the number of applicants who will get an apartment.

Constraints
1 ≤ n, m ≤ 2⋅10^5
0 ≤ k ≤ 10^9
1 ≤ ai, bi <= 1e9

Example
Input:
4 3 5
60 45 80 60
30 60 75

Output:
2

*/
/*
    Approach:  Greedy
        try to fulfill the smallest requirement with the smallest availibity.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    multiset<int> b;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++)
    {
        int el;
        cin >> el;
        b.insert(el);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int minreq = a[i] - k;
        auto minel = b.lower_bound(minreq);
        if (minel != b.end())
        {
            if (*minel <= a[i] + k)
            {
                ans++;
                b.erase(minel);
            }
        }
    }
    cout << ans << endl;
    return 0;
}