#include<stdio.h>
#include<stdlib.h>
#define MAX_VER 100

int kim[MAX_VER];
int num[MAX_VER];

// �ʱ�ȭ �Լ�

void init_set(int n) {

    int i;

    for (i = 0; i < n; i++) {

        //- : ����, ������ ���� : ������ ����, ����� �� : ������ �θ�

        kim[i] = -1;

        // �� �������� ������ ����

        num[i] = 1;

    }

}

//������ ��Ʈ ��带 ã�ư��� ����Ŭ�� �����Ǵ��� Ȯ���ϱ����� �Լ�

int find_set(int vertex) {

    int whatp, p, i = -1;

    for (i = vertex; (whatp = kim[i]) >= 0; i = whatp);
    // ������ kim�� ã�ư�

    p = i; //kim�� �߰��س�.

    for (i = vertex; (whatp = kim[i]) >= 0; i = whatp)

        kim[i] = p;  // ������ p

    return p;

}

//����Ŭ�� �������� �ʴ� �ΰ��� Ʈ�������� ����

//�� ���ڰ� �� ���� ���� ū ���� �ڽ����� ���� ���� ����.

void union_set(int r1, int r2) {



    if (num[r1] < num[r2]) {

        kim[r1] = r2;   //r2 = �θ��尡 �ɰ�  r1  = �ڽ�

        num[r2] += num[r1]; // r2�� ������ r1�� ������ ������ŭ ��.

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


/* �������� ������ ���� �Լ� -->qsort���� ���� */

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

    int uset, vset; //���� u�� ���� v�� ���� ��ȣ

    forSort arr[MAX_VER] = { 0 };


    for (i = 0; i < 9; i++) {

        for (j = 0; j < 9; j++) {

            if (cost[i][j] != 0) {

                arr[index].weight = cost[i][j];

                cost[j][i] = 0;

                arr[index].src = i;     // �ش� ����ġ�� ���� 2���� ����ϱ����� �迭

                arr[index].dest = j;

                index++;

            }

        }

    }

    qsort(arr, index, sizeof(forSort), compare);  //-->tmp_arr�迭�� ����� ����ġ�� ������������ ����


    for (i = 0; i < index; i++) {     // --> qsortȮ��

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

                printf("������ ����ġ: %d\t=>", min);

                printf("���� �ּҰ� : %d\n", mincost);

            }

            i++;

        }

    }

    printf("\n����ġ�� �հ� : %d \n", mincost);

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