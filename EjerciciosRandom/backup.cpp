#include "stdafx.h"  //________________________________________ EjerciciosRandom.cpp
#include "EjerciciosRandom.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE , LPTSTR cmdLine, int cmdShow){
	EjerciciosRandom app;
	return app.BeginDialog(IDI_EjerciciosRandom, hInstance);
}

void EjerciciosRandom::Window_Open(Win::Event& e)
{
}

void EjerciciosRandom::bt1_Click(Win::Event& e)
{
}

