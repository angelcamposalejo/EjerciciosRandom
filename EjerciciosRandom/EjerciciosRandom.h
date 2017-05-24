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
	std::tr1::mt19937 randomGenerator;
	void RefreshHistograma();
protected:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lb1;
	Win::Textbox tbxMean;
	Win::Label lb2;
	Win::Textbox tbxVarianza;
	Win::Histogram hist1;
protected:
	Win::Gdi::Font fontArial014A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx = Sys::Convert::PixelToDlgUnitX(449);
		dlgTemplate.cy = Sys::Convert::PixelToDlgUnitY(402);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		this->Text = L"EjerciciosRandom";
		lb1.Create(NULL, L"Mean", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 9, 9, 87, 25, hWnd, 1000);
		tbxMean.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 95, 9, 124, 25, hWnd, 1001);
		lb2.Create(NULL, L"Varianza", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 250, 9, 84, 25, hWnd, 1002);
		tbxVarianza.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 332, 8, 98, 25, hWnd, 1003);
		hist1.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_VISIBLE, 7, 50, 435, 345, hWnd, 1004);
		fontArial014A.Create(L"Arial", 14, false, false, false, false);
		lb1.Font = fontArial014A;
		tbxMean.Font = fontArial014A;
		lb2.Font = fontArial014A;
		tbxVarianza.Font = fontArial014A;
		hist1.Font = fontArial014A;
	}
	//_________________________________________________
	void tbxMean_Change(Win::Event& e);
	void tbxVarianza_Change(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (tbxMean.IsEvent(e, EN_CHANGE)) { tbxMean_Change(e); return true; }
		if (tbxVarianza.IsEvent(e, EN_CHANGE)) { tbxVarianza_Change(e); return true; }
		return false;
	}
};
