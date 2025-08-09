// Problem link : https://leetcode.com/problems/koko-eating-bananas/description/
/**
 * @param {number[]} piles
 * @param {number} h
 * @return {number}
 */
var minEatingSpeed = function (piles, h) {
    let i = 1, j = Math.max(...piles);
    while (i < j) {
        let mid = Math.floor(i + (j - i) / 2);
        if (auh(piles, mid, h)) {
            j = mid;

        } else {
            i = mid + 1;
        }
    }
    return i;

};



function auh(piles, mid, h) {
    let ans = 0;
    for (const take of piles) {
        ans += Math.ceil((take / mid));
    }
    return ans <= h;
}
