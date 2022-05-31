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

char a[12][12] = { "�����","��ī��","����Ĵ�","�źϿ�","��������","���ڸ�",
	"������","������","�ĵ� ","���Ӹ�","������","����Ǫ��" };

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
		cout << "\nü�� 2��!";
		break;
	case 1: speed *= power;
		cout << "\n��ø ����!";
		break;
	case 2: defence *= power;
		cout << "\n��� ����!";
		break;
	case 3: offence *= power;
		cout << "\n���� ����!";
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
	case 0: cout << "\n���� ��ø�� �����ߴ�!";
		cpu_val = cpu.pokemon[pok].spd();
		if (cpu_val - user_val > 50)
			user.pokemon[pok].health -= 10;
		else
			cpu.pokemon[pok].health -= 20;
		break;
	case 1: cout << "\n���� �� �����ߴ�!";
		cpu_val = cpu.pokemon[pok].def();
		if (user_val - cpu_val > 50)
			cpu.pokemon[pok].health -= 10;
		else
			user.pokemon[pok].health -= 20;
		break;
	case 2: cout << "\n���� ������ �����ߴ�!";
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
	case 3: cout << "\n���� ��ȭ�� �����ߴ�!";
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
	case 0: cout << "\n���� ��ø�� �����ߴ�!";
		cpu_val = cpu.pokemon[pok].spd();
		if (user_val - cpu_val > 50)
			cpu.pokemon[pok].health -= 10;
		else
			user.pokemon[pok].health -= 20;
		break;
	case 1: cout << "\n���� ������ �����ߴ�!";
		cpu_val = cpu.pokemon[pok].off();
		if (cpu_val - user_val > 50)
			user.pokemon[pok].health -= 10;
		else
			cpu.pokemon[pok].health -= 20;
		break;
	case 2: cout << "\n���� �� �����ߴ�!";
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
	case 3: cout << "\n���� ��ȭ�� �����ߴ�!";
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
	case 0: cout << "\n���� �� �����ߴ�!";
		cpu_val = cpu.pokemon[pok].def();
		if (cpu_val - user_val > 50)
			user.pokemon[pok].health -= 10;
		else
			cpu.pokemon[pok].health -= 20;
		break;
	case 1: cout << "\n���� ������ �����ߴ�!";
		cpu_val = cpu.pokemon[pok].off();
		if (user_val - cpu_val > 50)
			cpu.pokemon[pok].health -= 10;
		else
			user.pokemon[pok].health -= 20;
		break;
	case 2: cout << "\n���� ��ø�� �����ߴ�!";
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
	case 3: cout << "\n���� ��ȭ�� �����ߴ�!";
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
					cout << "\n\n���ϸ��� ���� �ϼ���.(1-3): ";
					cin >> p;
					if (!p)
						return 0;
					if (p == 10101)
						goto restart;
				} while (p > 3 || p < 0);//pok�� ���ܻ�Ȳ(����or3�ʰ�)�� �� �ݺ�
				play(--p);
			}

			cout << "\n\t\t________________________________________________________________\n";
			if (user_score > cpu_score)
				cout << "\t\t**********!!!���溸�� ������ �����ϴ�. �̰���ϴ�!!!**********";
			else
				cout << "\t\t**********!!!���濡�� ������ �����ϴ�.!!!**********";
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

	cout << "\n���� ���ϸ� : " << user.pokemon[p].getname();
	cout << "\n��� ���ϸ�: " << cpu.pokemon[p].getname() << endl;
	while ((user.pokemon[p].hlt() > 0) && (cpu.pokemon[p].hlt() > 0))
	{
		
		do {
			cout << "_____________________________________________";
			cout << "\n����: ";
			cout << "\n1.) ��ø: " << user.pokemon[p].spd()<<"%"
				<< "\t\t2.) ����:  " << user.pokemon[p].off()<<"%"
				<< "\n3.) ���: " << user.pokemon[p].def()<<"%"
				<< "\t\t4.) ��ȭ: " << user.pokemon[p].pow()<<"%";
			cout << "\n\n�����ϼ���: ";
			cin >> choice;
		} while (choice < 0 || choice>4);//���ܻ����϶� �ݺ�(����or4�ʰ�)

		switch (choice)
		{
		case 0:exit(0);
		case 1:user.pokemon[p].agility(p);	break;
		case 2:user.pokemon[p].attack(p);	break;
		case 3:user.pokemon[p].defend(p);	break;
		case 4:user.pokemon[p].special(p);	break;
		} 
		//(1~4���� ���� �� ���)

		cout << "\n\n���� ���ϸ�: " << user.pokemon[p].getname()
			<< "\tü��: " << user.pokemon[p].hlt();
		cout << "\n��� ���ϸ� : " << cpu.pokemon[p].getname()
			<< "\tü��: " << cpu.pokemon[p].hlt() << endl;

		if ((user.pokemon[p].hlt() > 0) && (cpu.pokemon[p].hlt() > 0))
		{
			cout << "\n____________________________________________\n";
			cout << "1) �ο��  2) ����  3) ���ϸ�  4) �������� :";
			cin >> num;
			if (num == 2) {
				cout << "1.�����ۺ� X 3\t  " << "2.�������� X "<< fruit << endl;
				cout << "�������ּ���:";
				cin >> bag;
				if (bag == 1) {
					cout << "��Ʋ �߿� ����� �� �����ϴ�!\n";
				}
				if (bag == 2) {
					if (fruit>0)
					{
						cout << user.pokemon[p].getname() << "�� ü���� 10���� �߽��ϴ�.\n";
						cout << "���� ü��" << user.pokemon[p].hlt() + 10 << endl;
						user.pokemon[p].health += 10;
					}
					else if (fruit == 0) { cout << "���Ű� �����ϴ�!\n"; }
					fruit--;
				}
			}
			else if (num == 3) {
				cout << "���� ���ϸ��� " << user.pokemon[p].getname() << "�Դϴ�.";
				
				pok_display();
				int l = p;
					cout << "\n\n3���� �� � ���ϸ����� ��ü�Ͻðڽ��ϱ�? : ";
					cin >> p;
					p -= 1;

					if (l == p) {
						cout << "���� ���ϸ����� ��ü�� �� �����ϴ�." << endl;
					}
					else {
						cout << user.pokemon[p].getname() << "���� ��ü�Ǿ����ϴ�. \n";
						//�ӽñ���ϱ� Ŭ���� ��ü = 
					}
				
			}
			else if (num == 4) {
				cout << "����ĥ �� �����ϴ�. ���� �Ͻðڽ��ϱ�?" << endl;
				cout << "1. �ο�� 2. �����Ѵ� : ";
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
		cout << "\n* �̰��!! *\n";
		cout << "**********************\n\n";
	}
	else
	{
		cpu_score++;
		cout << "\n\n**********************";
		cout << "\n* �����ϴ�. *\n";
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
//���ϸ� ����
void pok_display()
{
	cout << "\n\n���� ���ϸ�: \n";
	for (int i = 0; i < 3; ++i)
	{
		cout << "\n" << i + 1 << ") " << user.pokemon[i].getname();
		cout << "\n\t��ȭ\tü��\t��ø\t���\t����" << endl;
		cout << "\t" << user.pokemon[i].pow()
			<< "\t" << user.pokemon[i].hlt()
			<< "\t" << user.pokemon[i].spd()
			<< "\t" << user.pokemon[i].def()
			<< "\t" << user.pokemon[i].off();
	}
}

void pok_display(int i)
{

	cout << "\n\n���ϸ� �ɷ�:";

	cout << "\nUser: " << user.pokemon[i].getname();
	cout << "\n\t��ȭ\tü��\t��ø\t���\t����" << endl;
	cout << "\t" << user.pokemon[i].pow()
		<< "\t" << user.pokemon[i].hlt()
		<< "\t" << user.pokemon[i].spd()
		<< "\t" << user.pokemon[i].def()
		<< "\t" << user.pokemon[i].off();

	cout << "\nCPU : " << cpu.pokemon[i].getname();
	cout << "\n\t��ȭ\tü��\t��ø\t���\t����" << endl;
	cout << "\t" << cpu.pokemon[i].pow()
		<< "\t" << cpu.pokemon[i].hlt()
		<< "\t" << cpu.pokemon[i].spd()
		<< "\t" << cpu.pokemon[i].def()
		<< "\t" << cpu.pokemon[i].off();
}
//��ȭ�� ������ ���