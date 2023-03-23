/***************************************************************************************************************************************************************************************************************************************************************************
**																		SAKARYA �N�VERS�TES�
**																B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**																	B�LG�SAYAR M�HEND�SL��� B�L�M�
**																		PROGRAMLAMAYA G�R�� DERS�
**
**																�DEV NUMARASI: 1
**																��RENC� ADI: H�MEYRA �ZT�RK
**																��RENC� NUMARASI: 
**																DERS GRUBU: C
**
***************************************************************************************************************************************************************************************************************************************************************************/


#include <iostream>
#include <iomanip>
#include <locale.h>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

string name, surname, successLetter;

string nameArray[30] = { "Enes", "Poyraz", "�mer", "Faruk", "Umut", "�brahim", "Asaf", "Ayaz",
"Yi�it", "Kerem", "��nar", "Emin", "Emre", "Yusuf", "Ela", "Duru", "Eslem", "Hira", "Nisa",
"Asya", "Ya�mur", "Eyl�l", "Ecrin", "Nehir", "Azra", "Defne", "Elif", "Zeynep", "H�meyra", "Kader" };
string surnameArray[30] = { "Y�lmaz", "Kaya", "Demir", "�elik", "�ahin", "Y�ld�z", "Y�ld�r�m",
"�zt�rk", "Can", "�zdemir", "Kurt", "Kaplan", "�etin", "Bilgin", "Demirci", "Karakaya", "Sabanc�",
"Aslan", "Arslan", "Do�an", "�eker", "Ko�", "�im�ek", "Polat", "�zcan", "�en", "Akta�", "Yal��n",
"G�ne�", "Bozkurt" };

int i;
int j;
float quiz1[100];
float quiz2[100];
float homework1[100];
float homework2[100];
float project[100];
float midterm[100];
float final[100];


struct student {
	string name, surname, letterGrade, successLetter;
	float number, quiz1, quiz2, homework1, homework2, project, midterm, final, yearGrade, successGrade;

};

int student[];
struct birthday {
	int day, month, year;

};

struct student stu[100];
struct birthday birth[100];
string letterGrade(string lGrade);
float control1(string s, float min, float max, int i);
float control2(string s, float min, float max, int i);
float control3(string s, float min, float max, int i);
float control4(string s, float min, float max, int i);
float control5(string s, float min, float max, int i);
float control6(string s, float min, float max, int i);
float control7(string s, float min, float max, int i);
void option1();
void option2();
void menu1();
void menu2();
void classList1();
void classList2();
float highestGrade();
float lowestGrade();
float average();
float standardDeviation();
float maxBetweenMin();
float below();
float above();
float average2();
float standardDeviation2();
float maxBetweenMin2();
float below2();
float above2();

int main() {

	setlocale(LC_ALL, "Turkish");

	int answer1;
	int answer2;
	int option;
	// Kullan�c�ya hangi se�enekten devam etmek istedi�ini soruyorum. �stenen �ekilde cevap vermezse soruyu tekrarl�yorum.
	do {
		cout << "Which option would you like to choose? 1 or 2 ?" << endl;
		cin >> option;
	} while (option != 1 && option != 2);

	system("CLS");



		// Kullan�c�dan al�nan cevaba g�re b�l�mleri �al��t�rmak i�in switch-case kulland�m.
	switch (option) {
		case 1:
			do {
				option1();

				// Kullan�c�ya 2. se�ene�e ge�mek istiyor mu diye soruyorum. �stenen �ekilde cevap vermezse soruyu tekrarl�yorum.
				do {
					cout << "Would you like to switch to option 2 ? (Yes => 1/ No => 0) " << endl;
					cin >> answer1;
					system("CLS");

				} while (answer1 != 0 && answer1 != 1);

				// Kullan�c� 2. se�ene�e ge�mek istemezse program� sonland�r�yorum.
				if (answer1 == 0) {
					break;
				}

		case 2:

				option2();

				// Kullan�c�ya 1. se�ene�e ge�mek istiyor mu diye soruyorum. �stenen �ekilde cevap vermezse soruyu tekrarl�yorum.
				do {
					cout << "Would you like to switch to option 1 ? (Yes => 1/ No => 0) " << endl;
					cin >> answer2;
				} while (answer2 != 0 && answer2 != 1);
				system("CLS");

			// E�er kullan�c� 1. se�ene�e d�nmek isterse d�ng� burada do-while sayesinde tekrar ba�lat�l�yor.
			// �stemezse d�ng� bitiyor ve program sonlan�yor.
			} while (answer2 == 1);
			break;

	}

	return 0;

}


