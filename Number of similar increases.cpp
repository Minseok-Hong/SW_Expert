#include <stdio.h>
//#pragma warning(disable:4996)

int n, k;
int map[100001];
int result = 0;

int fun(int start, int end){

	//printf("	Start : %d  End : %d\n", start, end);

	int index = 0;
	int index1 = 0, index2 = 0, index3 = 0, index4 = 0;
	int flag = 0;

	for (int i = start; i < end; i++){
		if (map[i] < map[i + 1]){
			index1++;
		}
		if (map[i] > map[i + 1] && map[i] < map[i + 2]) {
			index2++;
		}
		if (i == end - 1){
			if (map[i] > map[i + 1]){
				index3++;
			}
		}

	}

	if (index1 == (end - start)){
		return 1;
	}
	if (index2 == 1 && index1 == (end - start - 1)){
		return 1;
	} 
	if (index3 == 1 && index1 == (end - start - 1)){
		return 1;
	}
	
	return 0;
}

int main(void)
{
	int test_case;
	int T;

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case){

		result = 0;

		scanf("%d %d", &n, &k);

		for (int i = 0; i < n; i++){
			scanf("%d", &map[i]);
		}

		for (int i = 0; i <= n - k; i++){
			for (int j = i + k - 1; j <= n; j++){

				if (fun(i, j)){
					result++;
				} 
				else{
					break;
				}

			}
		}

		printf("#%d %d\n", test_case, result);
	}
	return 0; //
}

/*

3
9 3
1 3 8 9 2 5 7 6 4
8 3
8 1 4 2 5 7 3 6
10 5
3 2 4 5 7 6 8 9 1 10

*/


/*

printf("(");
for (int i = start; i <= end; i++){
printf("%d, ", map[i]);
}
printf(")\n");

*/