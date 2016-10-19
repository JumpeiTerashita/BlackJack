#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int Pcard[21];
int Dcard[21];
int CardNum = 2;


enum {
	Disable,
	Enable
};

enum {
	Hit,
	Stay,
	HitStayMAX
};

char HS[][16] = {
	"‚g‚h‚s",
	"‚r‚s‚`‚m‚c",
};

int HitORStand() {
	int HSCursor = Hit;
	int EnterFlag = Disable;
	while (1) {
		printf("\r");
		for (int i = 0; i < HitStayMAX; i++) {
			if (i == HSCursor) {
				printf("@@„@%s", HS[i]);
			}
			else {
				printf("@@@@%s", HS[i]);
			}
		}
		switch (_getch()) {
		case 0x0d:
			if (HSCursor == Hit) {
				return 0;
			}
			if (HSCursor == Stay) {
				return 1;
			}
			break;
		case 0xe0:
			switch (_getch()) {
			case 0x4b:
				if (HSCursor != Hit) HSCursor--;
				else HSCursor++;
				break;
			case 0x4d:
				if (HSCursor == Hit) HSCursor++;
				else HSCursor--;
				break;
			}
			break;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 21; i++) {
		Pcard[i] = (rand() % 13) + 1;
		Dcard[i] = (rand() % 13) + 1;
		if (Pcard[i] >= 11) Pcard[i] = 10;
		if (Dcard[i] >= 11) Dcard[i] = 10;
	};
	while (1) {
		int Cardsum = 0;
		system("cls");
		printf("Player cardc\n");
		for (int i = 0; i < CardNum; i++) {
			Cardsum += Pcard[i];
			printf(" [%d]", Pcard[i]);
		}
		if (Cardsum == 21) printf("\n 21 # NICE BLACK JACK ! #");
		else if (Cardsum < 11) printf("\n %d or %d", Cardsum, Cardsum + 10);
		else if (Cardsum > 21) printf("\n %d@# BURST #", Cardsum);
		else printf("\n %d ", Cardsum);
		printf("\n\nDealer cardc\n");
		printf("[%d] [–]\n", Dcard[0]);
		getchar();
		printf("Hit? Stand?\n");
		int HitStand = HitORStand();
		if (HitStand == 0) {
			printf("\nHIT");
			getchar();
			CardNum++;
		}
		else if (HitStand == 1) {
			printf("\nSTAY");
			getchar();
		}
	}
	return 0;
}



