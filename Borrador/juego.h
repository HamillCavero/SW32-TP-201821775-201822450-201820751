#pragma once
//#include <vector>
#include <time.h>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <stdlib.h>
#include "CSoldado.h"
#include "CBombas.h"
#include "CMapa.h"
#include "CCola.h"
#include <sstream>

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
	CCola<int>* marcador;
	List<Bala*>* Balas_mundo;
	vector<Bala*>* VecBala;
	CBombas* hiroshima;
	int nivel = 1;
	bool pausa = true;
	int enemigosTotales;
	int enemigosRestantes;
	int score;
#pragma endregion
public:
	Juego(Bitmap^ otrasImagnes, int anchoP, int altoP, int nivel)
	{
		this->nivel = nivel;
		sold = new CSoldado(anchoP, altoP);
		mapa = new Mapa();
		score = 0;
		marcador = new CCola<int>;
		hiroshima = new CBombas();
		VecBala = new 	vector<Bala*>;
		Balas_mundo = new 	List<Bala*>;
		enemigosTotales = AgregarVArias(otrasImagnes, anchoP, altoP);
		enemigosRestantes = enemigosTotales;
		leer_score();
	}

	~Juego()
	{
		delete sold;
		delete mapa;
		VecBala->clear();
		delete VecBala;
		delete marcador;
		delete Balas_mundo;
		delete hiroshima;
	}

#pragma region crear, mover y destruir enemigos
	int  AgregarVArias(Bitmap^ otrasImagnes, int ancho, int alto)
	{
		return enemigosTotales = hiroshima->agregarVarias(otrasImagnes, ancho, alto, nivel);
	}
	int  AgregarALgunas(Bitmap^ otrasImagnes, int ancho, int alto)
	{
		return enemigosTotales = hiroshima->agregarAlgunas(otrasImagnes, ancho, alto);
	}

	//void EnemigoDisparo() { hiroshima->disparar(VecBala); }
	void EnemigoDisparo() { hiroshima->disparar(Balas_mundo); }
	/*void destruirBalas()
	{
		VecBala->clear();
	}*/
	void destruirBalas()
	{
		Balas_mundo->juicio();
	}
	//void Eliminar(int LimiAncho, int LimiAlto)
	//{
	//	if (hiroshima->borrarBomba(sold)) { enemigosRestantes--; }
	//	//hiroshima->borrarBomba(LimiAncho, LimiAlto);
	//	for (int j = 0; j < VecBala->size(); j++)
	//	{
	//		if (sold->choque(VecBala->at(j)))
	//		{
	//			VecBala->erase(VecBala->begin() + j);
	//			sold->setVida(2);
	//		}
	//	}
	//	for (int j = 0; j < VecBala->size(); j++)
	//	{
	//		if (hiroshima->colisionBala(VecBala->at(j))) { VecBala->erase(VecBala->begin() + j); }
	//		if (hiroshima->limpiarBomba(sold)) { enemigosRestantes--; }
	//	}
	//}
	void Eliminar(int LimiAncho, int LimiAlto)
	{
		if (hiroshima->borrarBomba(sold)) { enemigosRestantes--; }
		//hiroshima->borrarBomba(LimiAncho, LimiAlto);
		for (int j =1; j < Balas_mundo->size(); j++)
		{
			if (sold->choque(Balas_mundo->obtenerPos(j)))
			{
				Balas_mundo->delPos(j);
				sold->setVida(2);
			}
		}
		for (int j = 1; j < Balas_mundo->size(); j++)
		{
			if (hiroshima->colisionBala(Balas_mundo->obtenerPos(j))) { Balas_mundo->delPos(j); }
			if (hiroshima->limpiarBomba(score)) { enemigosRestantes--; score += 500; }
		}
	}
void EliminarTodos() { hiroshima->borrarTodos(); }
	void MoverEnemigos(int jugadorX, int jugadory, int LimiAncho, int LimiAlto)
	{
		hiroshima->moverBombas(jugadorX, jugadory, LimiAncho, LimiAncho);
	}
#pragma endregion
	//void agregarbala(int intX, int intY, int anchoP, int altoP) { sold->Disparar(VecBala, intX, intY, nivel, anchoP, altoP); }
	void agregarbala(int intX, int intY, int anchoP, int altoP) { sold->Disparar(Balas_mundo, intX, intY, nivel, anchoP, altoP);
	}
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ soldado, Bitmap^ mapita, Rectangle tmñn, Bitmap^objetos, float angulo)
	{
		mapa->Dibujar(buffer, mapita, tmñn);
		hiroshima->DibujarBombas(buffer, objetos);

		sold->Dibujar(buffer, soldado, angulo);

		for (int i = 1; i < Balas_mundo->size()-1; i++)
		{
			Balas_mundo->obtenerPos(i)->Dibujar(buffer, objetos);
		}
	}
	/*void Dibujar(BufferedGraphics^ buffer, Bitmap^ soldado, Bitmap^ mapita, Rectangle tmñn, Bitmap^objetos, float angulo)
	{
		mapa->Dibujar(buffer, mapita, tmñn);
		hiroshima->DibujarBombas(buffer, objetos);

		sold->Dibujar(buffer, soldado, angulo);

		for (int i = 0; i < VecBala->size(); i++)
		{
			VecBala->at(i)->Dibujar(buffer, objetos);
		}
	}*/
	void moverbala()
	{
		for (int i = 1; i < Balas_mundo->size()-1; i++) { Balas_mundo->obtenerPos(i)->mover(); }
	}
	/*void moverbala()
	{
		for (int i = 0; i < VecBala->size(); i++) { VecBala->at(i)->mover(); }
	}*/
	void MoverPersonaje(int tecla, int limitX, int limitY) { sold->Mover(tecla, limitX, limitY); }
	CSoldado* getSoldado() { return this->sold; }

#pragma region mover los niveles y pausar
	int getLvl() { return nivel; }
	int getScore() { return score; }
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
		//VecBala->clear();
		Balas_mundo->juicio();
		nivel = 1;
		enemigosTotales = AgregarVArias(otrasImagenes, ancho, alto);
		enemigosRestantes = enemigosTotales;
		//sold->decrecer();
	}
	void escribir()
	{
		ofstream archivopos;
		archivopos.open("Posicion.txt", ios::out);
		if (archivopos.fail()) 
		{
			exit(1);
		}
		archivopos << sold->getX() << "," << sold->getY();
		archivopos.close();
	}
	void leer_score()
	{
		ifstream marcadores;
		marcadores.open("Scores.txt", ios::in);

		string line;
		while (getline(marcadores, line)) {
			istringstream iss(line);
			string s;
			getline(iss, s, ',');
			int sscr = stoi(s);
			marcador->addFirst(sscr);
		}
		marcadores.close();
	}
	void escribir_Score()
	{
		marcador->addFirst(score);

		if (marcador->size()>6)
		{
			marcador->delLast();
		}

		ofstream archivo_score;
		archivo_score.open("Scores.txt", ios::out);
		if (archivo_score.fail())
		{
			exit(1);
		}
		for (int i =0; i < marcador->size(); i++)
		{
			if (i!=marcador->size())
			{
			archivo_score << marcador->obtenerPos(i) << ",";
			}
			else
			{
				archivo_score << marcador->obtenerPos(i );
			}
		}
		archivo_score.close();

	}
#pragma endregion

};