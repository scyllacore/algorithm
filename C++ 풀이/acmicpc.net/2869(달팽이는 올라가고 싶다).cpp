#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b, v;

    cin >> a >> b >> v;

    /*int sum = 0,cnt=0;


    for(;;)
    {
        sum += a;
        if(sum>=v)
        {
         break;
        }
        sum -= b;

        cnt++;
    }

    cout << cnt+1;
    */


    double result = (double)(v - b) / (a - b); // (A-B)(X-1) + A

    if (result > floor(result))
    {
        cout << (int)result + 1; // 소수점이 나오는 경우는 좀 더 올라가야 함으로 하루가 더 걸린다.
    }
    else
    {
        cout << (int)result; // 정확히 나눠지는 순간은 +A 만큼 올라가서 딱 정상에 도달했을 때 마무리 되는 경우
    }



}

//https://hyunipad.tistory.com/58