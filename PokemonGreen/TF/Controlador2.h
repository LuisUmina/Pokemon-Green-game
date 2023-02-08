#pragma once
//vector
#include <vector>
using namespace std; 
//Fase 1
#include "Enemigo1Nivel2.h"
#include "Ash2.h"
#include "Pokebola.h"
//Fase 2
#include "Boss.h"
#include "BalaBoss.h"
#include "Aliado1Nivel2.h"
#include "BalaAliadoNivel2.h"
//Objetos
#include "Objeto.h"
//Archivo
#include "Archivo.h"


class Controlador2 {
private:
	//Fase 1
	Ash2* jugador;
	vector<Enemigo1Nivel2*> enemigos;
	vector<Pokebola*> balas;
	//Fase 2
	Boss* boss;
	vector<BalaBoss*> balasBoss;
	vector<Aliado1Nivel2*> aliado1Nivel2;
	vector<BalaAliadoNivel2*> BalasAliado;
	vector<Enemigo1Nivel2*> enemigos2;
	bool limiteAliados;
	//Objetos
	Objeto* barraVidas;
	Objeto* barraVidasBoss;
	Objeto* DatosJuegoNivel2;
	//Archivo
	Archivo* archivo;
	//Contadores
	int contPokebolas;
	int contBasurasSuelo;

public:
	Controlador2(Bitmap^ bmpJugador, Bitmap^ bmpBoss, Bitmap^ bmpBarraVidas, Bitmap^ bmpBarraVidasBoss, Bitmap^ bmpDatosJuegoNivel2) {
		jugador = new Ash2(bmpJugador->Width / 4, bmpJugador->Height / 4);
		//Fase 2
		boss = new Boss(bmpBoss->Width / 1, bmpBoss->Height / 1);
		limiteAliados = true;
		//Archivo
		archivo = new Archivo();
		asignarValoresArchivo();
		//Objetos
		barraVidas = new Objeto(0, 0, bmpBarraVidas->Width / 2, bmpBarraVidas->Height / 3, 0.5);
		barraVidasBoss = new Objeto(boss->getX(), boss->getY(), bmpBarraVidasBoss->Width / 2, bmpBarraVidasBoss->Height / 5, 0.5);
		DatosJuegoNivel2 = new Objeto(820, 0, bmpDatosJuegoNivel2->Width / 1, bmpDatosJuegoNivel2->Height / 1, 0.32);
		//Contadores
		contPokebolas = 0;
		contBasurasSuelo = 0;
	}
	~Controlador2() {}


	int getContPokebolas() { return contPokebolas; }
	int getContBasurasSuelo() { return contBasurasSuelo; }

	void setContPokebolas(int _contPokebolas) { contPokebolas = _contPokebolas; }
	void setContBasurasSuelo(int _contBasurasSuelo) { contBasurasSuelo = _contBasurasSuelo; }


	//Archivo
	void asignarValoresArchivo(){
		jugador->setX(archivo->getPosXnivel2());
		jugador->setY(archivo->getPosYnivel2());
	}

	//Validacion de vidas
	void validacionBarraVidas() {
		if (jugador->getVidas() == 5) {
			barraVidas->setIndX(0);
			barraVidas->setIndY(0);
		}
		if (jugador->getVidas() == 4) {
			barraVidas->setIndX(0);
			barraVidas->setIndY(1);
		}
		if (jugador->getVidas() == 3) {
			barraVidas->setIndX(0);
			barraVidas->setIndY(2);
		}
		if (jugador->getVidas() == 2) {
			barraVidas->setIndX(1);
			barraVidas->setIndY(0);
		}
		if (jugador->getVidas() == 1) {
			barraVidas->setIndX(1);
			barraVidas->setIndY(1);
		}
		if (jugador->getVidas() == 0) {
			barraVidas->setIndX(1);
			barraVidas->setIndY(2);
		}
	}
	void validacionBarraVidasBoss() {
		if (boss->getVidas() == 9) {
			barraVidasBoss->setIndX(0);
			barraVidasBoss->setIndY(0);
		}
		if (boss->getVidas() == 8) {
			barraVidasBoss->setIndX(0);
			barraVidasBoss->setIndY(1);
		}
		if (boss->getVidas() == 7) {
			barraVidasBoss->setIndX(0);
			barraVidasBoss->setIndY(2);
		}
		if (boss->getVidas() == 6) {
			barraVidasBoss->setIndX(0);
			barraVidasBoss->setIndY(3);
		}
		if (boss->getVidas() == 5) {
			barraVidasBoss->setIndX(0);
			barraVidasBoss->setIndY(4);
		}
		if (boss->getVidas() == 4) {
			barraVidasBoss->setIndX(1);
			barraVidasBoss->setIndY(0);
		}
		if (boss->getVidas() == 3) {
			barraVidasBoss->setIndX(1);
			barraVidasBoss->setIndY(1);
		}
		if (boss->getVidas() == 2) {
			barraVidasBoss->setIndX(1);
			barraVidasBoss->setIndY(2);
		}
		if (boss->getVidas() == 1) {
			barraVidasBoss->setIndX(1);
			barraVidasBoss->setIndY(3);
		}
		if (boss->getVidas() == 0) {
			barraVidasBoss->setIndX(1);
			barraVidasBoss->setIndY(4);
		}
	}

