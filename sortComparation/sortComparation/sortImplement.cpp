#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

template <class T>

int getArrayLen(T& array)

{//return size of array

return (sizeof(array) / sizeof(array[0]));

}

//bubble sort          
void Bubble_Sort(int *list,int count)
{
     int flag = true;
     int i = 0,j = 0;
     for(i=0;i<=count&&flag;i++)
     {
         flag = false;
         for(j=count -1;j>=i;j--)
         {
             if(list[j]<list[j-1])
             {
                 swap(list[j],list[j-1]);
                 flag = true;
             }
         }
     }

}

//select sort
void Select_Sort(int *list,int count)
{
    int min,i,j;
    for(i=0;i<count;i++)
    {
         min = i;
         for(j=i+1;j<count;j++)
         {
             if(list[i]>list[j])
             {
                 min = j;
             }
         }
         if(min!=i)
         {
              swap(list[i],list[min]);
		 }

    }
}

//insert sort
        void Insert_Sort(int *list,int count)
        {
            int temp;//pointing to temporary address
            int i,j;
            for(i=1;i<count;i++)
            {
                if(list[i]<list[i-1])
                {
                    temp = list[i];
                    for(j=i-1;list[j]>temp&&j>=0;j--)
                    {
                        list[j+1] = list[j];
                    }
                    list[j+1] = temp;
                }
            }
        }

//shell sort
void Shell_Sort(int *list,int count)
{
    int i,j;
    int temp;
    int increment = count;
    do
    {
        increment = increment/3+1;
        for(i = increment;i<count;i++)
        {
             if(list[i]<list[i-increment])
             {
                  temp = list[i];
                  for(j=i-increment;j>=0&&list[j]>temp;j-=increment)
                  {
                       list[j+increment] = list[j];
                  }
                  list[j+increment] = temp;
             }
                    
        }

    }while(increment>1);
}

//transfor into a heap
void Heap_Adjust(int *list,int s,int m)
{
    int temp = list[s];
    for(int j=2*s+1;j<=m;j = 2*j+1)
    {
        if(list[j]<list[j+1]&&j<m)
        {
            j++;
        }
        if(temp>list[j])
            break;
        list[s] = list[j];
        s = j;
    }
    list[s] = temp;
}

//heap sort
void Heap_Sort(int *list,int len)
{
    //create a heap
    for(int s = len/2-1;s>=0;s--)
    {
        Heap_Adjust(list,s,len-1);
    }

    //sort
    for(int i = len-1;i >= 1;i--)
    {
        swap(list[0],list[i]);
        Heap_Adjust(list,0,i-1);
    }

}

//merge sort
void Merge(int *list,int start,int mid,int end)
{
    const int len1 = mid -start +1;
    const int len2 = end -mid;
    const int len = end - start +1;
    int i,j,k;


    int * front = (int *)malloc(sizeof(int)*len1);
    int * back = (int *)malloc(sizeof(int)*len2);

    for(i=0;i<len1;i++)
        front[i] = list[start+i];
    for(j=0;j<len2;j++)
        back[j] = list[mid+j+1];

    for(i=0,j=0,k=start;i<len1&&j<len2&&k<end;k++)
    {
        if(front[i]<back[j])
        {
            list[k] = front[i];
            i++;
        }else
        {
            list[k] = back[j];
            j++;
        }
    }
    while(i<len1)
    {
        list[k++] = front[i++];
    }
    while(j<len2)
    {
        list[k++] = back[j++];
    }

}

//merge sort interface
void MSort(int *list,int start,int end)
{
     if(start<end)
     {
          int mid = (start+end)/2;
          MSort(list,0,mid);
          MSort(list,mid+1,end);
          Merge(list,start,mid,end);
	 }
}
void Merge_Sort(int *list,int count)
{
     MSort(list,0,count-1);
}

int Partition(int *list,int low,int high)
{
     int pivotKey;
     pivotKey = list[low];
     while(low<high)
     {
          while(low<high&&list[high]>=pivotKey)
          {
               high--;
          }
               swap(list[low],list[high]);
          while(low<high&&list[low]<=pivotKey)
          {
               low++;
          }
               swap(list[low],list[high]);
     }
            return low;
}

//quick sort
void Qsort(int *list,int low,int high)
{
    int pivot;
    if(low<high)
    {
         pivot = Partition(list,low,high);
         Qsort(list,low,pivot-1);
         Qsort(list,pivot+1,high);
    }
}
//quick sort
void Quick_Sort(int *list,int count)
{
     Qsort(list,0,count-1);
}




int main(){
	//int n;
	//cout<<"enter the size of array:";
	//cin>>n;
	//int a[n];
	clock_t start,finish;
    double totaltime;
    start=clock();

  

    int length = 1000;
	int a[1000];
	for(int i=0; i<length; i++)
	{
        a[i]=rand()%10000+1;
	}
	//int a[]={3,4,6,2,1,8,5,7,10,9,2,4,2,4,24,42,5,5,2,423,234,2,4,456,456,2,46,6,76,76,767,556,67,76,79,734,67,89,77,9};
	//Bubble_Sort(a,getArrayLen(a));
	//Select_Sort(a,getArrayLen(a));
	//Insert_Sort(a,getArrayLen(a));
	//Shell_Sort(a,getArrayLen(a));
	Merge_Sort(a,getArrayLen(a));
	//Heap_Sort(a,getArrayLen(a));
	//Quick_Sort(a,getArrayLen(a));
	for(int i=0;i<getArrayLen(a);i++){
	    cout<<a[i]<<" "<<endl;
	}


	finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<"\nrunning time:"<<totaltime<<"second!"<<endl;
	system("pause");
	return 0;
}
