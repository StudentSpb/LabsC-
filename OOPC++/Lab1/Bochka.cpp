#pragma once
#include "Bochka.h"
#include <iostream>

Bochka::Bochka(int volume, float spirt, Fluid fluid)
{
	if (spirt > 1)
	{
		std::cout << "Соддежание спирта должно быть в долях";
	}
	else
	{
		m_spirt = spirt;
		m_volume = volume;
		m_fluid = fluid;
	}
}

void Bochka::Pereliv(Bochka& bochka)
{
	
	bochka.SetVolume(-1);

	/*
	float coef = 0;
	float dilute = 0;
	switch (m_fluid)
	{
	case spirt:
		coef = 1 - m_spirt; //Содержание примесей в долях
		dilute = (m_volume*coef) / (m_volume - 1) - (bochka.m_spirt / (bochka.m_volume+1)); //сколько стало примесей после разбавления
		m_spirt = m_spirt - (dilute - (1 - m_spirt)); //содержание спирта в долях 
		break;
	case watet:
		m_spirt = m_spirt + bochka.GetConc() / m_volume;
		break;
	}
	*/
	m_spirt = ((m_spirt*m_volume) + (bochka.m_spirt * 1)) / (m_volume + 1);
	SetVolume(1);
}

float Bochka::GetConc() const
{
	return m_spirt;
}

void Bochka::SetVolume(int addVolume)
{
	m_volume = m_volume +addVolume;
}




