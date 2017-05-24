#pragma once  //______________________________________ EjerciciosRandom.h  
#include "Resource.h"
class EjerciciosRandom : public Win::Dialog
{
public:
	EjerciciosRandom()
	{
		randomGenerator.seed(::GetTickCount());
	}
	~EjerciciosRandom()
	{
	}
	std::tr1::minstd_rand randomGenerator;
protected:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Textbox tbxSalida;
protected:
	Win::Gdi::Font fontArial014A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx = Sys::Convert::PixelToDlgUnitX(162);
		dlgTemplate.cy = Sys::Convert::PixelToDlgUnitY(245);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		this->Text = L"EjerciciosRandom";
		tbxSalida.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 12, 7, 143, 231, hWnd, 1000);
		fontArial014A.Create(L"Arial", 14, false, false, false, false);
		tbxSalida.Font = fontArial014A;
	}
	//_________________________________________________
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		return false;
	}
};
