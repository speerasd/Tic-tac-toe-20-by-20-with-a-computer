#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
using namespace std;
char gm[20][20];
int movei, movea;
int moveic, moveac;
int countc = 1;
void clear() {
	system("cls");
}
void board() {
	for (int i = 0; i < 20; i++) {
		for (int a = 0; a < 20; a++) {
			gm[a][i] = '-';
		}
	}
}//заполнение поля
void gameboard() {
	for (int j = 1; j <= 20; j++) {
		if (j < 10) {
			cout << " ";
		}
		cout << " " << j;
	}
	cout << endl;
	for (int i = 0; i < 20; i++) {
		if (i < 9) {
			cout << " ";
		}
		cout << i + 1;
		for (int a = 0; a < 20; a++) {
			cout << gm[a][i] << "  ";
		}
		cout << endl;
	}
}//вывод игрового поля

bool chek(string x) {
	string f;
	bool y = true, o, k = true;
	if ((x[0] != '0') * (x.length() != 0)) {
		f = "1234567890";
		for (int i = 0; i < x.length(); i++) {
			if (f.find(x[i]) == -1) {
				y = false;
				break;

			}

		}
		if (y != false) {
			if ((stoi(x) > 20) + (stoi(x) < 0)) {
				y = false;
			}
		}
		o = y;
	}
	else {
		o = false;
	}
	return o;
}

int GetRandomNumber(int min, int max)
{
	srand(time(NULL));

	int num = min + rand() % (max - min + 1);

	return num;
}

int humanmove(int* movei, int* movea)
{
	string s_movei = "";
	string s_movea = "";
	cout << "\n Ходы: \n";
	for (int j = 1; j <= 20; j++) {
		if (j < 10) {
			cout << " ";
		}
		cout << " " << j;
	}
	cout << endl;
	for (int i = 0; i < 20; i++) {
		if (i < 9) {
			cout << " ";
		}
		cout << i + 1;
		for (int a = 0; a < 20; a++) {
			cout << gm[a][i] << "  ";
		}
		cout << endl;
	}
	while (1) {
		cout << "Ваш ход(Горизонталь):";
		getline(cin, s_movea);
		while (!chek(s_movea)) {

			cout << "Неверный ввод!" << endl;
			cout << "Ваш ход(Горизонталь):";
			getline(cin, s_movea);
		}
		*movea = stoi(s_movea);
		cout << "Ваш ход(Вертикаль):";
		getline(cin, s_movei);
		while (!chek(s_movei)) {
			cout << "Неверный ввод!" << endl;
			cout << "Ваш ход(Вертикаль):";
			getline(cin, s_movei);
		}
		*movei = stoi(s_movei);
		*movea = *movea - 1;
		*movei = *movei - 1;
		if (gm[*movea][*movei] != '-') {
			cout << "Место занято!" << endl;
		}
		else {
			break;
		}
	}
	return 0;
}//игровое поле и ходы игрока


