// Problem link : https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1



class Solution {
    public int maximumSumSubarray(int[] arr, int k) {
        
        
        int maxi = 0;
        int n= arr.length;
        int i = 0;
        int j = 0;
        int maxsum =Integer.MIN_VALUE;
        int sum= 0;
        while(j<n){
            
            sum+=arr[j];
            
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                
                maxsum =Math.max(maxsum,sum);
                sum-=arr[i];
                i++;
                j++;
            }
        
        }
  
        
        
        return maxsum;
    }
}
