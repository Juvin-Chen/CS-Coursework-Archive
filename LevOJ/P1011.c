#include<stdio.h>
const int N=100;
int main(){
    int n;
    scanf("%d",&n);
    if(!n) printf("0");
    const char* str="01";
    char res[N];
    int k=0;
    while(n){
        res[k++]=str[n%2];
        n/=2;
    }
    for(int i=k-1;i>=0;i--){
        printf("%c",res[i]);
    }
    return 0;
}