void computermove() {
	&moveic, & moveac;
	int count, count0;//проверка на выигрышь у компьютера
	count = 1;
	count0 = 1;
	int count20 = 1;
	for (int a = 1; a < 5; a++) {
		if (gm[moveac + a][moveic] == '0') {
			count = count + 1;
		}
		else {
			if (gm[moveac + a][moveic] == 'X') {
				break;
			}
		}
	}

	for (int a = 1; a < 5; a++) {
		if (gm[moveac - a][moveic] == '0') {
			count = count + 1;
		}
		else {
			if (gm[moveac - a][moveic] == 'X') {
				break;
			}
		}
	}
	if (count >= 4) {
		for (int a = 1; a < 5; a++) {
			if ((gm[moveac + a][moveic] == '-') and (count0 == 1)) {
				gm[moveac + a][moveic] = '0';
				count0 = count0 + 1;
				break;
			}
			else {
				if (gm[moveac + a][moveic] == 'X') {
					break;
				}
			}
		}

		for (int a = 1; a < 5; a++) {
			if ((gm[moveac - a][moveic] == '-') and (count0 == 1)) {
				gm[moveac - a][moveic] = '0';
				count0 = count0 + 1;
				break;
			}
			else {
				if (gm[moveac - a][moveic] == 'X') {
					break;
				}
			}
		}
	}
	else {
		count = 1;
		for (int i = 1; i < 5; i++) {
			if (gm[moveac][moveic + i] == '0') {
				count = count + 1;
			}
			else {
				break;
			}
		}

		for (int i = 1; i < 5; i++) {
			if (gm[moveac][moveic - i] == '0') {
				count = count + 1;
			}
			else {
				if (gm[moveac][moveic - i] == '0') {
					break;
				}
			}
		}
		if (count >= 4) {
			for (int i = 1; i < 5; i++) {
				if ((gm[moveac][moveic + i] == '-') and (count0 == 1)) {
					gm[moveac][moveic + i] = '0';
					count0 = count0 + 1;
					break;
				}
				else {
					if (gm[moveac][moveic + i] == 'X') {
						break;
					}
				}
			}

			for (int i = 1; i < 5; i++) {
				if ((gm[moveac][moveic - i] == '-') and (count0 == 1)) {
					gm[moveac][moveic - i] = '0';
					count0 = count0 + 1;
					break;
				}
				else {
					if (gm[moveac][moveic - i] == 'X') {
						break;
					}
				}
			}
		}
		else {
			count = 1;
			for (int j = 1; j < 5; j++) {
				if (gm[moveac + j][moveic + j] == '0') {
					count = count + 1;
				}
				else {
					break;
				}
			}

			for (int j = 1; j < 5; j++) {
				if (gm[moveac - j][moveic - j] == '0') {
					count = count + 1;
				}
				else {
					break;
				}
			}
			if (count >= 4) {
				for (int j = 1; j < 5; j++) {
					if ((gm[moveac + j][moveic + j] == '-') and (count0 == 1)) {
						gm[moveac + j][moveic + j] = '0';
						count0 = count0 + 1;
						break;
					}
					else {
						if (gm[moveac + j][moveic + j] == 'X') {
							break;
						}
					}
				}

				for (int j = 1; j < 5; j++) {
					if ((gm[moveac - j][moveic - j] == '-') and (count0 == 1)) {
						gm[moveac - j][moveic - j] = '0';
						count0 = count0 + 1;
						break;
					}
					else {
						if (gm[moveac - j][moveic - j] == 'X') {
							break;
						}
					}
				}
			}
			else {
				count = 1;
				for (int r = 1; r < 5; r++) {
					if (gm[moveac + r][moveic - r] == '0') {
						count = count + 1;
					}
					else {
						break;
					}
				}

				for (int r = 1; r < 5; r++) {
					if (gm[moveac - r][moveic + r] == '0') {
						count = count + 1;
					}
					else {
						break;
					}
				}
				if (count >= 4) {
					for (int r = 1; r < 5; r++) {
						if ((gm[moveac + r][moveic - r] == '-') and (count0 == 1)) {
							gm[moveac + r][moveic - r] = '0';
							count0 = count0 + 1;
							break;
						}
						else {
							if (gm[moveac + r][moveic - r] == 'X') {
								break;
							}
						}
					}

					for (int r = 1; r < 5; r++) {
						if ((gm[moveac - r][moveic + r] == '-') and (count0 == 1)) {
							gm[moveac - r][moveic + r] = '0';
							count0 = count0 + 1;
							break;
						}
						else {
							if (gm[moveac - r][moveic + r] == 'X') {
								break;
							}
						}
					}
				}
			}
		}
	}





	//проверка на выигрышь игрока
	count = 1;
	for (int a = 1; a < 5; a++) {
		if (gm[movea + a][movei] == 'X') {
			count = count + 1;
		}
		else {
			if (gm[movea + a][movei] == '0') {
				count = count - 1;
				break;
			}
			else {
				if ((movea + a) == 20) {
					break;
				}
			}
		}
	}
	for (int a = 1; a < 5; a++) {
		if (gm[movea - a][movei] == 'X') {
			count = count + 1;
		}
		else {
			if (gm[movea - a][movei] == '0') {
				count = count - 1;
				break;
			}
			else {
				if ((movea - a) == -1) {
					break;
				}
			}
		}
	}
	if (count >= 3) {
		for (int a = 1; a < 4; a++) {
			if ((movea - a) != -1) {
				if ((gm[movea - a][movei] == '-') and (count0 == 1)) {
					gm[movea - a][movei] = '0';
					count0 = count0 + 1;
					break;
				}
			}
			else {
				break;
			}
		}
		for (int a = 1; a < 4; a++) {
			if ((movea + a) != 20) {
				if ((gm[movea + a][movei] == '-') and (count0 == 1)) {
					gm[movea + a][movei] = '0';
					count0 = count0 + 1;
					break;
				}
			}
			else {
				break;
			}
		}
	}
	else {
		count = 1;
		for (int i = 1; i < 5; i++) {
			if (gm[movea][movei + i] == 'X') {
				count = count + 1;
			}
			else {
				if (gm[movea][movei + i] == '0') {
					break;
				}
				else {
					if ((movei + i) == 20) {
						break;
					}
				}
			}
		}
		for (int i = 1; i < 5; i++) {
			if (gm[movea][movei - i] == 'X') {
				count = count + 1;
			}
			else {
				if (gm[movea][movei - i] == '0') {
					count = count - 1;
					break;
				}
				else {
					if ((movei - i) == -1) {
						break;
					}
				}
			}
		}
		if (count >= 3) {
			for (int i = 1; i < 5; i++) {
				if ((movei - i) != -1) {
					if ((gm[movea][movei - i] == '-') and (count0 == 1)) {
						gm[movea][movei - i] = '0';
						count0 = count0 + 1;
						break;
					}
					else {
						if (gm[movea][movei - i] == '0') {
							break;
						}
					}
				}
				else {
					break;
				}
			}
			for (int i = 1; i < 5; i++) {
				if ((movei + i) != 20) {
					if ((gm[movea][movei + i] == '-') and (count0 == 1)) {
						gm[movea][movei + i] = '0';
						count0 = count0 + 1;
						break;
					}
					else {
						if (gm[movea][movei + i] == '0') {
							break;
						}
					}
				}
				else {
					break;
				}
			}
		}
		else {
			count = 1;
			for (int j = 1; j < 5; j++) {
				if (gm[movea + j][movei + j] == 'X') {
					count = count + 1;
				}
				else {
					if ((gm[movea + j][movei + j] == '0')) {
						break;
					}
				}
			}
			for (int j = 1; j < 5; j++) {
				if (gm[movea - j][movei - j] == 'X') {
					count = count + 1;
				}
				else {
					if ((gm[movea - j][movei - j] == '0')) {
						break;
					}
				}
			}
			if (count >= 3) {
				for (int j = 1; j < 5; j++) {
					if (gm[movea + j][movei + j] != '0') {
						if ((gm[movea + j][movei + j] == '-') and (count0 == 1)) {
							gm[movea + j][movei + j] = '0';
							count0 = count0 + 1;
							break;
						}
					}
					else {
						break;
					}
				}
				for (int j = 1; j < 5; j++) {
					if (gm[movea - j][movei - j] != '0') {
						if ((gm[movea - j][movei - j] == '-') and (count0 == 1)) {
							gm[movea - j][movei - j] = '0';
							count0 = count0 + 1;
							break;

						}
					}
					else {
						break;
					}
				}
			}
			else {
				count = 1;
				for (int r = 1; r < 4; r++) {
					if (gm[movea + r][movei - r] == 'X') {
						count = count + 1;
					}
					else {
						if (gm[movea + r][movei - r] == '0') {
							break;
						}
					}
				}
				for (int r = 1; r < 4; r++) {
					if (gm[movea - r][movei + r] == 'X') {
						count = count + 1;
					}
					else {
						if (gm[movea - r][movei + r] == '0') {
							break;
						}
					}
				}
				if (count >= 3) {
					for (int r = 1; r < 4; r++) {
						if (gm[movea + r][movei - r] != '0') {
							if ((gm[movea + r][movei - r] == '-') and (count0 == 1)) {
								gm[movea + r][movei - r] = '0';
								count0 = count0 + 1;
								break;
							}
						}
						else {
							break;
						}

					}
					for (int r = 1; r < 4; r++) {
						if (gm[movea - r][movei + r] != '0') {
							if ((gm[movea - r][movei + r] == '-') and (count0 == 1)) {
								gm[movea - r][movei + r] = '0';
								count0 = count0 + 1;
								break;
							}
						}
						else {
							break;
						}
					}
				}
			}
		}
	}
	//ходы компьютера
	count = 1;
	if (countc == 1) {
		moveic = GetRandomNumber(7, 12);
		moveac = GetRandomNumber(7, 12);
		if ((gm[moveac][moveic] == '-') and (count0 == 1)) {
			gm[moveac][moveic] = '0';
			count0 = count0 + 1;
			countc = countc + 1;
		}
		if ((gm[moveac][moveic] != '-') and (count0 == 1)) {
			while (gm[moveac][moveic] != '-') {
				moveic = GetRandomNumber(7, 12);
				moveac = GetRandomNumber(7, 12);
				if (gm[moveac][moveic] == '-') {
					gm[moveac][moveic] = '0';
					count0 = count0 + 1;
					countc = countc + 1;
				}
				break;
			}
		}
	}
	else {
		for (int a = 1; a < 5; a++) {
			if ((gm[moveac + a][moveic] == '-') or (gm[moveac + a][moveic] == '0')) {
				count = count + 1;
			}
			else {
				if (gm[moveac + a][moveic] == 'X') {
					break;
				}
			}
		}
		for (int a = 1; a < 5; a++) {
			if ((gm[moveac - a][moveic] == '-') or (gm[moveac - a][moveic] == '0')) {
				count = count + 1;
			}
			else {
				if (gm[moveac - a][moveic] == 'X') {
					break;
				}
			}
		}
		if (count >= 4) {
			for (int a = 1; a < 5; a++) {
				if ((gm[moveac + a][moveic] == '-') and (count0 == 1) and ((moveac + a) != 20)) {
					gm[moveac + a][moveic] = '0';
					count0 = count0 + 1;
					moveac = moveac + a;
					break;
				}
				else {
					if (gm[moveac + a][moveic] == 'X') {
						break;
					}
				}
			}
			for (int a = 1; a < 5; a++) {
				if ((gm[moveac - a][moveic] == '-') and (count0 == 1) and ((moveac - a) != -1)) {
					gm[moveac - a][moveic] = '0';
					moveac = moveac - a;
					count0 = count0 + 1;
					break;
				}
				else {
					if (gm[moveac - a][moveic] == 'X') {
						break;
					}
				}
			}
		}
		else {
			count = 1;
			for (int i = 1; i < 4; i++) {
				if (gm[moveac][moveic + i] == '-') {
					count = count + 1;
				}
				else {
					if (gm[moveac][moveic + i] == 'X') {
						break;
					}
				}
			}
			for (int i = 1; i < 4; i++) {
				if (gm[moveac][moveic - i] == '-') {
					count = count + 1;
				}
				else {
					if (gm[moveac][moveic - i] == 'X') {
						break;
					}
				}
			}
			if (count >= 4) {
				for (int i = 1; i < 4; i++) {
					if ((gm[moveac][moveic + i] == '-') and (count0 == 1) and ((moveic + i) != 20)) {
						gm[moveac][moveic + i] = '0';
						count0 = count0 + 1;
						moveic = moveic + i;
						break;
					}
					else {
						if (gm[moveac][moveic + i] == 'X') {
							break;
						}
					}
					break;
				}
				for (int i = 1; i < 4; i++) {
					if ((gm[moveac][moveic - i] == '-') and (count0 == 1) and ((moveic - i) != -1)) {
						gm[moveac][moveic - i] = '0';
						moveic = moveic - i;
						count0 = count0 + 1;
						break;
					}
					else {
						if (gm[moveac][moveic - i] == 'X') {
							break;
						}
					}
				}
			}
			else {
				count = 1;
				for (int j = 1; j < 4; j++) {
					if (gm[moveac + j][moveic + j] == '-') {
						count = count + 1;
					}
					else {
						if (gm[moveac + j][moveic + j] == 'X') {
							break;
						}
					}
				}
				for (int j = 1; j < 4; j++) {
					if (gm[moveac - j][moveic - j] == '-') {
						count = count + 1;
					}
					else {
						if (gm[moveac - j][moveic - j] == 'X') {
							break;
						}
					}
				}
				if (count >= 4) {
					for (int j = 1; j < 4; j++) {
						if ((gm[moveac + j][moveic + j] == '-') and (count0 == 1)) {
							gm[moveac + j][moveic + j] = '0';
							count0 = count0 + 1;
							moveac = moveac + j;
							moveic = moveic + j;
							break;
						}
						break;
					}
					for (int j = 1; j < 4; j++) {
						if ((gm[moveac - j][moveic - j] == '-') and (count0 == 1)) {
							if ((gm[moveac - 1][moveic - 1] == '-') and (gm[moveac + 1][moveic + 1] != '0')) {
								gm[moveac - j][moveic - j] = '0';
								moveac = moveac - j;
								moveic = moveic - j;
								count0 = count0 + 1;
								break;
							}
						}
					}
				}
				else {
					count = 1;
					for (int r = 1; r < 4; r++) {
						if (gm[moveac + r][moveic - r] == '-') {
							count = count + 1;
						}
						else {
							if (gm[moveac + r][moveic - r] == 'X') {
								break;
							}
						}
					}
					for (int r = 1; r < 4; r++) {
						if (gm[moveac - r][moveic + r] == '-') {
							count = count + 1;
						}
						else {
							if (gm[moveac - r][moveic + r] == 'X') {
								break;
							}
						}
					}
					if (count >= 4) {
						for (int r = 1; r < 4; r++) {
							if ((gm[moveac + r][moveic - r] == '-') and (count0 == 1)) {
								gm[moveac + r][moveic - r] = '0';
								moveac = moveac + r;
								moveic = moveic - r;
								count0 = count0 + 1;
								break;
							}
							break;
						}
						for (int r = 1; r < 4; r++) {
							if ((gm[moveac - r][moveic + r] == '-') and (count0 == 1)) {
								gm[moveac - r][moveic + r] = '0';
								moveac = moveac - r;
								moveic = moveic + r;
								count0 = count0 + 1;
								break;
							}
						}
					}
				}
				for (movea = 0; movea < 20; movea++) {
					for (movei = 0; movei < 20; movei++) {
						if ((gm[moveac][moveic] == '-') and (count0 == 1)) {
							gm[moveac][moveic] = '0';
							count0 = count0 + 1;
							break;
						}
					}
					if (count0 != 1) {
						break;
					}
				}
			}
		}
	}
	count0 = 1;
}


