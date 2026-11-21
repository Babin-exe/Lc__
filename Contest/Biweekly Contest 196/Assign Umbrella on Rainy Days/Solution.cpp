// Problem Link : https://leetcode.com/problems/assign-umbrella-on-rainy-days/
class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {

        vector<string> ans;
        int n = rain.size();

        int ac = 0, bc = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (rain[i] == 1 && rain[i + 1] == 1) {
                if (ac > bc) {
                    bc++;
                    ans.push_back("Bob");

                } else {
                    ac++;
                    ans.push_back("Alice");
                }

            } else if (rain[i] == 0) {
                ans.push_back("None");
            } else if (rain[i] == 1) {
                bc++;
                ans.push_back("Bob");
            }
        }

        if (rain[n - 1] == 1) {
            ans.push_back("Bob");
        } else ans.push_back("None");
        return ans;
    }
};
