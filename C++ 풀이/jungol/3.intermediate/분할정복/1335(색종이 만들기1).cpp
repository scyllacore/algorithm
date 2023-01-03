#include <iostream>
 
using namespace std;
 
bool arr[128][128];
int white = 0;
int blue = 0;
 
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
            white++;
        }
        else
        {
            blue++;
        }
 
    }
    else {
        checkWhiteBlue(x, y, size / 2); // 1번 영역
        checkWhiteBlue(x + (size / 2), y, size / 2); // 처음에 2번 영역  -> 2번 영역이 아니고 3번 영역
        //아래 위라인 바꿔서 풀음 -> 다음 문제에 오류 발생 시킴
        checkWhiteBlue(x, y + (size / 2), size / 2); // 처음에 3번 영역  -> 3번 영역이 아니고 2번 영역
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
 
    cout << white << '\n' << blue;
 
 
 
 
}
 
//넓이가 1x1인 공간까지 탐색