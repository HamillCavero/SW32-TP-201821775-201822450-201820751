#pragma once
//#include <vector>
#include <time.h>
#include <cstdlib>
#include <math.h>
#include "CBomba.h"
#include "Lista.h"
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
//template <class T>
class CBombas
{
public:
	//vector<CBomba*>* bombas;
	List<CBomba*>* bombines;
	CBombas()
	{
		//bombas = new vector<CBomba*>;
		bombines = new List<CBomba*>;
	}
	~CBombas()
	{
		/*bombas->clear();
		delete bombas;*/
		//bombines->~List();
		delete bombines;
	}
	//int agregarVarias(Bitmap^ otrasImagnes, int ancho, int alto, int nivel)
	//{
	//	Random  r;
	//	//int n = r.Next(10 * pow(1.5, nivel - 1), 15 * pow(1.5, nivel - 1));
	//	int n = r.Next(10 * pow(1, nivel - 1), 15 * pow(1, nivel - 1));
	//	System::Threading::Thread::Sleep(5);
	//	for (int i = 0; i <= n; i++)
	//	{
	//		int t = r.Next(0, 3);
	//		System::Threading::Thread::Sleep(15);
	//		switch (t)
	//		{
	//		case 0: bombas->push_back(new CBomba(otrasImagnes, ancho, alto, 1, 1, nivel)); break;
	//		case 1: bombas->push_back(new CBomba(otrasImagnes, ancho, alto, 1, 2, nivel)); break;
	//		case 2: bombas->push_back(new CBomba(otrasImagnes, ancho, alto, 1, 3, nivel)); break;
	//		default:
	//			break;
	//		}
	//	}
	//	int M = r.Next(3, 6 + nivel);
	//	System::Threading::Thread::Sleep(5);
	//	for (int i = 0; i <= M; i++)
	//	{
	//		int t = r.Next(0, 2);
	//		System::Threading::Thread::Sleep(5);
	//		switch (t)
	//		{
	//		case 0: bombas->push_back(new CBomba(otrasImagnes, ancho, alto, 2, 4, nivel)); break;
	//		case 1: bombas->push_back(new CBomba(otrasImagnes, ancho, alto, 2, 5, nivel)); break;
	//		default:
	//			break;
	//		}
	//	}
	//	return n + M;
	//}

	int agregarVarias(Bitmap^ otrasImagnes, int ancho, int alto, int nivel)
	{
		Random  r;
		//int n = r.Next(10 * pow(1.5, nivel - 1), 15 * pow(1.5, nivel - 1));
		//int n = r.Next(10 * pow(1, nivel - 1), 15 * pow(1, nivel - 1));
		int n =5;
		System::Threading::Thread::Sleep(5);
		for (int i = 0; i < n; i++)
		{
			int t = r.Next(0, 3);
			System::Threading::Thread::Sleep(15);
			switch (t)
			{
			/*case 0: bombas->push_back(new CBomba(otrasImagnes, ancho, alto, 1, 1, nivel)); break;
			case 1: bombas->push_back(new CBomba(otrasImagnes, ancho, alto, 1, 2, nivel)); break;
			case 2: bombas->push_back(new CBomba(otrasImagnes, ancho, alto, 1, 3, nivel)); break;*/
			case 0: bombines->addFirst(new CBomba(otrasImagnes, ancho, alto, 1, 1, nivel)); break;
			case 1: bombines->addFirst(new CBomba(otrasImagnes, ancho, alto, 1, 2, nivel)); break;
			case 2: bombines->addFirst(new CBomba(otrasImagnes, ancho, alto, 1, 3, nivel)); break;
			default:
				break;
			}
		}
		//int M = r.Next(3, 6 + nivel);
		int M =0;
		System::Threading::Thread::Sleep(5);
		for (int i = 0; i < M; i++)
		{
			int t = r.Next(0, 2);
			System::Threading::Thread::Sleep(5);
			switch (t)
			{
			/*case 0: bombas->push_back(new CBomba(otrasImagnes, ancho, alto, 2, 4, nivel)); break;
			case 1: bombas->push_back(new CBomba(otrasImagnes, ancho, alto, 2, 5, nivel)); break;*/
			case 0: bombines->addFirst(new CBomba(otrasImagnes, ancho, alto, 2, 4, nivel)); break;
			case 1: bombines->addFirst(new CBomba(otrasImagnes, ancho, alto, 2, 5, nivel)); break;
			default:
				break;
			}
		}
		return n + M;
	}