	void agregarBalas(Bitmap^ bmpBala) {//Agregar pokebolas
		if (contPokebolas < 80) {
			balas.push_back(new Pokebola(bmpBala->Width / 1, bmpBala->Height / 1, jugador->getX() + 20, jugador->getY()));
			contPokebolas++;
		}
	}

	//Fase1
	void agregarEnemigos(Bitmap^ bmpEnemigo) {
		enemigos.push_back(new Enemigo1Nivel2(bmpEnemigo->Width / 1, bmpEnemigo->Height / 1));
	}
	void dibujarTodo(Graphics^ g, Bitmap^ bmpJugador, Bitmap^ bmpEnemigo, Bitmap^ bmpBala, Bitmap^ bmpBarraVidas, Bitmap^ bmpDatosJuegoNivel2) {
		jugador->dibujar(g, bmpJugador);

		for (int i = 0; i < enemigos.size(); i++)
			enemigos[i]->dibujar(g, bmpEnemigo);

		for (int i = 0; i < balas.size(); i++)
			balas[i]->dibujar(g, bmpBala);

		barraVidas->dibujar(g, bmpBarraVidas);
		DatosJuegoNivel2->dibujar(g, bmpDatosJuegoNivel2);
	}
	void moverTodo(Graphics^ g) {
		for (int i = 0; i < enemigos.size(); i++)
			enemigos[i]->mover(g);

		for (int i = 0; i < balas.size(); i++)
			balas[i]->mover(g);
	}
	void colisionFase1() {


		//----------BALAS(POKEBOLAS) - BASURA
		//Verificacion de Colision basura con pokebolas
		for (int i = 0; i < balas.size(); i++) {
			for (int j = 0; j < enemigos.size(); j++) {
				if (balas[i]->getRectangle().IntersectsWith(enemigos[j]->getRectangle())) {
					balas[i]->setVisible(false);
					enemigos[j]->setVisible(false);
				}
			}
		}

		//----------ASH2 - BASURA
		//Verificacion de Colision basura con ash2
		for (int i = 0; i < enemigos.size(); i++)
		{
			if (jugador->getRectangle().IntersectsWith(enemigos[i]->getRectangle())) {
				enemigos[i]->setVisible(false);
				jugador->bajarVida();
				//Validando la barra de vidas
				validacionBarraVidas();
			}
		}

		//----------BASURA  -  SUELO
		//Verificacion de Basura contra el suelo
		for (int i = 0; i < enemigos.size(); i++)
		{
			if (enemigos[i]->getY() + enemigos[i]->getAlto() > 1080){
				enemigos[i]->setVisible(false);
				contBasurasSuelo++;
			}
		}

		//----------BALAS(POKEBOLAS) - TECHO
		//Verificacion de Colision pokebolas con la parte superior
		for (int i = 0; i < balas.size(); i++)
		{
			if (balas[i]->getY() < 0) {
				balas[i]->setVisible(false);
			}
		}





		//Eliminacion de las balas
		for (int i = 0; i < balas.size(); i++) {
			if (balas[i]->getVisible()==false) {
				balas.erase(balas.begin() + i);
			}
		}
		//Eliminacion de las basuras
		for (int j = 0; j < enemigos.size(); j++) {
			if (!enemigos[j]->getVisible()) {
				enemigos.erase(enemigos.begin() + j);
			}
		}

	}

	//Eliminar todo para cambio de fase
	void eliminarCambioFase() {
		//Validando eliminacion de basuras
		for (int i = 0; i < enemigos.size(); i++)
			enemigos[i]->setVisible(false);

		//Validando eliminacion de balas
		for (int i = 0; i < balas.size(); i++)
			balas[i]->setVisible(false);


		//Eliminacion de las balas
		for (int i = 0; i < balas.size(); i++) {
			if (!balas[i]->getVisible()) {
				balas.erase(balas.begin() + i);
			}
		}
		//Eliminacion de las basuras
		for (int j = 0; j < enemigos.size(); j++) {
			if (!enemigos[j]->getVisible()) {
				enemigos.erase(enemigos.begin() + j);
			}
		}
	}

