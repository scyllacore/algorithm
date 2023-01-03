#include <stdio.h>
#define max(a,b)  (((a) > (b)) ? (a) : (b))


int main()
{
    int n;

    scanf("%d", &n);

    int totalMax= -1000; // 최종 결과가 될 변수
    int greaterSum=0 ; // 커지는 경우 더할 변수
    int allSum= 0; // 0보다 크면 더하는 변수

    // 입력되는 원소들을 저장한다.
    for (int i = 0; i < n; ++i)
    {
        int val;
        scanf("%d", &val);

        // 입력된 값이 0이상이면 항상 max가 커지므로 더한다.
        if (val >= 0)
        {
            greaterSum += val;
            allSum += val;
        }
        else
        {
            // 입력된 값이 0보다 작은 경우 작아지므로 초기화한다.
            greaterSum = 0;
            // 0보다 작아지지 않은 경우 더 커질 가능성이 있으므로 더한다.
            if (allSum + val > 0)
            {
                allSum += val;
            }
            // 음수가 된 경우 max가 될 수 없으므로 초기화한다.
            else
            {
                allSum = 0;
            }
        }

        // 최댓값을 저장한다.
        totalMax = max(max(greaterSum, allSum), totalMax);
    }

    printf("%d", totalMax);
}
