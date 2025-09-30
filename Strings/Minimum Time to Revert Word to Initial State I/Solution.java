 // Problem link : https://leetcode.com/problems/minimum-time-to-revert-word-to-initial-state-i/

class Solution {
public boolean isCheck(String word , int i){
    int j = 0;
    while(i<word.length()){
        if(word.charAt(i)==word.charAt(j)){
            i++;
            j++;
        }
        else{
            return false;
        }

    }
    return true;
}

    public int minimumTimeToInitialState(String word, int k) {
        int i = k;
        int count = 1;
        int n = word.length();
        while (i < n) {
            if (isCheck(word, i)) {
                break;
            } else {
                i += k;
                count++;
            }

        }
        return count;
    }
}