bool won(char player) {
	int count;
	count = 1;
	for (int a = 1; a < 5; a++) {
		if ((gm[movea + a][movei] == 'X') and (movea + a) != 20) {
			count = count + 1;
		}
		else {
			break;
		}
	}

	for (int a = 1; a < 5; a++) {
		if ((gm[movea - a][movei] == 'X') and (movea - a) != -1) {
			count = count + 1;
		}
		else {
			break;
		}
	}
	if (count >= 5) {
		return true;
	}
	else {
		count = 1;
		for (int i = 1; i < 5; i++) {
			if ((gm[movea][movei + i] == 'X') and (movei + i) != 20) {
				count = count + 1;
			}
			else {
				break;
			}
		}

		for (int i = 1; i < 5; i++) {
			if ((gm[movea][movei - i] == 'X') and (movei - i) != -1) {
				count = count + 1;
			}
			else {
				break;
			}
		}
		if (count >= 5) {
			return true;
		}
		else {
			count = 1;
			for (int j = 1; j < 5; j++) {
				if (gm[movea + j][movei + j] == 'X') {
					count = count + 1;
				}
				else {
					break;
				}
			}

			for (int j = 1; j < 5; j++) {
				if (gm[movea - j][movei - j] == 'X') {
					count = count + 1;
				}
				else {
					break;
				}
			}
			if (count >= 5) {
				return true;
			}
			else {
				count = 1;
				for (int r = 1; r < 5; r++) {
					if (gm[movea - r][movei + r] == 'X') {
						count = count + 1;
					}
					else {
						break;
					}
				}

				for (int r = 1; r < 5; r++) {
					if (gm[movea + r][movei - r] == 'X') {
						count = count + 1;
					}
					else {
						break;
					}
				}
				if (count >= 5) {
					return true;
				}
			}
		}
	}
	count = 1;
	for (int a = 1; a < 5; a++) {
		if (gm[moveac + a][moveic] == '0') {
			count = count + 1;
		}
		else {
			break;
		}
	}

	for (int a = 1; a < 5; a++) {
		if (gm[moveac - a][moveic] == '0') {
			count = count + 1;
		}
		else {
			break;
		}
	}
	if (count >= 5) {
		return true;
	}
	else {
		count = 1;
		for (int i = 1; i < 5; i++) {
			if (gm[moveac][moveic + i] == '0') {
				count = count + 1;
			}
			else {
				break;
			}
		}

		for (int i = 1; i < 5; i++) {
			if (gm[moveac][moveic - i] == '0') {
				count = count + 1;
			}
			else {
				break;
			}
		}
		if (count >= 5) {
			return true;
		}
		else {
			count = 1;
			for (int j = 1; j < 5; j++) {
				if (gm[moveac + j][moveic + j] == '0') {
					count = count + 1;
				}
				else {
					break;
				}
			}

			for (int j = 1; j < 5; j++) {
				if (gm[moveac - j][moveic - j] == '0') {
					count = count + 1;
				}
				else {
					break;
				}
			}
			if (count >= 5) {
				return true;
			}
			else {
				count = 1;
				for (int r = 1; r < 5; r++) {
					if (gm[moveac - r][moveic + r] == '0') {
						count = count + 1;
					}
					else {
						break;
					}
				}

				for (int r = 1; r < 5; r++) {
					if (gm[moveac + r][moveic - r] == '0') {
						count = count + 1;
					}
					else {
						break;
					}
				}
				if (count >= 5) {
					return true;
				}
			}
		}
	}
	return false;
}//проверка на выигрышь


