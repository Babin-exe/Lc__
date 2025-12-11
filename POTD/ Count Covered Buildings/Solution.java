// Problem Link : https://leetcode.com/problems/count-covered-buildings/description/

class Solution {
    public int countCoveredBuildings(int n, int[][] buildings) {
        int m = buildings.length;
        if (m <4)
            return 0;

        HashMap<Integer, Integer> minRowY = new HashMap<>();
        HashMap<Integer, Integer> maxRowY = new HashMap<>();
        HashMap<Integer, Integer> minColX = new HashMap<>();
        HashMap<Integer, Integer> maxColX = new HashMap<>();

        for (int[] b : buildings) {
            int x = b[0], y = b[1];

            minRowY.put(x, Math.min(minRowY.getOrDefault(x, y), y));
            maxRowY.put(x, Math.max(maxRowY.getOrDefault(x, y), y));

            minColX.put(y, Math.min(minColX.getOrDefault(y, x), x));
            maxColX.put(y, Math.max(maxColX.getOrDefault(y, x), x));
        }

        int count = 0;

        for (int[] b : buildings) {
            int x = b[0], y = b[1];

            boolean hasLeft = minRowY.get(x) < y;
            boolean hasRight = maxRowY.get(x) > y;
            boolean hasUp = minColX.get(y) < x;
            boolean hasDown = maxColX.get(y) > x;

            if (hasLeft && hasRight && hasUp && hasDown) {
                count++;
            }
        }

        return count;
    }
}
