#include <bits/stdc++.h>
using namespace std;

int main() {

    // ================= VECTOR =================
    vector<int> v = {5, 2, 8, 1};

    v.push_back(10);
    v.pop_back();

    sort(v.begin(), v.end());                
    sort(v.rbegin(), v.rend());              

    reverse(v.begin(), v.end());

    cout << "Vector: ";
    for (auto x : v) cout << x << " ";
    cout << "\n";

    // Remove duplicates
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());


    // ================= SET =================
    set<int> s = {3, 1, 4};

    s.insert(2);
    s.erase(1);

    cout << "Set contains 3? " << s.count(3) << "\n";

    auto it1 = s.lower_bound(2); // first >= 2
    auto it2 = s.upper_bound(2); // first > 2


    // ================= UNORDERED SET =================
    unordered_set<int> us;

    us.insert(10);
    us.insert(20);

    cout << "Unordered Set contains 10? " << us.count(10) << "\n";


    // ================= MAP =================
    map<int, int> mp;

    mp[1] = 100;
    mp[2] = 200;
    mp[1]++; // increment

    cout << "Map value at key 1: " << mp[1] << "\n";

    for (auto [key, val] : mp) {
        cout << key << " -> " << val << "\n";
    }


    // ================= UNORDERED MAP =================
    unordered_map<int, int> ump;

    ump[5]++;
    ump[10] = 50;


    // ================= PAIR =================
    pair<int, int> p = {1, 2};
    cout << "Pair: " << p.first << ", " << p.second << "\n";


    // ================= QUEUE =================
    queue<int> q;

    q.push(1);
    q.push(2);
    q.pop();

    cout << "Queue front: " << q.front() << "\n";


    // ================= STACK =================
    stack<int> st;

    st.push(5);
    st.push(10);
    st.pop();

    cout << "Stack top: " << st.top() << "\n";


    // ================= PRIORITY QUEUE =================
    priority_queue<int> maxHeap;

    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(20);

    cout << "MaxHeap top: " << maxHeap.top() << "\n";

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(20);

    cout << "MinHeap top: " << minHeap.top() << "\n";


    // ================= ALGORITHMS =================
    vector<int> a = {1, 2, 3, 4, 5};

    cout << "Binary search 3: " 
         << binary_search(a.begin(), a.end(), 3) << "\n";

    cout << "Lower bound of 3: " 
         << (lower_bound(a.begin(), a.end(), 3) - a.begin()) << "\n";

    cout << "Upper bound of 3: " 
         << (upper_bound(a.begin(), a.end(), 3) - a.begin()) << "\n";

    cout << "Min element: " 
         << *min_element(a.begin(), a.end()) << "\n";

    cout << "Max element: " 
         << *max_element(a.begin(), a.end()) << "\n";

    cout << "Sum: " 
         << accumulate(a.begin(), a.end(), 0) << "\n";

    cout << "Count of 3: " 
         << count(a.begin(), a.end(), 3) << "\n";


    // ================= NEXT PERMUTATION =================
    vector<int> perm = {1, 2, 3};

    next_permutation(perm.begin(), perm.end());

    cout << "Next permutation: ";
    for (auto x : perm) cout << x << " ";
    cout << "\n";


    // ================= FREQUENCY MAP =================
    vector<int> freqVec = {1, 2, 2, 3, 3, 3};

    unordered_map<int, int> freq;

    for (auto x : freqVec) {
        freq[x]++;
    }

    cout << "Frequency of 3: " << freq[3] << "\n";


    // ================= FIND =================
    auto it = find(a.begin(), a.end(), 3);

    if (it != a.end()) {
        cout << "Found 3 at index: " << (it - a.begin()) << "\n";
    }


    // ================= CONVERT SET TO VECTOR =================
    vector<int> fromSet(s.begin(), s.end());

    cout << "Vector from set: ";
    for (auto x : fromSet) cout << x << " ";
    cout << "\n";


    // ================= CUSTOM SORT =================
    vector<pair<int, int>> vp = {{1, 5}, {2, 3}, {3, 1}};

    sort(vp.begin(), vp.end(), [](auto &a, auto &b) {
        return a.second < b.second; // sort by second
    });

    cout << "Sorted pairs by second: ";
    for (auto [x, y] : vp) {
        cout << "(" << x << "," << y << ") ";
    }
    cout << "\n";


    return 0;
}
