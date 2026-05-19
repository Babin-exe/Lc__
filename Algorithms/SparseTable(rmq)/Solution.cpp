
/*

Sparse Table for Range Minimum Query (RMQ)

Idea:

m[i][k] stores the minimum value in the range:

[i ... i + 2^k - 1]

meaning:
starting from index i,
what is the minimum in a segment of length 2^k ?

Base Case:

k = 0

2^0 = 1

So the interval length is 1,
which means:

m[i][0] = a[i]



Transition:

To compute a segment of size 2^k,
split it into two halves of size 2^(k-1).

Left half:
[i ... i + 2^(k-1) - 1]

Right half:
[i + 2^(k-1) ... i + 2^k - 1]

Both halves already have their minimum precomputed.

So:

m[i][k] =
min(
    m[i][k-1],
    m[i + (1 << (k-1))][k-1]
)


Complexities:

Preprocessing:
O(n log n)

Query:
O(1)

*/




#include <bits/stdc++.h>
using namespace std;

const int LOG = 17;
const int MAX_N = 100'005;

int a[MAX_N];
int m[MAX_N][LOG];

int queryMin(int l, int r)
{
    int Len = (r - l) + 1;

    int k = 31 - __builtin_clz(Len);

    return min(m[l][k], m[r - (1 << k) + 1][k]);
}

int main()
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[i][0] = a[i];
    }

    for (int k = 1; k < LOG; k++)
    {
        for (int i = 0; i + (1 << k) - 1 < n; i++)
        {

            m[i][k] = min(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
        }
    }

    return 0;
}
