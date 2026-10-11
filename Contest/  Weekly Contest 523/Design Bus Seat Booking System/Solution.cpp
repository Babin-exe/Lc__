// Problem Link : https://leetcode.com/contest/weekly-contest-523/problems/design-bus-seat-booking-system/
class BusBooking {
public:
    int sum = 0;
    int min_stuff = 0;

    vector<vector<int>> rows;

    BusBooking(int n) { rows.resize(n, vector<int>(4, 0)); }

    void toggle(string seat) {

        char ch = seat[0];
        int row = stoi(seat.substr(1)) - 1;

        int idx = (ch == 'A' ? 0 : (ch == 'B' ? 1 : (ch == 'C' ? 2 : 3)));

        int val = rows[row][idx];

 
        if (val == 0) {

            if (idx == 1 || idx == 2) {
                sum += 1;
                min_stuff++;
                rows[row][idx] = 1;
            } else {
                if (idx == 0) {

                    if (rows[row][1] != 0) {
                        rows[row][0] = 3;
                        sum += 3;
                        min_stuff++;
                    } else {
                        rows[row][0] = 1;
                        sum++;
                        min_stuff++;
                    }

                } else {
                    if (rows[row][2] != 0) {
                        rows[row][3] = 3;
                        sum += 3;
                        min_stuff++;
                    } else {
                        rows[row][3] = 1;
                        sum++;
                        min_stuff++;
                    }
                }
            }

        } else {
            sum -= val;
            rows[row][idx] = 0;
            min_stuff--;
        }
    }

    int getTotalTime() { return sum; }

    int getMinTime() { return min_stuff; }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */
