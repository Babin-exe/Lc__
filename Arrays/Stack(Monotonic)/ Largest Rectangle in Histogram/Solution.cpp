// Problem Link : https://leetcode.com/problems/largest-rectangle-in-histogram/description/

/*
Thought process :


The question is asking if you at a histogram and you look at your left and right
and keep on expanding two things happen

one is your width increases by 1 and your height decreases to the min(yourheight
, adjacent )


so your area is keeps on happening : height * width


okay now we have the idea of what is happening , what can we think of isssss


I would like to expand my area in left or right direction until when????

until the height of my histogram is less than my adjacent , why would i think of
this ,,,, i would say if my adjacent is larger i can adjust the adjacent to be
my height but if it is smaller i cant extend it to be my height


okay now i have some kind of idea this question's sub problem looks like finding
the next smaller number for a position

which kind of uses the idea of monotonic stack

what is the idea??????
i would need two things one is what is the left smaller number for my height and
other is what is the right smaller number for my height if i can find those i
can say for that position my area woudl be

area = heights[i] * right[i]-left[i]-1;
and we can keep on taking the max of area and what this is calculated


what more i see here is if we go a bit lazy we can do a o(n) to build left and
other o(n) to build right and one last o(n) to find the ans

but if we really think about it we may do this in o(n)???

why would i say it

i would say it with something liek this in my mind::

i will go on finding the next smallest in the right and when i do find it the
other top of the stack is actually the smaller left value for me ,, why again
because the stack only takes the value in ascending order actually so that makes
sense somehow :)



*/

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<int> st;
        int ans = 0;
        int idx;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && h[st.top()] > h[i]) {

                idx = st.top();
                st.pop();

                if (!st.empty()) {
                    ans = max(ans, h[idx] * (i - st.top() - 1));

                } else {
                    ans = max(ans, h[idx] * i);
                }
            }
            st.push(i);
        }

        while (!st.empty()) {
            idx = st.top();
            st.pop();
            if (!st.empty()) {
                ans = max(ans, h[idx] * (n - st.top() - 1));

            } else {
                ans = max(ans, h[idx] * n);
            }
        }

        return ans;
    }
};
