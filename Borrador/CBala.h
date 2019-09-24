#pragma once
#pragma once
//#include <vector>
#include <time.h>
#include <cstdlib>
#include <math.h>
#include"CObjeto.h"
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
class Bala :public CObjeto
{
protected:
	int dirección;
	int tipo; //para saber si es bala amiga o enemiga
	int px; int py;
public:
	Bala(int x, int y, int dirección, int _tipo) : CObjeto()
	{
		this->x = x;
		this->y = y;
		/*dx = 22;
		dy = 22;*/
		this->dirección = dirección;
		this->ancho = 30;
		this->alto = 30;
		this->tipo = _tipo;
		switch (dirección)
		{
		case 1:dx = 0; dy = -15; break;
		case 2:dx = 0; dy = 15; break;
		case 3:dx = -15; dy = 0; break;
		case 4:dx = 15; dy = 0; break;
		default:
			break;
		}
	}
	Bala(int _x, int _y, int offX, int offY, int intX, int intY, int _tipo) : CObjeto()
	{
		this->x = _x;
		this->y = _y;
		px = intX;
		py = intY;
		distanciaT = getDistancia(px, py);
		dx = 10 * (px - x) / distanciaT;
		dy = 10 * (py - y) / distanciaT;
		this->x = _x + offX;
		this->y = _y + offY;
		this->ancho = 15;
		this->alto = 15;
		this->tipo = _tipo;
	}
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ imagenes)override
	{
		if (tipo == 1)
		{
			buffer->Graphics->DrawImage(imagenes, Rectangle(x, y, ancho, alto), Rectangle(0 * 256, 2 * 256, 256, 256), GraphicsUnit::Pixel);
		}
		else if (tipo == 2)
		{
			buffer->Graphics->DrawImage(imagenes, Rectangle(x, y, ancho, alto), Rectangle(1 * 256, 2 * 256, 256, 256), GraphicsUnit::Pixel);
		}
	}
	void mover()
	{
		if (tipo == 1)
		{
			x += dx;
			y += dy;
		}
		else if (tipo == 2)
		{ //arriba abajo izquierda derecha

			x += dx;
			y += dy;
		}
	}
	int getTipo() { return tipo; }
};
