class Solution {
    public int[][] solution(int[][] arr) {

        int row = arr.length;
        int col = arr[0].length;

        int[][] newArr;

        if(row>col){    
            newArr = new int[row][row];

            for(int i=0; i<row; i++){
                System.arraycopy(arr[i],0,newArr[i],0,arr[i].length);
            }

        }else{
            newArr = new int[col][col];

             for(int i=0; i<row; i++){
                System.arraycopy(arr[i],0,newArr[i],0,arr[i].length);
            }
        }


        return newArr;
    }
}

/*
class Solution {
    public int[][] solution(int[][] arr) {

        int row = arr.length;
        int col = arr[0].length;

        int[][] newArr;

        if(row>col){    
            newArr = new int[row][row];

            for(int i=0; i<row; i++){
                System.arraycopy(arr[i],0,newArr[i],0,arr[i].length);
            }

        }else{
            newArr = new int[col][col];

             for(int i=0; i<row; i++){
                System.arraycopy(arr[i],0,newArr[i],0,arr[i].length);
            }
        }


        return newArr;
    }
}
 */