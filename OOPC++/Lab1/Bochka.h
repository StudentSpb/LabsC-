#pragma once
enum Fluid { watet, spirt };

class Bochka
{
private:
	float m_spirt;	//���������� ������ (� ���������)
	int m_volume;	// ����� (� ������)
	Fluid m_fluid;

public:
	Bochka(int volumne, float spirt, Fluid fluid);

	void Pereliv(Bochka& T); // ����� ������ "��������"
	void SetVolume(int addVolume);
	float GetConc() const;
	
};