string letterGrade(string lGrade) {
	float grade;
	grade = stof(lGrade);
	string letter;

	// 100 ile 90 aras�ndaki notlara harf notunu atayan d�ng�.
	if (grade <= 100 && grade > 90) {
		letter = "AA";
	}
	// 90 ile 85 aras�ndaki notlara harf notunu atayan d�ng�.
	else if (grade <= 90 && grade > 85) {
		letter = "BA";
	}
	// 85 ile 80 aras�ndaki notlara harf notunu atayan d�ng�.
	else if (grade <= 85 && grade > 80) {
		letter = "BB";
	}
	// 80 ile 75 aras�ndaki notlara harf notunu atayan d�ng�.
	else if (grade <= 80 && grade > 75) {
		letter = "CB";
	}
	// 75 ile 65 aras�ndaki notlara harf notunu atayan d�ng�.
	else if (grade <= 75 && grade > 65) {
		letter = "CC";
	}
	// 65 ile 58 aras�ndaki notlara harf notunu atayan d�ng�.
	else if (grade <= 65 && grade > 58) {
		letter = "DC";
	}
	// 58 ile 50 aras�ndaki notlara harf notunu atayan d�ng�.
	else if (grade <= 58 && grade > 50) {
		letter = "DD";
	}
	// 50 ile 40 aras�ndaki notlara harf notunu atayan d�ng�.
	else if (grade <= 50 && grade > 40) {
		letter = "FD";
	}
	// 40 ile 0 aras�ndaki notlara harf notunu atayan d�ng�.
	else if (grade <= 40 && grade > 0) {
		letter = "FF";
	}
	//Kullan�c� 0-100 aras�nda de�er girmezse 'ge�ersiz de�er' yazd�r�yorum.
	else
		cout << "Invalid Grade" << endl;


	return letter;
}
float control1(string s, float min, float max, int i) {

	float note;

	//k�sa s�nav 1 de�erini kontrol eden d�ng�
	do {
		cout << s;
		cin >> note;
		stu[i].quiz1 = note;
	} while (!(note >= min && note <= max));

	return note;
}
float control2(string s, float min, float max, int i) {
	float note;
	//k�sa s�nav 2 de�erini kontrol eden d�ng�
	do {
		cout << s;
		cin >> note;
		stu[i].quiz2 = note;
	} while (!(note >= min && note <= max));
	i++;
	return note;
}
float control3(string s, float min, float max, int i) {
	float note;
	//�dev 1 de�erini kontrol eden d�ng�
	do {
		cout << s;
		cin >> note;
		stu[i].homework1 = note;
	} while (!(note >= min && note <= max));
	i++;
	return note;
}
float control4(string s, float min, float max, int i) {
	float note;
	//�dev 2 de�erini kontrol eden d�ng�
	do {
		cout << s;
		cin >> note;
		stu[i].homework2 = note;
	} while (!(note >= min && note <= max));
	i++;
	return note;
}
float control5(string s, float min, float max, int i) {
	float note;
	//proje de�erini kontrol eden d�ng�
	do {
		cout << s;
		cin >> note;
		stu[i].project = note;
	} while (!(note >= min && note <= max));
	i++;
	return note;
}
float control6(string s, float min, float max, int i) {
	float note;
	//vize de�erini kontrol eden d�ng�
	do {
		cout << s;
		cin >> note;
		stu[i].midterm = note;
	} while (!(note >= min && note <= max));
	i++;
	return note;
}
float control7(string s, float min, float max, int i) {
	float note;
	//final de�erini kontrol eden d�ng�
	do {
		cout << s;
		cin >> note;
		stu[i].final = note;
	} while (!(note >= min && note <= max));
	i++;
	return note;
}


