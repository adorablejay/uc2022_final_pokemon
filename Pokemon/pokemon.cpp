#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>

using namespace std;

int user_score = 0, cpu_score = 0;

void pok_assign(void);
void pok_display(void);
void pok_display(int);
void  play(int);

class POK
{
private:
	int power;
	float health;
	int speed;
	int defence;
	int offence;
	char name[10];

public:
	int pow() { return power; }
	float hlt() { return health; }
	int spd() { return speed; }
	int def() { return defence; }
	int off() { return offence; }
	char* getname() { return name; };
	void special(int);
	void attack(int);
	void defend(int);
	void agility(int);

	POK() {}

	POK(int p, float h, int s, int d, int o, char n[10])
	{
		power = p;
		health = h;
		speed = s;
		defence = d;
		offence = o;
		strcpy(name, n);
	}

};

char a[12][12] = { "찌리리공","피카츄","고라파덕","거북왕","나인테일","리자몽",
	"버터플","깨비참","후딘 ","마임맨","딱구리","투구푸스" };

POK Voltorb(4, 60, 5, 4, 3, a[0]), Pikachu(7, 80, 6, 5, 8, a[1]);
POK Psyduck(3, 50, 4, 7, 5, a[2]), Blastoise(8, 90, 5, 8, 7, a[3]);
POK Ninetales(7, 70, 8, 5, 6, a[4]), Charizard(9, 80, 4, 7, 9, a[5]);
POK Butterfee(6, 50, 8, 3, 6, a[6]), Spearow(8, 70, 9, 4, 7, a[7]);
POK Alakazam(7, 80, 4, 5, 9, a[8]), MrMime(8, 70, 4, 9, 7, a[9]);
POK Golem(7, 90, 3, 8, 7, a[10]), Kabutops(9, 70, 6, 9, 8, a[11]);

class player
{
public:
	POK pokemon[3];

}cpu, user;

void POK::special(int pok)
{
	//randomize();
	int ch = rand() % 4;
	switch (ch)
	{
	case 0:	health *= 2;
		cout << "\n체력 2배!";
		break;
	case 1: speed *= power;
		cout << "\n민첩 증폭!";
		break;
	case 2: defence *= power;
		cout << "\n방어 증폭!";
		break;
	case 3: offence *= power;
		cout << "\n공격 증폭!";
		break;
	}
	power = 0;
	pok_display(pok);

}

void POK::attack(int pok)
{
	//randomize();
	int ch = rand() % 4, cpu_val, user_val;
	user_val = user.pokemon[pok].off();
	switch (ch)
	{
	case 0: cout << "\n상대는 민첩을 선택했다!";
		cpu_val = cpu.pokemon[pok].spd();
		if (cpu_val - user_val > 50)
			user.pokemon[pok].health -= 10;
		else
			cpu.pokemon[pok].health -= 20;
		break;
	case 1: cout << "\n상대는 방어를 선택했다!";
		cpu_val = cpu.pokemon[pok].def();
		if (user_val - cpu_val > 50)
			cpu.pokemon[pok].health -= 10;
		else
			user.pokemon[pok].health -= 20;
		break;
	case 2: cout << "\n상대는 공격을 선택했다!";
		cpu_val = cpu.pokemon[pok].off();
		if (user_val - cpu_val > 50)
			cpu.pokemon[pok].health -= 20;
		else if (cpu_val - user_val > 50)
			user.pokemon[pok].health -= 20;
		else if (cpu_val > user_val)
			user.pokemon[pok].health -= 10;
		else if (user_val > cpu_val)
			cpu.pokemon[pok].health -= 10;
		break;
	case 3: cout << "\n상대는 강화를 선택했다!";
		cpu.pokemon[pok].special(pok);
		break;
	}
}

void POK::defend(int pok)
{
	//randomize();
	int ch = rand() % 4, cpu_val, user_val;
	user_val = user.pokemon[pok].def();
	switch (ch)
	{
	case 0: cout << "\n상대는 민첩을 선택했다!";
		cpu_val = cpu.pokemon[pok].spd();
		if (user_val - cpu_val > 50)
			cpu.pokemon[pok].health -= 10;
		else
			user.pokemon[pok].health -= 20;
		break;
	case 1: cout << "\n상대는 공격을 선택했다!";
		cpu_val = cpu.pokemon[pok].off();
		if (cpu_val - user_val > 50)
			user.pokemon[pok].health -= 10;
		else
			cpu.pokemon[pok].health -= 20;
		break;
	case 2: cout << "\n상대는 방어를 선택했다!";
		cpu_val = cpu.pokemon[pok].def();
		if (user_val - cpu_val > 50)
			cpu.pokemon[pok].health -= 20;
		else if (cpu_val - user_val > 50)
			user.pokemon[pok].health -= 20;
		else if (cpu_val > user_val)
			user.pokemon[pok].health -= 10;
		else if (user_val > cpu_val)
			cpu.pokemon[pok].health -= 10;
		break;
	case 3: cout << "\n상대는 강화를 선택했다!";
		cpu.pokemon[pok].special(pok);
		break;
	}
}

