#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

int Pcard[21];
int Dcard[21];
int Cardsum;
int k = 2;

enum {
	ACTION_HIT,
	ACTION_STAY,
	ACTION_MAX
};


int main()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 21; i++) {
		Pcard[i] = (rand() % 13) + 1;
		Dcard[i] = (rand() % 13) + 1;
		if (Pcard[i] >= 11) Pcard[i] = 10;
		if (Dcard[i] >= 11) Dcard[i] = 10;
	};
	printf("Player card…\n");
	Cardsum = Pcard[0] + Pcard[1];
	if (Pcard[0] == 1 || Pcard[1] == 1) {
		printf("[%d] [%d]\n%dor%d\n", Pcard[0], Pcard[1], Cardsum, Cardsum + 10);
	}
	else {
		printf("[%d] [%d]\n%d\n", Pcard[0], Pcard[1], Cardsum);
	}
	if (Cardsum == 21) {
		printf("# BLACK JACK! #");
	}
	getchar();
	printf("Dealer card…\n");
	printf("[%d] [＊]\n", Dcard[0]);
	getchar();
	printf("Hit=0,Stand=1\n");
	int scene = ACTION_STAY;
	scanf_s("%d", &scene);
	getchar();
	switch (scene) {
	case ACTION_HIT:
		printf("# HIT! #\n");
		getchar();
		system("cls");
		printf("Player card…\n");
		printf("[%d] [%d]", Pcard[0], Pcard[1]);
		Cardsum += Pcard[k];
		printf(" [%d]", Pcard[k]);
		printf("\n%d", Cardsum);
		/*if (Cardsum > 21) printf("# BURST #");
		if (Cardsum == 21) printf("# NICE 21! #");*/
		break;
	case ACTION_STAY:
		printf("# STAY #\n");
		getchar();
		system("cls");
		printf("Player card…\n");
		printf("[%d] [%d]", Pcard[0], Pcard[1]);
		break;
	default:
		printf("#ERROR!#\n未定義のコマンド\n");
	}

	printf("\n\nDealer card…\n");
	printf("[%d] [＊]\n", Dcard[0]);
	getchar();
	return 0;
}



