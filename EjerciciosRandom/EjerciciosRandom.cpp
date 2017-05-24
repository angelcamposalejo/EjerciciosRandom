#include "stdafx.h"  //________________________________________ EjerciciosRandom.cpp
#include "EjerciciosRandom.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR cmdLine, int cmdShow) {
	EjerciciosRandom app;
	return app.BeginDialog(IDI_EjerciciosRandom, hInstance);
}

void EjerciciosRandom::Window_Open(Win::Event& e)
{
	this->tbxMaximo.IntValue = 10;
	this->tbxMinimo.IntValue = 0;
	this->radioEntero.Checked = true;
	this->radioDouble.Checked = false;
	//________________________________________________________ spnContador
	//spnContador.SetBuddy(tbxNumber);
	spnContador.SetBuddy(tbxContador);
	spnContador.SetRange(1, 100);
	tbxContador.IntValue = 5;
}

void EjerciciosRandom::btGenerar_Click(Win::Event& e)
{
	tbxSalida.Text = L"";
	wstring texto;
	int contador = tbxContador.IntValue;
	for (int i = 0; i < contador; i++)
	{
		if (radioEntero.Checked == true)
		{
			int numero = rand() % ((tbxMaximo.IntValue + 1) - (tbxMinimo.IntValue));
			Sys::Format(texto, L"%d\r\n",numero);
			tbxSalida.Text += texto;
		}
		else
		{
			double numero = rand() % ((tbxMaximo.IntValue + 1) - (tbxMinimo.IntValue));
			Sys::Format(texto, L"%.2f\r\n", numero);
			tbxSalida.Text += texto;
		}
	}
	
	

}

