#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "include/Function.h"
#include "include/VectorMatrix.h"

/**
* @mainpage Wizualizacja pola wektorowego
* @author Jan Bizo�
* @author Maksym Kazhaiev
* @author Micha� Rogowski
* 
* @details
* Wizualizacja pola wektorowego
===================================

### Opis projektu

Celem projektu jest napisanie programu, kt�ry pozwala wizualizowa� funkcj� V = f(r) , gdzie V oraz r to wektory w przestrzeni 3D. Oczywi�cie program nie musi umie� interpretowa� �adnych funkcji wpisywanych przez u�ytkownika. Zestaw kilku przyk�adowych funkcji powinien zosta� wpisany na sta�e do kodu programu, a u�ytkownik powinien mie� mo�liwo�� wyboru jednej z nich i ewentualnie zmiany jej parametr�w.

### Wymagania podstawowe

Program pozwala na wizualizacj� funkcji pola poprzez rysowanie **strza�ek**, kt�re maj� pocz�tek w **punktach w�z�owych**. Przedzia� zmienno�ci argument�w X,Y,Z jak i to na ile odcink�w dzielimy te przedzia�y podaje u�ytkownik. Wsp�czynnik skalowania okre�laj�cy jak d�ugie s� strza�ki u�ytkownik mo�e zmienia� przy u�yciu suwaka. Oczywi�cie ca�o�� mo�na dowolnie **obraca�**. Program posiada tak�e kilka funkcji do wyboru. Funkcje te maj� wstawione parametry swobodne, kt�re u�ytkownik mo�e zmienia� w trakcie pracy programu.

### Wymagania rozszerzone

W tej wersji program potrafi sam dobra� d�ugo�� strza�ek tak, aby najd�u�sza nie by�a wi�ksza ni� odleg�o�ci w�ze�-w�ze�. Oczywi�cie u�ytkownik w dalszym ci�gu posiada mo�liwo�� zmiany skali r�cznie. Istnieje tryb wy�wietlania, w kt�rym d�ugo�ci strza�ek s� sta�e, a o warto�ci funkcji w w�le informuje nas kolor strza�ki (standardowa skala � **niebieski** dla minimum � **czerwony** dla maksimum). U�ytkownik ma mo�liwo�� zapisania wyniku na dysk w postaci pliku graficznego o zadanym. Program powinien mie� r�wnie� mo�liwo�� �odci�cia� cz�ci w�z��w poprzez wprowadzenie dodatkowej p�aszczyzny. Wszystkie strza�ki wychodz�ce z w�z��w po wybranej stronie p�aszczyzny nie b�d� rysowane.



### Plan:
+ Funkcje pola wektorowego wybierane z listy (mo�liwo�� manipulacji parametrami funkcji).
+ Wizualizacja pola poprzez rysowanie strza�ek
+ Mo�liwo�� okre�lenia przedzia�u zmiennno�ci oraz ilo�ci odcink�w na ile dzielimy ten przedzia�
+ Mo�liwo�� zmianny d�ugo�ci strza�ek za pomoc� suwaka
+ (Rozszerzenie) Automatyczny dob�r d�ugo�ci strza�ek
+ (Rozszerzenie) Alternatywny spos�b wy�wietlania strza�ek - sta�a d�ugo�� + kolor
+ (Rozszerzenie) Mo�liwo�� zapisu wyniku na dysku w postaci bit mapy
+ (Rozszerzenie) Odci�cie cz�ci pola za pomoc� p�aszczyzny


### Inspiracje:
+ https://www.geogebra.org/m/u3xregNW
+ https://www.geogebra.org/m/KKB2Ndez
+ https://glennmarshall.wordpress.com/2014/10/31/3d-neon-vector-fields/
+ https://chart-studio.plotly.com/~empet/14971.embed
+ https://forum.dynamobim.com/t/vector-field-visualization/26862

===============================================================================
![image](../doc.png)

- Jako Init() - nale�y rozumie� konstruktor MainFrame_Interface
- Jako Refresh() - nale�y rozumie� funkcje rysuj�c�
- Jako Menu Item() - nale�y rozumie� konkretny wyb�r z paska menu.

# Uwaga:
Cz�� klas nie zosta�a opisana - zosta�y one wygenerowane automatycznie, 
aby pozna� ich stuktur� i funkcj� kt�re pe�ni� nale�y zainstalowa� wxFormBuilder
i uruchomi� plik Layout.fbp.
*/ 


/**
*	@brief Klasa przechowujaca aktualna konfiguracje
*/
class Config {
public:
	/**
	* @brief Wska�nik do zbioru dost�pnych funkcji
	*/
	Config(std::vector<Function*>* function_ptr);

