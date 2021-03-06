#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct s_list{
    char number[11];
    char name[21];
    char subject[4][20];
    float goal[4];
    float average;
    struct s_list *next;
};
void create_list(struct s_list **headp,int n);
void compare(struct s_list **headp,int n);
int main(void)
{
     char search1[11];
     char search2[20];
     int i,b=0,N;
     printf("Please input the number of students.\n");
     scanf("%d",&N);//学生的数量
     float a;
     struct s_list *head=NULL,*p;
     printf("Input the information of every student.\n");
     create_list(&head,N);
     p=head;
     printf("\nIf you want change someone\'s point ,");
     printf("please input his student number ,else input # to leave.\n");
     scanf("%s",search1);
     for(;p!=NULL,search1[0]!='#';){
         if(strcmp(p->number,search1)==0){
            printf("Please input which subject\'point that you want change.\n");
            scanf("%s",search2);
            for(i=0;i<4;i++){
                if(strcmp(p->subject[i],search2)==0){
                    printf("Input new point.\n");
                    scanf("%f",&p->goal[i]);
                    p->average=(p->goal[0]+p->goal[1]+p->goal[2]+p->goal[3])/4;
                    break;
                }
            }
            printf("Continue correct? if continue please input student number,");
            printf(" else input # to leave.\n");
            scanf("%s",search1);
         }
         else
            p=p->next;
         if(p==NULL){
            printf("Not exist this student ,please input again.");
            printf("If you want to leave ,please input #.\n");
            scanf("%s",search1);
            p=head;
         }
     }
     printf("\n");
     p=head;
     while(p){
        puts(p->number);
        puts(p->name);
        for(i=0,a=0;i<4;i++){
            printf("%s:",p->subject[i]);
            printf("%-6.2f  ",p->goal[i]);
        }
        printf("平均成绩:%-6.2f\n",p->average);
        p=p->next;
     }
     compare(&head,N);
     return 0;
}
void create_list(struct s_list **headp,int n)
{
    int a,i,b;
    char sj[4][20]={"English","Math","Physics","C_language"};
    struct s_list *loc_head=NULL,*tail;
    loc_head=(struct s_list *)malloc(sizeof(struct s_list));
    for(a=0;a<4;a++){
        for(i=0;sj[a][i]!='\0';i++)
            loc_head->subject[a][i]=sj[a][i];
       loc_head->subject[a][i]='\0';
    }//将科目名称赋给数组
    scanf("%s",loc_head->number);
    scanf("%s",loc_head->name);
    for(a=0,i=0;a<4;a++){
        scanf("%f",&(loc_head->goal[a]));
        i=loc_head->goal[a]+i;
    }
    loc_head->average=i/4;
    tail=loc_head;
    for(b=1;b<n;b++){
        tail->next=(struct s_list *)malloc(sizeof(struct s_list));
        tail=tail->next;
        for(a=0;a<4;a++){
            for(i=0;sj[a][i]!='\0';i++)
                tail->subject[a][i]=sj[a][i];
        tail->subject[a][i]='\0';
        }
        scanf("%s",tail->number);
        scanf("%s",tail->name);
        for(a=0,i=0;a<4;a++){
            scanf("%f",&(tail->goal[a]));
            i=tail->goal[a]+i;
        }
        tail->average=i/4;
    }
    tail->next=NULL;
    *headp=loc_head;
}
void compare(struct s_list **headp,int n)
{
    int i,a,c,l;
    char e;
    float b;
    struct s_list *p;
    for(i=0;i<n-1;i++){
        p=*headp;
        for(a=0;a<n-i-1;a++,p=p->next){
                if(p->average>p->next->average){
                    for(c=0;c<11;c++){
                        l=p->number[c];
                        p->number[c]=p->next->number[c];
                        p->next->number[c]=l;
                    }
                    for(c=0;c<21;c++){
                        e=p->name[c];
                        p->name[c]=p->next->name[c];
                        p->next->name[c]=e;
                    }
                    for(c=0;c<4;c++){
                        b=p->goal[c];
                        p->goal[c]=p->next->goal[c];
                        p->next->goal[c]=b;
                    }
                    b=p->average;
                    p->average=p->next->average;
                    p->next->average=b;
                }
        }
    }
    p=*headp;
    printf("\nthe score in order:\n");
    while(p){
        puts(p->number);
        puts(p->name);
        for(i=0,a=0;i<4;i++){
            printf("%s:",p->subject[i]);
            printf("%-6.2f  ",p->goal[i]);
        }
        printf("平均成绩:%-6.2f\n",p->average);
        p=p->next;
     }
}
