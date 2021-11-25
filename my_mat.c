#include <stdio.h>
#include <string.h>
#include <limits.h>

#define SIZE 10
#define inf INT_MAX
int mat[SIZE][SIZE];

void matrixInPut(){
    for(int i = 0; i < (SIZE * SIZE); i++){
        scanf("%d", &mat[i/SIZE][i % SIZE]);
        // check if zero diagonal
        if(mat[i/SIZE][i % SIZE] == 0 && i/SIZE != i%SIZE){
            mat[i/SIZE][i % SIZE] = inf;
        }
    }

}

int IJInput(){
    int i;
    scanf("%d", &i);
    return i;
}
int helper (int l, int k ,int m){
    int d1;
    if(l == k || m == k || l == m){
        return 0;
    }
    if(mat[k][l] < inf && mat[k][m] < inf){
        d1 = mat[k][l] + mat[k][m];
    }
    else{
        d1 = inf;
    }
    if(d1 < mat[l][m]){
        mat[l][m] = d1;
        mat[m][l] = d1;
    }
    return 1;
}

void pathExists(){
    int i,j;
    int IJInput();
    i = IJInput();
    j = IJInput();
    if(i == j){
        printf("False\n");
        return;
    }
    if(mat[i][j] < inf){
        printf("True\n");
        return;
    }
    // if there is a path
    for(int k = 0; k < SIZE; k++){
        for(int l = 0; l < SIZE; l++){
            for(int m = 0; m < SIZE; m++){
                if(helper(l, k, m) == 0){
                    continue;
                }
                else if(mat[k][i] < inf && mat[k][j] < inf){
                    printf("True\n");
                    return;
                }
            }
        }
    }
    printf("False\n");
}

int pathMinDistance(){
    int i,j;
    int IJInput();
    i = IJInput();
    j = IJInput();
    if(i == j){
        return -1;
    }
    for(int k = 0; k < SIZE; k++){
        for(int l = 0; l < SIZE; l++){
            for(int m = l + 1; m < SIZE; m++){
                helper(l, k, m);
            }
        }
    }
    if(mat[i][j] < inf){
        return mat[i][j];
    }
    else{
        return -1;
    }
}