#include<stdio.h>

//顺序表的定义
#define MAXSIZE 100
typedef int ElemType;
typedef struct{
    ElemType *elem;
    int length;
}SqList;

//顺序表的初始化
bool InitList(SqList &L){
    L.elem = new ElemType[MAXSIZE];
    if(!L.elem){
        printf("内存分配失败，退出");
        return false;
    }
    L.length = 0;
    return true;
}

//顺序表元素的插入
bool ListInsert(SqList &L,int i,ElemType e){
    if(i<1 || i>L.length+1){
        printf("i值不合法");
        return false;
    }
    if(L.length >= MAXSIZE){
        printf("顺序表已满");
        return false;
    }
    for(int j=L.length;j>=i;j--){
        L.elem[j] = L.elem[j-1]; //将插入位置后的元素后移
    }
    L.elem[i-1] = e;
    L.length++;
    return true;
}

//删除顺序表中的重复元素
int removenum(int *nums,int length){
    int prev=0;
    for(int curr=1;curr<length;curr++){
        if(nums[curr]!=nums[prev]){
            prev++;
            nums[prev]=nums[curr];
        }
    }
    return prev+1;
}

int main(){
    SqList L;
    InitList(L);
    int i=1,e;
    while(scanf("%d",&e) == 1){  
    if(!ListInsert(L,i,e))
        break;  
    i++;
    }
    L.length = removenum(L.elem,L.length);
    for(int i=0;i<L.length;i++){
        printf("%d ",L.elem[i]);
    }
    delete[] L.elem;
    return 0;
}