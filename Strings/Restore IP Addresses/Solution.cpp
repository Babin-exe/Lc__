// Problem link : https://leetcode.com/problems/restore-ip-addresses/description/
class Solution {
    vector<string> result;
    int n;

public:
    void create(string& s, int index, int parts, string current) {
        if (index == n && parts == 4) {
            result.push_back(current.substr(0, current.size() - 1));
            return;
        }
        if (parts >= 4)
            return;
        if (index + 1 <= n) {
            create(s, index + 1, parts + 1, current + s.substr(index, 1) + ".");
        }
        if (index + 2 <= n && handleZero(s.substr(index, 2))) {
            create(s, index + 2, parts + 1, current + s.substr(index, 2) + ".");
        }
        if (index + 3 <= n && handleZero(s.substr(index, 3))) {
            create(s, index + 3, parts + 1, current + s.substr(index, 3) + ".");
        }
    }

public:
    bool handleZero(string taker) {
        if (taker.length() > 1 && taker[0] == '0')
            return false;
        int num = stoi(taker);
        return num <= 255;
    }

public:
    vector<string> restoreIpAddresses(string s) {

        n = s.length();
        string current = "";
        if (n < 4 || n > 12)
            return result;
        create(s, 0, 0, current);
        return result;
    }
};
