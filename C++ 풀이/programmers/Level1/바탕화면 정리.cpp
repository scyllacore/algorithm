#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX -1
#define MIN 51

vector<int> solution(vector<string> wallpaper) {
    int minY, minX;
    int maxY, maxX;

    minY = minX = MIN;
    maxY = maxX = MAX;

    int row = wallpaper.size();
    int col = wallpaper[0].size();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) { // ó���� �̰� ���µ�.. j for�� ������ col�̾ƴ� row�� �����صּ� ����.
            if (wallpaper[i][j] == '#') {
                minY = min(i, minY);
                minX = min(j, minX);
                maxY = max(i, maxY);
                maxX = max(j, maxX);
            }
        }
    }

    return { minY,minX,maxY + 1,maxX + 1 };

}

/* ������ ���
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 0
#define MIN 51

vector<int> solution(vector<string> wallpaper) {
    int minY,minX;
    int maxY,maxX;

    minY = minX = MIN;
    maxY = maxX = MAX;

    int row = wallpaper.size();
    int col = wallpaper[0].size();

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(wallpaper[i][j] == '#'){
                minY = i;
                break;
            }
        }

        if(minY != MIN){
            break;
        }

    }

    for(int i=0; i<col; i++){
        for(int j=0; j<row; j++){
            if(wallpaper[j][i] == '#'){
                minX = i;
                break;
            }
        }

        if(minX != MIN){
            break;
        }

    }

    for(int i=row-1; i>=0; i--){
        for(int j=col-1; j>=0; j--){
            if(wallpaper[i][j] == '#'){
                maxY = i;
                break;
            }
        }

        if(maxY != MAX){
            break;
        }

    }

     for(int i=col-1; i>=0; i--){
        for(int j=row-1; j>=0; j--){
            if(wallpaper[j][i] == '#'){
                maxX = i;
                break;
            }
        }

         if(maxX != MAX){
            break;
        }

    }

    return {minY,minX,maxY+1,maxX+1};


}
*/