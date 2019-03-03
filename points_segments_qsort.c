#include <stdio.h>
#include <stdlib.h>

int I = 2;
int S = 3;
int start = -1000;
int point = 0;
int end = 1000;

int comparator(const void *p, const void *q){
	int a = *(const int *)p;
	int b = *(const int *)q;
	if(a > b)
		return 1;
	return -1;	

}
void points_segments_qsort(int lines[][I], int n_lines, int points[][S], int n_points){
        int len = n_lines * 2 + n_points;
	int arr[len][2];
	for(int i = 0; i < n_lines*2 - 1; i++){
		arr[i][0] = lines[i][0];
		arr[i][1] = start;
		arr[i + 1][0] = lines[i][1];
		arr[i + 1][1] = end;
	}
	for(int i = n_points; i < len; i++){
		arr[i][0] = points[i][0];
		arr[i][1] = point;
	}
	int size = sizeof(arr[0])/sizeof(arr[0][0]);
	qsort((void*) arr, size, sizeof(arr[0][0]), comparator);
	for(int i = 0; i < len; i++){
		int count = 0;
		if(arr[i][0] = start) 
		arr[i] = 
		
}

int main(){
        int n_lines = 3;
        int n_points = 3;
        //int lines[n_lines][2];
        //int points[n_points]; 
        
        int lines[][2] = {{1, 3}, {2, 5}, {10, 13}};
        int points[][3] = {{2, 0}, {3, 0}, {4, 0}};
        
        points_segments_qsort(lines, n_lines, points, n_points);
        printf("%d %d %d\n", points[0][1], points[1][1], points[2][1]);
} 
