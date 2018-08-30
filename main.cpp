#include <stdio.h>
//#pragma warning(disable:4996)

int test_case;
int T;
int n;
char map[1001][4];

int midStar[1001][4];
int midStarlen = 0;

int max = 0;
int tmpMax = 0;
int doubl = 0;
int frontMax = 0;
int rearMax = 0;
int midMax = 0;
int testmap[500];

int main(void)
{
	setbuf(stdout, NULL);

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case){

		scanf("%d", &n);
		max = 0; doubl = 0; frontMax = 0; rearMax = 0; midMax = 0; midStarlen = 0;
		tmpMax = 0;

		for (int i = 0; i < n; i++){
			scanf("%s", map[i]);

			if (map[i][0] == '*' && map[i][2] != '*'){
				//Save the largest number in the front left to 'frontMax'.
				int tmp = 0;

				for (int j = 0; j < 3; j++){
					if (map[i][j] >= '0' && map[i][j] <= '9'){
						tmp += map[i][j] - 48;
					}
				}
				if (frontMax < tmp){
					frontMax = tmp;
				}

			}
			else if (map[i][0] != '*' && map[i][2] == '*'){
				//Save the largest number in the right to 'rearMax'.
				int tmp = 0;
				for (int j = 0; j < 3; j++){
					if (map[i][j] >= '0' && map[i][j] <= '9'){
						tmp += map[i][j] - 48;
					}
				}
				if (rearMax < tmp){
					rearMax = tmp;
				}

			}
			else if (map[i][0] == '*' && map[i][2] == '*'){
				//The largest number that can not be attached anywhere is saved separately.
				int tmp = map[i][1] - 48;
				if (doubl < tmp){
					doubl = tmp;
				}
			}
			else if (map[i][1] != '*' && map[i][0] != '*' && map[i][2] != '*'){
				//The numbers without stars are all available, so add.
				for (int j = 0; j < 3; j++){
					if (map[i][j] >= '0' && map[i][j] <= '9'){
						midMax += map[i][j] - 48;
					}
				}
			}
			else if (map[i][1] == '*' && map[i][0] != '*' && map[i][2] != '*'){
				//A number with a star in the middle is stored in an array.
				midStar[midStarlen][0] = map[i][0] - 48;
				midStar[midStarlen][1] = 0;
				midStar[midStarlen][2] = map[i][2] - 48;
				midStarlen++;
			}
		}

		max = midMax + rearMax + frontMax;

		if (doubl > max){
			max = doubl;
		}

		int left = frontMax, right = rearMax;

		for (int i = 0; i < midStarlen; i++){
			//Attach the center star from the left to the right hand
			left = frontMax, right = rearMax;

			if (midStar[i][0] < rearMax){
				continue;
			}

			right = midStar[i][0];
			for (int j = 0; j < midStarlen; j++){

				if (i == j){
					continue;
				}
				if (midStar[j][2] < frontMax) {
					continue;
				}

				left = midStar[j][2];
				tmpMax = midMax + left + right;

				if (max < tmpMax){
					max = tmpMax;
				}

			}
			tmpMax = midMax + left + right;

			if (max < tmpMax){
				max = tmpMax;
			}

		}

		for (int i = 0; i < midStarlen; i++){
			//Attach the center star from the right to the left and attach it to the left.
			left = frontMax, right = rearMax;

			if (midStar[i][2] < frontMax){
				continue;
			}

			left = midStar[i][2];

			for (int j = 0; j < midStarlen; j++){

				if (i == j){
					continue;
				}
				if (midStar[j][0] < rearMax) {
					continue;
				}

				right = midStar[j][0];

				tmpMax = midMax + left + right;

				if (max < tmpMax){
					max = tmpMax;
				}

			}
			tmpMax = midMax + left + right;

			if (max < tmpMax){
				max = tmpMax;
			}

		}

		printf("#%d %d\n", test_case, max);

	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
