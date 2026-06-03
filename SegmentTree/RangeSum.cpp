#include <bits/stdc++.h>
using namespace std;

vector<int> segTree;

void buildTree(int l, int r, int c, vector<int> &v)
{
    if (l == r)
    {
        segTree[c] = v[l];
        return;
    }

    int mid = l + (r - l) / 2;
    buildTree(l, mid, 2 * c + 1, v);
    buildTree(mid + 1, r, 2 * c + 2, v);

    segTree[c] = segTree[2 * c + 1] + segTree[2 * c + 2];
}

int getSum(int s, int e, int l, int r, int node)
{

    if (s > r || l > e)
        return 0;

    if (s >= l && e <= r)
        return segTree[node];

    int mid = s + (e - s) / 2;

    int q1 = getSum(s, mid, l, r, 2 * node + 1);
    int q2 = getSum(mid + 1, e, l, r, 2 * node + 2);

    return q1 + q2;
}

int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    segTree.resize(4 * n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    buildTree(0, n - 1, 0, v);

    for (int i = 0; i < 4 * n; i++)
        cout << segTree[i] << " ";

    cout << getSum(0, n - 1, 0, 1, 0) << "\n";

    return 0;
}
