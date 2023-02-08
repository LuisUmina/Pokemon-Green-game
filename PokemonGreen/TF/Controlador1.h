#pragma once
//Vector
#include <vector>
using namespace std;

//Nivel 1
#include "Ash1.h"
#include "Enemigo1.h"
#include "Enemigo2.h"
#include "Aliado1.h"
#include "Pared.h"//Pared
#include "Basura.h"
//Objetos
#include "Objeto.h"
//Archivo
#include "Archivo.h"

class Controlador1
{
private:
	Ash1* ash;
	vector<Enemigo1*> enemigos;
	vector<Enemigo2*> enemigos2;
	vector<Aliado1*> aliados;
	vector<Pared*> paredes;//Pared
	vector<Basura*> basuras;
	bool limiteAliados;//Para poder limitar en agregar aliados
	bool aparecePicture;
	bool validacionGanaste;
	//Objeto
	Objeto* point;
	Objeto* DatosJuegoNivel1;
	Objeto* barraVidas;
	Objeto* arbolOculto;
	//File
	Archivo* archivo;
	//Contadores
	int contPikachus; 
	int contBasuras;

public:
	Controlador1(Bitmap^ bmpAsh, Bitmap^ bmpEnemigo1, Bitmap^ bmpEnemigo2, Bitmap^ bmpSenal, Bitmap^ bmpBasura, Bitmap^ bmpDatosJuegoNivel1, Bitmap^ bmpBarraVidas, Bitmap^ bmpArbolOculto) {
		ash = new Ash1(bmpAsh->Width / 4, bmpAsh->Height / 4);

		for (int i = 0; i < 4; i++)
			enemigos.push_back(new Enemigo1(bmpEnemigo1->Width / 4, bmpEnemigo1->Height / 4));
		for (int i = 0; i < 2; i++)
			enemigos2.push_back(new Enemigo2(bmpEnemigo2->Width / 3, bmpEnemigo2->Height / 5));


		limiteAliados = true; //Para poder limitar en agregar aliados

		asignandoLimites();
		agregandoBasuras(bmpBasura);
		agregandoParedes();

		this->aparecePicture = false;
		this->validacionGanaste = false;

		//Objetos
		point = new Objeto(900, 360, bmpSenal->Width / 1, bmpSenal->Height / 1, 0.1);
		DatosJuegoNivel1 = new Objeto(0, 480, bmpDatosJuegoNivel1->Width / 1, bmpDatosJuegoNivel1->Height / 1, 0.32);
		barraVidas = new Objeto(23, 500, bmpBarraVidas->Width / 2, bmpBarraVidas->Height / 3, 0.4);
		arbolOculto = new Objeto(785, 115, bmpArbolOculto->Width / 1, bmpArbolOculto->Height / 1, 0.1);

		//Contadores
		contPikachus = 0;
		contBasuras = 0;

		//Archivo
		archivo = new Archivo();
		asignarValoresArchivo();
	}
	~Controlador1(){}

	//Archivo
	void asignarValoresArchivo() {
		ash->setX(archivo->getPosXnivel1());
		ash->setY(archivo->getPosYnivel1());
	}

	bool getaparecePicture() { return aparecePicture; }
	int getContPikachus() { return contPikachus; }
	int getContBasuras() { return contBasuras; }
	bool getvalidacionGanaste() { return validacionGanaste; }

	void setaparecePicture(bool _aparecePicture) { aparecePicture = _aparecePicture; }
	void setContPikachus(int _contPikachus) { contPikachus = _contPikachus; }
	void setContBasuras(int _contBasuras) { contBasuras = _contBasuras; }
	void setvalidacionGanaste(bool _validacionGanaste) { validacionGanaste = _validacionGanaste; }

