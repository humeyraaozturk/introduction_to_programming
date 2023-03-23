/***************************************************************************************************************************************************************************************************************************************************************************
**																		SAKARYA �N�VERS�TES�
**																B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**																	B�LG�SAYAR M�HEND�SL��� B�L�M�
**																		PROGRAMLAMAYA G�R�� DERS�
**
**																�DEV NUMARASI: PROJE
**																��RENC� ADI: H�MEYRA �ZT�RK
**																��RENC� NUMARASI: 
**																DERS GRUBU: C
**
***************************************************************************************************************************************************************************************************************************************************************************/


#include <iostream>
#include <iomanip>
#include <fstream> // Dosyalama yapabilmek i�in <fstream> k�t�phanesi eklendi.
#include <locale.h> // Diller k�t�phanesi
#include <string>
#include <cmath> // Matematiksel i�lemler i�in cmath k�t�phanesi eklendi

using namespace std;

int secim, ekleme, cevap, istek, adet, liste, siparis;
int cycleCounter = 0;
float toplam_kar;

float satisMiktar[100];
string sipari�Liste[39];
float tekYemekKar�[100];
float eldeKalanYemek[100];

// Kullan�c�dan al�nan g�nl�k pi�irilecek yemek bilgileri de�erleri a�a��daki de�i�kenlerin i�inde atan�yor.
float hamburger, kofte, patatesKizartmasi, musakka, karniyarik, karnibahar, iskender, patso, kasarliTost, koriSosluTavuk, cheesecake, magnolya, profiterol, browni, sufle, ayran, limonata, cay, kahve, su;
float pisenYemek[100] = { hamburger, kofte, patatesKizartmasi, musakka, karniyarik, karnibahar, iskender, patso, kasarliTost, koriSosluTavuk, cheesecake, magnolya, profiterol, browni, sufle, ayran, limonata, cay, kahve, su };

// Kullan�c�dan al�nan g�nl�k pi�irilecek yemek bilgileri de�erleri ve 1 ki�ilik yeme�in maliyet fiyat� �arp�larak a�a��daki de�i�kenlerin i�ine atan�yor.
float hamburger_maliyet, kofte_maliyet, patates_maliyet, musakka_maliyet, karniyarik_maliyet, karnibahar_maliyet, iskender_maliyet, patso_maliyet, kasarliTost_maliyet, tavuk_maliyet,
cheesecake_maliyet, magnolya_maliyet, profiterol_maliyet, browni_maliyet, sufle_maliyet, ayran_maliyet, limonata_maliyet, cay_maliyet, kahve_maliyet, su_maliyet, toplam_maliyet;
float maliyet[100] = { hamburger_maliyet, kofte_maliyet, patates_maliyet, musakka_maliyet, karniyarik_maliyet, karnibahar_maliyet, iskender_maliyet, patso_maliyet, kasarliTost_maliyet, tavuk_maliyet,
		cheesecake_maliyet, magnolya_maliyet, profiterol_maliyet, browni_maliyet, sufle_maliyet, ayran_maliyet, limonata_maliyet, cay_maliyet, kahve_maliyet, su_maliyet };

// Kullan�lan malzemelerin depoda g�r�nt�lenen stok miktarlar�
float stokMiktar�[39] = { 50, 50, 100, 50, 10, 100, 50, 50, 50, 100, 50, 50, 20, 20, 100, 100, 20, 50, 100, 10, 50, 50, 20, 200, 50, 50, 10, 10, 20, 20, 20, 20, 10, 10, 10, 50, 50, 100, 100 };

class Urun {
public:

	int yemekNo[100] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

	string yemekAdi[100] = { "Hamburger", "K�fte", "Patates K�zartmas�", "Musakka", "Karn�yar�k",  "Karn�bahar",
			"�skender", "Patso", "Ka�arl� Tost", "K�ri Soslu Tavuk", "Cheesecake", "Magnolya", "Profiterol",
			"Browni", "Sufle", "Ayran", "Kola", "�ay", "Kahve", "Su" };

	float kaloriGram[100] = { 295, 197, 310, 173, 97, 100, 755, 300, 212, 110, 320, 375, 335, 465, 170, 80, 40, 1, 0.5, 0 };

	float fiyat[100] = { 50, 45, 25, 15, 15, 10, 70, 20, 20, 80, 20, 30, 25, 25, 25, 10, 15, 3, 15, 2 };

};

class Malzeme {
public:

	string malzeme[100][10];


	string malzemeAdi[39] = { "Ekmek", "Marul", "Domates", "Tur�u", "Cheddar Peyniri", "Patates", "Ya�", "Tuz" , "Patl�can", "K�yma", "Biber", "So�an", "Karn�bahar", "Havu�",
						"Et", "Yo�urt", "Sosis", "Ka�ar", "Tavuk", "K�ri", "Mantar", "Labne", "Krema", "Yumurta", "�eker", "Un", "Vanilya", "Ni�asta", "Limon", "Bisk�vi", "�ilek",
						"�ikolata", "Kabartma Tozu", "Kakao", "Portakal", "�ay", "Kahve", "S�t", "Su" };

	int birimFiyat[39] = { 5, 10, 15, 40, 200, 20, 100, 30, 20, 180, 15, 15, 10, 10, 200, 25, 40, 80, 60, 150, 20, 30, 40, 2, 30, 30, 40, 40, 20, 10, 25, 50, 25, 40, 30, 60, 50, 20, 5 };



};


void gunluk_yemek();
void gunluk_maliyet();
void menu();
void yemekEkle();
void yemekSil();
void yemekGuncelle();
void yemekKontrol();
void yemekListele();
void random();
void toplamKar();
void eldeKalan();
void rapor();
void eksilecekMalzeme();
void hamburgerYap(int);
void kofteYap(int);
void patatesYap(int);
void musakkaYap(int);
void karniyarikYap(int);
void karnibaharYap(int);
void iskenderYap(int);
void patsoYap(int);
void kasarliTostYap(int);
void koriSosluTavukYap(int);
void cheesecakeYap(int);
void magnolyaYap(int);
void profiterolYap(int);
void browniYap(int);
void sufleYap(int);
void ayranYap(int);
void limonataYap(int);
void cayYap(int);
void kahveYap(int);
void suYap(int);
void sipari�Listesi();

