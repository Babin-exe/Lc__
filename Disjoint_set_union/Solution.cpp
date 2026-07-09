#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class DisjointSetUnion
{

    int n;
    vector<int> parent, rank;

public:
    DisjointSetUnion(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int v)
    {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    void unionByRank(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return;

        if (rank[pa] == rank[pb])
        {
            parent[pb] = pa;
            rank[pa]++;
        }
        else if (rank[pa] > rank[pb])
        {
            parent[pb] = pa;
        }
        else
        {
            parent[pa] = pb;
        }
    }

    void getInfo()
    {
        for (auto &it : parent)
            cout << it << " ";
        cout << "\n";

        for (auto &it : rank)
            cout << it << " ";
        cout << "\n";
    }
};

int main()
{

    DisjointSetUnion dj = DisjointSetUnion(5);
    cout << dj.find(4) << "\n";

    dj.unionByRank(1, 2);

    cout << dj.find(1) << " " << dj.find(2) << "\n";

    dj.unionByRank(2, 4);

    cout << dj.find(4) << "\n";

    dj.getInfo();

    return 0;
}
