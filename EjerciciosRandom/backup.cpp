#include "stdafx.h"  //________________________________________ EjerciciosRandom.cpp
#include "EjerciciosRandom.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR cmdLine, int cmdShow) {
	EjerciciosRandom app;
	return app.BeginDialog(IDI_EjerciciosRandom, hInstance);
}

void EjerciciosRandom::Window_Open(Win::Event& e)
{
	this->tbxMaximo.DoubleValue = 10.0;
	this->tbxMinimo.DoubleValue = 0.0;
	this->radioEntero.Checked = true;
	this->radioDouble.Checked = false;
	//________________________________________________________ spnContador
	//spnContador.SetBuddy(tbxNumber);
	//spnContador.SetBuddy(tbxContador);
	spnContador.SetRange(1, 100);
	//tbxContador.IntValue = 5;
}

void EjerciciosRandom::btGenerar_Click(Win::Event& e)
{
	tbxSalida.IntValue = rand();

}