int main() {

	setlocale(LC_ALL, "Turkish");

	Urun u;
	Malzeme m;

	gunluk_yemek();		//gunluk_yemek fonksiyonu �a��r�larak kullan�cadan g�nl�k hangi yemekten ka� ki�ilik pi�irilece�i ��renilir.
	gunluk_maliyet();	//gunluk_maliyet fonksiyonu �a��r�larak 1 �e�it yeme�in 1 g�nl�k maliyet hesab� yap�l�r.
	random();			//1 g�n i�inde sat�lan yemeklerin say�s� random fonksiyonu ile rastgele belirlenir.
	toplamKar();		//rastgele belirlenen sat�lan yemek say�lar� ile sat�� fiyatlar� �arp�l�r ve maliyetten ��kar�l�r. Bu sayede g�nl�k o yemekten elde edilen kar hesaplan�r.
	eldeKalan();		//pi�irilen yemek say�s�ndan sat�lan yemek say�s� ��kar�larak elde kalan yemek say�s� bulunur.

	// ofstream ile dosYaz tan�mlan�r. yemekcesit.txt dosyas� a��l�r ve s�ral� sat�rlar dosyan�n i�ine yaz�l�r.
	ofstream dosyaYaz;
	dosyaYaz.open("yemekcesit.txt", ios::out);
	dosyaYaz << "----------------------------------------------------------------------------	MEN�	-------------------------------------------------------------" << endl;
	dosyaYaz << left << setw(21) << "Yemek No" << setw(21) << "�r�n Ad�" << setw(29) << "Kalori De�eri" << setw(25) << "Sat�� Fiyat" << setw(10) << "Maliyet" << endl;
	dosyaYaz << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
	dosyaYaz << left << setw(21) << u.yemekNo[0] << setw(21) << u.yemekAdi[0] << u.kaloriGram[0] << setw(26) << " kcal" << u.fiyat[0] << setw(23) << " TL" << maliyet[0] << " TL" << endl
		<< setw(21) << u.yemekNo[1] << setw(21) << u.yemekAdi[1] << u.kaloriGram[1] << setw(26) << " kcal" << u.fiyat[1] << setw(23) << " TL" << maliyet[1] << " TL" << endl
		<< setw(21) << u.yemekNo[2] << setw(21) << u.yemekAdi[2] << u.kaloriGram[2] << setw(26) << " kcal" << u.fiyat[2] << setw(23) << " TL" << maliyet[2] << " TL" << endl
		<< setw(21) << u.yemekNo[3] << setw(21) << u.yemekAdi[3] << u.kaloriGram[3] << setw(26) << " kcal" << u.fiyat[3] << setw(23) << " TL" << maliyet[3] << " TL" << endl
		<< setw(22) << u.yemekNo[4] << setw(21) << u.yemekAdi[4] << u.kaloriGram[4] << setw(26) << " kcal" << u.fiyat[4] << setw(23) << " TL" << maliyet[4] << " TL" << endl
		<< setw(21) << u.yemekNo[5] << setw(21) << u.yemekAdi[5] << u.kaloriGram[5] << setw(26) << " kcal" << u.fiyat[5] << setw(23) << " TL" << maliyet[5] << " TL" << endl
		<< setw(21) << u.yemekNo[6] << setw(21) << u.yemekAdi[6] << u.kaloriGram[6] << setw(26) << " kcal" << u.fiyat[6] << setw(23) << " TL" << maliyet[6] << " TL" << endl
		<< setw(21) << u.yemekNo[7] << setw(21) << u.yemekAdi[7] << u.kaloriGram[7] << setw(26) << " kcal" << u.fiyat[7] << setw(23) << " TL" << maliyet[7] << " TL" << endl
		<< setw(21) << u.yemekNo[8] << setw(21) << u.yemekAdi[8] << u.kaloriGram[8] << setw(26) << " kcal" << u.fiyat[8] << setw(23) << " TL" << maliyet[8] << " TL" << endl
		<< setw(21) << u.yemekNo[9] << setw(21) << u.yemekAdi[9] << u.kaloriGram[9] << setw(26) << " kcal" << u.fiyat[9] << setw(23) << " TL" << maliyet[9] << " TL" << endl
		<< setw(21) << u.yemekNo[10] << setw(21) << u.yemekAdi[10] << u.kaloriGram[10] << setw(26) << " kcal" << u.fiyat[10] << setw(23) << " TL" << maliyet[10] << " TL" << endl
		<< setw(21) << u.yemekNo[11] << setw(21) << u.yemekAdi[11] << u.kaloriGram[11] << setw(26) << " kcal" << u.fiyat[11] << setw(23) << " TL" << maliyet[11] << " TL" << endl
		<< setw(21) << u.yemekNo[12] << setw(21) << u.yemekAdi[12] << u.kaloriGram[12] << setw(26) << " kcal" << u.fiyat[12] << setw(23) << " TL" << maliyet[12] << " TL" << endl
		<< setw(21) << u.yemekNo[13] << setw(21) << u.yemekAdi[13] << u.kaloriGram[13] << setw(26) << " kcal" << u.fiyat[13] << setw(23) << " TL" << maliyet[13] << " TL" << endl
		<< setw(21) << u.yemekNo[14] << setw(21) << u.yemekAdi[14] << u.kaloriGram[14] << setw(26) << " kcal" << u.fiyat[14] << setw(23) << " TL" << maliyet[14] << " TL" << endl
		<< setw(22) << u.yemekNo[15] << setw(21) << u.yemekAdi[15] << u.kaloriGram[15] << setw(26) << " kcal" << u.fiyat[15] << setw(23) << " TL" << maliyet[15] << " TL" << endl
		<< setw(22) << u.yemekNo[16] << setw(21) << u.yemekAdi[16] << u.kaloriGram[16] << setw(26) << " kcal" << u.fiyat[16] << setw(23) << " TL" << maliyet[16] << " TL" << endl
		<< setw(23) << u.yemekNo[17] << setw(21) << u.yemekAdi[17] << u.kaloriGram[17] << setw(27) << " kcal" << u.fiyat[17] << setw(23) << " TL" << maliyet[17] << " TL" << endl
		<< setw(21) << u.yemekNo[18] << setw(21) << u.yemekAdi[18] << u.kaloriGram[18] << setw(26) << " kcal" << u.fiyat[18] << setw(23) << " TL" << maliyet[18] << " TL" << endl
		<< setw(23) << u.yemekNo[19] << setw(21) << u.yemekAdi[19] << u.kaloriGram[19] << setw(27) << " kcal" << u.fiyat[19] << setw(23) << " TL" << maliyet[19] << " TL" << endl;
	dosyaYaz.close();	//yemekcesit.txt dosyas�na yazma i�lemimiz bitti�inde dosya kapat�l�r.

	//malzeme.txt dosyas� a��l�r ve s�ral� sat�rlar dosyan�n i�ine yaz�l�r.
	dosyaYaz.open("malzeme.txt", ios::out);
	dosyaYaz << "----------------------------------------------------------------------------	MALZEMELER	-------------------------------------------------------------------------------------------" << endl << endl;
	dosyaYaz << left << setw(25) << "�r�n Ad�  " << "Malzeme Listesi" << endl;
	dosyaYaz << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	dosyaYaz << left << setw(25) << u.yemekAdi[0] << "Ekmek, K�fte, Marul, Domates, Tur�u, Cheddar Peyniri" << endl;
	dosyaYaz << left << setw(25) << u.yemekAdi[1] << "K�fte" << endl;
	dosyaYaz << left << setw(25) << u.yemekAdi[2] << "Patates, Ya�, Tuz" << endl;
	dosyaYaz << left << setw(25) << u.yemekAdi[3] << "Patl�can, K�yma, Domates, Biber, So�an, Ya�" << endl;
	dosyaYaz << left << setw(25) << u.yemekAdi[4] << "Patl�can, K�yma, Domates, Patates, Biber, Tuz, Ya�" << endl;
	dosyaYaz << left << setw(25) << u.yemekAdi[5] << "Karn�bahar, Havu�, So�an, Ya�, Tuz" << endl;
	dosyaYaz << left << setw(25) << u.yemekAdi[6] << "Et, So�an, Domates, Biber, Yo�urt, Ya�" << endl;
	dosyaYaz << left << setw(25) << u.yemekAdi[7] << "Ekmek, Patates, Sosis, Ya�, Tuz" << endl;
	dosyaYaz << left << setw(25) << u.yemekAdi[8] << "Ekmek, Ka�ar" << endl;
	dosyaYaz << left << setw(25) << u.yemekAdi[9] << "Tavuk, K�ri, Biber, Mantar, Ya�, Tuz" << endl;
	dosyaYaz << left << setw(25) << u.yemekAdi[10] << "Labne, Krema, Yumurta, �eker, Vanilya, Un, Ni�asta, Limon, Bisk�vi, Ya�" << endl;
	dosyaYaz << left << setw(25) << u.yemekAdi[11] << "S�t, Krema, Un, Ni�asta, �eker, �ilek, Bisk�vi" << endl;
	dosyaYaz << left << setw(25) << u.yemekAdi[12] << "S�t, Un, Su, �eker, Yumurta, Vanilya, Ya�, �ikolata" << endl;
	dosyaYaz << left << setw(25) << u.yemekAdi[13] << "S�t, Yumurta, �eker, Ya�, Vanilya, Un, �ikolata" << endl;
	dosyaYaz << left << setw(25) << u.yemekAdi[14] << "Un, S�t, �eker, Vanilya, Kabartma Tozu, �ikolata, Kakao" << endl;
	dosyaYaz << left << setw(25) << u.yemekAdi[15] << "Yo�urt, Su, Tuz" << endl;
	dosyaYaz << left << setw(25) << u.yemekAdi[16] << "Limon, Portakal, �eker, Su" << endl;
	dosyaYaz << left << setw(25) << u.yemekAdi[17] << "�ay, Su" << endl;
	dosyaYaz << left << setw(25) << u.yemekAdi[18] << "Kahve, Su, �eker" << endl;
	dosyaYaz << left << setw(25) << u.yemekAdi[19] << "Su" << endl;
	dosyaYaz.close();	//malzeme.txt dosyas�na yazma i�lemimiz bitti�inde dosya kapat�l�r.

	//depo.txt dosyas� a��l�r ve s�ral� sat�rlar dosyan�n i�ine yaz�l�r.
	dosyaYaz.open("depo.txt", ios::out);
	dosyaYaz << "----------------------------------------------------------------------------	DEPO	------------------------------------------------------------------------------------------------------" << endl << endl;
	dosyaYaz << left << setw(28) << "Malzeme Ad�" << setw(30) << "�retim Tarihi" << setw(36) << "Son Kullanma Tarihi" << setw(41) << "Stok Miktar�(Adet-Kg-Lt)" << "Fiyat(Birim)" << endl;
	dosyaYaz << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[0] << setw(30) << "26/12/2022" << setw(36) << "27/12/2022" << stokMiktar�[0] << setw(39) << " Adet" << m.birimFiyat[0] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[1] << setw(30) << "26/12/2022" << setw(36) << "31/12/2022" << stokMiktar�[1] << setw(39) << " Adet" << m.birimFiyat[1] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[2] << setw(30) << "26/12/2022" << setw(36) << "31/12/2022" << stokMiktar�[2] << setw(38) << " Kg" << m.birimFiyat[2] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[3] << setw(30) << "26/12/2022" << setw(36) << "26/12/2023" << stokMiktar�[3] << setw(39) << " Kg" << m.birimFiyat[3] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[4] << setw(30) << "26/12/2022" << setw(36) << "31/12/2022" << stokMiktar�[4] << setw(39) << " Kg" << m.birimFiyat[4] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[5] << setw(30) << "26/12/2022" << setw(36) << "31/12/2022" << stokMiktar�[5] << setw(38) << " Kg" << m.birimFiyat[5] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[6] << setw(30) << "26/12/2022" << setw(36) << "26/12/2023" << stokMiktar�[6] << setw(39) << " Lt" << m.birimFiyat[6] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[7] << setw(30) << "26/12/2022" << setw(36) << "26/12/2024" << stokMiktar�[7] << setw(39) << " Kg" << m.birimFiyat[7] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[8] << setw(30) << "26/12/2022" << setw(36) << "31/12/2022" << stokMiktar�[8] << setw(39) << " Kg" << m.birimFiyat[8] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[9] << setw(30) << "26/12/2022" << setw(36) << "26/12/2023" << stokMiktar�[9] << setw(38) << " Kg" << m.birimFiyat[9] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[10] << setw(30) << "26/12/2022" << setw(36) << "31/12/2022" << stokMiktar�[10] << setw(39) << " Kg" << m.birimFiyat[10] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[11] << setw(30) << "26/12/2022" << setw(36) << "31/12/2022" << stokMiktar�[11] << setw(39) << " Kg" << m.birimFiyat[11] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[12] << setw(30) << "26/12/2022" << setw(36) << "31/12/2022" << stokMiktar�[12] << setw(39) << " Kg" << m.birimFiyat[12] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[13] << setw(30) << "26/12/2022" << setw(36) << "31/12/2022" << stokMiktar�[13] << setw(39) << " Kg" << m.birimFiyat[13] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[14] << setw(30) << "26/12/2022" << setw(36) << "26/12/2023" << stokMiktar�[14] << setw(38) << " Kg" << m.birimFiyat[14] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[15] << setw(30) << "26/12/2022" << setw(36) << "31/12/2022" << stokMiktar�[15] << setw(38) << " Kg" << m.birimFiyat[15] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[16] << setw(30) << "26/12/2022" << setw(36) << "31/12/2022" << stokMiktar�[16] << setw(39) << " Kg" << m.birimFiyat[16] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[17] << setw(30) << "26/12/2022" << setw(36) << "31/12/2022" << stokMiktar�[17] << setw(39) << " Kg" << m.birimFiyat[17] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[18] << setw(30) << "26/12/2022" << setw(36) << "31/12/2023" << stokMiktar�[18] << setw(38) << " Kg" << m.birimFiyat[18] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[19] << setw(30) << "26/12/2022" << setw(36) << "26/12/2027" << stokMiktar�[19] << setw(39) << " Kg" << m.birimFiyat[19] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[20] << setw(30) << "26/12/2022" << setw(36) << "31/12/2022" << stokMiktar�[20] << setw(39) << " Kg" << m.birimFiyat[20] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[21] << setw(30) << "26/12/2022" << setw(36) << "31/12/2022" << stokMiktar�[21] << setw(39) << " Kg" << m.birimFiyat[21] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[22] << setw(30) << "26/12/2022" << setw(36) << "31/12/2022" << stokMiktar�[22] << setw(39) << " Lt" << m.birimFiyat[22] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[23] << setw(30) << "26/12/2022" << setw(36) << "26/01/2023" << stokMiktar�[23] << setw(38) << " Adet" << m.birimFiyat[23] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[24] << setw(30) << "26/12/2022" << setw(36) << "26/12/2023" << stokMiktar�[24] << setw(39) << " Kg" << m.birimFiyat[24] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[25] << setw(30) << "26/12/2022" << setw(36) << "26/12/2024" << stokMiktar�[25] << setw(39) << " Kg" << m.birimFiyat[25] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[26] << setw(30) << "26/12/2022" << setw(36) << "26/12/2025" << stokMiktar�[26] << setw(39) << " Kg" << m.birimFiyat[26] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[27] << setw(30) << "26/12/2022" << setw(36) << "26/12/2025" << stokMiktar�[27] << setw(39) << " Kg" << m.birimFiyat[27] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[28] << setw(30) << "26/12/2022" << setw(36) << "26/01/2023" << stokMiktar�[28] << setw(39) << " Kg" << m.birimFiyat[28] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[29] << setw(30) << "26/12/2022" << setw(36) << "26/12/2023" << stokMiktar�[29] << setw(39) << " Paket" << m.birimFiyat[29] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[30] << setw(30) << "26/12/2022" << setw(36) << "31/12/2022" << stokMiktar�[30] << setw(39) << " Kg" << m.birimFiyat[30] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[31] << setw(30) << "26/12/2022" << setw(36) << "26/12/2023" << stokMiktar�[31] << setw(39) << " Kg" << m.birimFiyat[31] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[32] << setw(30) << "26/12/2022" << setw(36) << "26/12/2025" << stokMiktar�[32] << setw(39) << " Kg" << m.birimFiyat[32] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[33] << setw(30) << "26/12/2022" << setw(36) << "26/12/2025" << stokMiktar�[33] << setw(39) << " Kg" << m.birimFiyat[33] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[34] << setw(30) << "26/12/2022" << setw(36) << "26/01/2023" << stokMiktar�[34] << setw(39) << " Kg" << m.birimFiyat[34] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[35] << setw(30) << "26/12/2022" << setw(36) << "26/12/2025" << stokMiktar�[35] << setw(39) << " Kg" << m.birimFiyat[35] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[36] << setw(30) << "26/12/2022" << setw(36) << "26/12/2025" << stokMiktar�[36] << setw(39) << " Kg" << m.birimFiyat[36] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[37] << setw(30) << "26/12/2022" << setw(36) << "10/01/2023" << stokMiktar�[37] << setw(39) << " Lt" << m.birimFiyat[37] << " TL" << endl;
	dosyaYaz << left << setw(28) << m.malzemeAdi[38] << setw(30) << "26/12/2022" << setw(36) << "26/12/2023" << stokMiktar�[38] << setw(39) << " Lt" << m.birimFiyat[38] << " TL" << endl;
	dosyaYaz.close();	//depo.txt dosyas�na yazma i�lemimiz bitti�inde dosya kapat�l�r.


	gunluk_maliyet();
	random();
	toplamKar();
	eldeKalan();

	menu();

}


