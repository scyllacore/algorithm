#include <stdio.h>
#include <functional>
#include <algorithm>
 
int main()
{
    int m, s, c;
    int rooms[200];
    int sub[200];
 
    scanf("%d %d %d", &m, &s, &c);
    for (int i = 0; i < c; i++)
        scanf("%d", rooms + i);
 
    std::sort(rooms, rooms + c);
 
    for (int i = 0; i < c - 1; i++)
        sub[i] = rooms[i + 1] - rooms[i] - 1;
 
    std::sort(sub, sub + (c - 1), std::greater<int>());
 
    int res = rooms[c - 1] - rooms[0] + 1;
    for (int i = 0; i < m - 1 && i < c - 1; i++)
        res = res - sub[i];
 
    printf("%d", res);
 
    return 0;
}