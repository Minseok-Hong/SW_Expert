#include <stdio.h>
#pragma warning(disable:4996)

int n, k;
int map[100001];
int result = 0;

int fun(int start, int end){

	int index = 0;

	for (int i = start; i < end; i++){
		if (map[i] < map[i + 1]){
			index++;
		}
	}

	if (index == (end - start)){
		//printf("	%d %d\n", start, end);
		return 1;
	}
	else{
		return 0;
	}
		
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

		for (int i = 0; i < n - k; i++){
			for (int j = i + k-1; j < n; j++){
				printf("	(%d %d)\n", i, j);

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
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}

/*

2
9 3
1 3 8 9 2 5 7 6 4
10 5
3 2 4 5 7 6 8 9 1 10

*/