void gunluk_yemek() {
	// kullan�cadan g�nl�k hangi yemekten ka� ki�ilik pi�irilece�i bu fonksiyon �a��r�larak ��renilir.
	// al�nan de�ere g�re o yeme�in mazemelerini kontrol eden fonksiyon �a��r�larak depodaki malzemenin miktar� kontrol edilir.
	// e�er malzeme miktar� yeterli de�ilse eksik malzeme sipari� listesine yaz�l�r.
	// al�nan de�erler pisenYemek[] dizisinin i�ine atan�r.

	system("cls");

	Urun u;

	cout << "Bug�n Hangi Yemekten Ka� Ki�ilik Pi�irilece�ini Se�meniz Gerekiyor " << endl;
	cout << "Bir Yemekten Bir G�n ��inde En Az 20 Ki�ilik Pi�irilebilir" << endl << endl;
	cout << "Ka� Ki�ilik Hamburger Pi�irilecek?: ";
	cin >> hamburger;
	hamburgerYap(hamburger);
	pisenYemek[0] = hamburger;
	cout << "Ka� Ki�ilik K�fte Pi�irilecek?: ";
	cin >> kofte;
	kofteYap(kofte);
	pisenYemek[1] = kofte;
	cout << "Ka� Ki�ilik Patates K�zartmas� Pi�irilecek?: ";
	cin >> patatesKizartmasi;
	patatesYap(patatesKizartmasi);
	pisenYemek[2] = patatesKizartmasi;
	cout << "Ka� Ki�ilik Musakka Pi�irilecek?: ";
	cin >> musakka;
	musakkaYap(musakka);
	pisenYemek[3] = musakka;
	cout << "Ka� Ki�ilik Karn�yar�k Pi�irilecek?: ";
	cin >> karniyarik;
	karniyarikYap(karniyarik);
	pisenYemek[4] = karniyarik;
	cout << "Ka� Ki�ilik Karn�bahar Pi�irilecek?: ";
	cin >> karnibahar;
	karnibaharYap(karnibahar);
	pisenYemek[5] = karnibahar;
	cout << "Ka� Ki�ilik �skender Pi�irilecek?: ";
	cin >> iskender;
	iskenderYap(iskender);
	pisenYemek[6] = iskender;
	cout << "Ka� Ki�ilik Patso Pi�irilecek?: ";
	cin >> patso;
	patsoYap(patso);
	pisenYemek[7] = patso;
	cout << "Ka� Ki�ilik Ka�arl� Tost Pi�irilecek?: ";
	cin >> kasarliTost;
	kasarliTostYap(kasarliTost);
	pisenYemek[8] = kasarliTost;
	cout << "Ka� Ki�ilik K�ri Soslu Tavuk Pi�irilecek?: ";
	cin >> koriSosluTavuk;
	koriSosluTavukYap(koriSosluTavuk);
	pisenYemek[9] = koriSosluTavuk;
	cout << "Ka� Ki�ilik Cheesecake Pi�irilecek?: ";
	cin >> cheesecake;
	cheesecakeYap(cheesecake);
	pisenYemek[10] = cheesecake;
	cout << "Ka� Ki�ilik Magnolya Pi�irilecek?: ";
	cin >> magnolya;
	magnolyaYap(magnolya);
	pisenYemek[11] = magnolya;
	cout << "Ka� Ki�ilik Profiterol Pi�irilecek?: ";
	cin >> profiterol;
	profiterolYap(profiterol);
	pisenYemek[12] = profiterol;
	cout << "Ka� Ki�ilik Browni Pi�irilecek?: ";
	cin >> browni;
	browniYap(browni);
	pisenYemek[13] = browni;
	cout << "Ka� Ki�ilik Sufle Pi�irilecek?: ";
	cin >> sufle;
	sufleYap(sufle);
	pisenYemek[14] = sufle;
	cout << "Ka� Ki�ilik Ayran Yap�lacak?: ";
	cin >> ayran;
	ayranYap(ayran);
	pisenYemek[15] = ayran;
	cout << "Ka� Ki�ilik Limonata Yap�lacak?: ";
	cin >> limonata;
	limonataYap(limonata);
	pisenYemek[16] = limonata;
	cout << "Ka� Ki�ilik �ay Yap�lacak?: ";
	cin >> cay;
	cayYap(cay);
	pisenYemek[17] = cay;
	cout << "Ka� Ki�ilik Kahve Yap�lacak?: ";
	cin >> kahve;
	kahveYap(kahve);
	pisenYemek[18] = kahve;
	cout << "Ka� Ki�ilik Su Al�nacak?: ";
	cin >> su;
	suYap(su);
	pisenYemek[19] = su;

}

void gunluk_maliyet() {

	//gunluk_maliyet fonksiyonu �a��r�larak 1 �e�it yeme�in 1 g�nl�k maliyet hesab� yap�l�r.

	maliyet[0] = 15 * hamburger;
	maliyet[1] = 20 * kofte;
	maliyet[2] = 8 * patatesKizartmasi;
	maliyet[3] = 4 * musakka;
	maliyet[4] = 5 * karniyarik;
	maliyet[5] = 5 * karnibahar;
	maliyet[6] = 20 * iskender;
	maliyet[7] = 8 * patso;
	maliyet[8] = 8 * kasarliTost;
	maliyet[9] = 15 * koriSosluTavuk;
	maliyet[10] = 10 * cheesecake;
	maliyet[11] = 10 * magnolya;
	maliyet[12] = 10 * profiterol;
	maliyet[13] = 10 * browni;
	maliyet[14] = 10 * sufle;
	maliyet[15] = 3 * ayran;
	maliyet[16] = 5 * limonata;
	maliyet[17] = 1 * cay;
	maliyet[18] = 5 * kahve;
	maliyet[19] = 0.5 * su;

	// toplam maliyet hesab� yap�l�r.
	toplam_maliyet = hamburger_maliyet + kofte_maliyet + patates_maliyet + musakka_maliyet + karniyarik_maliyet + karnibahar_maliyet + iskender_maliyet +
		patso_maliyet + kasarliTost_maliyet + tavuk_maliyet + cheesecake_maliyet + magnolya_maliyet + profiterol_maliyet + browni_maliyet + sufle_maliyet +
		ayran_maliyet + limonata_maliyet + cay_maliyet + kahve_maliyet + su_maliyet;

}


void menu() {

	// Kullan�c�dan yapmak istedi�i i�lemi se�mesi istenir.
	// Cevaba g�re fonskiyon �al��t�r�lmas� i�in switch-case kullan�ld�.

	system("cls");
	do {
		system("cls");
		cout << "Yapmak �stedi�iniz ��lemi Se�iniz" << endl;
		cout << "Yemek Ekle => 1 " << endl;
		cout << "Yemek Sil => 2 " << endl;
		cout << "Yemek G�ncelle => 3 " << endl;
		cout << "Yemek Listele => 4 " << endl;
		cout << "Rapor Al => 5 " << endl;
		cout << "Sipari� Listesi => 6" << endl;
		cin >> secim;
	} while (secim < 1 && secim > 7);

	switch (secim) {
	case 1: {
		yemekEkle();
		break;
	}
	case 2: {
		yemekSil();
		break;
	}
	case 3: {
		yemekGuncelle();
		break;
	}
	case 4: {
		yemekListele();
		break;
	}
	case 5: {
		rapor();
		break;
	}
	case 6: {
		system("CLS");
		cout << left << "Al�nacak �r�n Ad�" << endl;
		sipari�Listesi();
		break;
	}
	}

}

void yemekEkle() {

	Urun u;
	Malzeme m;

	int i = 20;
	ofstream dosyaYaz;

	// Kullan�c�dan eklemek istedi�i yeme�in bilgilerini girmesi istenir

	do {

		system("cls");
		cout << "Yemek Ad�: "; cin >> u.yemekAdi[i];
		cout << endl;
		cout << "Yeme�in Kalorisi: "; cin >> u.kaloriGram[i];
		cout << endl;
		cout << "Yemegin Sat�� Fiyat�: "; cin >> u.fiyat[i];
		cout << endl;
		cout << "Yeme�in Maliyeti: "; cin >> maliyet[i];
		cout << endl;
		cout << "Ka� Adet Malzeme Gireceksiniz: "; cin >> adet;
		cout << endl;
		cout << "Belirledi�iniz Say� Kadar Malzeme Giriniz: " << endl;
		for (int a = 0; a < adet; a++) {
			cout << "Malzeme Ad�: ";	cin >> m.malzeme[i - 20][a];
		}

		dosyaYaz.open("yemekcesit.txt", ios::in | ios::out | ios::app);

		// Al�nan bilgilere g�re yemek dosyan�n sonuna eklenir.
		dosyaYaz << left << setw(21) << i + 1 << setw(21) << u.yemekAdi[i] << u.kaloriGram[i] << setw(26) << " kcal" << u.fiyat[i] << setw(23) << " TL" << maliyet[i] << " TL" << endl;
		dosyaYaz.close();

		dosyaYaz.open("malzeme.txt", ios::in | ios::out | ios::app);

		//Al�nan bilgilere g�re yeme�in malzemeleri dosyan�n sonuna eklenir.
		dosyaYaz << left << setw(25) << u.yemekAdi[i];
		for (int j = 0; j < adet; j++) {
			dosyaYaz << m.malzeme[i - 20][j] << ", ";
		}
		dosyaYaz << endl;
		dosyaYaz.close();

		system("cls");

		do {
			cout << "Yemek Eklemeye Devam Etmek ��in => 1 " << endl;
			cout << "�st Men�ye D�nmek ��in => 2 " << endl;
			cout << "��kmak ��in => 3 " << endl;
			cin >> ekleme;
		} while (ekleme != 1 && ekleme != 2 && ekleme != 3);

		cycleCounter++;
		i++;
		// Kullan�c� yemek eklemeye devam etmek isterse fonksiyonun tekrar �al��mas� i�in do-while kullan�ld�.
	} while (ekleme == 1);

	// men�ye d�nmek istenirse bu k�s�mda men� fonksiyonu �al��t�r�ld�.
	if (ekleme == 2)
		menu();

}