void POK::agility(int pok)
{
	//randomize();
	int ch = rand() % 4, cpu_val, user_val;
	user_val = user.pokemon[pok].spd();
	switch (ch)
	{
	case 0: cout << "\n상대는 방어를 선택했다!";
		cpu_val = cpu.pokemon[pok].def();
		if (cpu_val - user_val > 50)
			user.pokemon[pok].health -= 10;
		else
			cpu.pokemon[pok].health -= 20;
		break;
	case 1: cout << "\n상대는 공격을 선택했다!";
		cpu_val = cpu.pokemon[pok].off();
		if (user_val - cpu_val > 50)
			cpu.pokemon[pok].health -= 10;
		else
			user.pokemon[pok].health -= 20;
		break;
	case 2: cout << "\n상대는 민첩을 선택했다!";
		cpu_val = cpu.pokemon[pok].spd();
		if (user_val - cpu_val > 50)
			cpu.pokemon[pok].health -= 20;
		else if (cpu_val - user_val > 50)
			user.pokemon[pok].health -= 20;
		else if (cpu_val > user_val)
			user.pokemon[pok].health -= 10;
		else if (user_val > cpu_val)
			cpu.pokemon[pok].health -= 10;
		break;
	case 3: cout << "\n상대는 강화를 선택했다!";
		cpu.pokemon[pok].special(pok);
		break;
	}
}

int main()
{
	int pok, num;
	int ber;
	cout << "\t********* *****   * *  *******      *      *****    *" << endl;
	cout << "\t  *   *       *   * *  *     *     * *     *        *" << endl;
	cout << "\t  *   *   ***** *** *  *******    *   *    *        *" << endl;
	cout << "\t*********    *    * *     *      *     *   *        *" << endl;
	cout << "\t    *       *  ** * *  *******  *       *  *****  ***    " << endl;
	cout << "\t    *         *  *     *                   *        *" << endl;
	cout << "\t    *        *    *    *                   *        *" << endl;
	cout << "\t    *       *      *   *                   *        *" << endl;
	cout << "\t*********  *        *  ******* *********** *****    *" << endl;
	cout << "---------------------------------------------------------------------" << endl;

	while (true) {
		cout << "1) 싸운다  2) 가방  3) 포켓몬  4) 도망간다 :";
		cin >> num;

		if (num == 1) {
		restart:
			//	clrscr();
			pok_assign();
			for (int i = 0; i < 3; ++i)
			{
				cout << "\n______________________________________________";
				pok_display();
				do {
					cout << "\n\n포켓몬을 선택 해주세요.(1-3): ";
					cin >> pok;
					if (!pok)
						return 0;
					if (pok == 10101)
						goto restart;
				} while (pok > 3 || pok < 0);
				play(--pok);
			}
			cout << "\n\t\t____________________________________________\n";
			if (user_score > cpu_score)
				cout << "\t\t**********!!!이겼습니다!!!**********";
			else
				cout << "\t\t**********!!!상대방에게 졌습니다!!!**********";
			cout << "\n\t\t____________________________________________\n";
			//!	getch();
			return 0;
		}
		else if (num == 2) { exit; }
		else if (num == 3) {
			for (int i = 0; i < 6; ++i) {
				cout << "\n" << i + 1 << ") " << a[i];
			}
			cout << endl << endl;
		}


		if (num == 4) {
			cout << "도망칠 수 없습니다. 종료 하시겠습니까?" << endl;
			cout << "1. 싸운다 2. 종료한다 : ";

			cin >> ber;
			if (ber == 1) {
				goto restart;
			}
			else if (ber == 2)
			{
				return 0;
			}
		}
	}
}