void option1() {
	int answer;

	srand(time(NULL));
	int index1;
	int index2;
	//�sme isim dizisindeki 30 karakterden rastgele 100 de�er atayan d�ng�
	for (int i = 0; i < 100; i++) {

		index1 = rand() % 29 + 1;
		stu[i].name = nameArray[index1];
		//Soyisme soyisim dizisindeki 30 karakterden rastgele 100 de�er atayan d�ng�
		for (int j = 0; j < 100; j++) {

			index2 = rand() % 29 + 1;
			stu[j].surname = surnameArray[index2];
		}
	}

	int q1, q2, h1, h2, p, m, f;
	//Belirlenen 100 ��encinin %10'una 0-40 aras� de�er atayan d�ng�
	for (int i = 0; i < 10; i++) {
		q1 = rand() % 40;	quiz1[i] = q1;		stu[i].quiz1 = quiz1[i];
		q2 = rand() % 40;	quiz2[i] = q2;		stu[i].quiz2 = quiz2[i];
		h1 = rand() % 40;	homework1[i] = h1;	stu[i].homework1 = homework1[i];
		h2 = rand() % 40;	homework2[i] = h2;	stu[i].homework2 = homework2[i];
		p = rand() % 40;	project[i] = p;		stu[i].project = project[i];
		m = rand() % 40;	midterm[i] = m;		stu[i].midterm = midterm[i];
		f = rand() % 40;	final[i] = f;		stu[i].final = final[i];
	}
	//Belirlenen 100 ��encinin %50'sine 40-70 aras� de�er atayan d�ng�
	for (int i = 10; i < 60; i++) {
		q1 = rand() % 31 + 40;	quiz1[i] = q1;		stu[i].quiz1 = quiz1[i];
		q2 = rand() % 31 + 40;	quiz2[i] = q2;		stu[i].quiz2 = quiz2[i];
		h1 = rand() % 31 + 40;	homework1[i] = h1;	stu[i].homework1 = homework1[i];
		h2 = rand() % 31 + 40;	homework2[i] = h2;	stu[i].homework2 = homework2[i];
		p = rand() % 31 + 40;	project[i] = p;		stu[i].project = project[i];
		m = rand() % 31 + 40;	midterm[i] = m;		stu[i].midterm = midterm[i];
		f = rand() % 31 + 40;	final[i] = f;		stu[i].final = final[i];
	}
	//Belirlenen 100 ��encinin %15'ine 70-80 aras� de�er atayan d�ng�
	for (int i = 60; i < 75; i++) {
		q1 = rand() % 11 + 70;	quiz1[i] = q1;		stu[i].quiz1 = quiz1[i];
		q2 = rand() % 11 + 70;	quiz2[i] = q2;		stu[i].quiz2 = quiz2[i];
		h1 = rand() % 11 + 70;	homework1[i] = h1;	stu[i].homework1 = homework1[i];
		h2 = rand() % 11 + 70;	homework2[i] = h2;	stu[i].homework2 = homework2[i];
		p = rand() % 11 + 70;	project[i] = p;		stu[i].project = project[i];
		m = rand() % 11 + 70;	midterm[i] = m;		stu[i].midterm = midterm[i];
		f = rand() % 11 + 70;	final[i] = f;		stu[i].final = final[i];
	}
	//Belirlenen 100 ��encinin %25'ine 80-100 aras� de�er atayan d�ng�
	for (int i = 75; i < 100; i++) {
		q1 = rand() % 21 + 80;	quiz1[i] = q1;		stu[i].quiz1 = quiz1[i];
		q2 = rand() % 21 + 80;	quiz2[i] = q2;		stu[i].quiz2 = quiz2[i];
		h1 = rand() % 21 + 80;	homework1[i] = h1;	stu[i].homework1 = homework1[i];
		h2 = rand() % 21 + 80;	homework2[i] = h2;	stu[i].homework2 = homework2[i];
		p = rand() % 21 + 80;	project[i] = p;		stu[i].project = project[i];
		m = rand() % 21 + 80;	midterm[i] = m;		stu[i].midterm = midterm[i];
		f = rand() % 21 + 80;	final[i] = f;		stu[i].final = final[i];
	}
	//Belirlenen 100 ��renciye random atanan notlar�na g�re y�li�i notu belirleyen d�ng�
	for (int i = 0; i < 100; i++) {
		stu[i].yearGrade = stu[i].midterm * 50 / 100 + stu[i].quiz1 * 7 / 100 + stu[i].quiz2 * 7 / 100 +
			stu[i].homework1 * 10 / 100 + stu[i].homework2 * 10 / 100 + stu[i].project * 16 / 100;
	}
	//Belirlenen 100 ��renciye random atanan final notu ve hesaplanan y�li�i notuna g�re ba�ar� notu belirleyen d�ng�
	for (int i = 0; i < 100; i++) {
		stu[i].successGrade = stu[i].yearGrade * 55 / 100 + stu[i].final * 45 / 100;
	}
	//Belirlenen her bir ba�ar� notunu string'e �eviren d�ng�
	for (int i = 0; i < 100; i++) {
		stu[i].successLetter = to_string(stu[i].successGrade);
	}
	//String'e �evrilen her bir ba�ar� notunu yaz�lan harf notu fonksiyonuyla harf notu olarak atayan d�ng�
	for (int i = 0; i < 100; i++) {
		stu[i].letterGrade = letterGrade(stu[i].successLetter);
	}
	int num;
	//Her bir ��renciye 500-600 aras�nda okul numaras� belirleyen d�ng�
	for (int i = 0; i < 100; i++) {
		num = rand() % 101 + 500;
		stu[i].number = num;
	}
	int month;
	//Her bir ��renciye 12 ay �zerinden do�um ay� belirleyen d�ng�
	for (int i = 0; i < 100; i++) {
		month = rand() % 11 + 1;
		birth[i].month = month;
	}
	int day;
	//Her bir ��renciye 28 g�n �zerinden do�um g�n� belirleyen d�ng�
	for (int i = 0; i < 100; i++) {
		day = rand() % 27 + 1;
		birth[i].day = day;
	}
	int year;
	//Her bir ��renciye 1999-2003 aras�nda do�um y�l� belirleyen d�ng�
	for (int i = 0; i < 100; i++) {
		year = rand() % 4 + 1999;
		birth[i].year = year;

	}

	do {
		menu1();
		// Kullan�c�ya men�ye geri d�nmek isteyip istemedi�ini soruyorum.
		// �stenen �ekilde cevap vermezse soruyu tekrarl�yorum.
		do {
			cout << "Would You Like to Go Back to the Menu? (Yes => 1/ No => 0) " << endl;
			cin >> answer;
			system("CLS");
		} while (answer != 0 && answer != 1);
		// Kullan�c� men�ye d�nmek isterse d�ng�y� tekrar ba�lat�yorum.
		// �stemezse program� sonland�r�yorum.
	} while (answer == 1);

	system("CLS");
}

