#include<stdio.h>
#include<malloc.h>
typedef struct LNode   //����һ���ṹ�岢�������Ͷ���
{
    int password;      //����
    int num;           //���
    struct LNode *next;//ָ����

}LNode,*LinkList;      //���Ա�ĵ�����洢�ṹ


LinkList input(int n)  //ѭ�����������ɺ�����nΪ�ڵ����
{
    int i;
    LinkList tail,head;
    head= tail = (LinkList)malloc(sizeof(LNode));//�����½ڵ㣬head���������β����
    tail->num = 1;
    printf("please input the first password");   //��һ���˵�����
    scanf("%d",&tail->password);

    for(i=2;i<=n;i++)
    {
        LinkList p;                              //pΪ�ڵ�����
        p=(LinkList)malloc(sizeof(LNode));       //ָ�����p
        p->num=i;
        printf("please input the %d 'password:",i);
        scanf("%d",&p->password);

        tail->next=p;
        tail=p;                                  //��ʼָ����һ���ˣ���������
    }
      tail->next=head;                           //�����β���ӣ����ѭ����
      return tail;                               //return����tail

}
void output(LinkList L,int limit,int n)           //ģ��Լɪ��,Lģ����Χ�ɵ�Ȧ��limitΪ����ı�������ֵ��nΪ������
{
    int i;
    LinkList q;                                   //qΪ�м�ָ��
    while(n>0)
    {
        for(i=1;i<limit;i++)                      //����ѭ��
        {
            L=L->next;
        }
        q=L->next;
        printf("the %d people out,the password is %d\n",q->num,q->password);
        L->next=q->next;                           //Ҫ��ȥ���˵�ǰһ����ָ���һ���ˣ�������Ͽ�
        limit = q->password;                       //����һ���˵�������Ϊ��������
        free(q);                                   //�� q free������ʼ��һ�ֱ�����Ҳ��������˳�ȥ
        n--;                                       //��������һ
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
