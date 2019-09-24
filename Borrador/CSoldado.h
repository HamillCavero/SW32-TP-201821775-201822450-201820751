#pragma once
//#include <vector>
#include <time.h>
#include <cstdlib>
#include <math.h>
//#include "CObjeto.h"
#include "CBala.h"
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class CSoldado : public CObjeto
{
	int ancho_actual;
	int alto_actual;
	int vidas;
	int nivelactual;
#pragma region puntos de disparo
	int punto1X;
	int punto1Y;
	int punto2X;
	int punto2Y;
	int punto5X;
	int punto5Y;
	int punto6X;
	int punto6Y;
#pragma endregion
public:
	CSoldado(int anchoP, int altoP) : CObjeto()
	{
		x = anchoP / 2;
		y = altoP / 2;
		n_img = 16;
		ancho = 256;
		alto = 256;
		ix = 0;
		iy = 0;
		dx = 10;
		dy = 10;
		ancho_actual = ancho * 0.2; // / 1.5;;
		alto_actual = alto * 0.2; // / 1.5;
		vidas = 100;
		nivelactual = 1;
	}

	void crecer(int i)
	{
		if (ancho_actual <= 10 * ancho || alto_actual <= 10 * alto)
		{
			switch (i)
			{
			case 1:
				this->ancho_actual *= 1.05;
				this->alto_actual *= 1.05;
				break;
			case 2:
				this->ancho_actual *= 1.08;
				this->alto_actual *= 1.08;
				break;
			default:
				break;
			}
		}
	}
	void decrecer()
	{
		this->ancho_actual = ancho * 0.2;
		this->alto_actual = ancho * 0.2;
	}

	void selecimg(int angulo)
	{
		//1
		if (angulo >= 180 * 15 / 16 || angulo < 180 * -15 / 16)
		{
			ix = 0; iy = 0;
			punto1X = ancho_actual * 5 / 12;
			punto1Y = alto_actual * -1 / 12;

			punto2X = ancho_actual * -8 / 12;
			punto2Y = alto_actual * -1 / 12;

			punto5X = ancho_actual * 5 / 12;
			punto5Y = alto_actual * -3 / 12;
			punto6X = ancho_actual * 5 / 12;
			punto6Y = alto_actual * 2 / 12;
		}
		//2
		else  if (angulo >= 180 * 13 / 16 && angulo < 180 * 15 / 16)
		{
			ix = 1; iy = 0;
			punto1X = ancho_actual * 4 / 12;
			punto1Y = alto_actual * -3 / 12;

			punto2X = ancho_actual * -8 / 12;
			punto2Y = alto_actual * 3 / 12;

			punto5X = ancho_actual * 3 / 12;
			punto5Y = alto_actual * -5 / 12;
			punto6X = ancho_actual * 5 / 12;
			punto6Y = alto_actual * -1 / 12;
		}
		//3
		else  if (angulo >= 180 * 11 / 16 && angulo < 180 * 13 / 16)
		{
			ix = 2; iy = 0;
			punto1X = ancho_actual * 3 / 12;
			punto1Y = alto_actual * -4 / 12;

			punto2X = ancho_actual * -6 / 12;
			punto2Y = alto_actual * 4 / 12;

			punto5X = ancho_actual * 1 / 12;
			punto5Y = alto_actual * -6 / 12;
			punto6X = ancho_actual * 4 / 12;
			punto6Y = alto_actual * -3 / 12;
		}
		//4
		else  if (angulo >= 180 * 9 / 16 && angulo < 180 * 11 / 16)
		{
			ix = 3; iy = 0;
			punto1X = ancho_actual * 1 / 12;
			punto1Y = alto_actual * -5 / 12;

			punto2X = ancho_actual * -7 / 12;
			punto2Y = alto_actual * 5 / 12;

			punto5X = ancho_actual * -2 / 12;
			punto5Y = alto_actual * -6 / 12;
			punto6X = ancho_actual * 3 / 12;
			punto6Y = alto_actual * -5 / 12;
		}
		//5
		else  if (angulo >= 180 * 7 / 16 && angulo < 180 * 9 / 16)
		{
			ix = 0; iy = 1;
			punto1X = ancho_actual * -1 / 12;
			punto1Y = alto_actual * -7 / 12;

			punto2X = ancho_actual * -1 / 12;
			punto2Y = alto_actual * 6 / 12;

			punto5X = ancho_actual * -4 / 12;
			punto5Y = alto_actual * -7 / 12;
			punto6X = ancho_actual * 2 / 12;
			punto6Y = alto_actual * -7 / 12;
		}
		//6
		else  if (angulo >= 180 * 5 / 16 && angulo < 180 * 7 / 16)
		{
			ix = 1; iy = 1;
			punto1X = ancho_actual * -5 / 12;
			punto1Y = alto_actual * -6 / 12;
			punto2X = ancho_actual * 2 / 12;
			punto2Y = alto_actual * 6 / 12;
			punto5X = ancho_actual * -2 / 12;
			punto5Y = alto_actual * -7 / 12;
			punto6X = ancho_actual * -6 / 12;
			punto6Y = alto_actual * -4 / 12;
		}
		//7
		else  if (angulo >= 180 * 3 / 16 && angulo < 180 * 5 / 16)
		{
			ix = 2; iy = 1;
			punto1X = ancho_actual * -7 / 12;
			punto1Y = alto_actual * -6 / 12;
			punto2X = ancho_actual * 6 / 12;
			punto2Y = alto_actual * 6 / 12;
			punto5X = ancho_actual * -5 / 12;
			punto5Y = alto_actual * -7 / 12;
			punto6X = ancho_actual * -8 / 12;
			punto6Y = alto_actual * -4 / 12;
		}
		//8
		else  if (angulo >= 180 * 1 / 16 && angulo < 180 * 3 / 16)
		{
			ix = 3; iy = 1;
			punto1X = ancho_actual * -7 / 12;
			punto1Y = alto_actual * -5 / 12;
			punto2X = ancho_actual * 6 / 12;
			punto2Y = alto_actual * 3 / 12;
			punto5X = ancho_actual * -5 / 12;
			punto5Y = alto_actual * -2 / 12;
			punto6X = ancho_actual * -4 / 12;
			punto6Y = alto_actual * -7 / 12;
		}
		//9
		else  if (angulo >= 180 * -1 / 16 && angulo < 180 * 1 / 16)
		{
			ix = 0; iy = 2;
			punto1X = ancho_actual * -7 / 12;
			punto1Y = alto_actual * -1 / 12;

			punto2X = ancho_actual * 5 / 12;
			punto2Y = alto_actual * -1 / 12;

			punto5X = ancho_actual * -7 / 12;
			punto5Y = alto_actual * -3 / 12;
			punto6X = ancho_actual * -7 / 12;
			punto6Y = alto_actual * 2 / 12;
		}
		//10
		else  if (angulo >= 180 * -3 / 16 && angulo < 180 * -1 / 16)
		{
			ix = 1; iy = 2;
			punto1X = ancho_actual * -7 / 12;
			punto1Y = alto_actual * -0 / 12;
			punto2X = ancho_actual * 5 / 12;
			punto2Y = alto_actual * -3 / 12;
			punto5X = ancho_actual * -9 / 12;
			punto5Y = alto_actual * -3 / 12;
			punto6X = ancho_actual * -4 / 12;
			punto6Y = alto_actual * 3 / 12;
		}
		//11
		else  if (angulo >= 180 * -5 / 16 && angulo < 180 * -3 / 16)
		{
			ix = 2; iy = 2;
			punto1X = ancho_actual * -4 / 12;
			punto1Y = alto_actual * 1 / 12;
			punto2X = ancho_actual * 3 / 12;
			punto2Y = alto_actual * -5 / 12;
			punto5X = ancho_actual * -7 / 12;
			punto5Y = alto_actual * -2 / 12;
			punto6X = ancho_actual * -2 / 12;
			punto6Y = alto_actual * 3 / 12;
		}
		//12
		else  if (angulo >= 180 * -7 / 16 && angulo < 180 * -5 / 16)
		{
			ix = 3; iy = 2;
			punto1X = ancho_actual * -3 / 12;
			punto1Y = alto_actual * 4 / 12;
			punto2X = ancho_actual * 0 / 12;
			punto2Y = alto_actual * -8 / 12;
			punto5X = ancho_actual * -4 / 12;
			punto5Y = alto_actual * 3 / 12;
			punto6X = ancho_actual * -1 / 12;
			punto6Y = alto_actual * 5 / 12;
		}
		//13
		else  if (angulo >= 180 * -9 / 16 && angulo < 180 * -7 / 16)
		{
			ix = 0; iy = 3;
			punto1X = ancho_actual * -1 / 12;
			punto1Y = alto_actual * 5 / 12;

			punto2X = ancho_actual * -1 / 12;
			punto2Y = alto_actual * -6 / 12;

			punto5X = ancho_actual * -4 / 12;
			punto5Y = alto_actual * 5 / 12;
			punto6X = ancho_actual * 2 / 12;
			punto6Y = alto_actual * 5 / 12;
		}
		//14
		else  if (angulo >= 180 * -11 / 16 && angulo < 180 * -9 / 16)
		{
			ix = 1; iy = 3;
			punto1X = ancho_actual * -0 / 12;
			punto1Y = alto_actual * 5 / 12;
			punto2X = ancho_actual * -4 / 12;
			punto2Y = alto_actual * -6 / 12;
			punto5X = ancho_actual * -2 / 12;
			punto5Y = alto_actual * 7 / 12;
			punto6X = ancho_actual * 4 / 12;
			punto6Y = alto_actual * 4 / 12;
		}
		//15
		else  if (angulo >= 180 * -13 / 16 && angulo < 180 * -11 / 16)
		{
			ix = 2; iy = 3;
			punto1X = ancho_actual * 2 / 12;
			punto1Y = alto_actual * 4 / 12;
			punto2X = ancho_actual * -6 / 12;
			punto2Y = alto_actual * -5 / 12;
			punto5X = ancho_actual * 1 / 12;
			punto5Y = alto_actual * 5 / 12;
			punto6X = ancho_actual * 5 / 12;
			punto6Y = alto_actual * 3 / 12;
		}
		//16
		else  if (angulo >= 180 * -15 / 16 && angulo < 180 * -13 / 16)
		{
			ix = 3; iy = 3;
			punto1X = ancho_actual * 4 / 12;
			punto1Y = alto_actual * 2 / 12;

			punto2X = ancho_actual * -8 / 12;
			punto2Y = alto_actual * -3 / 12;
			punto5X = ancho_actual * 6 / 12;
			punto5Y = alto_actual * 0 / 12;
			punto6X = ancho_actual * 3 / 12;
			punto6Y = alto_actual * 4 / 12;
		}

	}
	void Disparar(vector<Bala*>* VecBala, int dirX, int dirY, int nivel, int AnchoP, int AltoP)
	{
		nivelactual = nivel;
		switch (nivelactual)
		{
		case 1:
			VecBala->push_back(new Bala(getX() + getAncho() / 2, getY() + getAlto() / 2, punto1X, punto1Y, dirX, dirY, 1));
			break;
		case 2:
			VecBala->push_back(new Bala(getX() + getAncho() / 2, getY() + getAlto() / 2, punto1X, punto1Y, dirX, dirY, 1));
			if (dirX >= getX())
			{
				if (dirY >= getY())
				{
					VecBala->push_back(new Bala(getX() + getAncho() / 2, getY() + getAlto() / 2, punto2X, punto2Y, getX() - abs(dirX - (getX() + getAncho() / 2)), getY() - abs(dirY - (getY() + getAlto() / 2)), 1));
				}
				else
				{
					VecBala->push_back(new Bala(getX() + getAncho() / 2, getY() + getAlto() / 2, punto2X, punto2Y, getX() - abs(dirX - (getX() + getAncho() / 2)), getY() + abs(dirY - (getY() + getAlto() / 2)), 1));
				}
			}
			else
			{
				if (dirY >= getY())
				{
					VecBala->push_back(new Bala(getX() + getAncho() / 2, getY() + getAlto() / 2, punto2X, punto2Y, getX() + abs(dirX - (getX() + getAncho() / 2)), getY() - abs(dirY - (getY() + getAlto() / 2)), 1));
				}
				else
				{
					VecBala->push_back(new Bala(getX() + getAncho() / 2, getY() + getAlto() / 2, punto2X, punto2Y, getX() + abs(dirX - (getX() + getAncho() / 2)), getY() + abs(dirY - (getY() + getAlto() / 2)), 1));
				}
			}
			break;
		case 3:
			VecBala->push_back(new Bala(getX() + getAncho() / 2, getY() + getAlto() / 2, punto6X, punto6Y, dirX, dirY, 1));
			VecBala->push_back(new Bala(getX() + getAncho() / 2, getY() + getAlto() / 2, punto5X, punto5Y, dirX, dirY, 1));
			break;
		case 4:
			VecBala->push_back(new Bala(getX() + getAncho() / 2, getY() + getAlto() / 2, punto1X, punto1Y, dirX, dirY, 1));
			VecBala->push_back(new Bala(getX() + getAncho() / 2, getY() + getAlto() / 2, punto6X, punto6Y, dirX, dirY, 1));
			VecBala->push_back(new Bala(getX() + getAncho() / 2, getY() + getAlto() / 2, punto5X, punto5Y, dirX, dirY, 1));
			break;
		case 5:
			VecBala->push_back(new Bala(getX() + getAncho() / 2, getY() + getAlto() / 2, punto1X, punto1Y, dirX, dirY, 1));
			VecBala->push_back(new Bala(getX() + getAncho() / 2, getY() + getAlto() / 2, punto6X, punto6Y, dirX, dirY, 1));
			VecBala->push_back(new Bala(getX() + getAncho() / 2, getY() + getAlto() / 2, punto5X, punto5Y, dirX, dirY, 1));

			if (dirX >= getX())
			{
				if (dirY >= getY())
				{
					VecBala->push_back(new Bala(getX() + getAncho() / 2, getY() + getAlto() / 2, punto2X, punto2Y, getX() - abs(dirX - (getX() + getAncho() / 2)), getY() - abs(dirY - (getY() + getAlto() / 2)), 1));
				}
				else
				{
					VecBala->push_back(new Bala(getX() + getAncho() / 2, getY() + getAlto() / 2, punto2X, punto2Y, getX() - abs(dirX - (getX() + getAncho() / 2)), getY() + abs(dirY - (getY() + getAlto() / 2)), 1));
				}
			}
			else
			{
				if (dirY >= getY())
				{
					VecBala->push_back(new Bala(getX() + getAncho() / 2, getY() + getAlto() / 2, punto2X, punto2Y, getX() + abs(dirX - (getX() + getAncho() / 2)), getY() - abs(dirY - (getY() + getAlto() / 2)), 1));
				}
				else
				{
					VecBala->push_back(new Bala(getX() + getAncho() / 2, getY() + getAlto() / 2, punto2X, punto2Y, getX() + abs(dirX - (getX() + getAncho() / 2)), getY() + abs(dirY - (getY() + getAlto() / 2)), 1));
				}
			}
			break;
		default:
			break;
		}
	}
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ img, float angulo) {
		selecimg(angulo);
		buffer->Graphics->DrawImage(img, Rectangle(x, y, ancho_actual, alto_actual), Rectangle(ix*ancho, iy*alto, ancho, alto), GraphicsUnit::Pixel);
	}
	void Mover(int tecla, int limitX, int limitY)
	{
		switch (tecla)
		{

		case 1: if (y - dy >= 0) { y -= dy; }; break;
		case 2: if (y + dy + alto_actual + 36 <= limitY) { y += dy; }break;
		case 3: if (x + dx + ancho_actual <= limitX) { x += dx; } break;
		case 4: if (x - dx >= 0) { x -= dx; } break;
		default: //iy = 0; ix = 2;
			break;
		}
	}
	bool choque(Bala* b)
	{
		if (b->getTipo() == 2)
		{
			if (Rectangle(x + ancho_actual / 4, y + alto_actual / 4, ancho_actual / 2, alto_actual / 2).IntersectsWith(Rectangle(b->getX(), b->getY(), b->getAncho(), b->getAlto())))
			{
				return true;
			}
		}
		return false;
	}
	void setVida(int daño_recibido) { vidas -= daño_recibido; }
	void iniciarVida(int _vida) { vidas = _vida; }
	int getVida() { return vidas; }
	void setPos(int limitX, int limitY) { x = limitX / 2; y = limitY / 2; }
	int getAlto() { return alto_actual; }
	int getAncho() { return ancho_actual; }
};