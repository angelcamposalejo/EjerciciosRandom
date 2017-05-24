#pragma once  //______________________________________ EjerciciosRandom.h  
#include "Resource.h"
class EjerciciosRandom : public Win::Dialog
{
public:
	EjerciciosRandom()
	{
		srand(::GetTickCount());
		randomNumber = (int)(15.0*rand() / RAND_MAX);
		intentos = 0;
	}
	~EjerciciosRandom()
	{
	}
	int randomNumber;
	int intentos;
protected:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lb1;
	Win::Textbox tbxIntentos;
	Win::Label lb2;
	Win::Button gbox1;
	Win::Textbox tbxEntrada;
	Win::Button btChecar;
	Win::Button btAgain;
	Win::Textbox tbx3;
protected:
	Win::Gdi::Font fontArial014A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx = Sys::Convert::PixelToDlgUnitX(338);
		dlgTemplate.cy = Sys::Convert::PixelToDlgUnitY(181);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		this->Text = L"EjerciciosRandom";
		lb1.Create(NULL, L"Intentos", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 13, 11, 58, 25, hWnd, 1000);
		tbxIntentos.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 69, 10, 103, 25, hWnd, 1001);
		lb2.Create(NULL, L"Intentos por hacer", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 220, 8, 111, 37, hWnd, 1002);
		gbox1.Create(WS_EX_TRANSPARENT, L"Número de 0 a 15", WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 14, 62, 205, 101, hWnd, 1003);
		tbxEntrada.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 23, 89, 74, 25, hWnd, 1004);
		btChecar.Create(NULL, L"Checar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 107, 90, 100, 28, hWnd, 1005);
		btAgain.Create(NULL, L"Jugar de nuevo", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 221, 72, 109, 46, hWnd, 1006);
		tbx3.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 250, 159, 61, 15, hWnd, 1007);
		fontArial014A.Create(L"Arial", 14, false, false, false, false);
		lb1.Font = fontArial014A;
		tbxIntentos.Font = fontArial014A;
		lb2.Font = fontArial014A;
		gbox1.Font = fontArial014A;
		tbxEntrada.Font = fontArial014A;
		btChecar.Font = fontArial014A;
		btAgain.Font = fontArial014A;
		tbx3.Font = fontArial014A;
	}
	//_________________________________________________
	void btChecar_Click(Win::Event& e);
	void btAgain_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btChecar.IsEvent(e, BN_CLICKED)) {btChecar_Click(e); return true;}
		if (btAgain.IsEvent(e, BN_CLICKED)) {btAgain_Click(e); return true;}
		return false;
	}
};
