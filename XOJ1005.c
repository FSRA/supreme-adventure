#include<stdio.h>
#include<stdlib.h>
/*
我定义了一个函数next_permutation来计算下一字典序，算法如下：
1）先从后往前找到一对升序组，设其坐标为a和a+1
2）从a+1到数组末尾找到一个大于a的最小的数，设其坐标为b
3）交换a和b位置的值
4）a+1位置到末尾之间的数组逆序

例：12354
1）从后往前找到第一对升序组（3， 5），若数组从0开始储存，这里a＝2，c＝3
2）从数组坐标为3的地方（值为5）开始到结束（值为4），找到b＝4（值为4）
3）即交换3和5，数组变为 12453
4）数组第三个位置到末尾（即3到4）逆序，数组变为12435
这样就找到了数组的下一个字典序*/

int factorial(int n)
{
    int result=1,i;
    for(i=2;i<=n;i++)
    {result*=i;}
    return result;
}

//改变数组顺序为下一个字典序
void next_permutation(int *arr,int length)
{
    int a=-1,b=-1;
    int min=100,i,temp;
    //找a
    for(i=length-2;i>=0;i--)
    {
        if(arr[i]<arr[i+1])
        {
            a=i;
            break;
        }
    }
    if(a==-1) return;//说明数组已经是逆序的了，不存在下一个字典序
    //找b
    for(i=a+1;i<length;i++)
    {
        if(arr[i]>arr[a]&&arr[i]<min)
        { b=i;min=arr[i];}
    }
    temp=arr[a];arr[a]=arr[b];arr[b]=temp;
    for(i=a+1;i<=(a+length-1)/2;i++)
    {
        temp=arr[i];arr[i]=arr[a+length-i];arr[a+length-i]=temp;
    }
}
int main()
{
    int n,i,j;
    int arr[11];

        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            arr[i]=i+1;
        }
        //全排列一共是n!先打印结果，再改变数组至下一个字典序
        for(j=1;j<=factorial(n);j++)
        {
            for(i=0;i<n-1;i++)
            {
                printf("%d ",arr[i]);
            }
            printf("%d",arr[n-1]);
            printf("\n");
            if(j!=factorial(n))
            next_permutation(arr,n);
        }
}
