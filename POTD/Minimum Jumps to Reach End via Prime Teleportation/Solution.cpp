// Problem Link : https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/description/

class Solution {
public:
    vector<bool> buildPrime(int n) {
        vector<bool> primes(n + 1, true);
        primes[0] = false;
        primes[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (primes[i]) {
                for (int j = i * i; j <= n; j += i) {
                    primes[j] = false;
                }
            }
        }
        return primes;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        queue<int> q;
        vector<bool> visited(n, false);

        unordered_map<int, vector<int>> mp;

        int maxel = 0;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            maxel = max(maxel, nums[i]);
        }

        unordered_set<int> seenPrimes;

        vector<bool> isPrime = buildPrime(maxel);

        q.push(0);
        visited[0] = true;

        int count = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int i = q.front();
                q.pop();

                if (i == n - 1)
                    return count;

                if (i - 1 >= 0 && !visited[i - 1]) {
                    visited[i - 1] = true;
                    q.push(i - 1);
                }

                if (i + 1 < n && !visited[i + 1]) {
                    visited[i + 1] = true;
                    q.push(i + 1);
                }

                int val = nums[i];

                if (!isPrime[val])
                    continue;

                if (!seenPrimes.count(val)) {
                    seenPrimes.insert(val);

                    for (int mult = val; mult <= maxel; mult += val) {
                        for (int idx : mp[mult]) {
                            if (!visited[idx]) {
                                visited[idx] = true;
                                q.push(idx);
                            }
                        }
                    }
                }
            }

            count++;
        }

        return -1;
    }
};
