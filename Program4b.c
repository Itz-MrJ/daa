// Program 4a: Write and execute a program to arrange nodes in topological order using source removal technique.

#include<stdio.h>

// Topology Function
void topology(int n, int a[10][10], int sc[10]) {
    int i, j;
    for(i = 1; i <= n; i++) {
        // printf("i is %d\n", i);
        if(sc[i] == 0) {
            printf("%d\t",i);
            sc[i] = -1;
            for(j = 1; j <= n; j++)
                if(a[i][j] == 1)
                    sc[j]--;
            i = 0;
        }
    }
}
// 0 1 0
// 0 0 1
// 0 0 0

// A -> B -> C

// -1 -1 -1

// Main Program
int main() {
    int a[10][10], n, i, j, sc[10];
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        sc[i] = 0;
    printf("Enter the adjacency matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            if(a[i][j] == 1)
                sc[j]++;
        }
    }
    printf("The Topological Order of graph is:\n");
    topology(n, a, sc);
}
