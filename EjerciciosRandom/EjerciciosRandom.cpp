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
}



