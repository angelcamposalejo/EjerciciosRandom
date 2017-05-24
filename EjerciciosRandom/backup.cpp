#include "stdafx.h"  //________________________________________ EjerciciosRandom.cpp
#include "EjerciciosRandom.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR cmdLine, int cmdShow) {
	EjerciciosRandom app;
	return app.BeginDialog(IDI_EjerciciosRandom, hInstance);
}

void EjerciciosRandom::Window_Open(Win::Event& e)
{
	std::uniform_int<int>distribucion(0, 9);
	int x = 0;
	for (int i = 0; i < 10; i++)
	{
		x = distribucion(randomGenerator);
		tbxSalida.Text += Sys::Convert::ToString(x);
		tbxSalida.Text += L"\r\n";
	}
	//________________________________________________________ hist1
	valarray<double> data1(1024);
	for(int i1 = 0; i1<1024; i1++) data1[i1] = 1+(int) (100.0*rand()/(RAND_MAX+1.0));
	hist1.SetData(data1, 100, false);
	hist1.MinX = 0.0;
	hist1.MaxX = 100.0;
	hist1.MinY = 0.0;
	hist1.MaxY = 40.0;
	hist1.CaptionY = L"Frequency";
}



void EjerciciosRandom::tbxMean_Change(Win::Event& e)
{
}