	//Fase 2	
	void agregarEnemigos2(Bitmap^ bmpEnemigo2) {
		enemigos2.push_back(new Enemigo1Nivel2(bmpEnemigo2->Width / 1, bmpEnemigo2->Height / 1));
	}
	void agregarAliadoFase2(Bitmap^ bmpaliado1Nivel2) {
		if (limiteAliados) {
			aliado1Nivel2.push_back(new Aliado1Nivel2(bmpaliado1Nivel2->Width / 3, bmpaliado1Nivel2->Height / 4));
			limiteAliados = false;
		}
	}
	void agregarBalasBoss(Bitmap^ bmpBalaBoss) {
			balasBoss.push_back(new BalaBoss(bmpBalaBoss->Width / 1, bmpBalaBoss->Height / 4, boss->getX() + 60, boss->getY() + 170));
	}
	void agregarBalasAliadoNivel2(Bitmap^ bmpBalasAliado) {
		if (aliado1Nivel2.size() == 1) {
			BalasAliado.push_back(new BalaAliadoNivel2(bmpBalasAliado->Width / 7, bmpBalasAliado->Height / 1, aliado1Nivel2[0]->getX(), aliado1Nivel2[0]->getY() + 15));
		}
	}
	void dibujarTodoFase2(Graphics^ g, Bitmap^ bmpJugador, Bitmap^ bmpBoss, Bitmap^ bmpBalaBoss, Bitmap^ bmpBala, Bitmap^ bmpaliado1Nivel2, Bitmap^ bmpBalasAliado, Bitmap^ bmpBarraVidas, Bitmap^ bmpEnemigo2, Bitmap^ bmpBarraVidasBoss, Bitmap^ bmpDatosJuegoNivel2) {
		jugador->dibujar(g, bmpJugador);
		boss->dibujar(g, bmpBoss);

		for (int i = 0; i < balasBoss.size(); i++)
			balasBoss[i]->dibujar(g, bmpBalaBoss);

		for (int i = 0; i < balas.size(); i++)
			balas[i]->dibujar(g, bmpBala);

		for (int i = 0; i < aliado1Nivel2.size(); i++)
			aliado1Nivel2[i]->dibujar(g, bmpaliado1Nivel2);

		for (int i = 0; i < BalasAliado.size(); i++)
			BalasAliado[i]->dibujar(g, bmpBalasAliado);

		barraVidas->dibujar(g, bmpBarraVidas);

		for (int i = 0; i < enemigos2.size(); i++)
			enemigos2[i]->dibujar(g, bmpEnemigo2);

		barraVidasBoss->dibujar(g, bmpBarraVidasBoss);
		DatosJuegoNivel2->dibujar(g, bmpDatosJuegoNivel2);
	}
	void moverTodoFase2(Graphics^ g) {
		boss->mover(g);

		for (int i = 0; i < balasBoss.size(); i++)
			balasBoss[i]->mover(g);

		for (int i = 0; i < balas.size(); i++)
			balas[i]->mover(g);

		for (int i = 0; i < aliado1Nivel2.size(); i++)
			aliado1Nivel2[i]->mover(g);

		for (int i = 0; i < BalasAliado.size(); i++)
			BalasAliado[i]->mover(g);

		for (int i = 0; i < enemigos2.size(); i++)
			enemigos2[i]->mover(g);

		//moviendo barra de vida
		barraVidasBoss->setX(boss->getX());//posicion x de la barra = x actual del boss 
		barraVidasBoss->setY(boss->getY());

	}
	void colisionFase2() {

		//----------BALAS(POKEBOLAS) - BALAS DEL BOSS
		//Verificacion de Colision balas del boss con pokebolas
		for (int i = 0; i < balas.size(); i++) {
			for (int j = 0; j < balasBoss.size(); j++) {
				if (balas[i]->getRectangle().IntersectsWith(balasBoss[j]->getRectangle())) {
					balas[i]->setVisible(false);
					balasBoss[j]->setVisible(false);
				}
			}
		}

		//----------BALAS DEL BOSS - BALAS DEL ALIADO
		//Verificacion de Colision balas del boss con las del aliado
		for (int i = 0; i < BalasAliado.size(); i++) {
			for (int j = 0; j < balasBoss.size(); j++) {
				if (BalasAliado[i]->getRectangle().IntersectsWith(balasBoss[j]->getRectangle())) {
					BalasAliado[i]->setVisible(false);
					balasBoss[j]->setVisible(false);
				}
			}
		}

		//----------BALAS(POKEBOLAS) - TECHO
		//Verificacion de Colision pokebolas con la parte superior
		for (int i = 0; i < balas.size(); i++)
		{
			if (balas[i]->getY() < 0) {
				balas[i]->setVisible(false);
			}
		}

		//----------BALAS BOSS  -  SUELO
		//Verificacion de las balas del boss contra el suelo
		for (int i = 0; i < balasBoss.size(); i++)
		{
			if (balasBoss[i]->getY() + balasBoss[i]->getAlto() > 890) {
				balasBoss[i]->setVisible(false);
			}
		}

		//----------ASH2 - BALA BOSS
		//Verificacion de Colision blas balas del boss con ash2
		for (int i = 0; i < balasBoss.size(); i++)
		{
			if (jugador->getRectangle().IntersectsWith(balasBoss[i]->getRectangle())) {
				balasBoss[i]->setVisible(false);
				jugador->bajarVida();
				//Validando la barra de vidas
				validacionBarraVidas();
			}
		}

		//----------BALAS ALIADO  -  PARED IZQUIERDA
		//Verificacion de las balas del aliado contra la pared izquierda
		for (int i = 0; i < BalasAliado.size(); i++)
		{
			if (BalasAliado[i]->getX() < 1) {
				BalasAliado[i]->setVisible(false);
			}
		}

		//----------BALAS(POKEBOLAS) - BOSS
		//Verificacion de Colision de pokebolas con boss
		for (int i = 0; i < balas.size(); i++)
		{
			if (boss->getRectangle().IntersectsWith(balas[i]->getRectangle())) {
				balas[i]->setVisible(false);
				//Validacion de la vidas del boss
				boss->bajarVidaBoss();
				validacionBarraVidasBoss();
			}
		}

		//----------BASURA  -  SUELO
		//Verificacion de Basura contra el suelo
		for (int i = 0; i < enemigos2.size(); i++)
		{
			if (enemigos2[i]->getY() + enemigos2[i]->getAlto() > 1080) {
				enemigos2[i]->setVisible(false);
				contBasurasSuelo++;
			}
		}

		//----------BALAS(POKEBOLAS) - BASURA
		//Verificacion de Colision basura con pokebolas
		for (int i = 0; i < balas.size(); i++) {
			for (int j = 0; j < enemigos2.size(); j++) {
				if (balas[i]->getRectangle().IntersectsWith(enemigos2[j]->getRectangle())) {
					balas[i]->setVisible(false);
					enemigos2[j]->setVisible(false);
				}
			}
		}

		//----------ASH2 - BASURA
		//Verificacion de Colision basura con ash2
		for (int i = 0; i < enemigos2.size(); i++)
		{
			if (jugador->getRectangle().IntersectsWith(enemigos2[i]->getRectangle())) {
				enemigos2[i]->setVisible(false);
				jugador->bajarVida();
				//Validando la barra de vidas
				validacionBarraVidas();
			}
		}

		//----------BASURAS - BALAS DEL ALIADO
		//Verificacion de basuras con las balas del aliado
		for (int i = 0; i < BalasAliado.size(); i++) {
			for (int j = 0; j < enemigos2.size(); j++) {
				if (BalasAliado[i]->getRectangle().IntersectsWith(enemigos2[j]->getRectangle())) {
					BalasAliado[i]->setVisible(false);
					enemigos2[j]->setVisible(false);
				}
			}
		}




		//Eliminacion de las balas(pokebolas)
		for (int i = 0; i < balas.size(); i++) {
			if (!balas[i]->getVisible()) {
				balas.erase(balas.begin() + i);
			}
		}

		//Eliminacion de las balas del boss
		for (int i = 0; i < balasBoss.size(); i++) {
			if (!balasBoss[i]->getVisible()) {
				balasBoss.erase(balasBoss.begin() + i);
			}
		}

		//Eliminacion de las balas del aliado
		for (int i = 0; i < BalasAliado.size(); i++) {
			if (!BalasAliado[i]->getVisible()) {
				BalasAliado.erase(BalasAliado.begin() + i);
			}
		}

		//Eliminacion de las basuras
		for (int j = 0; j < enemigos2.size(); j++) {
			if (!enemigos2[j]->getVisible()) {
				enemigos2.erase(enemigos2.begin() + j);
			}
		}
	}

	Ash2* getAsh2() { return jugador; }
	Boss* getBoss() { return boss; }
};
