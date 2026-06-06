// Problem Link : https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/description/
/*


what did we observer here ????

There can be two cases either the array given to us is

just shifted version of the ascending array like

1 , 2 , 3 ,4
1st shift : 2 3 4 1  -----mirror-----             1 4 3 2
2nd shift : 3 4 1 2  -----mirror-----             2 1 4 3
3rd shift : 4 1 2 3  -----mirror-----             3 2 1 4
4th shift : 1 2 3 4 (original)  -----mirror-----  4 3 2 1




now lets think about it :

if i have an array given to me i can either follwo the left path
to reach the top by going down again and again until i go from the
last 3rd shift and finally to the top

and one thing to see here is the smallest index (1) index gives us the
cost  required  like from the 1st shift if i want to go to 1 2 3 4
it costs index of smallest element 1(3) , 2nd -> 3rd -> to sorted

if we see in 3rd shift index of smallest is = 1 so 1 cost is required

3rd to 4th is same as 3rd to original

so we know one way to go

now if we see we can also go right which costs us 1 , just a reflection

fine after that all we need is to go up to the reflection of the original
array that costs us (i + 1) % n and then from there we just have to
reflect back

example :
 i am at 3rd shift values are : 3 2 1 4 , here smallest number is 1 and it's
index is 2 , so (2 +1) % 4 = 3 so cost to reach top is 3

 and then we have to reflect back so +1




 okay now if we think about the case where our array is the reflected version of
the original array we have two choices


 either we go to the top of our relflected plane and then reflect
 so that gives us 1 for the reflection and (i+1) % n for going to the top as
shown above

 and then we can also do first reflect and then go to the top in the original
plane , but here what we have to see is if we hvae found i as the index of the
smallest element in the original plane its translatin to the relect plane is
(n-1-i);

so now we can say the cost here would be 1 + (n-1-i)


*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int i = min_element(begin(nums), end(nums)) - nums.begin();

        bool rev = false;
        int k = 0;
        int n = nums.size();

        for (int a = i; a < n; a++, k++) if (nums[a] != k) {rev = true; break;}
        for (int a = 0; a < i; a++, k++) if (nums[a] != k) {rev = true;break;}

        if (!rev) return min(i, (n-i) % n +2 );

        k = 0;
        for (int a = i; a >= 0; a--, k++) if (nums[a] != k) return -1;
        for (int a = n - 1; a > i; a--, k++) if (nums[a] != k)return -1;

        return min(1 + (i + 1) % n, 1 + (n - 1 - i));
    }
};
