// Problem Link : https://leetcode.com/problems/minimum-operations-to-make-array-parity-alternating/description/

/*
Thought process

An array can either go with the sequence [odd,even,odd,even,odd ,even .......]
or [even, odd , even , odd , even , odd , .......]

we can simply try two  iterations and see for both sequences and store how many
changes will it require for both of these cases and the minimum of those gives
us the answer for our 1st case

we were just concerned about changing the parity there was no record of either
+1 was done or -1 was done to change the partiy so we somehow need to know all
the values  at that index +-1 and check by taking both of them in our final
array and see that the maxium of the array - mininum of the array is minimized

I still have not figured out how woudl i tackle the 2nd case lets seeee....


*/

class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {}
};
