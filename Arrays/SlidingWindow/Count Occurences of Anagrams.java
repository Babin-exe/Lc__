// Problem link : https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1





class Solution {
    
    //This is to check if the populated freq array is all 0 or not
    private static boolean filled(int [] hehe){
        for(int take : hehe){
            if(take!=0){
                return false;
            }
        }
        return true;
    }
    

    int search(String pat, String txt) {
        
        int [] freq = new int[26];
        Arrays.fill(freq,0);
    
        
        //populate the frequencey array
        for( char ch : pat.toCharArray()){
            
            freq[ch-'a']++;
        }
        
        int i= 0 , j = 0;
        int n = txt.length();
        int result = 0;
        int ans = 0;
        
        while(j<n){
            
            freq[txt.charAt(j)-'a']--;
            
            //lets check if we got the window
         if(j-i+1==pat.length()){
             if(filled(freq)){
                 ans++;
             }
             //slide the front pointer once window is found
             freq[txt.charAt(i)-'a']++;
             i++;
         }
            j++;
            
        }
           return ans;        
    }
}