	/**
	* @brief Zwraca doln� granic� przestrzeni wektorowej w osi X
	*/ 
	double GetX_Min() const;
	/**
	* @brief Zwraca g�rn� granic� przestrzeni wektorowej w osi X
	*/
	double GetX_Max() const;
	/**
	* @brief Zwraca doln� granic� przestrzeni wektorowej w osi Y
	*/
	double GetY_Min() const;
	/**
	* @brief Zwraca g�rn� granic� przestrzeni wektorowej w osi Y
	*/
	double GetY_Max() const;
	/**
	* @brief Zwraca doln� granic� przestrzeni wektorowej w osi Z
	*/
	double GetZ_Min() const;
	/**
	* @brief Zwraca g�rn� granic� przestrzeni wektorowej w osi Z
	*/
	double GetZ_Max() const;
	/**
	* @brief Zwraca d�ugo�� jaka ma zosta� dodana w p�tli rysujacej
	*/
	double GetCutLen() const; 
	/**
	* @brief Zwraca aktualnie wy�wietlan� funkcje
	*/
	Function* GetCurrentFun();
	/**
	* @brief Zwraca tryb wy�wietlania pola wektorowego - (0) Kolor /  (1) Dlugosc ??
	*/
	unsigned int GetPrintOption() const;
	/**
	* @brief Zwraca dlugo�� strza�ki
	*/
	double GetArrowsLen() const;
	/**
	* @brief Zwraca odleg�o�� do kt�rej mamy wy�wietla� - ustawienie Z-buffer-a
	*/
	double GetFarPlane() const;
	/**
	* @brief Informacja wyswietlana na pasku postepu - pocz�tek. Infrormuje o najbli�ej po�o�onym punkcie obiektu.
	*/
	double GetNearest() const;
	/**
	* @brief Informacja wy�wietlana na pasku postepu - koniec. Infrormuje o najdalej po�o�onym punkcie obiektu.
	*/
	double GetFurthest() const;

	// Ruch myszki na ekranie
	/**
	* @brief Wsp�rz�dna x wci�ni�tej myszy
	*/
	double GetStartX() const;
	/**
	* @brief Wsp�rz�dna y wci�ni�tej myszy
	*/
	double GetStartY() const;
	/**
	* @brief Wsp�rz�dna x po upuszczeniu klawisza myszy
	*/
	double GetEndX() const;
	/**
	* @brief Wsp�rz�dna y po upuszczeniu klawisza myszy
	*/
	double GetEndY() const;
	/**
	* @brief Czy mysz jest wcisnieta
	*/
	bool GetPressed() const;
	/**
	* @brief Ustawienie aktualnego stanu wci�ni�cia myszy
	*/
	void SetPressed(bool x);


	/**
	* @brief Ustawia doln� granic� przestrzeni wektorowej w osi X
	*/
	void SetX_Min(double x);
	/**
	* @brief Ustawia g�rn� granic� przestrzeni wektorowej w osi X
	*/
	void SetX_Max(double x);
	/**
	* @brief Ustawia doln� granic� przestrzeni wektorowej w osi Y
	*/
	void SetY_Min(double x);
	/**
	* @brief Ustawia g�rn� granic� przestrzeni wektorowej w osi Y
	*/
	void SetY_Max(double x);
	/**
	* @brief Ustawia doln� granic� przestrzeni wektorowej w osi Z
	*/
	void SetZ_Min(double x);
	/**
	* @brief Ustawia g�rn� granic� przestrzeni wektorowej w osi Z
	*/
	void SetZ_Max(double x);
	/**
	* @brief Ustawia d�ugo�� jaka ma zosta� dodana w p�tli rysujacej
	*/
	void SetCutLen(double x);
	/**
	* @brief Ustawia aktualnie wy�wietlan� funkcje
	*/
	void SetCurrentFun(Function* fun); 
	/**
	* @brief Informacja wyswietlana na pasku postepu - koniec. Infrormuje o najdalej po�o�onym punkcie obiektu.
	*/
	Function* GetFunction(int id) const;
	/**
	* @brief Ustawia tryb wy�wietlania pola wektorowego - (0) Kolor / (1) Dlugosc ???
	*/
	void SetPrintOption(unsigned int x);
	/**
	* @brief Ustawia dlugo�� strza�ki
	*/
	void SetArrowsLen(double x);
	/**
	* @brief Ustawia odleg�o�� do kt�rej mamy wy�wietla� - ustawienie Z-buffer-a
	*/
	void SetFarPlane(double x);
	/**
	* @brief Ustawai informacj� wy�wietlan� na pasku postepu - pocz�tek. Infrormuje o najbli�ej po�o�onym punkcie obiektu.
	*/
	void SetNearest(double x);
	/**
	* @brief Informacja wyswietlana na pasku postepu - koniec. Infrormuje o najdalej po�o�onym punkcie obiektu.
	*/
	void SetFurthest(double x);
	/**
	* @brief Ustawienie pozycji myszy - pozycja start
	*/
	void SetStart(double x, double y);
	/**
	* @brief Ustawienie pozycji myszy - pozycja end
	*/
	void SetEnd(double x, double y);


	/**
	* @brief Zwraca aktualnie ustawion� skal� przestrzeni.
	*/
	double GetScale() const;
	/**
	* @brief Ustawia skal� przestrzeni.
	*/
	double SetScale(double x);
	/**
	* @brief Ustawia informacj� o tym czy odci�cie cz�ci danych ma zosta� zrealizowane.
	*/
	void PlaneEnabled(bool x);
	/**
	* @brief Zwraca informacj� o tym czy odci�cie cz�ci danych ma zosta� zrealizowane.
	*/
	bool isPlaneEnable() const;
	/**
	* @brief Zwraca aktualn� rotacj� przestrzeni
	*/
	Matrix4 GetRotation() const;
	/**
	* @brief Ustawia aktualn� rotacj� przestrzeni
	*/
	void SetRotation(Matrix4 rot, XRotate_Matrix l_x, YRotate_Matrix l_y);

private:
	double x_min, x_max;
	double y_min, y_max;
	double z_min, z_max;
	double lenght_of_cut;
	Function* current_function;
	unsigned int print_option;
	double length_of_arrows;

	double far_plane;
	double nearest_point;
	double furthest_point;

	double start_swipe_x;
	double start_swipe_y;
	double end_swipe_x;
	double end_swipe_y;

	bool pressed;
	double scale;
	bool plane_enable;
	Matrix4 rotation;

	std::vector<Function*>* function_ptr;
};