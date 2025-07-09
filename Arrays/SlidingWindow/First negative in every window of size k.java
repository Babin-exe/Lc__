// Problem link : https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1




class Solution {
    static List<Integer> firstNegInt(int arr[], int k) {
        
        
        Queue<Integer>queue = new LinkedList<>();
        List<Integer>list = new ArrayList<>();
        int i  = 0 , j = 0 , n = arr.length;
        while(j<n){
            
            if(arr[j]<0){
                queue.add(arr[j]);
            }
            
            if(j-i+1==k){
             
             if(!queue.isEmpty()){
                 list.add(queue.peek());
             }
             else{
                 list.add(0);
             }
             
             
             if(!queue.isEmpty()&&arr[i]==queue.peek()){
                 queue.poll();
             }
             i++;
             
                
            }
            j++;
        }
       return list;
    }
}