void menu1() {
	int menu;
	int min = 1;
	int max = 8;
	//Verilen cevap sunulan se�eneklerden biri de�ilse men� ekran� tekrar a��l�yor.
	do {
		cout << "Please choose which action you want to do: " << endl << endl;
		cout << "Class List => 1" << endl;
		cout << "Highest Grade => 2" << endl;
		cout << "Lowest Grade => 3" << endl;
		cout << "Average => 4" << endl;
		cout << "Standard Deviation => 5" << endl;
		cout << "Students Whose Success Grade Between max and min => 6" << endl;
		cout << "Students Whose Success Grade Below the Grade You Will Set => 7" << endl;
		cout << "Students Whose Success Grade Above the Grade You Will Set => 8" << endl;
		cin >> menu;
		system("CLS");
	} while (menu < min && menu > max);

	// ��kt� k�sm�ndaki sorulardan se�ilen soruya g�re cevap verecek olan b�l�m� �al��t�rmak i�in switch-case kulland�m.
	switch (menu) {
	case 1:
		classList1();
		break;
	case 2:
		highestGrade();
		break;
	case 3:
		lowestGrade();
		break;
	case 4:
		average();
		break;
	case 5:
		standardDeviation();
		break;
	case 6:
		maxBetweenMin();
		break;
	case 7:
		below();
		break;
	case 8:
		above();
		break;
	}
}

