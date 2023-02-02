#include<stdio.h>
#define INF 99999
#define n 5

void printSolution(int g[n]){
    printf("Hop count :\t\t");
    for(int j=0;j<n;j++){
        if(g[j] == INF)
            printf("INF\t");
        else
            printf("%d\t",g[j]);
    }
    printf("\n");
}

void findShortestPath(int dist[][n]){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                if(dist[i][j] > dist[i][k] + dist[k][j] &&(dist[i][k] != INF && dist[k][j] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
        }
    }

    char c = 'A';
    for(int i=0; i<n; i++ ){
        printf("Router table entries for router %c:\n", c);
        printf("Destination router:\tA\tB\tC\tD\tE\n");
        printSolution(dist[i]);
        c++;
    }
}

int main(){
    int graph[][n] = { {0, 1, 1, INF, INF},
                        {1, 0, INF, INF, INF},
                        {1, INF, 0, 1, 1},
                        {INF, INF, 1, 0, INF},
                        {INF, INF, 1, INF, 0}};

    findShortestPath(graph);
    return 0;
}