void yemekSil() {
	int silme;
	int counter = 0;
	string line;

	system("cls");
	cout << "------------------------ MEN� -------------------------" << endl;
	cout << "Hamburger => 1 " << endl << "K�fte => 2" << endl << "Patates K�zartmas� => 3" << endl << "Musakka => 4"
		<< endl << "Karn�yar�k => 5" << endl << "Karn�bahar => 6" << endl << "�skender => 7" << endl << "Patso => 8"
		<< endl << "Ka�arl� Tost => 9" << endl << "K�ri Soslu Tavuk => 10" << endl << "Cheesecake => 11"
		<< endl << "Magnolya => 12" << endl << "Profiterol => 13" << endl << "Browni => 14" << endl << "Sufle => 15"
		<< endl << "Ayran => 16" << endl << "Kola => 17" << endl << "�ay => 18" << endl << "Kahve => 19" << endl <<
		"Su => 20" << endl << endl;
	cout << "Silmek �stedi�iniz Yeme�in Numaras�n� Giriniz: ";
	cin >> silme;
	// Kullan�c�dan silmek istedi�i yeme�in numaras�n� girmesi istenir.
	// girilen numara+4 asl�nda yeme�in dosyada bulundu�u sat�r� beirtir

	ifstream dosyaOku;
	dosyaOku.open("yemekcesit.txt");
	ofstream dosyaYaz;
	dosyaYaz.open("gecici.tmp");

	// yemekcesit.txt dosyas�ndan kullan�c�n�n silmek istedi�i yeme�in sat�r� hari� di�er sat�rlar okunur
	// okunan sat�rlar gecici.tmp dosyan�n i�ine yazd�r�l�r.
	while (getline(dosyaOku, line)) {

		counter++;
		if (counter != silme + 4) {
			dosyaYaz << line << endl;
		}

	}

	dosyaOku.close();
	dosyaYaz.close();
	remove("yemekcesit.txt");
	rename("gecici.tmp", "yemekcesit.txt");		//gecici.tmp dosyas�n�n ad� de�i�tirilerek yeni yemekcesit.txt dosyas� olu�turulur.

	counter = 0;

	dosyaOku.open("malzeme.txt");
	dosyaYaz.open("gecici2.tmp");

	// malzeme.txt dosyas�ndan kullan�c�n�n silmek istedi�i yeme�in sat�r� hari� di�er sat�rlar okunur
	// okunan sat�rlar gecici2.tmp dosyan�n i�ine yazd�r�l�r.
	while (getline(dosyaOku, line)) {

		counter++;
		if (counter != silme + 4) {
			dosyaYaz << line << endl;
		}

	}

	dosyaOku.close();
	dosyaYaz.close();
	remove("malzeme.txt");
	rename("gecici2.tmp", "malzeme.txt");	//gecici2.tmp dosyas�n�n ad� de�i�tirilerek yeni yemekcesit.txt dosyas� olu�turulur.

	cout << endl;
	cout << "Yemek Ba�ar�yla Silindi" << endl << endl;

	do {
		system("pause");
		system("cls");
		cout << "Men�ye D�nmek ��in => 1" << endl;
		cout << "��kmak ��in => 2 " << endl;
		cin >> istek;
		// kullan�c� belirli say�lar d���nda bir say� girerse soru tekrarlan�r.
	} while (istek != 1 && istek != 2);
	// Kullan�c� men�ye d�nmek isterse menu fonskiyonu �al��t�r�l�r.
	if (istek == 1)
		menu();

}

void yemekGuncelle() {

	Urun u;

	int guncel;
	int counter = 0;
	string line;
	int guncelKalori = 0;
	int guncelFiyat = 0;
	int guncelMaliyet = 0;

	system("cls");
	cout << "------------------------ MEN� -------------------------" << endl;
	cout << "Hamburger => 1 " << endl << "K�fte => 2" << endl << "Patates K�zartmas� => 3" << endl << "Musakka => 4"
		<< endl << "Karn�yar�k => 5" << endl << "Karn�bahar => 6" << endl << "�skender => 7" << endl << "Patso => 8"
		<< endl << "Ka�arl� Tost => 9" << endl << "K�ri Soslu Tavuk => 10" << endl << "Cheesecake => 11"
		<< endl << "Magnolya => 12" << endl << "Profiterol => 13" << endl << "Browni => 14" << endl << "Sufle => 15"
		<< endl << "Ayran => 16" << endl << "Kola => 17" << endl << "�ay => 18" << endl << "Kahve => 19" << endl <<
		"Su => 20" << endl << endl;
	cout << "G�ncellemek �stedi�iniz Yeme�in Numaras�n� Giriniz: ";
	cin >> guncel;
	// Kullan�c�dan g�ncelleyece�i yeme�in numaras�n� girmesi istenir
	// Kullan�c�dan yeme�in g�ncel de�erlerini girmesi istenir.
	cout << "G�ncellenecek Yemek: " << u.yemekAdi[guncel - 1] << endl;
	cout << "G�ncel Kalori: ";	cin >> guncelKalori;
	cout << "G�ncel Fiyat: ";	cin >> guncelFiyat;
	cout << "G�ncel Maliyet: ";	cin >> guncelMaliyet;

	ifstream dosyaOku;
	dosyaOku.open("yemekcesit.txt");
	ofstream dosyaYaz;
	dosyaYaz.open("gecici3.tmp");

	// �stenen yeme�in bulundu�u sat�r hari� di�er sat�rar de�i�tirilmeden gecici3.tmp dosyas�na yaz�l�r.
	while (getline(dosyaOku, line)) {

		counter++;
		if (counter != guncel + 4) {

			dosyaYaz << line << endl;

		}
		// �stenen yeme�in bulundu�u sat�ra yeme�in g�ncel de�erleri yaz�l�r.
		else if (counter == guncel + 4) {
			dosyaYaz << left << setw(21) << u.yemekNo[guncel - 1] << setw(21) << u.yemekAdi[guncel - 1] << guncelKalori
				<< setw(26) << " kcal" << guncelFiyat << setw(23) << " TL" << guncelMaliyet << " TL" << endl;
		}
	}

	dosyaOku.close();
	dosyaYaz.close();
	remove("yemekcesit.txt");
	rename("gecici3.tmp", "yemekcesit.txt");	//gecici3.tmp dosyas�n�n ad� de�i�tirilerek yeni yemekcesit.txt dosyas� olu�turulur.

	cout << endl;
	cout << "Yemek Ba�ar�yla G�ncellendi" << endl << endl;
	cout << "Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n�z" << endl;
	system("pause");
	menu();

}


void yemekListele() {

	Urun u;

	//Men�deki yemekler ve 1. se�enekte eklenen yemekler konsol ekran�na listelenir.
	do {
		system("cls");

		cout << "----------------------------------------------------------------------------	MEN�	-------------------------------------------------------------" << endl;
		cout << left << setw(21) << "�r�n Ad�" << setw(29) << "Kalori De�eri" << setw(25) << "Sat�� Fiyat" << setw(10) << "Maliyet" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
		cout << left << setw(21) << u.yemekAdi[0] << u.kaloriGram[0] << setw(26) << " kcal" << u.fiyat[0] << setw(23) << " TL" << maliyet[0] << " TL" << endl
			<< setw(21) << u.yemekAdi[1] << u.kaloriGram[1] << setw(26) << " kcal" << u.fiyat[1] << setw(23) << " TL" << maliyet[1] << " TL" << endl
			<< setw(21) << u.yemekAdi[2] << u.kaloriGram[2] << setw(26) << " kcal" << u.fiyat[2] << setw(23) << " TL" << maliyet[2] << " TL" << endl
			<< setw(21) << u.yemekAdi[3] << u.kaloriGram[3] << setw(26) << " kcal" << u.fiyat[3] << setw(23) << " TL" << maliyet[3] << " TL" << endl
			<< setw(22) << u.yemekAdi[4] << u.kaloriGram[4] << setw(26) << " kcal" << u.fiyat[4] << setw(23) << " TL" << maliyet[4] << " TL" << endl
			<< setw(21) << u.yemekAdi[5] << u.kaloriGram[5] << setw(26) << " kcal" << u.fiyat[5] << setw(23) << " TL" << maliyet[5] << " TL" << endl
			<< setw(21) << u.yemekAdi[6] << u.kaloriGram[6] << setw(26) << " kcal" << u.fiyat[6] << setw(23) << " TL" << maliyet[6] << " TL" << endl
			<< setw(21) << u.yemekAdi[7] << u.kaloriGram[7] << setw(26) << " kcal" << u.fiyat[7] << setw(23) << " TL" << maliyet[7] << " TL" << endl
			<< setw(21) << u.yemekAdi[8] << u.kaloriGram[8] << setw(26) << " kcal" << u.fiyat[8] << setw(23) << " TL" << maliyet[8] << " TL" << endl
			<< setw(21) << u.yemekAdi[9] << u.kaloriGram[9] << setw(26) << " kcal" << u.fiyat[9] << setw(23) << " TL" << maliyet[9] << " TL" << endl
			<< setw(21) << u.yemekAdi[10] << u.kaloriGram[10] << setw(26) << " kcal" << u.fiyat[10] << setw(23) << " TL" << maliyet[10] << " TL" << endl
			<< setw(21) << u.yemekAdi[11] << u.kaloriGram[11] << setw(26) << " kcal" << u.fiyat[11] << setw(23) << " TL" << maliyet[11] << " TL" << endl
			<< setw(21) << u.yemekAdi[12] << u.kaloriGram[12] << setw(26) << " kcal" << u.fiyat[12] << setw(23) << " TL" << maliyet[12] << " TL" << endl
			<< setw(21) << u.yemekAdi[13] << u.kaloriGram[13] << setw(26) << " kcal" << u.fiyat[13] << setw(23) << " TL" << maliyet[13] << " TL" << endl
			<< setw(21) << u.yemekAdi[14] << u.kaloriGram[14] << setw(26) << " kcal" << u.fiyat[14] << setw(23) << " TL" << maliyet[14] << " TL" << endl
			<< setw(22) << u.yemekAdi[15] << u.kaloriGram[15] << setw(26) << " kcal" << u.fiyat[15] << setw(23) << " TL" << maliyet[15] << " TL" << endl
			<< setw(22) << u.yemekAdi[16] << u.kaloriGram[16] << setw(26) << " kcal" << u.fiyat[16] << setw(23) << " TL" << maliyet[16] << " TL" << endl
			<< setw(23) << u.yemekAdi[17] << u.kaloriGram[17] << setw(27) << " kcal" << u.fiyat[17] << setw(23) << " TL" << maliyet[17] << " TL" << endl
			<< setw(21) << u.yemekAdi[18] << u.kaloriGram[18] << setw(26) << " kcal" << u.fiyat[18] << setw(23) << " TL" << maliyet[18] << " TL" << endl
			<< setw(23) << u.yemekAdi[19] << u.kaloriGram[19] << setw(27) << " kcal" << u.fiyat[19] << setw(23) << " TL" << maliyet[19] << " TL" << endl;

		// cycleCounter 1. se�enekte eklenen yemek say�s�n� belirtir.
		// eklenen yemek say�s� kadar d�ng� d�nd�r�l�r
		for (int i = 20; i < 20 + cycleCounter; i++) {
			cout << left << setw(21) << u.yemekAdi[i] << u.kaloriGram[i] << setw(26) << " kcal" << u.fiyat[i] << setw(22) << " TL" << maliyet[i] << " TL" << endl;
		}

		system("pause");

		do {
			system("cls");
			cout << "Listeyi Tekrar G�mek ��in => 1 " << endl;
			cout << "�st Men�ye D�nmek ��in => 2 " << endl;
			cout << "��kmak ��in => 3" << endl;
			cin >> liste;
			// kullan�c� belirli say�lar d���nda bir say� girerse soru tekrarlan�r.
		} while (liste != 1 && liste != 2 && liste != 3);
		// Listeyi tekrar g�rmek isterse fonksiyon tekrar �al��t�r�l�r.
	} while (liste == 1);
	// men�ye d�nmek isterse menu fonksiyonu �al��t�r�l�r
	if (liste == 2)
		menu();

}

