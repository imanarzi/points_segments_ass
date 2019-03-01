#include <stdio.h>
#include <stdlib.h>

int I = 2;
int S = 3;
void points_segments_naive(int lines[][I], int n_lines, int points[][S], int n_points){
        for(int i = 0; i < n_points; i++)
                for(int j = 0; j < n_lines; j++){
                        if(points[i][0] >= lines[j][0] && points[i][0] <= lines[j][1])
                                points[i][1]++;
                }
}

int main(){
        int n_lines = 3;
        int n_points = 3;
        //int lines[n_lines][2];
        //int points[n_points]; 
        
        int lines[][2] = {{1, 3}, {2, 5}, {10, 13}};
        int points[][3] = {{2, 0}, {3, 0}, {4, 0}};
        
        points_segments_naive(lines, n_lines, points, n_points);
        printf("%d %d %d\n", points[0][1], points[1][1], points[2][1]);
} 