int cycleCounter = 0;
void option2() {
	int answer1;
	int answer2;
	int index = 0;

	do {
		cout << "Please enter your name: " << endl;
		cin >> stu[index].name;
		cout << "Please enter your surname: " << endl;
		cin >> stu[index].surname;

		cout << "Your first quiz note: " << control1("Please enter your first quiz note: ", 0.0, 100.0, index) << endl;
		cout << "Your second quiz note:  " << control2("Please enter your second quiz note:  ", 0.0, 100.0, index) << endl;
		cout << "Your first homework note: " << control3("Please enter your first homework note: ", 0.0, 100.0, index) << endl;
		cout << "Your second homework note: " << control4("Please enter your second homework note: ", 0.0, 100.0, i) << endl;
		cout << "Your project note: " << control5("Please enter your project note: ", 0.0, 100.0, index) << endl;
		cout << "Your midterm note: " << control6("Please enter your midterm note: ", 0.0, 100.0, index) << endl;
		cout << "Your final note: " << control7("Please enter your final note: ", 0.0, 100.0, index) << endl;

		stu[index].yearGrade = stu[index].midterm * 50 / 100 + stu[index].quiz1 * 7 / 100 + stu[index].quiz2 * 7 / 100 +
			stu[index].homework1 * 10 / 100 + stu[index].homework2 * 10 / 100 + stu[index].project * 16 / 100;

		stu[index].successGrade = stu[index].yearGrade * 55 / 100 + stu[index].final * 45 / 100;

		system("CLS");
		cycleCounter++;
		// Kullan�c�n�n listeye ba�ka bir ��renci eklemek isteyip istemedi�ini soruyorum.
		// Sunulan se�enek d���nda bir cevap al�n�rsa soruyu tekrarl�yorum.
		do {
			cout << "Do you wamt to add another student to the list? (Yes => 1/No => 0)" << endl;
			cin >> answer1;
		} while (answer1 != 1 && answer1 != 0);
		index++;
		cout << stu;
		system("CLS");
		// E�er ba�ka bir ��renci daha eklemek istiyorsa sorular� tekrarl�yorum.
	} while (answer1 == 1);
	// Belirlenen her bir ba�ar� notunu string'e �eviren d�ng�
	for (int i = 0; i < index; i++) {
		stu[i].successLetter = to_string(stu[i].successGrade);
	}
	//String'e �evrilen her bir ba�ar� notunu yaz�lan harf notu fonksiyonuyla harf notu olarak atayan d�ng�
	for (int i = 0; i < index; i++) {
		stu[i].letterGrade = letterGrade(stu[i].successLetter);
	}

	do {
		menu2();
		// Kullan�c�ya men�ye geri d�nmek isteyip istemedi�ini soruyorum.
		// Sunulan se�enekler d���nda cevap al�n�rsa soruyu tekrarl�yorum.
		do {
			cout << "Would You Like to Go Back to the Menu? (Yes => 1/ No => 0) " << endl;
			cin >> answer2;
			system("CLS");
		} while (answer2 != 0 && answer2 != 1);
		// Kullan�c� men�ye geri d�nmek isterse tekrar men� ekran�n� a��yorum.
	} while (answer2 == 1);

	system("CLS");

}

void classList1() {
	int ESAY = 20;
	int cycleCounter1 = 0;
	int cycleCounter2 = 0;
	int cycleCounter3 = 0;

	do {
		cout << setw(8) << left << "Name" << setw(13) << "Surname" << setw(12) << "Number" << setw(14) << "Birthday" << setw(16) << "First Quiz" << setw(17) << "Second Quiz" << setw(20)
			<< "First Homework" << setw(21) << "Second Homework" << setw(13) << "Project" << setw(13) << "Midterm" << setw(11)
			<< "Final" << setw(16) << "Year Grade" << setw(19) << "Success Grade" << setw(18) << "Letter Grade" << endl << endl;
		cout << "******************************************************************************************************************************************************************************************************************" << endl << endl;

		do {
			srand(time(NULL));
			// Random olarak atanan isimleri herhangi bir tu�a bas�ld���nda ekrana 20 isim atanmas� i�in girilen d�ng�.
			for (int i = cycleCounter2; i < ESAY; i++) {
				stu[i].name;
				// Random olarak atanan soyisimleri herhangi bir tu�a bas�ld���nda ekrana 20 soyisim atanmas� i�in girilen d�ng�.
				for (int j = cycleCounter2; j < ESAY; j++) {
					stu[j].surname;
				}

			}
			// Random olarak atanan her bir not de�i�keninin herhangi bir tu�a bas�ld���nda ekrana 20 not de�i�kenini atanmas� i�in girilen d�ng�.
			for (int i = cycleCounter2; i < ESAY; i++) {
				stu[i].quiz1;
				stu[i].quiz2;
				stu[i].homework1;
				stu[i].homework2;
				stu[i].project;
				stu[i].midterm;
				stu[i].final;
				stu[i].yearGrade;
				stu[i].successGrade;
				stu[i].letterGrade;
			}
			// Atanan de�erlerin sonucunda herhangi bir tu�a bas�ld���nda ekrana t�m belirlenen de�erleri yazd�ran d�ng�.
			for (int i = cycleCounter2; i < ESAY; i++) {
				letterGrade(stu[i].successLetter);
				cout << setw(8) << left << stu[i].name << setw(13) << stu[i].surname << setw(12) << stu[i].number << setw(2) << birth[i].day << "/" << setw(2) << birth[i].month << "/"
					<< setw(8) << birth[i].year << setw(16) << stu[i].quiz1 << setw(17) << stu[i].quiz2 << setw(20) << stu[i].homework1 << setw(21)
					<< stu[i].homework2 << setw(13) << stu[i].project << setw(13) << stu[i].midterm << setw(11) << stu[i].final << setw(16) << stu[i].yearGrade
					<< setw(19) << stu[i].successGrade << setw(18) << stu[i].letterGrade << endl;
			}

			cycleCounter2 += 20;
			cycleCounter3++;
			// Her d�ng� sonunda cycleCounter2 +20 de�er al�r, cycleCounter3 +1 de�er al�r.
			// Buradaki d�ng� cycleCounter2 ve cycleCounter3'e de�er eklenmesi konusunda �nemlidir.
			// ��nk� her seferinde ekrana 20 isim yaz�lmal�d�r ve yukar�da belirlenen i de�i�keni cycleCounter2 say�s�ndan ba�lar
			// ve her d�ng� bitip a�a��daki d�ng�ye ge�ildi�inde ESAY olarak belirlenen de�ere kadar yazd�r�r.
		} while (cycleCounter3 < 1);

		system("pause");
		system("CLS");

		cycleCounter1++;
		cycleCounter3 = 0;
		ESAY += 20;
		// Yukar�daki d�ng�de ekrana 20 isim yaz�lmaktad�r ancak belirlenen 100 ��rencinin de ekrana yaz�lmas� i�in bu d�ng� 5 kez tekrar etmelidir.
		// cyceCounter1 say�s� burada d�ng�n�n 5 kez tekrar etmesi i�in her d�ng�den sonra +1 de�er al�r.
		// ESAY say�s� burada ekrana herhangi bir tu�a bas�ld�ktan sonra 20 ki�inin yaz�lmas� i�in bir s�n�rd�r.
		// Bu y�zden her d�ng� sonunda +20 de�er alarak yukar�daki d�ng�y� 20 ki�inin yaz�lmas� i�in s�n�rlar.
	} while (cycleCounter1 < 5);

}

