#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "my_mat.h"




int main(){
    void inputHandler();
    inputHandler();
   
    
    return 0;
}

void inputHandler(){
    
    char x[2] ;
    int shortDis;
    do{
        scanf("%s", x);
        if((strcmp(x, "A") == 0))
        {
            matrixInPut();
        }
        else if((strcmp(x, "B") == 0)){
            pathExists();
        }
        else if((strcmp(x, "C") == 0)){
            shortDis = pathMinDistance();
            printf("%d\n", shortDis);
        }
        else if((strcmp(x, "D") == 0)){
        }
    }
    while((strcmp(x, "D") != 0));
}