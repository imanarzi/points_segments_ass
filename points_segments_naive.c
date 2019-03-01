#include <stdio.h>
#include <stdlib.h>

int points_segments_naive(int** lines, int n_lines, int* points, int n_points){
	int count = 0;
	for(int i = 0; i < n_points; i++)
		for(int j = 0; j < n_lines; j++){
			if(points[i] >= lines[j][0] && points[i] <= lines[j][1])
					count++;
		}
	return count; 
}

int main(){
	int n_lines = 3;
	int n_points = 3;
	//int lines[n_lines][2];
	//int points[n_points];	
	
	int lines[3][2] = {{1, 3}, {2, 5}, {10, 13}};
	int points[3] = {2, 3, 4};
	
	printf("%d\n", points_segments_naive(lines, n_lines, points, n_points));
}
