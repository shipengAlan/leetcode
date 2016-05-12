#include<iostream>
#include<vector>
#include<stdio.h>
#include<map>
using namespace std;
int main(){
    int num;
    cin>>num;
    int n=1;
    while(n<=num){
        int N;
        int M;
        cin>>N>>M;
        //input network address
        int ** net_addr = new int*[N];
        for(int k=0;k<N;k++){
            net_addr[k] = new int[4];
        }
        int i=0;
        while(i<N){
            scanf("%d.%d.%d.%d",&net_addr[i][0],&net_addr[i][1],&net_addr[i][2],&net_addr[i][3]);
            i++;
        }
        //input mask address
        int ** mask_addr = new int*[M];
        for(int k=0;k<M;k++){
            mask_addr[k] = new int[4];
        }
        i=0;
        while(i<M){
            scanf("%d.%d.%d.%d",&mask_addr[i][0],&mask_addr[i][1],&mask_addr[i][2],&mask_addr[i][3]);
            i++;
        }
        printf("Case #%d:\n",n);
        for(i=0;i<M;i++){
            map<int,int> result;
            for(int j=0;j<N;j++){
                int sum =0;
                for(int k=0;k<4;k++){
                    sum=sum<<4;
                    sum+=(mask_addr[i][k]&net_addr[j][k]);
                }
                map<int, int>::iterator it = result.find(sum);
                if(it!=result.end()){
                    result[sum]+=1;
                }
                else{
                    result.insert(pair<int,int>(sum,1));
                }
            }
            printf("%d\n",result.size());
        }
        for(int k=0;k<N;k++){
            delete [] net_addr[k];
        }
        delete [] net_addr;
        for(int k=0;k<M;k++){
            delete [] mask_addr[k];
        }
        delete [] mask_addr;
        n++;
    }
    return 0;
}