	//Validacion de vidas
	void validacionBarraVidas() {
		if (ash->getVidas() == 5) {
			barraVidas->setIndX(0);
			barraVidas->setIndY(0);
		}
		if (ash->getVidas() == 4) {
			barraVidas->setIndX(0);
			barraVidas->setIndY(1);
		}
		if (ash->getVidas() == 3) {
			barraVidas->setIndX(0);
			barraVidas->setIndY(2);
		}
		if (ash->getVidas() == 2) {
			barraVidas->setIndX(1);
			barraVidas->setIndY(0);
		}
		if (ash->getVidas() == 1) {
			barraVidas->setIndX(1);
			barraVidas->setIndY(1);
		}
		if (ash->getVidas() == 0) {
			barraVidas->setIndX(1);
			barraVidas->setIndY(2);
		}
	}
	void agregandoParedes() {//Paredes
		paredes.push_back(new Pared(0, 0, 160, 638));//P1
		paredes.push_back(new Pared(160, 0, 675, 130));//P2
		paredes.push_back(new Pared(835, 0, 145, 380));//P3
		paredes.push_back(new Pared(835, 430, 145, 100));//P4
		paredes.push_back(new Pared(305, 530, 675, 110));//P5
		paredes.push_back(new Pared(160, 530, 70, 110));//P6
		paredes.push_back(new Pared(160, 445, 175, 53));//P7
		paredes.push_back(new Pared(385, 477, 105, 23));//P8
		paredes.push_back(new Pared(540, 385, 240, 115));//P9
		paredes.push_back(new Pared(540, 275, 240, 75));//P10
		paredes.push_back(new Pared(540, 130, 240, 112));//P11
		paredes.push_back(new Pared(160, 350, 330, 95));//P12
		paredes.push_back(new Pared(215, 203, 275, 85));//P13
		paredes.push_back(new Pared(215, 288, 118, 28));//P14
		paredes.push_back(new Pared(385, 288, 105, 28));//P15
		paredes.push_back(new Pared(420, 318, 70, 30));//P16
		paredes.push_back(new Pared(160, 130, 175, 38));//P17
		paredes.push_back(new Pared(420, 130, 120, 38));//P18

	}
	void agregandoBasuras(Bitmap^ bmpBasuras){
		basuras.push_back(new Basura(170, 290, bmpBasuras->Width, bmpBasuras->Height));//Creo que este es el problema del lag 
		basuras.push_back(new Basura(380, 305, bmpBasuras->Width, bmpBasuras->Height));
		basuras.push_back(new Basura(380, 440, bmpBasuras->Width, bmpBasuras->Height));
		basuras.push_back(new Basura(600, 240, bmpBasuras->Width, bmpBasuras->Height));
	}
	void asignandoLimites() { //Asiganando limites de los aliados y enemigos
		//Enemigos 1
		enemigos[0]->setX(160);
		enemigos[0]->setY(145);
		enemigos[0]->setLimite1(157);
		enemigos[0]->setLimite2(550);

		enemigos[1]->setX(160);
		enemigos[1]->setY(293);
		enemigos[1]->setLimite1(157);
		enemigos[1]->setLimite2(450);

		enemigos[2]->setX(160);
		enemigos[2]->setY(475);
		enemigos[2]->setLimite1(157);
		enemigos[2]->setLimite2(850);

		enemigos[3]->setX(360);
		enemigos[3]->setY(475);
		enemigos[3]->setLimite1(157);
		enemigos[3]->setLimite2(850);


		//Enemigos 2
		enemigos2[0]->setX(493);
		enemigos2[0]->setY(156);
		enemigos2[0]->setLimite1(145);
		enemigos2[0]->setLimite2(550);

		enemigos2[1]->setX(787);
		enemigos2[1]->setY(156);
		enemigos2[1]->setLimite1(145);
		enemigos2[1]->setLimite2(550);
	}
	void agregarAliados(Bitmap^ bmpAliado) {
		if (limiteAliados) {
			aliados.push_back(new Aliado1(bmpAliado->Width / 4, bmpAliado->Height / 4));
			//aliados  //Pikachu
			//Tengo que asigar aca porque solo puedo dar valores si existen los objetos, si no se rompe el code
			if (aliados.size() == 1) {
				aliados[0]->setX(490);
				aliados[0]->setY(220);
				aliados[0]->setLimite1(485);
				aliados[0]->setLimite2(840);
			}
			if (aliados.size() == 2) {
				aliados[1]->setX(490);
				aliados[1]->setY(327);
				aliados[1]->setLimite1(485);
				aliados[1]->setLimite2(840);
				limiteAliados = false; //Impedimos agregar mas de 2 aliados
			}
		}
	}
	void dibujarTodo(Graphics^ g, Bitmap^ bmpAsh, Bitmap^ bmpEnemigo1, Bitmap^ bmpEnemigo2, Bitmap^ bmpSenal, Bitmap^ bmpAliado, Bitmap^ bmpBasura, Bitmap^ bmpDatosJuegoNivel1, Bitmap^ bmpBarraVidas, Bitmap^ bmpArbolOculto) {
		ash->dibujar(g, bmpAsh);

		for (int i = 0; i < enemigos.size(); i++)
			enemigos[i]->dibujar(g, bmpEnemigo1);

		for (int i = 0; i < enemigos2.size(); i++)
			enemigos2[i]->dibujar(g, bmpEnemigo2);

		point->dibujar(g, bmpSenal);//Dibujando el mapa

		for (int i = 0; i < aliados.size(); i++)
			aliados[i]->dibujar(g, bmpAliado);

		//Paredes
		//agregandoParedes();//ESTO DABA EL LAG ESTABA AGREGANDO CADA 100 ms
		for (int i = 0; i < paredes.size(); i++)
			paredes[i]->dibujar(g);

		//Basuras
		//agregandoBasuras(bmpBasura); //ESTO DABA EL LAG ESTABA AGREGANDO CADA 100 ms
		for (int i = 0; i < basuras.size(); i++)
			basuras[i]->dibujar(g, bmpBasura);

		DatosJuegoNivel1->dibujar(g, bmpDatosJuegoNivel1);
		barraVidas->dibujar(g, bmpBarraVidas);
		arbolOculto->dibujar(g, bmpArbolOculto);
	}
	void moverEnemigos(Graphics^ g) { //Mover todo
		for (int i = 0; i < enemigos.size(); i++)
			enemigos[i]->mover(g);

		for (int i = 0; i < enemigos2.size(); i++)
			enemigos2[i]->mover(g);

		for (int i = 0; i < aliados.size(); i++)
			aliados[i]->mover(g);
	}
	void colisionPared() {
		for (int i = 0; i < paredes.size(); i++) {
			if (ash->getRectangle().IntersectsWith(paredes[i]->getRectangle())) {
				ash->setPasar(false);
			}
		}
	}
	void colision() {
		//----------Enemigos tipo 1 - ASH
		//Verificacion de Colision entre enemigos tipo 1 y ash
		for (int i = 0; i < enemigos.size(); i++)
		{
			if (ash->getRectangle().IntersectsWith(enemigos[i]->getRectangle())) {
				enemigos[i]->setVisible(false);
				ash->bajarVida();
				//Validando la barra de vidas
				validacionBarraVidas();
			}
		}

		//----------Enemigos tipo 2 - ASH
		//Verificacion de Colision entre enemigos tipo 2 y ash
		for (int i = 0; i < enemigos2.size(); i++)
		{
			if (ash->getRectangle().IntersectsWith(enemigos2[i]->getRectangle())) {
				enemigos2[i]->setVisible(false);
				ash->bajarVida();
				//Validando la barra de vidas
				validacionBarraVidas();
			}
		}

		//----------Aliado(PIKACHU) - ASH
		//Verificacion de Colision entre pikachu y ash
		for (int i = 0; i < aliados.size(); i++)
		{
			if (ash->getRectangle().IntersectsWith(aliados[i]->getRectangle())) {
				aliados[i]->setVisible(false);
				ash->aumentarVelocidad();
				contPikachus++;
			}
		}

		//----------Basuras - ASH
		//Verificacion de Colision entre basura y ash
		for (int i = 0; i < basuras.size(); i++)
		{
			if (ash->getRectangle().IntersectsWith(basuras[i]->getRectangle())) {
				basuras[i]->setVisible(false);
				contBasuras++;
			}
		}

		//----------Secreto - ASH
		//Verificacion de Colision entre secreto y ash
		if (ash->getRectangle().IntersectsWith(arbolOculto->getRectangle())) {
			aparecePicture = true;
		}

		//----------Punto de llegada - ASH
		//Verificacion de Colision entre punto de llegada y ash
		if (contBasuras == 4) {
			if (ash->getRectangle().IntersectsWith(point->getRectangle())) {
				validacionGanaste = true;
			}
		}


		//Eliminacion de aliados
		for (int i = 0; i < aliados.size(); i++) {
			if (!aliados[i]->getVisible()) {
				aliados.erase(aliados.begin() + i);
			}
		}
		//Eliminacion de enemigos tipo 1
		for (int j = 0; j < enemigos.size(); j++) {
			if (!enemigos[j]->getVisible()) {
				enemigos.erase(enemigos.begin() + j);
			}
		}
		//Eliminacion de enemigos tipo 2
		for (int j = 0; j < enemigos2.size(); j++) {
			if (!enemigos2[j]->getVisible()) {
				enemigos2.erase(enemigos2.begin() + j);
			}
		}
		//Eliminacion de basuras
		for (int j = 0; j < basuras.size(); j++) {
			if (!basuras[j]->getVisible()) {
				basuras.erase(basuras.begin() + j);
			}
		}
	}

	Ash1* getAsh() { return ash; }
	vector<Enemigo1*> getEnemigos() { return enemigos; }
	vector<Enemigo2*> getEnemigos2() { return enemigos2; }
	vector<Aliado1*> getAliados() { return aliados; }
	vector<Basura*> getBasuras() { return basuras; }
};