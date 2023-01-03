#include <iostream>
 
using namespace std;
 
bool arr[1024][1024];
 
 
void checkWhiteBlue(int x, int y, int size) {
 
    if (size <= 0) // 다풀고 추가
    {
        return;
    }
 
    bool flag = true;
    int i, j;
    bool tmp = arr[x][y];
 
    for (i = x; i < x + size; i++)
    {
        if (!flag)
            break;
 
        for (j = y; j < y + size; j++)
        {
            if (arr[i][j] != tmp)
            {
                flag = false;
                break;
            }
 
        }
    }
 
 
    if (flag)
    {
        if (tmp == false)
        {
            cout << 0;
        }
        else
        {
            cout << 1;
        }
 
    }
    else {
        cout << 'X';
        checkWhiteBlue(x, y, size / 2); // 1번 영역
        checkWhiteBlue(x, y + (size / 2), size / 2); // 2번 영역
        //전 문제 틀린 부분 반영하여 오류 수정 -> 위 아래 라인 SWAP
        checkWhiteBlue(x + (size / 2), y, size / 2); // 3번 영역
        checkWhiteBlue(x + (size / 2), y + (size / 2), size / 2); // 4번 영역
    }
 
 
 
}
 
int main() {
 
    //cin.tie(NULL);
    //ios::sync_with_stdio(false);
 
    int size;
    int i, j;
 
    cin >> size;
 
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            cin >> arr[i][j];
        }
    }
 
    checkWhiteBlue(0, 0, size);
 
 
    //X(1) X(1-1) X(1-1-1) 1(1-1-1-1)0(1-1-1-2)0(1-1-1-3)1(1-1-1-4) 1(1-1-2)0(1-1-3)0(1-1-4) 1(1-2) X(1-3) 1(1-3-1)0(1-3-2)0(1-3-3)1(1-4-4) 0(1-4)​
 
}