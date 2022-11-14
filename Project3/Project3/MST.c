#include<stdio.h>
#include<stdlib.h>
#define MAX_VER 100

int kim[MAX_VER];
int num[MAX_VER];

// 초기화 함수

void init_set(int n) {

    int i;

    for (i = 0; i < n; i++) {

        //- : 정점, 음수의 숫자 : 집합의 갯수, 양수의 수 : 원소의 부모

        kim[i] = -1;

        // 각 정점들의 집합의 갯수

        num[i] = 1;

    }

}

//원소의 루트 노드를 찾아가서 사이클이 형성되는지 확인하기위한 함수

int find_set(int vertex) {

    int whatp, p, i = -1;

    for (i = vertex; (whatp = kim[i]) >= 0; i = whatp);
    // 원소의 kim를 찾아감

    p = i; //kim를 발견해냄.

    for (i = vertex; (whatp = kim[i]) >= 0; i = whatp)

        kim[i] = p;  // 원소의 p

    return p;

}

//사이클이 형성되지 않는 두개의 트리집합을 연결

//단 숫자가 더 작은 쪽이 큰 쪽의 자식으로 들어가는 것이 좋다.

void union_set(int r1, int r2) {



    if (num[r1] < num[r2]) {

        kim[r1] = r2;   //r2 = 부모노드가 될것  r1  = 자식

        num[r2] += num[r1]; // r2의 갯수가 r1의 집합의 갯수만큼 들어남.

    }

    else {

        kim[r2] = r1;

        num[r1] += num[r2];

    }

}

typedef struct {

    int src;

    int dest;

    int weight;

}forSort;


/* 오름차순 정렬을 위한 함수 -->qsort에서 쓰임 */

int compare(const void* a, const void* b) {

    const forSort* m1 = (const forSort*)a;

    const forSort* m2 = (const forSort*)b;



    return m1->weight - m2->weight;

}


void kruskal(int cost[9][9]) {

    int i, j;

    int index = 0;

    int edge_count = 0;

    int min, mincost = 0;

    int uset, vset; //정점 u와 정점 v의 집합 번호

    forSort arr[MAX_VER] = { 0 };


    for (i = 0; i < 9; i++) {

        for (j = 0; j < 9; j++) {

            if (cost[i][j] != 0) {

                arr[index].weight = cost[i][j];

                cost[j][i] = 0;

                arr[index].src = i;     // 해당 가중치의 정점 2개를 기억하기위한 배열

                arr[index].dest = j;

                index++;

            }

        }

    }

    qsort(arr, index, sizeof(forSort), compare);  //-->tmp_arr배열에 저장된 가중치가 오름차순으로 정리


    for (i = 0; i < index; i++) {     // --> qsort확인

        printf("%d\n", arr[i].weight);

    }

    init_set(9);

    i = 0;

    while (edge_count < (9 - 1)) {

        if (i < index) {

            min = arr[i].weight;

            uset = find_set(arr[i].src);

            vset = find_set(arr[i].dest);



            if (uset != vset) {

                edge_count++;

                union_set(uset, vset);

                mincost += min;

                printf("선택한 가중치: %d\t=>", min);

                printf("현재 최소값 : %d\n", mincost);

            }

            i++;

        }

    }

    printf("\n가중치의 합계 : %d \n", mincost);

}

int main() {

    



    int graph[9][9] = {               

             {0, 4, 0, 0, 0, 0, 0, 8, 0},

             {4, 0, 8, 0, 0, 0, 0, 11, 0},

             {0, 8, 0, 7, 0, 4, 0, 0, 2},

             {0, 0, 7, 0, 9, 14, 0, 0, 0},

             {0, 0, 0, 9, 0, 10, 0, 0, 0},

             { 0, 0, 4, 14, 10, 0, 2, 0, 0},

             { 0, 0, 0, 0, 0, 2, 0, 1, 6},

             { 8, 11, 0, 0, 0, 0, 0, 0, 7},

             { 0, 0, 2, 0, 0, 0, 6, 7, 0 },

    };





    kruskal(graph);



}