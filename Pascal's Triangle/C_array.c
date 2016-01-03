/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes, int* returnSize) {
    int** parr = NULL;
    int i,j;
    (*returnSize)=numRows;
    parr = malloc(sizeof(int*)*numRows);
    *columnSizes = (int *) malloc(sizeof(int) * numRows);
    for(i=0;i<numRows;i++){
        parr[i] = malloc(sizeof(int)*(i+1));
        (*columnSizes)[i] = i+1;
        for(j=0;j<=i;j++){
            if(j==0||j==i){
                parr[i][j] = 1;
            }else{
                parr[i][j] = parr[i-1][j-1]+parr[i-1][j];
            }
        }
    }
    return parr;
}