	////constructor obsoleto
	////int agregarVarias(Bitmap^ bomba, Bitmap^ bomba2, Bitmap^ bomba3, Bitmap^ enemigo_grande1, Bitmap^ enemigo_grande2, int ancho, int alto, int nivel)
	////{
	////	Random  r;
	////	int n = r.Next(10 * pow(1.5, nivel - 1), 15 * pow(1.5, nivel - 1));
	////	System::Threading::Thread::Sleep(5);
	////	for (int i = 0; i <= n; i++)
	////	{
	////		int t = r.Next(0, 3);
	////		System::Threading::Thread::Sleep(15);
	////		switch (t)
	////		{
	////		case 0: bombas->push_back(new CBomba(bomba, ancho, alto, 1, 1, nivel)); break;
	////		case 1: bombas->push_back(new CBomba(bomba2, ancho, alto, 1, 2, nivel)); break;
	////		case 2: bombas->push_back(new CBomba(bomba3, ancho, alto, 1, 3, nivel)); break;
	////		default:
	////			break;
	////		}
	////	}
	////	int M = r.Next(3, 6 + nivel);
	////	System::Threading::Thread::Sleep(5);
	////	for (int i = 0; i <= n; i++)
	////	{
	////		int t = r.Next(0, 2);
	////		System::Threading::Thread::Sleep(5);
	////		switch (t)
	////		{
	////		case 0: bombas->push_back(new CBomba(enemigo_grande1, ancho, alto, 2, 4, nivel)); break;
	////		case 1: bombas->push_back(new CBomba(enemigo_grande2, ancho, alto, 2, 5, nivel)); break;
	////		default:
	////			break;
	////		}
	////	}
	////	return n + M;
	////}

	//void disparar(vector<Bala*>* VecBala)
	//{
	//	int n = rand() % bombas->size();
	//	if (bombas->at(n)->getTipo() == 2)
	//	{
	//		bombas->at(n)->Disparar(VecBala);
	//	}
	//}

	void disparar(vector<Bala*>* VecBala)
	{
		int n = rand() % (bombines->size())+1;
		//int n =0;
		if (bombines->obtenerPos(n)->getTipo() ==2)
		{
			bombines->obtenerPos(n)->Disparar(VecBala);
		}
	}

	//bool borrarBomba(CSoldado* sold)
	//{
	//	for (int i = 0; i < bombas->size(); i++)
	//	{
	//		if (bombas->at(i)->choque(sold)) {
	//			bombas->erase(bombas->begin() + i);
	//			return true;
	//		}
	//	}
	//	return false;
	//}
	bool borrarBomba(CSoldado* sold)
	{
		for (int i =1; i < bombines->size(); i++)
		{
			if (bombines->obtenerPos(i)->choque(sold))
			{
				bombines->delPos(i);
				return true;
			}
		}
		return false;
	}

	//bool limpiarBomba(CSoldado* player)
	//{
	//	for (int i = 0; i < bombas->size(); i++)
	//	{
	//		if (bombas->at(i)->getVida() <= 0)
	//		{
	//			//player->crecer(bombas->at(i)->getTipo());

	//			borrarBomba(i);
	//			return true;
	//		}
	//	}
	//	return false;
	//}
	bool limpiarBomba(CSoldado* player)
	{
		for (int i = 1; i < bombines->size(); i++)
		{
			if (bombines->obtenerPos(i)->getVida() <= 0)
			{
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

	//void borrarBomba(int i)
	//{
	//	bombas->erase(bombas->begin() + i);
	//}
	void borrarBomba(int i)
	{
		bombines->delPos(i);
	}

	//void borrarTodos()
	//{
	//	for (int i = 0; i < bombas->size(); i++)
	//	{
	//		bombas->clear();
	//	}
	//}
	void borrarTodos()
	{
		bombines->juicio();
	}

	/*void moverBombas(int jugadorX, int jugadory, int LimiAncho, int LimiAlto)
	{
		for (int i = 0; i < bombas->size(); i++)
		{
			bombas->at(i)->Mover(jugadorX, jugadory, LimiAncho, LimiAlto);
		}
	}*/
	void moverBombas(int jugadorX, int jugadory, int LimiAncho, int LimiAlto)
	{
		for (int i = 1; i < bombines->size(); i++)
		{
			bombines->obtenerPos(i)->Mover(jugadorX, jugadory, LimiAncho, LimiAlto);
		}
	}

	/*void DibujarBombas(BufferedGraphics^ buffer, Bitmap^enemigos)
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
	}*/
	void DibujarBombas(BufferedGraphics^ buffer, Bitmap^enemigos)
	{
		for (int i =1; i < bombines->size(); i++)
		{
			switch (bombines->obtenerPos(i)->getMascara())
			{
			case 1:bombines->obtenerPos(i)->Dibujar(buffer, enemigos, 0, 0); break;
			case 2:bombines->obtenerPos(i)->Dibujar(buffer, enemigos, 1, 0); break;
			case 3:bombines->obtenerPos(i)->Dibujar(buffer, enemigos, 2, 0); break;
			case 4:bombines->obtenerPos(i)->Dibujar(buffer, enemigos, 1, 1); break;
			case 5:bombines->obtenerPos(i)->Dibujar(buffer, enemigos, 3, 1); break;
			default:
				break;
			}

		}
	}

	/*bool colisionBala(Bala* baaa)
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
	}*/
	bool colisionBala(Bala* baaa)
	{
		for (int i = 1; i < bombines->size(); i++)
		{
			if (bombines->obtenerPos(i)->choque(baaa) && baaa->getTipo() == 1)
			{
				bombines->obtenerPos(i)->setVida();
				return true;
			}
		}
		return false;
	}
};
