#include <stdio.h>

void interpolation_search(int data[], int len, int search);

void interpolation_search(int data[], int len, int search)
{
        int low = 0;
        int high = len - 1;

        while (low <= high) {
                int mid = low + (high - low) * (search - data[low])
                        / (data[high] - data[low]);

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
        int data[] = {5, 12, 19, 26, 37, 44, 60, 65, 73, 85};
        int len = 10;
        int search = 44;
        interpolation_search(data, len, search);
        return 0;
}
