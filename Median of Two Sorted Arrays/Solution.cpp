#include<iostream>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int pA = 0;
        int pB = 0;
        int average = 0;
        int medium = (n+m)/2;
        if((n+m)%2==0){
            average = 1;
            medium--;
        }
        int num = 0;
        int temp = A[0];
        while(true){
          if(pA<m&&pB<n){
            if(A[pA]>B[pB]){
                num++;
                temp = B[pB];
                pB++;
            }
            else{
                num++;
                temp = A[pA];
                pA++;
            }
            if(num==medium+1){
                if(average==1){
                    if(pA<m&&pB<n){
                        if(A[pA]>B[pB]){
                            return (temp + B[pB])/2.0;
                        }
                        else{
                            return (temp + A[pA])/2.0;
                        }
                    }
                    else{
                        if(pA<m)
                            return (temp + A[pA])/2.0;
                        else
                            return (temp + B[pB])/2.0;
                    }
                }
                else{
                    return temp;
                }
            }
          }
          else if(pA<m){
            temp = A[pA];
            num++;
            pA++;
            if(num==medium+1){
                if(average==1){
                    return (temp + A[pA])/2.0;
                }
                else{
                    return temp;
                }
            }
          }
          else{
            temp = B[pB];
            num++;
            pB++;
            if(num==medium+1){
                if(average==1){
                   return (temp + B[pB])/2.0;
                }
                else{
                    return temp;
                }
            }
          }
        }
    }
};
int main(){
    Solution s;
    int m = 3;
    int A[] = {1,3,5};
    int n = 2;
    int B[] = {2,4};
    cout<<s.findMedianSortedArrays(A,m,B,n);
}
