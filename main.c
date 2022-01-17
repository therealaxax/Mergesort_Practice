#include <stdio.h>
#include <stdlib.h>

int main()
{
    int list[8];
    list[0] = 90;
    list[1] = 25;
    list[2] = 10;
    list[3] = 71;
    list[4] = 94;
    list[5] = 22;
    list[6] = 59;
    list[7] = 74;
    int i = 0;
    int keycomparisons = 0;

    keycomparisons = keycomparisons + mergesort(0,7,list);

    printf("Please enter 1 to continue\n");
    scanf("%d");

    for(i=0;i<8;i++){
        printf("array element %d \n", list[i]);
    }

    printf("Number of key comparisons: %d \n", keycomparisons);

    printf("Hooray for Gareth!\n");
    return 0;
}

int mergesort(int n, int m, int list[]){
    int keycomparisons = 0;
    int mid = (n+m)/2;
    if(m-n<=0)return;
    else if(m-n>1){
        keycomparisons = mergesort(n,mid,list) + keycomparisons;
        keycomparisons = mergesort(mid+1,m,list) + keycomparisons;
    }
    keycomparisons = keycomparisons + merge(n,m,list);
    return keycomparisons;
}

int merge(int n, int m, int list[]){
    int mid = (n+m)/2; //for partitioning the list into 2 halves (both halves are sorted)
    int a = n, b = mid+1, i, tmp, keycomparisons = 0;
    if(m-n<0)return keycomparisons; //if (m-n <= 0) return;
    while(a<=mid&&b<=m){ //while both halves are not empty
        int cmp = compare(list[a], list[b]); //compare the first elements of the two halves
        keycomparisons++; //increase number of key comparisons by 1
        if(cmp>0){ //if first element of the second half is smaller
            tmp=list[b++];
            for(i=++mid;i>a;i--)
                list[i]=list[i-1];
            list[a++]=tmp; //move the first element of the second half to the end of the merged list
        }else if (cmp<0) a++; //if first element of first half is smaller, first element of first half joins the end of the merged list
        else{ //cmp == 0 is true, the first elements of the 2 halves is equal
            if(a==mid&&b==m)break; //if they are the last elements, break
            tmp=list[b++];
            a++;
            for(i=++mid;i>a;i--)
                list[i]=list[i-1];
            list[a++]=tmp; //move the first element of second half to the end of the merged list
        }
    }return keycomparisons;
}

int compare(int a, int b){
    if(a>b)return 1;
    else if(a==b)return 0;
    else return -1;
}
