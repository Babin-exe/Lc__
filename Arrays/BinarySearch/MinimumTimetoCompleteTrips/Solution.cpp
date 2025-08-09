// Problem link : https://leetcode.com/problems/minimum-time-to-complete-trips/
class Solution {

public:
    bool Hehe(vector<int>& time, long long mid, int totalTrips) {
        long long sum = 0;
        for (int t : time) {
            sum += (mid / t);
        }
        return sum >= totalTrips;
    }

public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long i = 1;
        long long j =
            (long long)*min_element(begin(time), end(time)) * totalTrips;
        while (i < j) {

            long long mid = i + (j - i) / 2;
            if (Hehe(time,mid,totalTrips)) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return i;
    }
};
