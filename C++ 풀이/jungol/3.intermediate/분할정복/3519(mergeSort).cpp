#include <iostream>

using namespace std;

int n;

void mergeSort(int arr[], int low, int  high, int tmp[]) {
    // 1. base condition
    if (low >= high) {
        return;
    }
    else {

        // 2. 분할(divide)
        int mid = (low + high) / 2;

        // 3. 정복(conquer)
        mergeSort(arr, low, mid, tmp);
        mergeSort(arr, mid + 1, high, tmp);

        // 4. 결합(merge)
        int i = low, j = mid + 1;
        for (int k = low; k <= high; k++) {
            if (j > high)
                tmp[k] = arr[i++];
            else if (i > mid)
                tmp[k] = arr[j++];
            else if (arr[i] <= arr[j])
                tmp[k] = arr[i++];
            else
                tmp[k] = arr[j++];
        }


        // 5. 복사(copy)
        for (i = low; i <= high; i++)
            arr[i] = tmp[i];

        // *** 출력 하는 위치 ***

        for (i = 0; i < n; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    cin >> n;

    int* arr = new int[n];
    int* tmp = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1, tmp);

    delete[] arr;
    delete[] tmp;

    return 0;

}