void random() {
	// G�nl�k 1 yemekten sat�lacak olan miktarlar random olarak belirlenir.
	srand(time(NULL));
	for (int i = 0; i < 20 + cycleCounter; i++) {
		int satis = rand() % 19 + 1;
		satisMiktar[i] = satis;
	}

}

void toplamKar() {
	//her yemek i�in kendi i�inde kar hesab� yap�l�r

	Urun u;

	random();
	gunluk_maliyet();
	int kar;
	for (int i = 0; i < 20 + cycleCounter; i++) {
		kar = (satisMiktar[i] * u.fiyat[i]);
		tekYemekKar�[i] = kar - maliyet[i];
	}

	toplam_kar = kar - toplam_maliyet;
}

void eldeKalan() {
	// pi�irilen yemekten sat�lan yemek say�s� ��kar�larak elde kalan yemek say�s� bulunur.
	Urun u;

	random();
	gunluk_maliyet();
	for (int i = 0; i < 20 + cycleCounter; i++) {
		eldeKalanYemek[i] = pisenYemek[i] - satisMiktar[i];
	}

}

void rapor() {
	// het yeme�in g�nl�k pi�irilen miktar, g�nl�k sat�lan miktar, toplam maliyet, g�nl�k kar ve elde kalan miktar� listelenir
	Urun u;

	system("cls");
	random();
	gunluk_maliyet();
	toplamKar();
	eldeKalan();

	do {
		cout << left << setw(34) << "Bug�n Pi�irilen Yemekler" << setw(23) << "Ki�i Say�lar�" << setw(23) << "Sat�� Miktar�" << setw(24) << "Toplam Maliyet" << setw(2) << "G�nl�k Kar" << "Elde Kalan Yemek(Ki�i)" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
		cout << left << setw(34) << u.yemekAdi[0] << setw(23) << hamburger << setw(23) << satisMiktar[0] << setw(24) << maliyet[0] << setw(20) << tekYemekKar�[0] << eldeKalanYemek[0] << endl;
		cout << left << setw(34) << u.yemekAdi[1] << setw(23) << kofte << setw(23) << satisMiktar[1] << setw(24) << maliyet[1] << setw(20) << tekYemekKar�[1] << eldeKalanYemek[1] << endl;
		cout << left << setw(34) << u.yemekAdi[2] << setw(23) << patatesKizartmasi << setw(23) << satisMiktar[2] << setw(24) << maliyet[2] << setw(20) << tekYemekKar�[2] << eldeKalanYemek[2] << endl;
		cout << left << setw(34) << u.yemekAdi[3] << setw(23) << musakka << setw(23) << satisMiktar[3] << setw(24) << maliyet[3] << setw(20) << tekYemekKar�[3] << eldeKalanYemek[3] << endl;
		cout << left << setw(34) << u.yemekAdi[4] << setw(23) << karniyarik << setw(23) << satisMiktar[4] << setw(24) << maliyet[4] << setw(20) << tekYemekKar�[4] << eldeKalanYemek[4] << endl;
		cout << left << setw(34) << u.yemekAdi[5] << setw(23) << karnibahar << setw(23) << satisMiktar[5] << setw(24) << maliyet[5] << setw(20) << tekYemekKar�[5] << eldeKalanYemek[5] << endl;
		cout << left << setw(34) << u.yemekAdi[6] << setw(23) << iskender << setw(23) << satisMiktar[6] << setw(24) << maliyet[6] << setw(20) << tekYemekKar�[6] << eldeKalanYemek[6] << endl;
		cout << left << setw(34) << u.yemekAdi[7] << setw(23) << patso << setw(23) << satisMiktar[7] << setw(24) << maliyet[7] << setw(20) << tekYemekKar�[7] << eldeKalanYemek[7] << endl;
		cout << left << setw(34) << u.yemekAdi[8] << setw(23) << kasarliTost << setw(23) << satisMiktar[8] << setw(24) << maliyet[8] << setw(20) << tekYemekKar�[8] << eldeKalanYemek[8] << endl;
		cout << left << setw(34) << u.yemekAdi[9] << setw(23) << koriSosluTavuk << setw(23) << satisMiktar[9] << setw(24) << maliyet[9] << setw(20) << tekYemekKar�[9] << eldeKalanYemek[9] << endl;
		cout << left << setw(34) << u.yemekAdi[10] << setw(23) << cheesecake << setw(23) << satisMiktar[10] << setw(24) << maliyet[10] << setw(20) << tekYemekKar�[10] << eldeKalanYemek[10] << endl;
		cout << left << setw(34) << u.yemekAdi[11] << setw(23) << magnolya << setw(23) << satisMiktar[11] << setw(24) << maliyet[11] << setw(20) << tekYemekKar�[11] << eldeKalanYemek[11] << endl;
		cout << left << setw(34) << u.yemekAdi[12] << setw(23) << profiterol << setw(23) << satisMiktar[12] << setw(24) << maliyet[12] << setw(20) << tekYemekKar�[12] << eldeKalanYemek[12] << endl;
		cout << left << setw(34) << u.yemekAdi[13] << setw(23) << browni << setw(23) << satisMiktar[13] << setw(24) << maliyet[13] << setw(20) << tekYemekKar�[13] << eldeKalanYemek[13] << endl;
		cout << left << setw(34) << u.yemekAdi[14] << setw(23) << sufle << setw(23) << satisMiktar[14] << setw(24) << maliyet[14] << setw(20) << tekYemekKar�[14] << eldeKalanYemek[14] << endl;
		cout << left << setw(34) << u.yemekAdi[15] << setw(23) << ayran << setw(23) << satisMiktar[15] << setw(24) << maliyet[15] << setw(20) << tekYemekKar�[15] << eldeKalanYemek[15] << endl;
		cout << left << setw(34) << u.yemekAdi[16] << setw(23) << limonata << setw(23) << satisMiktar[16] << setw(24) << maliyet[16] << setw(20) << tekYemekKar�[16] << eldeKalanYemek[16] << endl;
		cout << left << setw(34) << u.yemekAdi[17] << setw(23) << cay << setw(23) << satisMiktar[17] << setw(24) << maliyet[17] << setw(20) << tekYemekKar�[17] << eldeKalanYemek[17] << endl;
		cout << left << setw(34) << u.yemekAdi[18] << setw(23) << kahve << setw(23) << satisMiktar[18] << setw(24) << maliyet[18] << setw(20) << tekYemekKar�[18] << eldeKalanYemek[18] << endl;
		cout << left << setw(34) << u.yemekAdi[19] << setw(23) << su << setw(23) << satisMiktar[19] << setw(24) << maliyet[19] << setw(20) << tekYemekKar�[19] << eldeKalanYemek[19] << endl;

		system("pause");
		system("cls");
		do {
			cout << "Listeyi Tekrar G�mek ��in => 1 " << endl;
			cout << "�st Men�ye D�nmek ��in => 2 " << endl;
			cout << "��kmak ��in => 3" << endl;
			cin >> cevap;
			// kullan�c� belirli say�lar d���nda bir say� girerse soru tekrarlan�r.
		} while (cevap != 1 && cevap != 2 && cevap != 3);
		// Listeyi tekrar g�rmek isterse fonksiyon tekrar �al��t�r�l�r.
	} while (cevap == 1);
	// men�ye d�nmek isterse menu fonksiyonu �al��t�r�l�r
	if (cevap == 2)
		menu();

}

void hamburgerYap(int) {
	// Hamburger i�in malzemelerin stok yeterlili�i �l��l�r.
	// E�er stokta yeterli malzeme yoksa malzeme sipari� listesine al�n�r.
	// Belirlenen miktarlar 1 ki�ilik yemek i�in ihtiya� olunan miktar ile g�nl�k pi�irilmesi istenen miktar�n �arp�m�d�r.
	Malzeme m;

	if (stokMiktar�[0] < hamburger * 1) {
		cout << "Ekmek Stokta Yetersiz" << endl;
		sipari�Liste[0] = m.malzemeAdi[0];
		return;
	}
	stokMiktar�[0] -= hamburger * 1;
	if (stokMiktar�[1] < hamburger * 0.2) {
		cout << "Marul Stokta Yetersiz" << endl;
		sipari�Liste[1] = m.malzemeAdi[1];
		return;
	}
	stokMiktar�[1] -= hamburger * 0.2;
	if (stokMiktar�[2] < hamburger * 0.2) {
		cout << "Domates Stokta Yetersiz" << endl;
		sipari�Liste[2] = m.malzemeAdi[2];
		return;
	}
	stokMiktar�[2] -= hamburger * 0.2;
	if (stokMiktar�[4] < hamburger * 0.01) {
		cout << "Cheddar Peyniri Stokta Yetersiz" << endl;
		sipari�Liste[4] = m.malzemeAdi[4];
		return;
	}
	stokMiktar�[4] -= hamburger * 0.01;
	if (stokMiktar�[3] < hamburger * 0.01) {
		cout << "Tur�u Stokta Yetersiz" << endl;
		sipari�Liste[3] = m.malzemeAdi[3];
		return;
	}
	stokMiktar�[3] -= hamburger * 0.01;

}

