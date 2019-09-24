#pragma once
#include <vector>
#include <time.h>
#include <cstdlib>
#include <math.h>
#include "CSoldado.h"
#include "CBombas.h"
#include "CMapa.h"
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

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
		//sold->decrecer();
	}
#pragma endregion

};