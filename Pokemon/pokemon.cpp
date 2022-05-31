#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <list>
#include<Windows.h>

using namespace std;

int user_score = 0, cpu_score = 0;
int p;
void pok_assign(void);
void pok_display(void);
void pok_display(int);
void  play(int);

class POK
{
private:
	int power;
	int speed;
	int defence;
	int offence;
	char name[10];

public:
	
	float health;
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

POK Voltorb(100, 60, 50, 40, 30, a[0]), Pikachu(100, 80, 60, 50, 80, a[1]);
POK Psyduck(100, 50, 40, 70, 50, a[2]), Blastoise(100, 90, 50, 80, 70, a[3]);
POK Ninetales(100, 70, 80, 50, 60, a[4]), Charizard(100, 80, 40, 70, 90, a[5]);
POK Butterfee(100, 50, 80, 30, 60, a[6]), Spearow(100, 70, 90, 40, 70, a[7]);
POK Alakazam(100, 80, 40, 50, 90, a[8]), MrMime(100, 70, 40, 90, 70, a[9]);
POK Golem(100, 90, 30, 80, 70, a[10]), Kabutops(100, 70, 60, 90, 80, a[11]);

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
	int pok;
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
		restart:
			//	clrscr();
			pok_assign();
			for (int i = 0; i < 3; ++i)
			{
				pok_display();
				do {
					cout << "\n\n포켓몬을 선택 하세요.(1-3): ";
					cin >> p;
					if (!p)
						return 0;
					if (p == 10101)
						goto restart;
				} while (p > 3 || p < 0);//pok이 예외상황(음수or3초과)일 때 반복
				play(--p);
			}

			cout << "\n\t\t________________________________________________________________\n";
			if (user_score > cpu_score)
				cout << "\t\t**********!!!상대방보다 점수가 높습니다. 이겼습니다!!!**********";
			else
				cout << "\t\t**********!!!상대방에게 점수가 낮습니다.!!!**********";
			cout << "\n\t\t________________________________________________________________\n";
			//!	getch();
			return 0;		
	}
}

void play(int pok)
{
	int choice, num, ber;
	int bag, fruit;
	fruit = 1;

	cout << "\n나의 포켓몬 : " << user.pokemon[p].getname();
	cout << "\n상대 포켓몬: " << cpu.pokemon[p].getname() << endl;
	while ((user.pokemon[p].hlt() > 0) && (cpu.pokemon[p].hlt() > 0))
	{
		
		do {
			cout << "_____________________________________________";
			cout << "\n선택: ";
			cout << "\n1.) 민첩: " << user.pokemon[p].spd()<<"%"
				<< "\t\t2.) 공격:  " << user.pokemon[p].off()<<"%"
				<< "\n3.) 방어: " << user.pokemon[p].def()<<"%"
				<< "\t\t4.) 강화: " << user.pokemon[p].pow()<<"%";
			cout << "\n\n선택하세요: ";
			cin >> choice;
		} while (choice < 0 || choice>4);//예외사항일때 반복(음수or4초과)

		switch (choice)
		{
		case 0:exit(0);
		case 1:user.pokemon[p].agility(p);	break;
		case 2:user.pokemon[p].attack(p);	break;
		case 3:user.pokemon[p].defend(p);	break;
		case 4:user.pokemon[p].special(p);	break;
		} 
		//(1~4까지 선택 할 경우)

		cout << "\n\n나의 포켓몬: " << user.pokemon[p].getname()
			<< "\t체력: " << user.pokemon[p].hlt();
		cout << "\n상대 포켓몬 : " << cpu.pokemon[p].getname()
			<< "\t체력: " << cpu.pokemon[p].hlt() << endl;

		if ((user.pokemon[p].hlt() > 0) && (cpu.pokemon[p].hlt() > 0))
		{
			cout << "\n____________________________________________\n";
			cout << "1) 싸운다  2) 가방  3) 포켓몬  4) 도망간다 :";
			cin >> num;
			if (num == 2) {
				cout << "1.하이퍼볼 X 3\t  " << "2.나무열매 X "<< fruit << endl;
				cout << "선택해주세요:";
				cin >> bag;
				if (bag == 1) {
					cout << "배틀 중에 사용할 수 없습니다!\n";
				}
				if (bag == 2) {
					if (fruit>0)
					{
						cout << user.pokemon[p].getname() << "의 체력이 10증가 했습니다.\n";
						cout << "현재 체력" << user.pokemon[p].hlt() + 10 << endl;
						user.pokemon[p].health += 10;
					}
					else if (fruit == 0) { cout << "열매가 없습니다!\n"; }
					fruit--;
				}
			}
			else if (num == 3) {
				cout << "현재 포켓몬은 " << user.pokemon[p].getname() << "입니다.";
				
				pok_display();
				int l = p;
					cout << "\n\n3마리 중 어떤 포켓몬으로 교체하시겠습니까? : ";
					cin >> p;
					p -= 1;

					if (l == p) {
						cout << "같은 포켓몬으로 교체할 수 없습니다." << endl;
					}
					else {
						cout << user.pokemon[p].getname() << "으로 교체되었습니다. \n";
						//임시기억하기 클래스 객체 = 
					}
				
			}
			else if (num == 4) {
				cout << "도망칠 수 없습니다. 종료 하시겠습니까?" << endl;
				cout << "1. 싸운다 2. 종료한다 : ";
				cin >> ber;
				if (ber == 1) {
					continue;
				}
				else if (ber == 2)
				{
					exit(0);
				}
			}
			//system("cls");
		}
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
//포켓몬 정함
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

	cout << "\n\n포켓몬 능력:";

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
//강화를 선택할 경우