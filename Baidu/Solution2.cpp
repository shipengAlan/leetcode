#include<iostream>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
char str[100005]={0};
int main(){
    int T;
    scanf("%d",&T);
    //cin>>T;
    int t=1;
    //printf("%d\n",T);
    while(t<=T){
        // read lines
        gets(str);
        gets(str);
        int n=1;
        scanf("%d",&n);
        int last = strlen(str)%n;
        int num = strlen(str)/n;
        printf("Case #%d:\n",t);
        int i=0,j=0;
        int s=0,c=num;
        if(n==1)
            printf("%s\n",str);
        else{
        while(s<n&&i<strlen(str)){
            int b=0;
            int step;
            int a=s;
            while(a<strlen(str)){
                printf("%c",str[a]);
                i++;
                if(i>=strlen(str))
                    break;
                if(b<last){
                    step = c + 1;
                    b++;
                }
                else{
                    step = c;
                }
                a+=step;
            }
            s++;
            printf("\n");
        }
        printf("\n");
        }
        t++;
    }

    return 0;
}
