#pragma once
//#include <vector>
#include <time.h>
#include <cstdlib>
#include <math.h>
//#include "CObjeto.h"
#include "CBala.h"
#include "CSoldado.h"
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class CBomba : public CObjeto
{
	int tipo;
	int modelo;
	int velocidad;
	int vidas;
	int vida_actual;
public:
	CBomba(Bitmap^ img, int anchoP, int altoP, int tipo, int modelo, int nivel) : CObjeto()
	{
		this->ancho = img->Width;
		this->alto = img->Height;
		System::Threading::Thread::Sleep(10);
		this->x = rand() % (anchoP);
		System::Threading::Thread::Sleep(10);
		this->y = rand() % (altoP);
		if (x < 74 && y < 74)
		{
			x += 300;
			y += 300;
		}
		dx = 10;
		dy = 10;
		this->tipo = tipo;
		this->modelo = modelo;
		velocidad = 20;
		if (tipo == 1)
		{
			vida_actual = vidas = 1 + nivel;
		}
		else if (tipo == 2)
		{
			velocidad = 5;
			vida_actual = vidas = 9 + nivel;
		}
	}
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ img, int iX, int iY)
	{
		if (tipo == 1)
		{
			buffer->Graphics->DrawImage(img, Rectangle(x, y, ancho / 40, alto / 40), Rectangle(iX * 256, iY * 256, 256, 256), GraphicsUnit::Pixel);

		}
		else
		{
			buffer->Graphics->DrawImage(img, Rectangle(x, y, ancho / 10, alto / 10), Rectangle(iX * 256, iY * 256, 256, 256), GraphicsUnit::Pixel);

		}
	}
	void Mover(int jugadorX, int jugadorY, int LimiAncho, int LimiAlto)
	{
		if (tipo == 1)
		{
			int distancia = getDistancia(jugadorX, jugadorY);
			if (distancia <= 200 && distancia != 0)
			{
				if (jugadorX > x)
				{
					if (jugadorY > y)
					{
						dx = 5;
						dy = 5;
					}
					else if (jugadorY < y)
					{
						dx = 5;
						dy = -5;
					}
					else if (jugadorY == y)
					{
						dx = 5;
						dy = 0;
					}
				}
				if (jugadorX < x)
				{
					if (jugadorY > y)
					{
						dx = -5;
						dy = 5;
					}
					else if (jugadorY < y)
					{
						dx = -5;
						dy = -5;
					}
					else if (jugadorY == y)
					{
						dx = -5;
						dy = 0;
					}
				}
				if (jugadorX == x)
				{
					if (jugadorY > y)
					{
						dx = 0;
						dy = 5;
					}
					else if (jugadorY < y)
					{
						dx = 0;
						dy = -5;
					}
					else if (jugadorY == y)
					{
						dx = 0;
						dy = 0;
					}
				}
				x += dx * (abs(jugadorX - x)) / distancia;
				y += dy * (abs(jugadorY - y)) / distancia;
			}
			else //if(distancia>=200)
			{
				if (x - dx >= 0 || x + velocidad + ancho <= LimiAncho)
				{

					//x += (1 - rand() % 3)*dx;
					dx = velocidad * (1 - rand() % 3);
				}
				else if (x < 0)
				{
					//x += dx;
					dx = velocidad * 1;
				}
				else
				{
					//x -= dx;
					dx = velocidad * -1;
				}

				if (y - dy >= 0 || y + velocidad + alto <= LimiAlto)
				{
					//y += (1 - rand() % 3)*dy;
					dy = velocidad * (1 - rand() % 3);
				}
				else if (y < 0)
				{
					//y += dy;
					dy = velocidad * 1;
				}
				else
				{
					y -= dy;
					dy = velocidad * -1;
				}
				x += dx;
				y += dy;
			}
		}
		else if (tipo == 2)
		{
			int distancia = getDistancia(jugadorX, jugadorY);
			if (distancia <= 80 && distancia != 0)
			{
				if (jugadorX > x)
				{
					if (jugadorY > y)
					{
						dx = 5;
						dy = 5;
					}
					else if (jugadorY < y)
					{
						dx = 5;
						dy = -5;
					}
					else if (jugadorY == y)
					{
						dx = 5;
						dy = 0;
					}
				}
				if (jugadorX < x)
				{
					if (jugadorY > y)
					{
						dx = -5;
						dy = 5;
					}
					else if (jugadorY < y)
					{
						dx = -5;
						dy = -5;
					}
					else if (jugadorY == y)
					{
						dx = -5;
						dy = 0;
					}
				}
				if (jugadorX == x)
				{
					if (jugadorY > y)
					{
						dx = 0;
						dy = 5;
					}
					else if (jugadorY < y)
					{
						dx = 0;
						dy = -5;
					}
					else if (jugadorY == y)
					{
						dx = 0;
						dy = 0;
					}
				}
				x += dx * (abs(jugadorX - x)) / distancia;
				y += dy * (abs(jugadorY - y)) / distancia;
			}
			else //if(distancia>=80)
			{
				if (x - dx >= 0 || x + velocidad + ancho <= LimiAncho / 30)
				{

					//x += (1 - rand() % 3)*dx;
					dx = velocidad * (1 - rand() % 3);
				}
				else if (x < 0)
				{
					//x += dx;
					dx = velocidad * 1;
				}
				else
				{
					//x -= dx;
					dx = velocidad * -1;
				}

				if (y - dy >= 0 || y + velocidad + alto <= LimiAlto / 30)
				{
					//y += (1 - rand() % 3)*dy;
					dy = velocidad * (1 - rand() % 3);
				}
				else if (y < 0)
				{
					//y += dy;
					dy = velocidad * 1;
				}
				else
				{
					y -= dy;
					dy = velocidad * -1;
				}
				x += dx;
				y += dy;
			}
		}
	}
	void Disparar(vector<Bala*>* VecBala)
	{
		if (modelo == 5)
		{
			VecBala->push_back(new Bala(this->getX() + 128 / 20, this->getY() + 128 / 20, 3, 2));
			VecBala->push_back(new Bala(this->getX() + 128 / 20, this->getY() + 128 / 20, 4, 2));
		}
		if (modelo == 4)
		{
			VecBala->push_back(new Bala(this->getX() + 128 / 20, this->getY() + 128 / 20, 1, 2));
			VecBala->push_back(new Bala(this->getX() + 128 / 20, this->getY() + 128 / 20, 2, 2));
			VecBala->push_back(new Bala(this->getX() + 128 / 20, this->getY() + 128 / 20, 3, 2));
			VecBala->push_back(new Bala(this->getX() + 128 / 20, this->getY() + 128 / 20, 4, 2));
		}
	}
	bool choque(CSoldado* s)
	{
		if (Rectangle(x, y, ancho / 30, alto / 30).IntersectsWith(Rectangle(s->getX(), s->getY(), s->getAncho(), s->getAlto())))
		{
			s->setVida(2);
			this->vida_actual = -1;
			return true;
		}
		return false;
	}
	bool choque(Bala* b)
	{
		if (tipo == 1)
		{
			if (Rectangle(x, y, ancho / 40, alto / 40).IntersectsWith(Rectangle(b->getX(), b->getY(), b->getAncho(), b->getAlto())))
			{
				return true;
			}
		}
		else if (tipo == 2)
		{
			if (Rectangle(x, y, ancho / 10, alto / 10).IntersectsWith(Rectangle(b->getX(), b->getY(), b->getAncho(), b->getAlto())))
			{
				return true;
			}
		}
		return false;
	}
	int getVida() { return vida_actual; }
	void setVida() { vida_actual = vida_actual - 1; }
	int getTipo() { return tipo; }
	int getMascara() { return modelo; }
};
