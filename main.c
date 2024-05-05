#include <stdio.h>
#include <stdbool.h>

/**
 *  This is trivial
 * @param x
 * @return Absolute value
 */

int abs(int x){
    if(x<0)
        return -x;
    else
        return x;
}
/**
 * 1 --> Above Main Diagonal
 * 0 --> Main Diagonal
 * -1 --> Below Main Diagonal
 *
 *
 * @param row
 * @param column
 * @return
 */
int tellMeDiagonalType(int row, int column){
    if(row == column)
        return 0;
    else if(row > column)
        return -1;
    else
        return 1;
}


/** --> This roxygen is super cool btw
 * 'row==i' is impossible in this encoding since we are assuming already there can only be a queen per row
 *
 *  With '(row+1==column)==(i+1==S[i])' we are checking if both are on the main diagonal
 *
 *  And with 'S[i]+i==row+column' we are checking whether they are in the second diagonal
 * @param S solution array
 * @param s_count size of solution array (excluding our current choice)
 * @param row row of the move we want to make
 * @param column column of the move we want to make
 * @return whether is a valid queen or not
 */
bool isInvalidQueen(int s_count,int S[s_count],int row,int column){
    for (int i = 0; i < s_count; ++i)
        if(column==S[i]||row == i||S[i]+i==row+column||(abs(row+1-column)==abs(i+1-S[i]) && tellMeDiagonalType(row+1,column)==
                                                                                          tellMeDiagonalType(i+1,S[i])))
            return true;
    return false;
}

/**
 *  What if we want more than one solution?
 *  - Just copy the solution and keep doing backtracking.
 * @return
 */
int main() {
    //printf("Hello, World!\n");
    //S[i] = {j0,j1,j2,j3} where j means the queen is located on j th column so that state S[i] = {0,0,0,0} would mean that we haven't decided yet
    // State {1,1,1,1} would mean that all queens are located on 1st column of each row
    // State {1,2,3,4} would mean that all my queens are located on the main diagonal
    // State {4,3,2,1} would mean that all my queens are located on the second diagonal and so on
    // It all depends on how you are encoding information
    int n = 4;
    int i =0;
    int S[n];
    int snapshot[n];
    for (int i = 0; i < n; ++i) {
        S[i] = 0;
        snapshot[i] = 0;
    }
    while(true){
        S[i]++;
        if(S[i]==5){
            if(i==0){
                printf("We have reached the end!! :D");
                return 0;
            }
            else{
                S[i] = 0;
                i--;
            }
        }else{
            if(!isInvalidQueen(i,S,i,S[i]))
                i++;
            if(i==n){
                printf("(");
                for (int j = 0; j < n; ++j) {
                    printf("%d,",S[j]);
                }
                printf(")\n");
                i--;
            }
        }
    }
    //return 0;
}