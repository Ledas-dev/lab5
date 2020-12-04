//


#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <locale>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include <queue>

void BFSD(int p,int arr);
int **M1, *visit;

void BFSD(int p, int arr){
  std::queue <int> Q;
  Q.push(p);
  visit[p] = 0;
  while(!Q.empty()){
    p = Q.front();
    printf("%d ", p);
    Q.pop();
    for(int i = 0; i<=arr; i++){
      if(M1[p][i] == 1 && visit[i] == -1){
        Q.push(i);
        visit[i] = visit[p] + 1;
      }
    }
  }
}

int main()
{
  srand(time(NULL));

  int p;
  int arr;
  int s = 0;
float k;
  printf("Введем матрицу");
  scanf("%d",&arr );

  M1 = (int**)malloc(arr*sizeof(int));
  for(int i = 0; i<arr;i++){
      M1[i] = (int *)malloc(arr*sizeof(int));
  }
  visit = (int*)malloc(arr*sizeof(int));

  for(int i = 0;i<arr;i++){
    visit[i] = -1;
  }

  printf("Введем матрицу:\n");
  for(int i = 0;i<arr;i++){
    for(int j = 0;j<i+1;j++){
       k = rand()%100;
       if(k>70){
         k = 1;
       }else{
         k = 0;
       }
      if(i != j ){
        M1[i][j] = k;
        M1[j][i] = k;
      }else{
        M1[i][j] = 0;
      }
    }
  }
  for(int i = 0;i<arr;i++){
    for(int j = 0;j<arr;j++){
      printf("%d ",M1[i][j] );
    }
    printf("\n");
  }
  printf("\n");
  for(int i = 0;i<1;i++){
  printf("Выберете вершину с которойъ начанете обход:");
  scanf("%d", &p);
    if(p<=arr){
      printf("\nВы проходите");

    }else{
      printf("Выберете новую координату\n");
      i--;
    }
  }

  printf("\n");
    BFSD(p, arr);
    printf("\n");

    for(int i=0; i<arr; i++){
      printf("%d ", visit[i]);
    }

}
