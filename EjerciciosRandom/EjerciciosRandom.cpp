#include "stdafx.h"  //________________________________________ EjerciciosRandom.cpp
#include "EjerciciosRandom.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR cmdLine, int cmdShow) {
	EjerciciosRandom app;
	return app.BeginDialog(IDI_EjerciciosRandom, hInstance);
}

void EjerciciosRandom::Window_Open(Win::Event& e)
{
	this->tbxMean.DoubleValue = 40.0;
	this->tbxVarianza.DoubleValue = 5.0;
	//________________________________________________________ hist1
	valarray<double> data1(1024);
	for (int i1 = 0; i1<1024; i1++) data1[i1] = 1 + (int)(100.0*rand() / (RAND_MAX + 1.0));
	hist1.SetData(data1, 100, false);
	hist1.MinX = 0.0;
	hist1.MaxX = 100.0;
	hist1.MinY = 0.0;
	hist1.MaxY = 40.0;
	hist1.CaptionY = L"Frequency";
}
void EjerciciosRandom::RefreshHistograma()
{
	valarray<double>data(2000);
	const double mean = tbxMean.DoubleValue;
	const double varianza = tbxVarianza.DoubleValue;
	if (varianza == 0)return;
	std::tr1::normal_distribution<double>distribution(mean, varianza);
	for (int i = 0; i < 2000; i++)
	{
		data[i] = distribution(randomGenerator);
	}
	hist1.MinX = mean - 20.0*sqrt(varianza);
	hist1.MaxX = mean + 20.0*sqrt(varianza);
	hist1.SetData(data, 100, false);
	hist1.MinY = 0.0;
	hist1.MaxY = 60.0;
	hist1.CaptionY = L"Frecuencia";

}



void EjerciciosRandom::tbxMean_Change(Win::Event& e)
{
	RefreshHistograma();
}

void EjerciciosRandom::tbxVarianza_Change(Win::Event& e)
{
	RefreshHistograma();
}

