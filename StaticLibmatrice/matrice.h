#pragma once
#include<iostream>
using namespace std;
namespace geo {
	class Matrice
	{
	private:
		unsigned int col;
		unsigned int lig;
		float** mat;
	public:
		Matrice(unsigned int l , unsigned int c );
		Matrice(const Matrice&) = delete;
		Matrice& operator=(const Matrice&) = delete;
		void remplissage(float v);
		Matrice& operator+(const Matrice& m) const;
		Matrice& operator-(const Matrice& m) const;
		void print() const;
		Matrice& operator*(const Matrice&)const;
		Matrice& operator*(float k)const;
		Matrice& operator/(float k)const;
		~Matrice();



	};
}

