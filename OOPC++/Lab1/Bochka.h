#pragma once
enum Fluid { watet, spirt };

class Bochka
{
private:
	float m_spirt;	//количество спирта (в процентах)
	int m_volume;	// объем (в литрах)
	Fluid m_fluid;

public:
	Bochka(int volumne, float spirt, Fluid fluid);

	void Pereliv(Bochka& T); // метод класса "перелить"
	void SetVolume(int addVolume);
	float GetConc() const;
	
};