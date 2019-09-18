#pragma once
#include <vector>
#include <time.h>
#include <cstdlib>
#include <math.h>
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
class CObjeto
{
protected:
	int x, y, ancho, alto, ix, iy, dx, dy, n_img, distanciaT;
	virtual void Dibujar(BufferedGraphics^ buffer, Bitmap^ img) {}
public:
	int getX() { return this->x; }
	int getY() { return  this->y; }
	int getAncho() { return this->ancho; }
	int getAlto() { return  this->alto; }
	int getDistancia(int posicionX, int posicionY)
	{
		return pow(pow(this->x - posicionX, 2) + pow(this->y - posicionY, 2), 0.5);
	}
};