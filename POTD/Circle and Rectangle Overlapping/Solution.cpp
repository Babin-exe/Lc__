// Problem Link : https://leetcode.com/problems/circle-and-rectangle-overlapping/description/
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2) {

        int near_x;
        int near_y;

        if (xCenter >= x1 && xCenter <= x2)
            near_x = xCenter;
        else if (xCenter < x1)
            near_x = x1;
        else
            near_x = x2;

        if (yCenter >= y1 && yCenter <= y2)
            near_y = yCenter;
        else if (yCenter < y1)
            near_y = y1;
        else
            near_y = y2;

        int ver = yCenter - near_y;
        int hor = xCenter - near_x;

        return hor * hor + ver * ver <= radius * radius;
    }
};
