// Problem Link : https://leetcode.com/problems/walking-robot-simulation/description/?envType=daily-question&envId=2026-04-09

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        set<pair<int, int>> obs;

        for (auto& it : obstacles) {
            obs.insert({it[0], it[1]});
        }

        int dir = 0;
        int x = 0, y = 0;
        int idx = 0;

        int maxdis = 0;

        for (int val : commands) {
            if (val == -1) {
                idx = (idx + 1) % 4;
            } else if (val == -2) {
                idx = (idx + 3) % 4;
            } else {
                for (int i = 1; i <= val; i++) {
                    int nx = x + dx[idx];
                    int ny = y + dy[idx];

                    if (obs.count({nx, ny}))
                        break;

                    x = nx;
                    y = ny;

                    maxdis = max(maxdis, x * x + y * y);
                }
            }
        }
        return maxdis;
    }
};

// 90 deg to the left rotation  = -2
// 90 deg to the right rotation = -1

/*
We will be starting with the initial direction that is north


we shoudl always remember something

if x is > 0 that means we are pointing at east direction
if x <0  we are pointing at west direction

if y > 0 we are pointing at north direction

if y < 0 then we are pointting at south direction


*/

/*
 -1 rule :
 if we are at east we will make it south
 if we are at south we will make it west
 if we area at west we will make it north
 if we are at north we will make it east
*/

/*

-2Rule :

if we are at east we will go north
if we are at south we will go east
if we are at west we will go south
if we are at north we will go west
*/

/*


To take the right turn we did idx = (idx + 1) % size , size = 4;
And to take left we did idx = (size + (idx -1) ) % size where size = 4 so this
simplifies to (idx + 3) % 4;


also we can see north is up so it is +1 in the y , east is +x so +1 , south is
-y so it is -1 and west is -x so we place -1




*/