void kofteYap(int) {
	// K�fte i�in malzemelerin stok yeterlili�i �l��l�r.
	// E�er stokta yeterli malzeme yoksa malzeme sipari� listesine al�n�r.
	// Belirlenen miktarlar 1 ki�ilik yemek i�in ihtiya� olunan miktar ile g�nl�k pi�irilmesi istenen miktar�n �arp�m�d�r.
	Malzeme m;

	if (stokMiktar�[9] < kofte * 0.1) {
		cout << "K�yma Stokta Yetersiz" << endl;
		sipari�Liste[9] = m.malzemeAdi[9];
		return;
	}
	stokMiktar�[9] -= kofte * 0.1;

}


void patatesYap(int) {
	// Patates K�zartmas� i�in malzemelerin stok yeterlili�i �l��l�r.
	// E�er stokta yeterli malzeme yoksa malzeme sipari� listesine al�n�r.
	// Belirlenen miktarlar 1 ki�ilik yemek i�in ihtiya� olunan miktar ile g�nl�k pi�irilmesi istenen miktar�n �arp�m�d�r.
	Malzeme m;

	if (stokMiktar�[5] < patatesKizartmasi * 0.3) {
		cout << "Patates Stokta Yetersiz" << endl;
		sipari�Liste[5] = m.malzemeAdi[5];
		return;
	}
	stokMiktar�[5] -= patatesKizartmasi * 0.3;
	if (stokMiktar�[6] < patatesKizartmasi * 0.25) {
		cout << "Ya� Stokta Yetersiz" << endl;
		sipari�Liste[6] = m.malzemeAdi[6];
		return;
	}
	stokMiktar�[6] -= patatesKizartmasi * 0.25;
	if (stokMiktar�[7] < patatesKizartmasi * 0.001) {
		cout << "Tuz Stokta Yetersiz" << endl;
		sipari�Liste[7] = m.malzemeAdi[7];
		return;
	}
	stokMiktar�[7] -= patatesKizartmasi * 0.001;

}
void musakkaYap(int) {
	// Musakka i�in malzemelerin stok yeterlili�i �l��l�r.
	// E�er stokta yeterli malzeme yoksa malzeme sipari� listesine al�n�r.
	// Belirlenen miktarlar 1 ki�ilik yemek i�in ihtiya� olunan miktar ile g�nl�k pi�irilmesi istenen miktar�n �arp�m�d�r.
	Malzeme m;

	if (stokMiktar�[8] < musakka * 0.2) {
		cout << "Patl�can Stokta Yetersiz" << endl;
		sipari�Liste[8] = m.malzemeAdi[8];
		return;
	}
	stokMiktar�[8] -= musakka * 0.2;
	if (stokMiktar�[9] < musakka * 0.2) {
		cout << "K�yma Stokta Yetersiz" << endl;
		sipari�Liste[9] = m.malzemeAdi[9];
		return;
	}
	stokMiktar�[9] -= musakka * 0.2;
	if (stokMiktar�[2] < musakka * 0.2) {
		cout << "Domates Stokta Yetersiz" << endl;
		sipari�Liste[2] = m.malzemeAdi[2];
		return;
	}
	stokMiktar�[2] -= musakka * 0.2;
	if (stokMiktar�[11] < musakka * 0.1) {
		cout << "So�an Stokta Yetersiz" << endl;
		sipari�Liste[11] = m.malzemeAdi[11];
		return;
	}
	stokMiktar�[11] -= musakka * 0.1;
	if (stokMiktar�[10] < musakka * 0.1) {
		cout << "Biber Stokta Yetersiz" << endl;
		sipari�Liste[10] = m.malzemeAdi[10];
		return;
	}
	stokMiktar�[10] -= musakka * 0.1;
	if (stokMiktar�[6] < musakka * 0.05) {
		cout << "Ya� Stokta Yetersiz" << endl;
		sipari�Liste[6] = m.malzemeAdi[6];
		return;
	}
	stokMiktar�[6] -= musakka * 0.05;

}

void karniyarikYap(int) {
	// Karn�yar�k i�in malzemelerin stok yeterlili�i �l��l�r.
	// E�er stokta yeterli malzeme yoksa malzeme sipari� listesine al�n�r.
	// Belirlenen miktarlar 1 ki�ilik yemek i�in ihtiya� olunan miktar ile g�nl�k pi�irilmesi istenen miktar�n �arp�m�d�r.
	Malzeme m;

	if (stokMiktar�[8] < karniyarik * 0.2) {
		cout << "Patl�can Stokta Yetersiz" << endl;
		sipari�Liste[8] = m.malzemeAdi[8];
		return;
	}
	stokMiktar�[8] -= karniyarik * 0.2;
	if (stokMiktar�[9] < karniyarik * 0.2) {
		cout << "K�yma Stokta Yetersiz" << endl;
		sipari�Liste[9] = m.malzemeAdi[9];
		return;
	}
	stokMiktar�[9] -= karniyarik * 0.2;
	if (stokMiktar�[2] < karniyarik * 0.2) {
		cout << "Domates Stokta Yetersiz" << endl;
		sipari�Liste[2] = m.malzemeAdi[2];
		return;
	}
	stokMiktar�[2] -= karniyarik * 0.2;
	if (stokMiktar�[5] < karniyarik * 0.2) {
		cout << "Patates Stokta Yetersiz" << endl;
		sipari�Liste[5] = m.malzemeAdi[5];
		return;
	}
	stokMiktar�[5] -= karniyarik * 0.2;
	if (stokMiktar�[10] < karniyarik * 0.1) {
		cout << "Biber Stokta Yetersiz" << endl;
		sipari�Liste[10] = m.malzemeAdi[10];
		return;
	}
	stokMiktar�[10] -= karniyarik * 0.1;
	if (stokMiktar�[7] < karniyarik * 0.001) {
		cout << "Tuz Stokta Yetersiz" << endl;
		sipari�Liste[7] = m.malzemeAdi[7];
		return;
	}
	stokMiktar�[7] -= karniyarik * 0.001;
	if (stokMiktar�[6] < karniyarik * 0.05) {
		cout << "Ya� Stokta Yetersiz" << endl;
		sipari�Liste[6] = m.malzemeAdi[6];
		return;
	}
	stokMiktar�[6] -= karniyarik * 0.05;
}
void karnibaharYap(int) {
	// Karn�bahar i�in malzemelerin stok yeterlili�i �l��l�r.
	// E�er stokta yeterli malzeme yoksa malzeme sipari� listesine al�n�r.
	// Belirlenen miktarlar 1 ki�ilik yemek i�in ihtiya� olunan miktar ile g�nl�k pi�irilmesi istenen miktar�n �arp�m�d�r.
	Malzeme m;

	if (stokMiktar�[12] < karnibahar * 0.2) {
		cout << "Karn�bahar Stokta Yetersiz" << endl;
		sipari�Liste[12] = m.malzemeAdi[12];
		return;
	}
	stokMiktar�[12] -= karnibahar * 0.2;
	if (stokMiktar�[13] < karnibahar * 0.1) {
		cout << "Havu� Stokta Yetersiz" << endl;
		sipari�Liste[13] = m.malzemeAdi[13];
		return;
	}
	stokMiktar�[13] -= karnibahar * 0.1;
	if (stokMiktar�[11] < karnibahar * 0.1) {
		cout << "So�an Stokta Yetersiz" << endl;
		sipari�Liste[11] = m.malzemeAdi[11];
		return;
	}
	stokMiktar�[11] -= karnibahar * 0.1;
	if (stokMiktar�[7] < karnibahar * 0.001) {
		cout << "Tuz Stokta Yetersiz" << endl;
		sipari�Liste[7] = m.malzemeAdi[7];
		return;
	}
	stokMiktar�[7] -= karnibahar * 0.001;
	if (stokMiktar�[6] < karnibahar * 0.05) {
		cout << "Ya� Stokta Yetersiz" << endl;
		sipari�Liste[6] = m.malzemeAdi[6];
		return;
	}
	stokMiktar�[6] -= karnibahar * 0.05;
}
void iskenderYap(int) {
	// �skender i�in malzemelerin stok yeterlili�i �l��l�r.
	// E�er stokta yeterli malzeme yoksa malzeme sipari� listesine al�n�r.
	// Belirlenen miktarlar 1 ki�ilik yemek i�in ihtiya� olunan miktar ile g�nl�k pi�irilmesi istenen miktar�n �arp�m�d�r.
	Malzeme m;

	if (stokMiktar�[14] < iskender * 0.2) {
		cout << "Et Stokta Yetersiz" << endl;
		sipari�Liste[14] = m.malzemeAdi[14];
		return;
	}
	stokMiktar�[14] -= iskender * 0.2;
	if (stokMiktar�[2] < iskender * 0.2) {
		cout << "Domates Stokta Yetersiz" << endl;
		sipari�Liste[2] = m.malzemeAdi[2];
		return;
	}
	stokMiktar�[2] -= iskender * 0.2;
	if (stokMiktar�[6] < iskender * 0.05) {
		cout << "Ya� Stokta Yetersiz" << endl;
		sipari�Liste[6] = m.malzemeAdi[6];
		return;
	}
	stokMiktar�[6] -= iskender * 0.05;
	if (stokMiktar�[11] < iskender * 0.1) {
		cout << "So�an Stokta Yetersiz" << endl;
		sipari�Liste[11] = m.malzemeAdi[11];
		return;
	}
	stokMiktar�[11] -= iskender * 0.1;
	if (stokMiktar�[15] < iskender * 0.1) {
		cout << "Yo�urt Stokta Yetersiz" << endl;
		sipari�Liste[15] = m.malzemeAdi[15];
		return;
	}
	stokMiktar�[15] -= iskender * 0.1;
	if (stokMiktar�[10] < iskender * 0.1) {
		cout << "Biber Stokta Yetersiz" << endl;
		sipari�Liste[10] = m.malzemeAdi[10];
		return;
	}
	stokMiktar�[10] -= iskender * 0.1;
}
void patsoYap(int) {
	// Patso i�in malzemelerin stok yeterlili�i �l��l�r.
	// E�er stokta yeterli malzeme yoksa malzeme sipari� listesine al�n�r.
	// Belirlenen miktarlar 1 ki�ilik yemek i�in ihtiya� olunan miktar ile g�nl�k pi�irilmesi istenen miktar�n �arp�m�d�r.
	Malzeme m;

	if (stokMiktar�[0] < patso) {
		cout << "Ekmek Stokta Yetersiz" << endl;
		sipari�Liste[0] = m.malzemeAdi[0];
		return;
	}
	stokMiktar�[0] -= patso * 1;
	if (stokMiktar�[5] < patso * 0.2) {
		cout << "Patates Stokta Yetersiz" << endl;
		sipari�Liste[5] = m.malzemeAdi[5];
		return;
	}
	stokMiktar�[5] -= patso * 0.2;
	if (stokMiktar�[16] < patso * 0.1) {
		cout << "Sosis Stokta Yetersiz" << endl;
		sipari�Liste[16] = m.malzemeAdi[16];
		return;
	}
	stokMiktar�[16] -= patso * 0.1;
	if (stokMiktar�[7] < patso * 0.001) {
		cout << "Tuz Stokta Yetersiz" << endl;
		sipari�Liste[7] = m.malzemeAdi[7];
		return;
	}
	stokMiktar�[7] -= patso * 0.001;
	if (stokMiktar�[6] < patso * 0.05) {
		cout << "Ya� Stokta Yetersiz" << endl;
		sipari�Liste[6] = m.malzemeAdi[6];
		return;
	}
	stokMiktar�[6] -= patso * 0.05;
}
void kasarliTostYap(int) {
	// Ka�arl� Tost i�in malzemelerin stok yeterlili�i �l��l�r.
	// E�er stokta yeterli malzeme yoksa malzeme sipari� listesine al�n�r.
	// Belirlenen miktarlar 1 ki�ilik yemek i�in ihtiya� olunan miktar ile g�nl�k pi�irilmesi istenen miktar�n �arp�m�d�r.
	Malzeme m;

	if (stokMiktar�[0] < kasarliTost) {
		cout << "Ekmek Stokta Yetersiz" << endl;
		sipari�Liste[0] = m.malzemeAdi[0];
		return;
	}
	stokMiktar�[0] -= kasarliTost * 1;
	if (stokMiktar�[17] < kasarliTost * 0.2) {
		cout << "Ka�ar Stokta Yetersiz" << endl;
		sipari�Liste[17] = m.malzemeAdi[17];
		return;
	}
	stokMiktar�[17] -= kasarliTost * 0.2;
}
void koriSosluTavukYap(int) {
	// K�ri Soslu Tavuk i�in malzemelerin stok yeterlili�i �l��l�r.
	// E�er stokta yeterli malzeme yoksa malzeme sipari� listesine al�n�r.
	// Belirlenen miktarlar 1 ki�ilik yemek i�in ihtiya� olunan miktar ile g�nl�k pi�irilmesi istenen miktar�n �arp�m�d�r.
	Malzeme m;

	if (stokMiktar�[18] < koriSosluTavuk * 0.2) {
		cout << "Tavuk Stokta Yetersiz" << endl;
		sipari�Liste[18] = m.malzemeAdi[18];
		return;
	}
	stokMiktar�[18] -= koriSosluTavuk * 0.2;
	if (stokMiktar�[19] < koriSosluTavuk * 0.01) {
		cout << "K�ri Stokta Yetersiz" << endl;
		sipari�Liste[19] = m.malzemeAdi[19];
		return;
	}
	stokMiktar�[19] -= koriSosluTavuk * 0.01;
	if (stokMiktar�[20] < koriSosluTavuk * 0.1) {
		cout << "Mantar Stokta Yetersiz" << endl;
		sipari�Liste[20] = m.malzemeAdi[20];
		return;
	}
	stokMiktar�[20] -= koriSosluTavuk * 0.1;
	if (stokMiktar�[10] < koriSosluTavuk * 0.1) {
		cout << "Biber Stokta Yetersiz" << endl;
		sipari�Liste[10] = m.malzemeAdi[10];
		return;
	}
	stokMiktar�[10] -= koriSosluTavuk * 0.1;
	if (stokMiktar�[7] < koriSosluTavuk * 0.001) {
		cout << "Tuz Stokta Yetersiz" << endl;
		sipari�Liste[7] = m.malzemeAdi[7];
		return;
	}
	stokMiktar�[7] -= koriSosluTavuk * 0.001;
	if (stokMiktar�[6] < koriSosluTavuk * 0.05) {
		cout << "Ya� Stokta Yetersiz" << endl;
		sipari�Liste[6] = m.malzemeAdi[6];
		return;
	}
	stokMiktar�[6] -= koriSosluTavuk * 0.05;
}


