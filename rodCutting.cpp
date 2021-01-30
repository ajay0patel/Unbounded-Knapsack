/*Given a rod of length n inches and an array of prices that contains prices of
all pieces of size smaller than n. 
Determine the maximum value obtainable by
cutting up the rod and selling the pieces.*/

#include<bits/stdc++.h>
using namespace std;
#define end "\n"

int unboundedKnapsack(int length[],int price[],int lengthOfRod,int n){
    
    int dp[n+1][lengthOfRod+1]; //dp table
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=lengthOfRod;j++){
            
            //recursive code 
            if (i == 0 || j == 0) //initialization of dp array
                dp[i][j] = 0; 
            
            else if(length[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else if(length[i-1] <= j){
                dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],  //only change in this line dp[i-1]-->dp[i]
                                dp[i-1][j]);
            }
        }
    }

    
    return dp[n][lengthOfRod];
}
   // int  n=8,lengthOfRod = 8;    
   // int price [] = { 1, 5, 8, 9, 10, 17, 17, 20 };
   // o/p : 22

int main(){
    int n,lengthOfRod;  //n=size of array
    cin>>n>>lengthOfRod;
    
    int length[n];  //all lengths in which we can cut
    for(int i=0;i<n;i++){
        length[i]=i+1;
    }
    int price[n];
	for(int i=0;i<n;i++){
        cin>>price[i];
    }
    cout<<unboundedKnapsack(length,price,lengthOfRod,n);
    
    
	return 0;
}