void playing() {
	string x;
	bool count = false;

	if ((GetRandomNumber(1, 2) == 1) and (count == false)) {
		cout << "Ваш ход первый, нажмите y если согласны, в противном случае нажимте n" << endl;
		getline(cin, x);
		while (x != "y" and x != "n") {
			cout << "Для продожения вы должны ввести y/n:";
			getline(cin, x);
			clear();
		}

		if (x == "y") {
			int motion;
			motion = 1;
			while (!won('X') and !won('0')) {
				clear();
				if (motion % 2 == 1) {
					humanmove(&movei, &movea);
					gm[movea][movei] = 'X';
					if (won('X')) {
						clear();
						gameboard();
						cout << "Ты победил!";
						count = true;
					}
				}
				else {
					computermove();
					if (won('0')) {
						clear();
						gameboard();
						cout << "Победил компьютер(";
						count = true;
					}
				}
				motion++;
				if (motion == 200) {
					clear();
					gameboard();
					cout << "Ничья!";
					count = true;
				}
			}
		}
		if (x == "n") {
			int motion;
			motion = 1;
			while (!won('X') and !won('0')) {
				clear();
				if (motion % 2 == 1) {
					computermove();
					if (won('0')) {
						gm[moveac][moveic] = '0';
						clear();
						gameboard();
						cout << "Победил компьютер(";
						count = true;
					}
				}
				else {
					humanmove(&movei, &movea);
					gm[movea][movei] = 'X';
					if (won('X')) {
						clear();
						gameboard();
						cout << "Ты победил!";
						count = true;
					}
				}
				motion++;
				if (motion == 200) {
					clear();
					gameboard();
					cout << "Ничья!";
					count = true;
				}
			}
		}
	}
	if ((GetRandomNumber(1, 2) == 2) and (count == false)) {
		cout << "Ваш ход второй, нажмите y если согласны, в противном случае нажимте n" << endl;
		getline(cin, x);
		while (x != "y" and x != "n") {
			cout << "Для продожения вы должны ввести y/n:";
			getline(cin, x);
			clear();
		}
		if (x == "y") {
			int motion;
			motion = 1;
			while (!won('X') and !won('0')) {
				clear();
				if (motion % 2 == 1) {
					computermove();
					if (won('0')) {
						gm[moveac][moveic] = '0';
						clear();
						gameboard();
						cout << "Победил компьютер(";
						count = true;
					}
				}
				else {
					humanmove(&movei, &movea);
					gm[movea][movei] = 'X';
					if (won('X')) {
						clear();
						gameboard();
						cout << "Ты победил!";
						count = true;
					}
				}
				motion++;
				if (motion == 200) {
					clear();
					gameboard();
					cout << "Ничья!";
					count = true;
				}
			}
		}
		if (x == "n") {
			int motion;
			motion = 1;
			while (!won('X') and !won('0')) {
				clear();
				if (motion % 2 == 1) {
					humanmove(&movei, &movea);
					gm[movea][movei] = 'X';
					if (won('X')) {
						clear();
						gameboard();
						cout << "Ты победил!";
						count = true;
					}
				}
				else {
					computermove();
					if (won('0')) {
						gm[moveac][moveic] = '0';
						clear();
						gameboard();
						cout << "Победил компьютер(";
						count = true;
					}
				}
				motion++;
				if (motion == 200) {
					clear();
					gameboard();
					cout << "Ничья!";
					count = true;
				}
			}
		}
	}
}//механика игры
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	board();
	clear();
	playing();
}


