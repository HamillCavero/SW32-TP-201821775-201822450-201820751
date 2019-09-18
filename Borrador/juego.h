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

class Mapa :public CObjeto
{
public:
	Mapa() : CObjeto() {}
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ img, Rectangle tmñ)
	{
		buffer->Graphics->DrawImage(img, tmñ);
	}
};

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
			if (distancia <= 200&&distancia!=0)
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
			if (distancia <= 80&&distancia!=0)
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

class CBombas 
{
public:
	vector<CBomba*>* bombas;
	CBombas() 
	{
		bombas = new vector<CBomba*>;
	}
	~CBombas()
	{
		bombas->clear();
		delete bombas;
	}
	int agregarVarias(Bitmap^ otrasImagnes, int ancho, int alto, int nivel)
	{
		Random  r;
		int n = r.Next(10 * pow(1.5, nivel - 1), 15 * pow(1.5, nivel - 1));
		System::Threading::Thread::Sleep(5);
		for (int i = 0; i <= n; i++)
		{
			int t = r.Next(0, 3);
			System::Threading::Thread::Sleep(15);
			switch (t)
			{
			case 0: bombas->push_back(new CBomba(otrasImagnes, ancho, alto, 1, 1, nivel)); break;
			case 1: bombas->push_back(new CBomba(otrasImagnes, ancho, alto, 1, 2, nivel)); break;
			case 2: bombas->push_back(new CBomba(otrasImagnes, ancho, alto, 1, 3, nivel)); break;
			default:
				break;
			}
		}
		int M = r.Next(3, 6 + nivel);
		System::Threading::Thread::Sleep(5);
		for (int i = 0; i <= M; i++)
		{
			int t = r.Next(0, 2);
			System::Threading::Thread::Sleep(5);
			switch (t)
			{
			case 0: bombas->push_back(new CBomba(otrasImagnes, ancho, alto, 2, 4, nivel)); break;
			case 1: bombas->push_back(new CBomba(otrasImagnes, ancho, alto, 2, 5, nivel)); break;
			default:
				break;
			}
		}
		return n + M;
	}

	int agregarVarias(Bitmap^ bomba, Bitmap^ bomba2, Bitmap^ bomba3, Bitmap^ enemigo_grande1, Bitmap^ enemigo_grande2, int ancho, int alto, int nivel)
	{
		Random  r;
		int n = r.Next(10 * pow(1.5, nivel - 1), 15 * pow(1.5, nivel - 1));
		System::Threading::Thread::Sleep(5);
		for (int i = 0; i <= n; i++)
		{
			int t = r.Next(0, 3);
			System::Threading::Thread::Sleep(15);
			switch (t)
			{
			case 0: bombas->push_back(new CBomba(bomba, ancho, alto, 1, 1, nivel)); break;
			case 1: bombas->push_back(new CBomba(bomba2, ancho, alto, 1, 2, nivel)); break;
			case 2: bombas->push_back(new CBomba(bomba3, ancho, alto, 1, 3, nivel)); break;
			default:
				break;
			}
		}
		int M = r.Next(3, 6 + nivel);
		System::Threading::Thread::Sleep(5);
		for (int i = 0; i <= n; i++)
		{
			int t = r.Next(0, 2);
			System::Threading::Thread::Sleep(5);
			switch (t)
			{
			case 0: bombas->push_back(new CBomba(enemigo_grande1, ancho, alto, 2, 4, nivel)); break;
			case 1: bombas->push_back(new CBomba(enemigo_grande2, ancho, alto, 2, 5, nivel)); break;
			default:
				break;
			}
		}
		return n + M;
	}

	void disparar(vector<Bala*>* VecBala)
	{
		int n = rand() % bombas->size();
		if (bombas->at(n)->getTipo() == 2)
		{
			bombas->at(n)->Disparar(VecBala);
		}

	}
	bool borrarBomba(CSoldado* sold)
	{
		for (int i = 0; i < bombas->size(); i++)
		{
			if (bombas->at(i)->choque(sold)) {
				bombas->erase(bombas->begin() + i);
				return true;
			}
		}
		return false;
	}
	bool limpiarBomba(CSoldado* player)
	{
		for (int i = 0; i < bombas->size(); i++)
		{
			if (bombas->at(i)->getVida() <= 0)
			{
				player->crecer(bombas->at(i)->getTipo());

				borrarBomba(i);
				return true;
			}
		}
		return false;
	}
	//void borrarBomba(int LimiAncho, int LimiAlto)
	//{
	//	for (int i = 0; i < bombas->size(); i++)
	//	{
	//		if (bombas->at(i)->getX() > LimiAncho || bombas->at(i)->getY() > LimiAlto)
	//		{
	//			borrarBomba(i);
	//		}
	//	}
	//}
	void borrarBomba(int i)
	{
		bombas->erase(bombas->begin() + i);
	}
	void borrarTodos()
	{
		for (int i = 0; i < bombas->size(); i++)
		{
			bombas->clear();
		}
	}
	void moverBombas(int jugadorX, int jugadory, int LimiAncho, int LimiAlto)
	{
		for (int i = 0; i < bombas->size(); i++)
		{
			bombas->at(i)->Mover(jugadorX, jugadory, LimiAncho, LimiAlto);
		}
	}
	void DibujarBombas(BufferedGraphics^ buffer, Bitmap^enemigos)
	{
		for (int i = 0; i < bombas->size(); i++)
		{
			switch (bombas->at(i)->getMascara())
			{
			case 1:bombas->at(i)->Dibujar(buffer, enemigos, 0, 0); break;
			case 2:bombas->at(i)->Dibujar(buffer, enemigos, 1, 0); break;
			case 3:bombas->at(i)->Dibujar(buffer, enemigos, 2, 0); break;
			case 4:bombas->at(i)->Dibujar(buffer, enemigos, 1, 1); break;
			case 5:bombas->at(i)->Dibujar(buffer, enemigos, 3, 1); break;
			default:
				break;
			}

		}
	}

