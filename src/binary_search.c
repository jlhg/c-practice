#include <stdio.h>


void binary_search(int data[], int len, int search);


void binary_search(int data[], int len, int search)
{
        int low = 0;
        int high = len - 1;

        while (low <= high) {
                int mid = (low + high) / 2;

                if (data[mid] == search) {
                        printf("%d\n", mid);
                        return;
                } else if (data[mid] > search) {
                        high = mid - 1;
                } else if (data[mid] < search) {
                        low = mid + 1;
                }
        }
}


int main()
{
        int data[] = {3, 7, 14, 20, 23, 32, 41, 44, 56, 57, 73, 89, 93};
        int len = 12;
        int search = 44;
        binary_search(data, len, search);

        return 0;
}
