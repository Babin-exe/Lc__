// Problem Link : https://www.hackerrank.com/challenges/sherlock-and-divisors/problem
#include<bits/stdc++.h>
using namespace std;
int main() {
    
    int t;
    cin>>t;
    while(t--)  {
        int n;
        cin>>n;
        
        int c = 0 ;
        for(int i = 2 ; i * i <=n ;i++) {
            if(n%i==0) {
            if(i%2==0)c++;
           int other = n / i;
           if(other !=i && other%2==0) c++;
        }
    }
        if(n%2==0)c++;
        cout<<c<<"\n";
    }
        return 0;
}