void cheesecakeYap(int) {
	// Cheesecake i�in malzemelerin stok yeterlili�i �l��l�r.
	// E�er stokta yeterli malzeme yoksa malzeme sipari� listesine al�n�r.
	// Belirlenen miktarlar 1 ki�ilik yemek i�in ihtiya� olunan miktar ile g�nl�k pi�irilmesi istenen miktar�n �arp�m�d�r.
	Malzeme m;

	if (stokMiktar�[21] < cheesecake * 0.02) {
		cout << "Labne Stokta Yetersiz" << endl;
		sipari�Liste[21] = m.malzemeAdi[21];
		return;
	}
	stokMiktar�[21] -= cheesecake * 0.02;
	if (stokMiktar�[22] < cheesecake * 0.02) {
		cout << "Krema Stokta Yetersiz" << endl;
		sipari�Liste[22] = m.malzemeAdi[22];
		return;
	}
	stokMiktar�[22] -= cheesecake * 0.02;
	if (stokMiktar�[23] < cheesecake * 1) {
		cout << "Yumurta Stokta Yetersiz" << endl;
		sipari�Liste[23] = m.malzemeAdi[23];
		return;
	}
	stokMiktar�[23] -= cheesecake * 1;
	if (stokMiktar�[24] < cheesecake * 0.02) {
		cout << "�eker Stokta Yetersiz" << endl;
		sipari�Liste[24] = m.malzemeAdi[24];
		return;
	}
	stokMiktar�[24] -= cheesecake * 0.02;
	if (stokMiktar�[26] < cheesecake * 0.001) {
		cout << "Vanilya Stokta Yetersiz" << endl;
		sipari�Liste[26] = m.malzemeAdi[26];
		return;
	}
	stokMiktar�[26] -= cheesecake * 0.001;
	if (stokMiktar�[27] < cheesecake * 0.01) {
		cout << "Ni�asta Stokta Yetersiz" << endl;
		sipari�Liste[27] = m.malzemeAdi[27];
		return;
	}
	stokMiktar�[27] -= cheesecake * 0.01;
	if (stokMiktar�[25] < cheesecake * 0.02) {
		cout << "Un Stokta Yetersiz" << endl;
		sipari�Liste[25] = m.malzemeAdi[25];
		return;
	}
	stokMiktar�[25] -= cheesecake * 0.02;
	if (stokMiktar�[28] < cheesecake * 0.05) {
		cout << "Limon Stokta Yetersiz" << endl;
		sipari�Liste[28] = m.malzemeAdi[28];
		return;
	}
	stokMiktar�[28] -= cheesecake * 0.05;
	if (stokMiktar�[29] < cheesecake * 0.5) {
		cout << "Bisk�vi Stokta Yetersiz" << endl;
		sipari�Liste[29] = m.malzemeAdi[29];
		return;
	}
	stokMiktar�[29] -= cheesecake * 0.5;
	if (stokMiktar�[6] < cheesecake * 0.005) {
		cout << "Ya� Stokta Yetersiz" << endl;
		sipari�Liste[6] = m.malzemeAdi[6];
		return;
	}
	stokMiktar�[6] -= cheesecake * 0.005;
}
void magnolyaYap(int) {
	// Magnolya i�in malzemelerin stok yeterlili�i �l��l�r.
	// E�er stokta yeterli malzeme yoksa malzeme sipari� listesine al�n�r.
	// Belirlenen miktarlar 1 ki�ilik yemek i�in ihtiya� olunan miktar ile g�nl�k pi�irilmesi istenen miktar�n �arp�m�d�r.
	Malzeme m;

	if (stokMiktar�[37] < magnolya * 0.2) {
		cout << "S�t Stokta Yetersiz" << endl;
		sipari�Liste[37] = m.malzemeAdi[37];
		return;
	}
	stokMiktar�[37] -= magnolya * 0.2;
	if (stokMiktar�[22] < magnolya * 0.04) {
		cout << "Krema Stokta Yetersiz" << endl;
		sipari�Liste[22] = m.malzemeAdi[22];
		return;
	}
	stokMiktar�[22] -= magnolya * 0.04;
	if (stokMiktar�[27] < magnolya * 0.02) {
		cout << "Ni�asta Stokta Yetersiz" << endl;
		sipari�Liste[27] = m.malzemeAdi[27];
		return;
	}
	stokMiktar�[27] -= magnolya * 0.02;
	if (stokMiktar�[25] < magnolya * 0.02) {
		cout << "Un Stokta Yetersiz" << endl;
		sipari�Liste[25] = m.malzemeAdi[25];
		return;
	}
	stokMiktar�[25] -= magnolya * 0.02;
	if (stokMiktar�[24] < magnolya * 0.02) {
		cout << "�eker Stokta Yetersiz" << endl;
		sipari�Liste[24] = m.malzemeAdi[24];
		return;
	}
	stokMiktar�[24] -= magnolya * 0.02;
	if (stokMiktar�[30] < magnolya * 0.02) {
		cout << "�ilek Stokta Yetersiz" << endl;
		sipari�Liste[30] = m.malzemeAdi[30];
		return;
	}
	stokMiktar�[30] -= magnolya * 0.02;
	if (stokMiktar�[29] < magnolya * 0.1) {
		cout << "Bisk�vi Stokta Yetersiz" << endl;
		sipari�Liste[29] = m.malzemeAdi[29];
		return;
	}
	stokMiktar�[29] -= magnolya * 0.1;
}
void profiterolYap(int) {
	// Profiterol i�in malzemelerin stok yeterlili�i �l��l�r.
	// E�er stokta yeterli malzeme yoksa malzeme sipari� listesine al�n�r.
	// Belirlenen miktarlar 1 ki�ilik yemek i�in ihtiya� olunan miktar ile g�nl�k pi�irilmesi istenen miktar�n �arp�m�d�r.
	Malzeme m;

	if (stokMiktar�[37] < profiterol * 0.02) {
		cout << "S�t Stokta Yetersiz" << endl;
		sipari�Liste[37] = m.malzemeAdi[37];
		return;
	}
	stokMiktar�[37] -= profiterol * 0.02;
	if (stokMiktar�[25] < profiterol * 0.02) {
		cout << "Un Stokta Yetersiz" << endl;
		sipari�Liste[25] = m.malzemeAdi[25];
		return;
	}
	stokMiktar�[25] -= profiterol * 0.02;
	if (stokMiktar�[24] < profiterol * 0.02) {
		cout << "�eker Stokta Yetersiz" << endl;
		sipari�Liste[24] = m.malzemeAdi[24];
		return;
	}
	stokMiktar�[24] -= profiterol * 0.02;
	if (stokMiktar�[26] < profiterol * 0.001) {
		cout << "Vanilya Stokta Yetersiz" << endl;
		sipari�Liste[26] = m.malzemeAdi[26];
		return;
	}
	stokMiktar�[26] -= profiterol * 0.001;
	if (stokMiktar�[6] < profiterol * 0.05) {
		cout << "Ya� Stokta Yetersiz" << endl;
		sipari�Liste[6] = m.malzemeAdi[6];
		return;
	}
	stokMiktar�[6] -= profiterol * 0.05;
	if (stokMiktar�[38] < profiterol * 0.005) {
		cout << "Su Stokta Yetersiz" << endl;
		sipari�Liste[38] = m.malzemeAdi[38];
		return;
	}
	stokMiktar�[38] -= profiterol * 0.005;
	if (stokMiktar�[23] < profiterol * 1) {
		cout << "Yumurta Stokta Yetersiz" << endl;
		sipari�Liste[23] = m.malzemeAdi[23];
		return;
	}
	stokMiktar�[23] -= profiterol * 1;
	if (stokMiktar�[31] < profiterol * 0.02) {
		cout << "�ikolata Stokta Yetersiz" << endl;
		sipari�Liste[31] = m.malzemeAdi[31];
		return;
	}
	stokMiktar�[31] -= profiterol * 0.02;
}
void browniYap(int) {
	// Browni i�in malzemelerin stok yeterlili�i �l��l�r.
	// E�er stokta yeterli malzeme yoksa malzeme sipari� listesine al�n�r.
	// Belirlenen miktarlar 1 ki�ilik yemek i�in ihtiya� olunan miktar ile g�nl�k pi�irilmesi istenen miktar�n �arp�m�d�r.
	Malzeme m;

	if (stokMiktar�[37] < browni * 0.2) {
		cout << "S�t Stokta Yetersiz" << endl;
		sipari�Liste[37] = m.malzemeAdi[37];
		return;
	}
	stokMiktar�[37] -= browni * 0.2;
	if (stokMiktar�[25] < browni * 0.2) {
		cout << "Un Stokta Yetersiz" << endl;
		sipari�Liste[25] = m.malzemeAdi[25];
		return;
	}
	stokMiktar�[25] -= browni * 0.2;
	if (stokMiktar�[24] < browni * 0.02) {
		cout << "�eker Stokta Yetersiz" << endl;
		sipari�Liste[24] = m.malzemeAdi[24];
		return;
	}
	stokMiktar�[24] -= browni * 0.02;
	if (stokMiktar�[26] < browni * 0.01) {
		cout << "Vanilya Stokta Yetersiz" << endl;
		sipari�Liste[26] = m.malzemeAdi[26];
		return;
	}
	stokMiktar�[26] -= browni * 0.01;
	if (stokMiktar�[6] < browni * 0.005) {
		cout << "Ya� Stokta Yetersiz" << endl;
		sipari�Liste[6] = m.malzemeAdi[6];
		return;
	}
	stokMiktar�[6] -= browni * 0.005;
	if (stokMiktar�[23] < browni * 1) {
		cout << "Yumurta Stokta Yetersiz" << endl;
		sipari�Liste[23] = m.malzemeAdi[23];
		return;
	}
	stokMiktar�[23] -= browni * 1;
	if (stokMiktar�[31] < browni * 0.02) {
		cout << "�ikolata Stokta Yetersiz" << endl;
		sipari�Liste[31] = m.malzemeAdi[31];
		return;
	}
	stokMiktar�[31] -= browni * 0.02;
}
void sufleYap(int) {
	// Sufle i�in malzemelerin stok yeterlili�i �l��l�r.
	// E�er stokta yeterli malzeme yoksa malzeme sipari� listesine al�n�r.
	// Belirlenen miktarlar 1 ki�ilik yemek i�in ihtiya� olunan miktar ile g�nl�k pi�irilmesi istenen miktar�n �arp�m�d�r.
	Malzeme m;

	if (stokMiktar�[37] < sufle * 0.2) {
		cout << "S�t Stokta Yetersiz" << endl;
		sipari�Liste[37] = m.malzemeAdi[37];
		return;
	}
	stokMiktar�[37] -= sufle * 0.2;
	if (stokMiktar�[25] < sufle * 0.02) {
		cout << "Un Stokta Yetersiz" << endl;
		sipari�Liste[25] = m.malzemeAdi[25];
		return;
	}
	stokMiktar�[25] -= sufle * 0.02;
	if (stokMiktar�[24] < sufle * 0.02) {
		cout << "�eker Stokta Yetersiz" << endl;
		sipari�Liste[24] = m.malzemeAdi[24];
		return;
	}
	stokMiktar�[24] -= sufle * 0.02;
	if (stokMiktar�[26] < sufle * 0.01) {
		cout << "Vanilya Stokta Yetersiz" << endl;
		sipari�Liste[26] = m.malzemeAdi[26];
		return;
	}
	stokMiktar�[26] -= sufle * 0.01;
	if (stokMiktar�[31] < sufle * 0.02) {
		cout << "�ikolata Stokta Yetersiz" << endl;
		sipari�Liste[31] = m.malzemeAdi[31];
		return;
	}
	stokMiktar�[31] -= sufle * 0.02;
	if (stokMiktar�[32] < sufle * 0.001) {
		cout << "Kabartma Tozu Stokta Yetersiz" << endl;
		sipari�Liste[32] = m.malzemeAdi[32];
		return;
	}
	stokMiktar�[32] -= sufle * 0.001;
	if (stokMiktar�[33] < sufle * 0.02) {
		cout << "Kakao Stokta Yetersiz" << endl;
		sipari�Liste[33] = m.malzemeAdi[33];
		return;
	}
	stokMiktar�[33] -= sufle * 0.02;
}
void ayranYap(int) {
	// Ayran i�in malzemelerin stok yeterlili�i �l��l�r.
	// E�er stokta yeterli malzeme yoksa malzeme sipari� listesine al�n�r.
	// Belirlenen miktarlar 1 ki�ilik yemek i�in ihtiya� olunan miktar ile g�nl�k pi�irilmesi istenen miktar�n �arp�m�d�r.
	Malzeme m;

	if (stokMiktar�[15] < ayran * 0.02) {
		cout << "Yo�urt Stokta Yetersiz" << endl;
		sipari�Liste[15] = m.malzemeAdi[15];
		return;
	}
	stokMiktar�[15] -= ayran * 0.02;
	if (stokMiktar�[38] < ayran * 0.2) {
		cout << "Su Stokta Yetersiz" << endl;
		sipari�Liste[38] = m.malzemeAdi[38];
		return;
	}
	stokMiktar�[38] -= ayran * 0.2;
	if (stokMiktar�[7] < ayran * 0.005) {
		cout << "Tuz Stokta Yetersiz" << endl;
		sipari�Liste[7] = m.malzemeAdi[7];
		return;
	}
	stokMiktar�[7] -= ayran * 0.005;
}
void limonataYap(int) {
	// Limonata i�in malzemelerin stok yeterlili�i �l��l�r.
	// E�er stokta yeterli malzeme yoksa malzeme sipari� listesine al�n�r.
	// Belirlenen miktarlar 1 ki�ilik yemek i�in ihtiya� olunan miktar ile g�nl�k pi�irilmesi istenen miktar�n �arp�m�d�r.
	Malzeme m;

	if (stokMiktar�[38] < limonata * 0.2) {
		cout << "Su Stokta Yetersiz" << endl;
		sipari�Liste[38] = m.malzemeAdi[38];
		return;
	}
	stokMiktar�[38] -= limonata * 0.2;
	if (stokMiktar�[24] < limonata * 0.02) {
		cout << "�eker Stokta Yetersiz" << endl;
		sipari�Liste[24] = m.malzemeAdi[24];
		return;
	}
	stokMiktar�[24] -= limonata * 0.02;
	if (stokMiktar�[34] < limonata * 0.1) {
		cout << "Portakal Stokta Yetersiz" << endl;
		sipari�Liste[34] = m.malzemeAdi[0, 34];
		return;
	}
	stokMiktar�[34] -= limonata * 0.1;
	if (stokMiktar�[28] < limonata * 0.2) {
		cout << "Limon Stokta Yetersiz" << endl;
		sipari�Liste[28] = m.malzemeAdi[28];
		return;
	}
	stokMiktar�[28] -= limonata * 0.2;
}
void cayYap(int) {
	// �ay i�in malzemelerin stok yeterlili�i �l��l�r.
	// E�er stokta yeterli malzeme yoksa malzeme sipari� listesine al�n�r.
	// Belirlenen miktarlar 1 ki�ilik yemek i�in ihtiya� olunan miktar ile g�nl�k pi�irilmesi istenen miktar�n �arp�m�d�r.
	Malzeme m;

	if (stokMiktar�[38] < cay * 0.2) {
		cout << "Su Stokta Yetersiz" << endl;
		sipari�Liste[38] = m.malzemeAdi[38];
		return;
	}
	stokMiktar�[38] -= cay * 0.2;
	if (stokMiktar�[35] < cay * 0.02) {
		cout << "�ay Stokta Yetersiz" << endl;
		sipari�Liste[35] = m.malzemeAdi[35];
		return;
	}
	stokMiktar�[35] -= cay * 0.02;
}
void kahveYap(int) {
	// Kahve i�in malzemelerin stok yeterlili�i �l��l�r.
	// E�er stokta yeterli malzeme yoksa malzeme sipari� listesine al�n�r.
	// Belirlenen miktarlar 1 ki�ilik yemek i�in ihtiya� olunan miktar ile g�nl�k pi�irilmesi istenen miktar�n �arp�m�d�r.
	Malzeme m;

	if (stokMiktar�[38] < kahve * 0.2) {
		cout << "Su Stokta Yetersiz" << endl;
		sipari�Liste[38] = m.malzemeAdi[38];
		return;
	}
	stokMiktar�[38] -= kahve * 0.2;
	if (stokMiktar�[36] < kahve * 0.02) {
		cout << "Kahve Stokta Yetersiz" << endl;
		sipari�Liste[36] = m.malzemeAdi[36];
		return;
	}
	stokMiktar�[36] -= kahve * 0.02;
	if (stokMiktar�[24] < kahve * 0.001) {
		cout << "�eker Stokta Yetersiz" << endl;
		sipari�Liste[24] = m.malzemeAdi[24];
		return;
	}
	stokMiktar�[24] -= kahve * 0.001;
}
void suYap(int) {
	// su i�in malzemelerin stok yeterlili�i �l��l�r.
	// E�er stokta yeterli malzeme yoksa malzeme sipari� listesine al�n�r.
	// Belirlenen miktarlar 1 ki�ilik yemek i�in ihtiya� olunan miktar ile g�nl�k pi�irilmesi istenen miktar�n �arp�m�d�r.
	Malzeme m;

	if (stokMiktar�[38] < su * 0.5) {
		cout << "Su Stokta Yetersiz" << endl;
		sipari�Liste[38] = m.malzemeAdi[38];
		return;
	}
	stokMiktar�[38] -= su * 0.5;
}

void sipari�Listesi() {
	//Yukar�da yap�lan i�lemler sonucunda malzeme stokta yetersiz bulundu�unda ad� ge�en malzeme sipari� listesine eklenir.
	Malzeme m;

	do {
		system("cls");
		for (int i = 0; i < 39; i++) {
			if (sipari�Liste[i] == m.malzemeAdi[i])
				cout << left << sipari�Liste[i] << endl;
			else
				continue;

		}
		do {
			system("pause");
			system("cls");

			cout << "Listeyi Tekrar G�r�nt�lemek ��in => 1 " << endl;
			cout << "�st Men�ye D�nmek ��in => 2 " << endl;
			cout << "��kmak ��in => 3 " << endl;
			cin >> siparis;
			// Kullan�c� istenen de�erler d���nda de�er girerse soru tekrarlan�r.
		} while (siparis != 1 && siparis != 2 && siparis != 3);
		// Kullan�c� listeyi tekrar g�rmek isterse fonksiyon tekrar �al��t�r�l�r
	} while (siparis == 1);
	// Kullan�c� men�ye d�nmek isterse menu fonksiyonu �al��t�r�l�r.
	if (siparis == 2)
		menu();
}

