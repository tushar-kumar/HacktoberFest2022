import java.util.Scanner;

public class MergeSort {

    static void merge(int arr[], int start, int mid, int end){
        int n1 = mid - start + 1;
        int n2 = end - mid;

        int L[] = new int[n1];
        int R[] = new int[n2];

        for(int i=0;i<n1;i++){
            L[i] = arr[start+i];
        }
        for(int i=0;i<n2;i++){
            R[i] = arr[mid + 1 + i];
        }

        int i=0, j=0;
        int k = start;

        while(i < n1 && j < n2){
            if(L[i] <= R[j]){
                arr[k] = L[i];
                i++;
            }
            else{
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while(i < n1){
            arr[k] = L[i];
            i++;
            k++;
        }

        while(j < n2){
            arr[k] = R[j];
            j++;
        }
    }

    static void mergeSort(int arr[], int start, int end){
        if(start < end){
            int mid = start + (end - start) / 2;

            mergeSort(arr, start, mid);
            mergeSort(arr, mid+1, end);
            merge(arr,start,mid,end);
        }
    }

    static void printArray(int[] arr, int size)
    {
        for (int i = 0; i < size; i++)
            System.out.print(arr[i] + " ");
  
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

        int[] arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = scan.nextInt();
        }

        System.out.println("Array before sorting");
        printArray(arr, n);
        System.out.println();

        mergeSort(arr, 0, n - 1);

        System.out.println("Array after sorting ");
        printArray(arr, n);
        System.out.println();
        
        scan.close();
    }
}
