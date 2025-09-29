class Solution {
    
    public :
    void makeLSP(string &pat , string &txt , vector<int>&LSP){
        
        int m= pat.length();
        LSP[0] = 0;
        int i = 1;
        int length = 0;
        while(i<m){
            
            if(pat[i]==pat[length]){
                length++;
                LSP[i] = length;
                i++;
            }else{
                if(length==0){
                    i++;
                }
                else{
                    length = LSP[length-1];
                }
            }
        }
    }
    
    
  public:
    vector<int> search(string &pat, string &txt) {
    
    int m = pat.length();
    int n= txt.length();
    
    int i = 0 , j = 0;
    
    vector<int>LSP(m , 0);
    vector<int>ans;
    
    makeLSP(pat, txt , LSP);
    
    while(i<n){
        
        if(pat[j]==txt[i]){
            i++;
            j++;
        }
        
      if(j==m){
    ans.push_back(i-j);
    j = LSP[j-1];
     }
     
     if(pat[j]!=txt[i]){
         
         if(j!=0){
             j = LSP[j-1];
         }else{
             i++;
         }
         
     }
        
        }
    return ans;
    }
};
