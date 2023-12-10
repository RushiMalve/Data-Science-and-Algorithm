import java.util.*;
import java.util.Scanner;

class MergeSortExample
{
    void merge(int arr[],int left,int mid,int right)
    {
        int ls=mid-left+1;	//divide equal array
        int rs=right-mid;	//divide equal array

	//create array
        int left_arr[]=new int[ls];
        int right_arr[]=new int[rs];

	//copy array
        for(int i=0;i<ls;i++)
        {
            left_arr[i]=arr[left+i];
        }
        for(int j=0;j<rs;j++)
        {
            right_arr[j]=arr[mid+1+j];
        }

	//counter left and right array
        int i=0;
        int j=0;
	//initialize head size value of array
        int k=left;
        while(i<ls && j<rs)
        {
            if(left_arr[i]<right_arr[j])
            {
                arr[k]=left_arr[i];
                i++;
            }
            else
            {
                arr[k]=right_arr[j];
                j++;
            }
            k++;	//update array
        }

	//merge remaining
        while(i<ls)
        {
            arr[k]=left_arr[i];
            i++;
            k++;
        }
        while(j<rs)
        {
            arr[k]=right_arr[j];
            j++;
            k++;
        }
    }


    void sort(int arr[],int l,int r)
    {
        if(r>l)
        {
            int mid=(r+l)/2;
            sort(arr,l,mid);
            sort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }


    public static void main(String args[])
    {

      int n;
      Scanner sc=new Scanner(System.in);
      System.out.print("Enter the number of elements you want to store: ");

      n=sc.nextInt();

      int[] arr = new int[10];
      System.out.println("Enter the elements of the array: ");
      for(int i=0; i<n; i++)
      {
          arr[i]=sc.nextInt();
      }
      System.out.println("Array elements are: ");
      for (int i=0; i<n; i++)
      {
          System.out.println(arr[i]);
      }

      MergeSortExample mse=new MergeSortExample();
      mse.sort(arr,0,arr.length-1);
      System.out.println("\nArray after sorting");
      for(int i:arr)
      System.out.print(i+"\t");
    }
}
