// Problem link : https://leetcode.com/problems/minimum-time-to-complete-trips/


/**
 * @param {number[]} time
 * @param {number} totalTrips
 * @return {number}
 */
var minimumTime = function (time, totalTrips) {

let i = 1, j = time.reduce((min, current) => Math.min(min, current)) * totalTrips;

    while (i < j) {
        let mid = Math.floor(i + (j - i) / 2);
        if (auhNsk(time, mid, totalTrips)) {
            j = mid;
        }
        else {
            i = mid + 1;
        }

    }
    return i;
};


function auhNsk(time, mid, totalTrips) {

    let hehe = 0;
    for (const take of time) {
        hehe += Math.floor(mid / take);

    }

    return hehe >= totalTrips;
}
