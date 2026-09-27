// Problem Link : https://leetcode.com/problems/transform-array-using-pair-operations/description/


/*

[x,y,z,k] -> [a,b,c,d]

lets say

i = 0 , y = 1
now , i = x+y - b , j = b

[x + y - b , b , z ,k]

now again i = 0  , j = 2

i = x + y - b + z - c , j = c

[x + y - b + z - c , b , c , k];


now i = 0 , j = 3
 i = x + y -b + z - c + k - d , j = d

 [x + y -b + z - c + k - d , b , c d]

 now we only need to know if ,
 x + y -b + z - c + k - d  = a
 , this can be written as

 (x + y  + z + k ) - (b + c + d) = a
 or
 x + y + z + k  = a + b + c + d

 */
using ll = long long;

class Solution {

public:
    bool canTransform(vector<int>& s, vector<int>& t) {

        ll a = accumulate(begin(s), end(s), 0LL);
        ll b = accumulate(begin(t), end(t), 0LL);
        return a == b;
    }
};
