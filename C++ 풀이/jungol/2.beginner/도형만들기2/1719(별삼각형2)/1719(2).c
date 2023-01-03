#include "1719.h"

int printstar(int n,int m){

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			arr[i][j] = 0;
	
	int loopidx = 0;

	int whileidx = 0;
	int y = 0;

	switch (m) {
	case 1:
		for (int i = 0; i < n / 2 + 1; i++) {
			y = 0; loopidx = i + 1;
			while (y < loopidx) {
				arr[i][y++] = 1;
			}
		}

		for (int i = n / 2 + 1; i < n; i++) {
			y = 0; loopidx = n - i;
			while (y < loopidx) {
				arr[i][y++] = 1;
			}
		}

		break;

	case 2:

		for (int i = 0; i < n / 2 + 1; i++) {

			y = 0; loopidx = i + 1;

			while (y < loopidx) {

				arr[i][(n / 2 + 1) - (y++)] = 1;

			}

		}

		for (int i = n / 2 + 1; i < n; i++) {

			y = 0; loopidx = n - i;

			while (y < loopidx) {

				arr[i][(n / 2 + 1) - (y++)] = 1;

			}

		}

		break;

	case 3:

		for (int i = 0; i < n / 2 + 1; i++) {

			y = 0; loopidx = n / 2 - i;

			arr[i][n / 2 + 1] = 1;

			while (y < loopidx) {

				++y;

				arr[i][(n / 2 + 1) - y] = 1;

				arr[i][(n / 2 + 1) + y] = 1;

			}

		}

		for (int i = n / 2 + 1; i < n; i++) {

			y = 0; loopidx = i - (n / 2 + 1) + 1;

			arr[i][n / 2 + 1] = 1;

			while (y < loopidx) {

				++y;

				arr[i][(n / 2 + 1) - y] = 1;

				arr[i][(n / 2 + 1) + y] = 1;

			}

		}

		break;

	case 4:

		for (int i = 0; i < n / 2 + 1; i++) {

			y = 0; loopidx = n / 2 - i;

			arr[i][n / 2 + 1] = 1;

			while (y < loopidx) {

				++y;

				arr[i][(n / 2 + 1) - y] = 1;

			}

		}

		for (int i = n / 2 + 1; i < n; i++) {

			y = 0; loopidx = i - (n / 2 + 1) + 1;

			arr[i][n / 2 + 1] = 1;

			while (y < loopidx) {

				++y;

				arr[i][(n / 2 + 1) + y] = 1;

			}

		}

		break;

	default:

		break;

	}

}