void classList2() {

	cout << setw(8) << left << "Name" << setw(13) << "Surname" << setw(16) << "First Quiz" << setw(17) << "Second Quiz" << setw(20)
		<< "First Homework" << setw(21) << "Second Homework" << setw(13) << "Project" << setw(13) << "Midterm" << setw(11)
		<< "Final" << setw(16) << "Year Grade" << setw(19) << "Success Grade" << setw(18) << "Letter Grade" << endl << endl;
	cout << "******************************************************************************************************************************************************************************************" << endl << endl;
	// option2 fonksiyonunda belirlenen cycleCounter her d�ng� sonunda +1 de�er alarak d�ng�n�n ka� kez tekrar etti�ini
	// ve ka� ki�inin listeye eklendi�ini anlayarak bir s�n�r belirlememiz i�in bize yard�mc� olur.
	// Manuel olarak girilen ��renci bilgilerinin ekrana yaz�lmas� i�in belirlenen d�ng�.
	for (int i = 0; i < cycleCounter; i++) {

		cout << setw(8) << left << stu[i].name << setw(13) << stu[i].surname << setw(16) << stu[i].quiz1 << setw(17) << stu[i].quiz2 << setw(20)
			<< stu[i].homework1 << setw(21) << stu[i].homework2 << setw(13) << stu[i].project << setw(13) << stu[i].midterm
			<< setw(11) << stu[i].final << setw(16) << stu[i].yearGrade << setw(19) << stu[i].successGrade << setw(18) << stu[i].letterGrade << endl;
		cout << endl << endl << endl;
	}

}

float highestGrade() {
	float max = stu[0].successGrade;
	// Belirlenen ba�ar� notu de�erlerinden en y�ksek notun belirlenmesi i�in girilen d�ng�.
	for (int i = 0; i < 100; i++) {
		if (stu[i].successGrade > max) {
			max = stu[i].successGrade;
		}
	}
	cout << "Highest Grade: " << max << endl;
	system("pause");
	system("CLS");
	return max;
}

float lowestGrade() {
	float min = stu[0].successGrade;
	// Belirlenen ba�ar� notu de�erlerinden en d���k notun belirlenmesi i�in girilen d�ng�.
	for (int i = 0; i < 100; i++) {
		if (stu[i].successGrade < min) {
			min = stu[i].successGrade;
		}
	}
	cout << "Lowest Grade: " << min << endl;
	system("pause");
	system("CLS");

	return min;

}

