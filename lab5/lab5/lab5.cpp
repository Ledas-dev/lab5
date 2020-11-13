// lab5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

void BFS(int p,int arr);
int **M1, *visit;

void BFS(int p, int arr){
  std::queue <int> Q;
  Q.push(p);
  visit[p] = 1;
  while(!Q.empty()){
    p = Q.front();
    printf("%d ", p);
    Q.pop();
    for(int i = 0; i<=arr; i++){
      if(M1[p][i] == 1 && visit[i] == false){
        Q.push(i);
        visit[i] = 1;
      }
    }
  }
}

int main()
{
  srand(time(NULL));

  int p;
  int arr;


  printf("Введем матрицу");
  scanf("%d",&arr );

  M1 = (int**)malloc(arr*sizeof(int));
  for(int i = 0; i<arr;i++){
      M1[i] = (int *)malloc(arr*sizeof(int));
  }
  visit = (int*)malloc(arr*sizeof(int));

  for(int i = 0;i<arr;i++){
    visit[i] = 0;
  }

  printf("Введем матрицу:\n");
  for(int i = 0;i<arr;i++){
    for(int j = 0;j<i+1;j++){
      float k = rand()%2;
      if(i != j){
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
    BFS(p, arr);


}
