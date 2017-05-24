#pragma once  //______________________________________ EjerciciosRandom.h  
#include "Resource.h"
class EjerciciosRandom : public Win::Dialog
{
public:
	EjerciciosRandom()
	{
		srand(::GetTickCount());
	}
	~EjerciciosRandom()
	{
	}
protected:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Textbox tbxSalida;
	Win::Button btGenerar;
	Win::Label lb1;
	Win::Textbox tbxMinimo;
	Win::Label lb2;
	Win::Textbox tbxMaximo;
	Win::Label lb3;
	Win::Label lb4;
	Win::Button radioEntero;
	Win::Button radioDouble;
	Win::Label lb5;
	Win::Spin spnContador;
	Win::Textbox tbxContador;
protected:
	Win::Gdi::Font fontArial014A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx = Sys::Convert::PixelToDlgUnitX(462);
		dlgTemplate.cy = Sys::Convert::PixelToDlgUnitY(265);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		this->Text = L"EjerciciosRandom";
		tbxSalida.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 312, 27, 143, 231, hWnd, 1000);
		btGenerar.Create(NULL, L"Generar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 218, 25, 89, 28, hWnd, 1001);
		lb1.Create(NULL, L"Minimo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 8, 25, 59, 25, hWnd, 1002);
		tbxMinimo.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 66, 25, 131, 25, hWnd, 1003);
		lb2.Create(NULL, L"Maximo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 7, 63, 59, 25, hWnd, 1004);
		tbxMaximo.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 65, 66, 132, 25, hWnd, 1005);
		lb3.Create(NULL, L"Rango", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 59, 0, 95, 17, hWnd, 1006);
		lb4.Create(NULL, L"Tipo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 65, 99, 100, 25, hWnd, 1007);
		radioEntero.Create(NULL, L"Entero", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 18, 141, 179, 26, hWnd, 1008);
		radioDouble.Create(NULL, L"Double", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 18, 167, 181, 26, hWnd, 1009);
		lb5.Create(NULL, L"Contador", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 9, 212, 68, 25, hWnd, 1010);
		spnContador.Create(NULL, NULL, WS_CHILD | WS_VISIBLE | UDS_ALIGNRIGHT | UDS_ARROWKEYS | UDS_SETBUDDYINT | UDS_WINVERT, 141, 213, 90, 24, hWnd, 1011);
		tbxContador.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 77, 213, 66, 25, hWnd, 1012);
		fontArial014A.Create(L"Arial", 14, false, false, false, false);
		tbxSalida.Font = fontArial014A;
		btGenerar.Font = fontArial014A;
		lb1.Font = fontArial014A;
		tbxMinimo.Font = fontArial014A;
		lb2.Font = fontArial014A;
		tbxMaximo.Font = fontArial014A;
		lb3.Font = fontArial014A;
		lb4.Font = fontArial014A;
		radioEntero.Font = fontArial014A;
		radioDouble.Font = fontArial014A;
		lb5.Font = fontArial014A;
		tbxContador.Font = fontArial014A;
	}
	//_________________________________________________
	void btGenerar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btGenerar.IsEvent(e, BN_CLICKED)) { btGenerar_Click(e); return true; }
		return false;
	}
};
