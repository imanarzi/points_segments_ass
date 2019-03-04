#include <stdio.h>
#include <stdlib.h>

extern L;
extern P;
int start = -1000;
int point = 0;
int end = 1000;

int comparator(const void* p, const void* q){
	int* a = (int *)p;
	int* b = (int *)q;
	if(a[0] > b[0])
		return 1;
	if(a[0] == b[0]){
		if(a[1] > b[1])
			return 1;
		return -1;
	}
	return -1;	

}


void points_segments_qsort(int lines[][L], int n_lines, int points[][P], int n_points){
        int len = n_lines * 2 + n_points;
	int arr[len][2];
	//printf("%d", len);
	int j = 0;
	for(int i = 0; i < n_lines; i++){
		arr[i*2][0] = lines[i][0];
		arr[i*2][1] = start;
		arr[i*2 + 1][0] = lines[i][1];
		arr[i*2 + 1][1] = end;
		//j++;
	}
	for(int i = n_lines*2; i < len; i++){
		arr[i][0] = points[j][0];
		arr[i][1] = point;
		j++;
	}
	/*for(int i = 0; i < len; i++){
                printf("before  %d %d\n", arr[i][0], arr[i][1]);
        }*/
	//int size = sizeof(arr)/sizeof(arr[0]);
	qsort(arr, len, 2*sizeof(int), comparator);
	/*for(int i = 0; i < len; i++){
		printf("after %d %d\n", arr[i][0], arr[i][1]);
	}*/
	int s = 0;
	int c = 0;
	if(arr[0][1] == start)
		s++;
	for(int i = 1; i < len; i++){
		if(arr[i][1] == start) 
			s++;
		if(arr[i][1] == point){
			points[c][1] = s;
			c++;
		}
		if(arr[i][1] == end)
			s--;
	}
			
 
		
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
