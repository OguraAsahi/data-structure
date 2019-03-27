#include<stdio.h>
#include<malloc.h>
typedef struct LNode   //建立一个结构体并进行类型定义
{
    int password;      //密码
    int num;           //编号
    struct LNode *next;//指针域

}LNode,*LinkList;      //线性表的单链表存储结构


LinkList input(int n)  //循环单链表生成函数，n为节点个数
{
    int i;
    LinkList tail,head;
    head= tail = (LinkList)malloc(sizeof(LNode));//生成新节点，head用于最后首尾连接
    tail->num = 1;
    printf("please input the first password");   //第一个人的密码
    scanf("%d",&tail->password);

    for(i=2;i<=n;i++)
    {
        LinkList p;                              //p为节点载体
        p=(LinkList)malloc(sizeof(LNode));       //指针变量p
        p->num=i;
        printf("please input the %d 'password:",i);
        scanf("%d",&p->password);

        tail->next=p;
        tail=p;                                  //开始指向下一个人，输入密码
    }
      tail->next=head;                           //最后首尾连接，完成循环体
      return tail;                               //return的是tail

}
void output(LinkList L,int limit,int n)           //模拟约瑟夫环,L模拟人围成的圈，limit为最初的报数上限值，n为总人数
{
    int i;
    LinkList q;                                   //q为中间指针
    while(n>0)
    {
        for(i=1;i<limit;i++)                      //报数循环
        {
            L=L->next;
        }
        q=L->next;
        printf("the %d people out,the password is %d\n",q->num,q->password);
        L->next=q->next;                           //要出去的人的前一个人指向后一个人，避免结点断开
        limit = q->password;                       //将下一个人的密码作为报数上限
        free(q);                                   //将 q free掉，开始下一轮报数，也就是这个人出去
        n--;                                       //总人数减一
    }
}
int main()
{
    LinkList s;
    int n,m;
    printf("please input the total people N:");
    scanf("%d",&n);
    printf("please input the upper limit M:");
    scanf("%d",&m);
    printf("please input the total %d 's password:\n",n);
    s=input(n);
    printf("   number            password\n");
    output(s,m,n);
}