void play(int pok)
{
	int choice;
	cout << "\n나의 포켓몬 : " << user.pokemon[pok].getname();
	cout << "\n상대 포켓몬: " << cpu.pokemon[pok].getname() << endl;
	while ((user.pokemon[pok].hlt() > 0) && (cpu.pokemon[pok].hlt() > 0))
	{
		do {
			cout << "_____________________________________________";
			cout << "\n선택하세요: ";
			cout << "\n1.) 민첩: " << user.pokemon[pok].spd()
				<< "\t\t2.) 공격:  " << user.pokemon[pok].off()
				<< "\n3.) 방어: " << user.pokemon[pok].def()
				<< "\t\t4.) 강화: " << user.pokemon[pok].pow();
			cout << "\n\n선택하세요: ";
			cin >> choice;
		} while (choice < 0 || choice>4);

		switch (choice)
		{
		case 0:exit(0);
		case 1:user.pokemon[pok].agility(pok);	break;
		case 2:user.pokemon[pok].attack(pok);	break;
		case 3:user.pokemon[pok].defend(pok);	break;
		case 4:user.pokemon[pok].special(pok);	break;
		}

		cout << "\n\n나의 포켓몬: " << user.pokemon[pok].getname()
			<< "\t체력: " << user.pokemon[pok].hlt();
		cout << "\n상대 포켓몬 : " << cpu.pokemon[pok].getname()
			<< "\t체력: " << cpu.pokemon[pok].hlt() << endl;
	}

	if (user.pokemon[pok].hlt() > cpu.pokemon[pok].hlt())
	{
		user_score++;
		cout << "\n\n**********************";
		cout << "\n* 이겼다!! *\n";
		cout << "**********************\n\n";
	}
	else
	{
		cpu_score++;
		cout << "\n\n**********************";
		cout << "\n* 졌습니다. *\n";
		cout << "**********************\n\n";
	}
}




void pok_assign()
{
	//randomize();
	int uval, cval;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 3; ++i)
	{
		uval = rand() % 11;
		cval = rand() % 11;
		switch (uval)
		{
		case 0:user.pokemon[i] = Voltorb;	 break;
		case 1:user.pokemon[i] = Pikachu;	 break;
		case 2:user.pokemon[i] = Psyduck;	 break;
		case 3:user.pokemon[i] = Blastoise; break;
		case 4:user.pokemon[i] = Ninetales; break;
		case 5:user.pokemon[i] = Charizard; break;
		case 6:user.pokemon[i] = Butterfee; break;
		case 7:user.pokemon[i] = Spearow;	 break;
		case 8:user.pokemon[i] = Alakazam; break;
		case 9:user.pokemon[i] = MrMime;	 break;
		case 10:user.pokemon[i] = Golem;	 break;
		case 11:user.pokemon[i] = Kabutops; break;
		}
		switch (cval)
		{
		case 0:cpu.pokemon[i] = Voltorb;	 break;
		case 1:cpu.pokemon[i] = Pikachu;	 break;
		case 2:cpu.pokemon[i] = Psyduck;	 break;
		case 3:cpu.pokemon[i] = Blastoise; break;
		case 4:cpu.pokemon[i] = Ninetales; break;
		case 5:cpu.pokemon[i] = Charizard; break;
		case 6:cpu.pokemon[i] = Butterfee; break;
		case 7:cpu.pokemon[i] = Spearow;	 break;
		case 8:cpu.pokemon[i] = Alakazam;  break;
		case 9:cpu.pokemon[i] = MrMime;	 break;
		case 10:cpu.pokemon[i] = Golem;	 break;
		case 11:cpu.pokemon[i] = Kabutops; break;
		}
	}
}

void pok_display()
{
	cout << "\n\n나의 포켓몬: \n";
	for (int i = 0; i < 3; ++i)
	{
		cout << "\n" << i + 1 << ") " << user.pokemon[i].getname();
		cout << "\n\t강화\t체력\t민첩\t방어\t공격" << endl;
		cout << "\t" << user.pokemon[i].pow()
			<< "\t" << user.pokemon[i].hlt()
			<< "\t" << user.pokemon[i].spd()
			<< "\t" << user.pokemon[i].def()
			<< "\t" << user.pokemon[i].off();
	}
}

void pok_display(int i)
{

	cout << "\n_____________________________________________";
	cout << "\n포켓몬 능력:\n";

	cout << "\nUser: " << user.pokemon[i].getname();
	cout << "\n\t강화\t체력\t민첩\t방어\t공격" << endl;
	cout << "\t" << user.pokemon[i].pow()
		<< "\t" << user.pokemon[i].hlt()
		<< "\t" << user.pokemon[i].spd()
		<< "\t" << user.pokemon[i].def()
		<< "\t" << user.pokemon[i].off();

	cout << "\nCPU : " << cpu.pokemon[i].getname();
	cout << "\n\t강화\t체력\t민첩\t방어\t공격" << endl;
	cout << "\t" << cpu.pokemon[i].pow()
		<< "\t" << cpu.pokemon[i].hlt()
		<< "\t" << cpu.pokemon[i].spd()
		<< "\t" << cpu.pokemon[i].def()
		<< "\t" << cpu.pokemon[i].off();
}