float average() {
	float ave = 0;
	// Belirlenen t�m ba�ar� notlar�n� toplay�p ave de�i�kenine atayan d�ng�.
	for (int i = 0; i < 100; i++) {
		ave += stu[i].successGrade;
	}
	cout << "Average: " << ave / 100 << endl;
	system("pause");
	system("CLS");
	return (float)ave / 100;
}

float standardDeviation() {
	float sum = 0.0, mean, st = 0.0, std = 0.0, standard = 0.0;
	// Belirlenen t�m ba�ar� notlar�n� toplay�p sum de�i�kenine atayan d�ng�. 
	for (int i = 0; i < 100; i++) {
		sum += stu[i].successGrade;
	}
	mean = sum / 100;
	// Her bir ba�ar� notunu mean( s�n�f ortalamas� ) de�erinden ��kar�p karelerini alarak toplay�p standard de�i�kenine atayan d�ng�.
	for (int i = 0; i < 100; i++) {

		st += pow(stu[i].successGrade - mean, 2);
	}
	std = st / 99;
	standard = sqrt(std);
	cout << "Standard Deviation: " << standard  << endl;
	system("pause");
	system("CLS");

	return standard;
}

float maxBetweenMin() {
	float max = 0;
	float min = 0;
	cout << "Please set a minumum grade: " << endl;
	cin >> min;
	cout << "Please set a maximum grade: " << endl;
	cin >> max;
	system("CLS");

	cout << setw(8) << left << "Name" << setw(13) << "Surname" << setw(19) << "Success Grade" << endl << endl;
	// Manuel olarak belirlenen max ve min de�er aral���ndaki ��rencileri ve notlar�n� yazd�ran d�ng�.
	for (i = 0; i < 100; i++) {
		if (min < stu[i].successGrade && stu[i].successGrade < max)
			cout << setw(8) << left << stu[i].name << setw(13) << stu[i].surname << setw(19) << stu[i].successGrade << endl;
		else
			continue;
	}
	system("pause");
	system("CLS");

	return 0;
}

float below() {
	float below = 0;
	cout << "Please set a grade: " << endl;
	cin >> below;

	cout << setw(8) << left << "Name" << setw(13) << "Surname" << setw(19) << "Success Grade" << endl << endl;
	// Manuel olarak belirlenen notun alt�nda de�er alan ��rencileri ve notlar�n� yazd�ran d�ng�.
	for (i = 0; i < 100; i++) {
		if (stu[i].successGrade < below) {
			cout << setw(8) << left << stu[i].name << setw(13) << stu[i].surname << setw(19) << stu[i].successGrade << endl;
		}
		else
			continue;
	}
	system("pause");
	system("CLS");

	return 0;
}

float above() {
	float above = 0;
	cout << "Please set a grade: " << endl;
	cin >> above;

	cout << setw(8) << left << "Name" << setw(13) << "Surname" << setw(19) << "Success Grade" << endl << endl;
	// Manuel olarak belirlenen notun �st�nde de�er alan ��rencileri ve notlar�n� yazd�ran d�ng�.
	for (i = 0; i < 100; i++) {
		if (stu[i].successGrade > above) {
			cout << setw(8) << left << stu[i].name << setw(13) << stu[i].surname << setw(19) << stu[i].successGrade << endl;
		}
		else
			continue;
	}
	system("pause");
	system("CLS");

	return 0;
}

float average2() {
	float ave = 0;
	// Belirlenen t�m ba�ar� notlar�n� toplay�p ave de�i�kenine atayan d�ng�.
	// Bu fonksiyon 2. se�enek i�in yaz�lm��t�r.
	for (int i = 0; i < cycleCounter; i++) {
		ave += stu[i].successGrade;
	}
	cout << "Average: " << ave / cycleCounter << endl;
	system("pause");
	system("CLS");
	return (float)ave / cycleCounter;
}

