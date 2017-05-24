#include "stdafx.h"  //________________________________________ EjerciciosRandom.cpp
#include "EjerciciosRandom.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR cmdLine, int cmdShow) {
	EjerciciosRandom app;
	return app.BeginDialog(IDI_EjerciciosRandom, hInstance);
}

void EjerciciosRandom::Window_Open(Win::Event& e)
{
	tbxIntentos.IntValue = intentos;
	lb2.Text = L"Intentos por hacer: ";
	lb2.Text += Sys::Convert::ToString(5);
}



void EjerciciosRandom::btChecar_Click(Win::Event& e)
{
	int x=5;
	const int checar = tbxEntrada.IntValue;
	if (checar == randomNumber)
	{
		tbxEntrada.ShowBalloonTip(L"Busqueda de número",L"Acertastes al número", TTI_INFO);
	}
	else
	{
		
		intentos++;
		if (intentos == 5)
		{
			tbxEntrada.ShowBalloonTip(L"Busqueda de número", L"Intento Fallido Se terminaron tus intentos", TTI_ERROR);
			tbxIntentos.IntValue = intentos;
			x = x - intentos;
			lb2.Text = L"Intentos por hacer: ";
			lb2.Text += Sys::Convert::ToString(x);
			btChecar.Enabled = false;
		}
		else
		{
			tbxEntrada.ShowBalloonTip(L"Busqueda de número", L"Intento Fallido", TTI_ERROR);
			tbxIntentos.IntValue = intentos;
			x = x - intentos;
			lb2.Text = L"Intentos por hacer: ";
			lb2.Text += Sys::Convert::ToString(x);
		}

	}
}

void EjerciciosRandom::btAgain_Click(Win::Event& e)
{
	randomNumber = (int)(15.0*rand() / RAND_MAX);
	intentos = 0;
	tbxEntrada.Text = L"";
	tbxIntentos.IntValue = intentos;
	lb2.Text = L"Intentos por hacer: ";
	lb2.Text += Sys::Convert::ToString(5);
	btChecar.Enabled = true;
}

