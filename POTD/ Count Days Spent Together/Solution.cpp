// Problem Link : https://leetcode.com/problems/count-days-spent-together/description/
class Solution {
public:
    vector<int> days = {

        31, 28, 31, 30, 31, 30, 31,
        31, 30, 31, 30, 31

    };

    int convert(string s) {

        int month = stoi(s.substr(0, 2));
        int day = stoi(s.substr(3, 2));

        for (int i = 0; i < month - 1; ++i) {
            day += days[i];
        }

        return day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int a = convert(arriveAlice);
        int b = convert(leaveAlice);

        int c = convert(arriveBob);
        int d = convert(leaveBob);

        int start = max(a, c);
        int end = min(b, d);

        cout << a << " " << b << " " << c << " " << d;

        int s = max(a, c);
        int e = min(b, d);

        return max(e - s + 1, 0);
    }
};
