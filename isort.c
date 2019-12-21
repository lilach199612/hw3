#include <stdio.h>
#define numbers 50
void shift_element(int* arr, int i)
{
    int pre=*arr;
    int next;
    int *j=arr;
    while(j<arr+i)    
    {
        next=*(j+1);
        *(j+1)=pre;
        pre=next;
        j++;
    }
}
void insertion_sort(int* arr , int len)
{
    int *j=arr;
    for(int i=1;i<len;i++)
    {
        int *certain=(j+i);
        int count=0;
        int save=*certain;
        certain--;
        while(certain>=arr&&save<*certain) //check how much number to move
        {
            count++;
            certain--;
        }
        certain++;
        shift_element(certain,count);
        *certain=save;
    }
}
int main()
{
    int array[numbers];
    printf("Enter 50 numbers for the array \n");
    for(int i=0;i<numbers;i++)//input of 50 numbers
    {
        if (scanf("%d",&*(array+i)) < 1)
            return 1;
    }
    insertion_sort(array , numbers);
     for(int i=0;i<numbers;i++)
    {
        if(i+1==numbers)
            printf("%d \n",*(array+i));
        else
            printf("%d,",*(array+i));
    }
}