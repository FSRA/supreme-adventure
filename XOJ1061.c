#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char name[15];
    int start;
    int end;
}task;

int main()
{
    int n,i,j,k,t,count=0,start1,start2,end1,end2;
    char temp[15];
    task*miss;
    scanf("%d",&n);
    miss=(task*)malloc(sizeof(task)*n);
    for(i=0;i<n;i++)
    {
        scanf("%s %d:%d %d:%d",miss[i].name,&start1,&start2,&end1,&end2);
        miss[i].start=start1*60+start2;
        miss[i].end=end1*60+end2;
    }
    for(i=0;i<n;i++)
        for(j=0;j<n-1;j++)
        {
            if(miss[j].end>miss[j+1].end)
            {
                strcpy(temp,miss[j].name);
                strcpy(miss[j].name,miss[j+1].name);
                strcpy(miss[j+1].name,temp);
                t=miss[j].start;
                miss[j].start=miss[j+1].start;
                miss[j+1].start=t;
                t=miss[j].end;
                miss[j].end=miss[j+1].end;
                miss[j+1].end=t;
            }
        }
    k=0;
    count++;
    for(i=1;i<n;i++)
    {
        if(miss[j].start>=miss[k].end)
        {
            count++;
            k=i;
        }
    }
    printf("%d\n",count);
    k=0;
    printf("%s ",miss[0].name);
    for(i=1;i<n;i++)
    {
        if(miss[i].start>=miss[k].end)
        {
            printf("%s ",miss[i].name);
            k=i;
        }
    }
    printf("\b");//光标往前移动一个字符
    return 0;
}
