/* There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.

Each customer announces the maximum price they are willing to pay for a ticket, and after this, they will get a ticket with the nearest possible price such that it does not exceed the maximum price.

Input
The first input line contains integers n and m: the number of tickets and the number of customers.

The next line contains n integers h1, h2,..., hn: the price of each ticket.
The last line contains m integers t1, t2,..., tn: the maximum price for each costumer in the order they arrive.

Output
Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.

If a customer cannot get any ticket, print −1.

Constraints
1 <= n, m <= 2*1e5
1 <= hi, ti <= 1e9

Example

Input:

5 3
5 3 7 8 5
4 8 3

Output:

3
8
-1

*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    multiset<int> h;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        h.insert(el);
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;                     // the maximum value current customer wants to pay.
        auto temp = h.upper_bound(t); // the first undesirable value.
        if (temp != h.begin())
        {
            --temp; // desirable value
            cout << *temp << " ";
            h.erase(temp);
        }
        else
            cout << -1 << " ";
    }
    return 0;
}