import java.util.Arrays;
import java.util.Scanner;

// Shell sort
class ShellSort
{
  void shellSort(int array[], int n)
  {
    for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
    int temp = array[i];
    int j;
    for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
    {
      array[j] = array[j - interval];
    }
    array[j] = temp;
    }
  }
  }

  public static void main(String args[])
  {

  int n;
  Scanner sc=new Scanner(System.in);
  System.out.print("Enter the number of elements you want to store: ");

  n=sc.nextInt();

  int[] data = new int[10];
  System.out.println("Enter the elements of the array: ");
  for(int i=0; i<n; i++)
  {
  data[i]=sc.nextInt();
  }
  System.out.println("Array elements are: ");
  for (int i=0; i<n; i++)
	{
	System.out.println(data[i]);
	}
  int size = data.length;
  ShellSort ss = new ShellSort();
  ss.shellSort(data, size);
  System.out.println("Sorted Array in Ascending Order: ");
  System.out.println(Arrays.toString(data));
  }
}
