#include <bits/stdc++.h>
using namespace std;

int find_med(int a[],int n)                                  //this funcion is for finding median element out of 5(or less than 5)by sorting.
 { 
       	sort(a,a+n);
	return a[n/2];
}
void swap(int &a,int &b)                                           //this function is for swaping two number
{
	int temp=a;
	a=b;
	b=temp;
}
int partition(int a[],int left,int right,int x)               //here x is pivot .
{                                                                        // the number which is less than pivot that  is on left side
	int i=left;                                              //number which is greater than pivot  that is on right  side
              int k ;                                                  	
              for (k=left;k<right;k++)                       //this loop is find the pivot in array and swap with last element of array
	{
		if(a[k]==x)
		{
			break;
		}
	}
	swap(a[k],a[right]);
	
	for(int j=left;j<=right-1;j++)
	{
		if(a[j]<=x)
		{
			swap(a[i],a[j]);
			i++;
			
		}
	}
	
	swap(a[i],a[right]);                                                       // this function return pivot index in sorted array.
	return i;
}
int Find_Kth_Element(int a[],int p,int q,int k)                                   //function for finding kth smallest element
{
	if(k>0  && k<=q-p+1)                                                       //if k is in range of array length then follow this code
	{                                                                                       //otherwise return INT_MAX
		int n = q-p+1;                                                    //size of array
		int i;
		int mid[(n+4)/5];                                                //this array store the median of each group		                                                                           		                                                                         //size of this array is floor function ( n/5 ).
		for (i=0;i<n/5;i++)   		
                            {
			int b[5];
			for (int j=0;j<5;j++)
			{
				b[j]=a[p+i*5 + j];                 //divide array in sunarray of 5 element
			}
			mid[i]=find_med(b,5);                      //and then find median of each array.
		}
		
		if(i*5<n)                                                 //if size is not in multiple of 5 then remaining some element
		{                                                            //find the median of some remaining element.
			int c[5];
			int sub=n-i*5;
			for(int k=0;k<sub;k++)
			{
				c[k]=a[p+i*5+k];
			}
			mid[i]=find_med(c,sub);
			i++;
		}
		
		int pivot;                                                            		
                             if (i==1)
		{
			pivot=mid[i-1];
		}
		else
		{
			pivot=Find_Kth_Element(mid,0,i-1,i/2);          //find median of median array using. recursion.
                             }
		
		int index = partition(a,p,q,pivot);         //here we call partition according to median of median array
		
		if (index-p == k-1)                                              //if index is  kth element then rerurn element
		{
			return a[index];
		}
		else if (index-p > k-1)                                       //if k is less than index then call recursion for left part
		{
			return Find_Kth_Element(a,p,index-1,k);
		}
		else                                                                 //if k is greter than index then call recursion for right part
		{
			return Find_Kth_Element(a,index+1,q,k-index+p-1);
		}
	}
	
	return INT_MAX;
}
int main() {
    cout<<"ENTER THE SIZE OF ARRAY:";
    int n;
    cin>>n;
    int a[n];
     cout<<"ENTER THE ELEMENTS OF ARRAY:";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"ENTER THE NUMBER K WHICH SMALLEST ELEMENT "<<endl;
    int k;
    cin>>k;
	cout<<"K TH SMALLEST ELEMENT IS :"<<Find_Kth_Element(a,0,n-1,k);
	return 0;
}