	bool colisionBala(Bala* baaa)
	{
		for (int i = 0; i < bombas->size(); i++)
		{
			if (bombas->at(i)->choque(baaa) && baaa->getTipo() == 1)
			{
				bombas->at(i)->setVida();
				return true;
			}
		}
		return false;
	}
};

class Juego
{
#pragma region variables iniciales
	CSoldado* sold;
	Mapa* mapa;
	vector<Bala*>* VecBala;
	CBombas* hiroshima;
	int nivel = 1;
	bool pausa = true;
	int enemigosTotales;
	int enemigosRestantes;
#pragma endregion
public:
	Juego(Bitmap^ otrasImagnes, int anchoP, int altoP, int nivel)
	{
		this->nivel = nivel;
		sold = new CSoldado(anchoP, altoP);
		mapa = new Mapa();
		hiroshima = new CBombas();
		VecBala = new 	vector<Bala*>;
		enemigosTotales = AgregarVArias(otrasImagnes, anchoP, altoP);
		enemigosRestantes = enemigosTotales;
	}

	~Juego()
	{
		delete sold;
		delete mapa;
		VecBala->clear();
		delete VecBala;
		delete hiroshima;
	}

#pragma region crear, mover y destruir enemigos
	int  AgregarVArias(Bitmap^ otrasImagnes, int ancho, int alto)
	{
		return enemigosTotales = hiroshima->agregarVarias(otrasImagnes, ancho, alto, nivel);
	}
	void EnemigoDisparo() { hiroshima->disparar(VecBala); }
	void destruirBalas()
	{
		VecBala->clear();
	}
	void Eliminar(int LimiAncho, int LimiAlto)
	{
		if (hiroshima->borrarBomba(sold)) { enemigosRestantes--; }
		//hiroshima->borrarBomba(LimiAncho, LimiAlto);
		for (int j = 0; j < VecBala->size(); j++)
		{
			if (sold->choque(VecBala->at(j)))
			{
				VecBala->erase(VecBala->begin() + j);
				sold->setVida(2);
			}
		}
		for (int j = 0; j < VecBala->size(); j++)
		{
			if (hiroshima->colisionBala(VecBala->at(j))) { VecBala->erase(VecBala->begin() + j); }
			if (hiroshima->limpiarBomba(sold)) { enemigosRestantes--; }
		}
	}
	void EliminarTodos() { hiroshima->borrarTodos(); }
	void MoverEnemigos(int jugadorX, int jugadory, int LimiAncho, int LimiAlto)
	{
		hiroshima->moverBombas(jugadorX, jugadory, LimiAncho, LimiAncho);
	}
#pragma endregion

	void agregarbala(int intX, int intY, int anchoP, int altoP) { sold->Disparar(VecBala, intX, intY, nivel, anchoP, altoP); }
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ soldado, Bitmap^ mapita, Rectangle tmñn, Bitmap^objetos, float angulo)
	{
		mapa->Dibujar(buffer, mapita, tmñn);
		hiroshima->DibujarBombas(buffer, objetos);

		sold->Dibujar(buffer, soldado, angulo);

		for (int i = 0; i < VecBala->size(); i++)
		{
			VecBala->at(i)->Dibujar(buffer, objetos);
		}
	}
	void moverbala()
	{
		for (int i = 0; i < VecBala->size(); i++) { VecBala->at(i)->mover(); }
	}
	void MoverPersonaje(int tecla, int limitX, int limitY) { sold->Mover(tecla, limitX, limitY); }
	CSoldado* getSoldado() { return this->sold; }

#pragma region mover los niveles y pausar
	int getLvl() { return nivel; }

	void subirNivel(int LimiAncho, int LimiAlto) {
		if (nivel < 5)
		{
			nivel++;
			EliminarTodos();
			sold->setPos(LimiAncho, LimiAlto);
		}
		else { nivel = 6; }
	}

	bool getPausa() { return pausa; }

	void setPausa(bool x) { pausa = x; }

	int getEnemigosRestantes() { return enemigosRestantes; }

	void setEnemigosRestantes() { enemigosRestantes = enemigosTotales; }

	int getEnemigosTotales() { return enemigosTotales; }

	void reiniciar(Bitmap^ otrasImagenes, int ancho, int alto)
	{
		EliminarTodos();
		VecBala->clear();
		nivel = 1;
		enemigosTotales = AgregarVArias(otrasImagenes, ancho, alto);
		enemigosRestantes = enemigosTotales;
		sold->decrecer();
	}
#pragma endregion

};