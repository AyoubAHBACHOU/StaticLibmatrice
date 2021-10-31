#include "pch.h"
#include "matrice.h"
#include <iostream>
#include <assert.h>
using namespace geo;
using namespace std;


geo::Matrice::Matrice(unsigned int l, unsigned int c)
{
	this->lig = l;
	this->col = c;
	this->mat = new float* [l];
	for (int i = 0; i < l; i++) this->mat[i] = new float[c];
	assert(l > 0 && c > 0);
	try
	{
		if (l < 0 || c < 0) throw "nombre ligne et nmbr col doit etre +";
	}
	catch (char* e)
	{
		cout << e<<endl;
	}

	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < c; j++)
		{
			this->mat[i][j] = 0;
		}
	}
}


void geo::Matrice::remplissage(float v)
{
	for (int i = 0; i < this->lig; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->mat[i][j] = v;
		}
	}
}

Matrice& geo::Matrice::operator+(const Matrice& m) const
{
	
	assert(this->col==m.col && this->lig==m.col);
	try
	{
		if (this->col != m.col && this->lig != m.col) throw "les deux matrices doivent avoir la meme dimension";
		Matrice* res=new Matrice(this->lig,this->col);
		for (int i = 0; i < this->lig; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				res->mat[i][j]=this->mat[i][j] + m.mat[i][j];
			}
		}
		return *res;
	}
	catch (char* e)
	{
		cout << e << endl;
	}


}

Matrice& geo::Matrice::operator-(const Matrice& m) const
{
	assert(this->col == m.col && this->lig == m.col);
	try
	{
		if (this->col != m.col && this->lig != m.col) throw "les deux matrices doivent avoir la meme dimension";
		Matrice* res = new Matrice(this->lig, this->col);
		for (int i = 0; i < this->lig; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				res->mat[i][j] = this->mat[i][j] - m.mat[i][j];
			}
		}
		return *res;
	}
	catch (char* e)
	{
		cout << e << endl;
	}
}

void geo::Matrice::print() const
{
	for (int i = 0; i < this->lig; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			
			cout << this->mat[i][j] << "\t";
			
		}
		cout << endl;
	}
}

Matrice& geo::Matrice::operator*(const Matrice& R) const
{
	assert(this->col == R.lig);

	Matrice* res = new Matrice(this->lig, R.col);
	for (int i = 0; i < res->lig; i++)
	{
		for (int j = 0; j < res->col; j++)
		{
			//res->mat[i][j] = 0;
			for (int k = 0; k < this->col; k++)
			{
				res->mat[i][j] += this->mat[i][k] * R.mat[k][i];
			}
		}
	}
	return *res;
}

Matrice& geo::Matrice::operator*(float k) const
{
	Matrice* res = new Matrice(this->lig,this->col);
	for (int i = 0; i < this->lig; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			res->mat[i][j] = k * this->mat[i][j];
		}
	}
	return*res;

}

Matrice& geo::Matrice::operator/(float k) const
{
	Matrice* res = new Matrice(this->lig, this->col);
	for (int i = 0; i < this->lig; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			res->mat[i][j] = this->mat[i][j]/k;
		}
	}
	return*res;
}

geo::Matrice::~Matrice()
{
	for (int i = 0; i < this->lig; i++)
		delete(this->mat[i]);
	delete (this->mat);
}
