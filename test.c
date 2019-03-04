#include "points_segments.h"
int L = 0;
int P = 0;

void print_array(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);	
	}
	printf("\n");
}

void print_array_2D(int **arr, int rows, int cols){
	for (int i=0; i<rows; i++){
		printf("[");
		for (int j=0; j<cols; j++)
			printf("%d ",arr[i][j]);
		printf("] ");
	}
	printf("\n");
}
void points_segments_naive(int lines[][L], int n_lines, int points[][P], int n_points){
        for(int i = 0; i < n_points; i++)
                for(int j = 0; j < n_lines; j++){
                        if(points[i][0] >= lines[j][0] && points[i][0] <= lines[j][1])
                                points[i][1]++;
                }
}

int main() {	
	const char * files[] = {"input1.txt", "input2.txt", "input3.txt"};   

	for (int f=0; f < 3; f++){
		FILE *pfile = fopen(files[f], "r");
		if(pfile == NULL)  {
			printf("Error opening file %s\n", files[f]);
			return 1;
		}
		
		int s, p;
		while(fscanf(pfile, "%d %d", &s, &p)!=EOF){		
		
			//allocate 2D array to hold s segments
			int ** segments = malloc(s*sizeof(int *));
			for (int i=0; i < s; i++){
				segments[i] = malloc(2*sizeof(int));
			}
		
			//scan all segment lines and populate the segments
			for (int i=0; i < s; i++){
				fscanf(pfile, "%d %d", &segments[i][0], &segments[i][1]);
			}		
		
			//allocate a single array to hold p points
			int * points = malloc(p*sizeof(int));
		
			//scan all point coordinates into points array
			for (int i=0; i < p; i++){
				fscanf(pfile, "%d", &points[i]);
			}
			
			printf("There are total %d segments, and %d points\n", s, p);
			L = s;
			P = p;
			print_array_2D(segments, s, 2);
			print_array(points, p);
			//TODO: pass s, p, segments, and points to your two algorithms
			//the output should be an array of size p containing 
			//-for each point- the number of covering segments 
			int points_qsort[][p];
			int points_naive[][p];
			for(int i = 0; i < p; i++){
				points_qsort[i][0] = points[i];
				points_naive[i][0] = points[i];
			}
			points_segments_qsort(segments, s, points_qsort, p);	
			points_segments_naive(segments, s, points_naive, p);
			//TODO: implement - compare these outputs from 2 algorithms
			int passed = 1;
			for(int i = 0; i < p; i++){
				if(points_naive != points_qsort)
					passed = 0;
			} 
			if(passed){
				printf("OK\n");
			}
			else{
				printf("FAILED\n");
				break;
			}
		}
		fclose(pfile);
	}
	return 0;
}