float standardDeviation2() {
	float sum = 0.0, mean, standard = 0.0, st = 0.0, std = 0.0;
	// Belirlenen t�m ba�ar� notlar�n� toplay�p sum de�i�kenine atayan d�ng�. 
	// Bu fonksiyon 2. se�enek i�in yaz�lm��t�r.
	for (int i = 0; i < cycleCounter; i++) {
		sum += stu[i].successGrade;
	}
	mean = sum / cycleCounter;
	// Her bir ba�ar� notunu mean( s�n�f ortalamas� ) de�erinden ��kar�p karelerini alarak toplay�p standard de�i�kenine atayan d�ng�.
	for (int i = 0; i < cycleCounter; i++) {
		st += pow(stu[i].successGrade - mean, 2);
	}
	std = st / cycleCounter - 1;
	standard = sqrt(std);
	cout << "Standard Deviation: " << standard << endl;
	system("pause");
	system("CLS");

	return standard;
}

float maxBetweenMin2() {
	float max = 0;
	float min = 0;
	cout << "Please set a minumum grade: " << endl;
	cin >> min;
	cout << "Please set a maximum grade: " << endl;
	cin >> max;
	system("CLS");

	cout << setw(8) << left << "Name" << setw(13) << "Surname" << setw(19) << "Success Grade" << endl << endl;
	// Manuel olarak belirlenen max ve min de�er aral���ndaki ��rencileri ve notlar�n� yazd�ran d�ng�.
	// Bu fonksiyon 2. se�enek i�in yaz�lm��t�r.
	for (i = 0; i < cycleCounter; i++) {
		// 
		if (min < stu[i].successGrade && stu[i].successGrade < max)
			cout << setw(8) << left << stu[i].name << setw(13) << stu[i].surname << setw(19) << stu[i].successGrade << endl;
		else
			continue;
	}
	system("pause");
	system("CLS");

	return 0;
}

float below2() {
	float below = 0;
	cout << "Please set a grade: " << endl;
	cin >> below;

	cout << setw(8) << left << "Name" << setw(13) << "Surname" << setw(19) << "Success Grade" << endl << endl;
	// Manuel olarak belirlenen notun alt�nda de�er alan ��rencileri ve notlar�n� yazd�ran d�ng�.
	// Bu fonksiyon 2. se�enek i�in yaz�lm��t�r.
	for (i = 0; i < cycleCounter; i++) {
		if (stu[i].successGrade < below) {
			cout << setw(8) << left << stu[i].name << setw(13) << stu[i].surname << setw(19) << stu[i].successGrade << endl;
		}
		else
			continue;
	}
	system("pause");
	system("CLS");

	return 0;
}

float above2() {
	float above = 0;
	cout << "Please set a grade: " << endl;
	cin >> above;

	cout << setw(8) << left << "Name" << setw(13) << "Surname" << setw(19) << "Success Grade" << endl << endl;
	// Manuel olarak belirlenen notun �st�nde de�er alan ��rencileri ve notlar�n� yazd�ran d�ng�.
	// Bu fonksiyon 2. se�enek i�in yaz�lm��t�r.
	for (i = 0; i < cycleCounter; i++) {
		if (stu[i].successGrade > above) {
			cout << setw(8) << left << stu[i].name << setw(13) << stu[i].surname << setw(19) << stu[i].successGrade << endl;
		}
		else
			continue;
	}
	system("pause");
	system("CLS");

	return 0;
}


void menu2() {
	int menu;
	int min = 1;
	int max = 8;
	// Kullan�c� istenen de�erlerden biriyle cevap vermezse men� ekran�n� tekrar a��yorum.
	do {
		cout << "Please choose which action you want to do: " << endl << endl;
		cout << "Class List => 1" << endl;
		cout << "Highest Grade => 2" << endl;
		cout << "Lowest Grade => 3" << endl;
		cout << "Average => 4" << endl;
		cout << "Standard Deviation => 5" << endl;
		cout << "Students Whose Success Grade Between max and min => 6" << endl;
		cout << "Students Whose Success Grade Below the Grade You Will Set => 7" << endl;
		cout << "Students Whose Success Grade Above the Grade You Will Set => 8" << endl;
		cin >> menu;
		system("CLS");
	} while (menu < min && menu > max);
	// Kullan�c�n�n se�ti�i b�l�me g�re oradaki fonksiyonlar� �al��t�rmas� i�in switch-case kulland�m
	switch (menu) {
	case 1:
		classList2();
		break;
	case 2:
		highestGrade();
		break;
	case 3:
		lowestGrade();
		break;
	case 4:
		average2();
		break;
	case 5:
		standardDeviation2();
		break;
	case 6:
		maxBetweenMin2();
		break;
	case 7:
		below2();
		break;
	case 8:
		above2();
		break;
	}

}


