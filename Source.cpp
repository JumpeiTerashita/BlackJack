#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "MT.h"

typedef struct {
	int number;
	int cardSuit;
}Card;

Card Pcard[21];
Card Dcard[21];
int CardNum = 2;

enum {
	TYPE_SPADE,
	TYPE_CLUB,
	TYPE_DIAMOND,
	TYPE_HEART
};

enum {
	Hit,
	Stay,
	HitStayMAX
};

char HS[][16] = {
	"ÇgÇhÇs",
	"ÇrÇsÇ`Çx",
};

int HitORStand() {
	int HSCursor = Hit;
	int EnterFlag = FALSE;
	while (1) {
		printf("\r");
		for (int i = 0; i < HitStayMAX; i++) {
			if (i == HSCursor) {
				printf("Å@Å@ÅÑÅ@%s", HS[i]);
			}
			else {
				printf("Å@Å@Å@Å@%s", HS[i]);
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
	init_genrand((unsigned)time(NULL));
	for (int i = 0; i < 21; i++) {
		Pcard[i].number = (genrand_int32() % 13) + 1;
		Dcard[i].number = (genrand_int32() % 13) + 1;
		if (Pcard[i].number >= 11) Pcard[i].number = 10;
		if (Dcard[i].number >= 11) Dcard[i].number = 10;
		Pcard[i].cardSuit = genrand_int32() % 4;
		Dcard[i].cardSuit = genrand_int32() % 4;
	};
	while (1) {
		int Cardsum = 0;
		system("cls");
		printf("Player cardÅc\n");
		for (int i = 0; i < CardNum; i++) {
			Cardsum += Pcard[i].number;
			printf(" [%d]", Pcard[i].number);
		}
		if (Cardsum == 21) printf("\n 21 # NICE BLACK JACK ! #");
		else if (Cardsum < 11) printf("\n %d or %d", Cardsum, Cardsum + 10);
		else if (Cardsum > 21) printf("\n %dÅ@# BURST #", Cardsum);
		else printf("\n %d ", Cardsum);
		printf("\n\nDealer cardÅc\n");
		printf("[%d] [Åñ]\n", Dcard[0].number);
		getchar();
		printf("Hit ? Stay ?\n");
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



