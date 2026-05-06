#include <stdio.h>

void print_arr(int *arr, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        printf("%d ", arr[i]);
    }
    if (start < end)
        printf("\n");
}

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int *arr, int start, int end)
{

    int i = start - 1;
    int off_end = end;
    for (int j = start; j < off_end; j++)
    {
        if (arr[j] < arr[off_end])
        {
            i++;
            swap(arr, i, j);
        }
    }
    i++;
    swap(arr, i, off_end);

    return i;
}

void quicksort(int *arr, int start, int end)
{
    static int occur = 0;
    occur++;
    printf("Invocation: %d\n", occur);

    int mid;
    if (start < end)
    {
        mid = partition(arr, start, end);
        print_arr(arr, start, mid + 1);
        print_arr(arr, mid + 1, end + 1);
        quicksort(arr, start, mid - 1);
        quicksort(arr, mid + 1, end);
    }
}

int main(int argc, char *argv[])
{
    int arr[] = {9, 13, 9, 24, 23, 1, 26, 4, 5, 20};
    int size = sizeof(arr) / sizeof(arr[0]);

    quicksort((int *)arr, 0, size - 1);

    print_arr(arr, 0, size);

    return 0;
}