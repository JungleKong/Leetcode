#include <bits/stdc++.h>
using namespace std;
//链表定义
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//相关函数的声明
void insertList(ListNode* &head,int x);     //头插法在链表头部插入节点
void printList(ListNode *head);             //打印链表
int getLenght(ListNode* head);              //获取链表长度
ListNode *creatList(int a[],int n);         //根据数组创建链表
//在这里放入Solution类
//类开始
 
//类结束
// int main(){
//    ListNode *head=nullptr;
//    int list[]={1,2};
//    int len=sizeof(list)==0?0:sizeof(list)/sizeof(list[0]);
//    head=creatList(list,len);                //根据数组序列创建链表
//    Solution ans;
//    //根据要求自己编辑输出内容
 
//    return 0;
// }

//插入链表,头插,无头结点
void insertList(ListNode* &head,int x){
   ListNode *p=new ListNode(x);
   if(head==nullptr){
      head=p;
   }
   else{
      p->next=head;
      head=p;
   }
}
//打印链表
void printList(ListNode *head){
   if(head==nullptr){            //空链表输出空
      printf("NULL\n");
      return;
   }
    while(head){
        printf("%d ",head->val);
        head=head->next;
    }
    putchar('\n');
}
//获取链表长度
int getLenght(ListNode* head){
   int len=0;
   while(head){
      len++;
      head=head->next;
   }
   return len;
}
//根据一个数组序列，使用头插创建链表，需要知道元素个数
ListNode *creatList(int a[],int n){
   ListNode *head=nullptr;
   if(n>0) reverse(a,a+n);                   //头插方法创建的链表是给定序列的逆序，这里提前逆置一下
   for(int i=0;i<n;i++){                     //得到给定序列顺序的链表
      insertList(head,a[i]);
   }
   return head;
}
