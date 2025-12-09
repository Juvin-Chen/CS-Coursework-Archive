/*
用 C 语言编写程序，其中 Lb={2,4,6,8,10} La={1,2,3,4,5},
①算法 2.1 执行后，得到的 new La = 1,2,3,4,5,6,8,10
②修改 Lb=2,6,8,9,11,15,20，与新生成的 La，合并后得到 Lc，
Lc= 1,2,2,3,4,5,6,6,8,8,9,10,11,15,20
将 Lc 中重复的元素只保留一个，其余删除，并输出结果。
*/

/*
简化为几个步骤：
1 创建La，Lb
2 将Lb中与La不相同的元素加入La
3 修改Lb为新表，与新生成的La，合并为Lc(直接将元素合并，无多余的判断条件)
4 将Lc中元素去重
*/

//此版本带有头结点
#include<stdio.h>
#include<stdlib.h>

typedef int Status;
#define ERROR 0
#define OK 1

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

//创建链表，将链表初始化
LinkList CreatList_L(LinkList L,int len){
    if(len<=0) return NULL;
    LinkList head=(LinkList)malloc(sizeof(LNode));
    if(!head) return NULL;
    head->next=NULL; //头结点
    LinkList temp=head;
    while(len--){
        int e;
        scanf("%d",&e);
        LinkList p=(LinkList)malloc(sizeof(LNode));
        p->data=e; p->next=NULL;
        temp->next=p; 
        temp=p;
    }
    return head;
}

//将b中与a不重复的元素插入a中
LinkList InsertLb(LinkList La,LinkList Lb){
    if(!Lb) return La;
    LinkList prev=La,prev2=Lb,pa=La->next,pb=Lb->next;
    while(pb){ //将b中所有元素插入La中
        //寻找Lb中元素插入的位置  
        if(pa&&pa->data<pb->data){
            prev=pa;
            pa=pa->next; 
        }else if(pa&&pa->data==pb->data){
            prev2=pb;
            pb=pb->next;
        }else{ //pa=NULL/pb->data<pa->data
            //这里采用移动节点的方式，从Lb中断开,从Lb中删除节点pb
            LinkList p=pb;
            prev2->next=pb->next;
            pb=pb->next; //更新pb为下一个节点
            prev->next=p;
            prev=p;
        }
    }
    return La;
}

//没有其他条件，只是将两表进行升序合并
LinkList MergeList_L(LinkList La,LinkList Lb){
    if(!La&&!Lb) return NULL;
    LinkList pa=La->next,pb=Lb->next;
    free(La); free(Lb);  //将La和Lb的两个头结点指针释放
    LinkList head=(LinkList)malloc(sizeof(LNode)); 
    head->next=NULL;
    LinkList pc=head;
    while(pa&&pb){
        if(pa->data<=pb->data){
            LinkList p=pa;
            pa=pa->next;
            pc->next=p; p->next=NULL;
            pc=p;
        }else{
            LinkList p=pb;
            pb=pb->next;
            pc->next=p; p->next=NULL;
            pc=p;
        }  
    }
    while(pa){
        LinkList p=pa;
        pa=pa->next;
        pc->next=p; p->next=NULL;
        pc=p;
    }
    while(pb){
        LinkList p=pb;
        pb=pb->next;
        pc->next=p; p->next=NULL;
        pc=p;
    }
    return head;
}

//去重
void RemoveList(LinkList L){
    if(!L) return;
    LinkList cur=L->next;
    while(cur&&cur->next){
        if(cur->data==cur->next->data){
            LinkList q=cur->next;
            cur->next=q->next;
            free(q);
        }else{
            cur=cur->next;
        }
    }
}

//打印
void PrintList(LinkList L){
    LinkList p=L->next; //不要破坏链表L
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

//释放内存
void FreeList(LinkList L){
    LinkList p=L;
    while(p){
        LinkList q=p->next;
        free(p);
        p=q;
    }
}
void main()
{
    LinkList La,Lb,Lc;   //未初始化的野指针
    La=CreatList_L(La,5);
    Lb=CreatList_L(Lb,5);
    La=InsertLb(La,Lb);
    //更新Lb
    // 先释放旧的 Lb（注意InsertLb已经把部分节点移动到La，FreeList(Lb)，只会释放仍留在 Lb 中的节点和头结点）
    FreeList(Lb); 
    printf("修改Lb中元素为: \n");
    Lb=CreatList_L(Lb,7);
    Lc=MergeList_L(La, Lb);
    printf("合并La,Lb后的结果： \n");
    PrintList(Lc);
    printf("将Lc去重: \n");
    RemoveList(Lc);
    PrintList(Lc);
    FreeList(Lc);
}