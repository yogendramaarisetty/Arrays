//Longest common span length of 2 binary arrays
#include <bits/stdc++.h>
using namespace std;



// This is a naive approach
//traversinng all possible subarrays and comparing the corresponding sum of array span
int naiveLongestCommonSpanSum(int arr1[],int arr2[],int n){
    int maxLen = 0;
    for(int i=0;i<n;i++){
        int sum1 = 0 , sum2=0;
        for(int j=i;j<n;j++){
            sum1+=arr1[j];
            sum2+=arr2[j];
            if(sum1==sum2){
                int len = j-i+1;
                if(len> maxLen){
                    maxLen  =len;
                }
            }
        }
    }
    return maxLen;
}

int effLongestCommonSpanSum(int arr1[],int arr2[],int n){
        int preSum1=0,preSum2=0;
        int diffArr[2*n+1],maxLen = 0;
        for(int i=0;i<2*n+1;i++)
            diffArr[i] = -1;
        for(int i=0;i<n;i++){
            preSum1+=arr1[i];
            preSum2+=arr2[i];

            int currDiff = preSum1 - preSum2;
            int diffIndex = n+currDiff;
            if(currDiff == 0){
                maxLen = i+1;
            }
            else if(diffArr[diffIndex] == -1){
                diffArr[diffIndex] = i;
            }
            else{
                int len = i-diffArr[diffIndex];
                maxLen = len>maxLen ? len:maxLen;
            }
           
        }
         return maxLen;
}

int main(){

    int arr1[] = {0,1,0,1,1,1,1};
    int arr2[] = {1,1,1,1,1,0,1};
    int n =  sizeof(arr1)/sizeof(arr1[0]); ;
    int max = naiveLongestCommonSpanSum(arr1,arr2,n);
    cout<< max;
    max = effLongestCommonSpanSum(arr1,arr2,n);
    cout<< max;

}