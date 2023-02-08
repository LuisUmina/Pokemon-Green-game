#pragma once
#include <iostream>
#include "EnemigoP.h"
using namespace System::Drawing;

class Enemigo2 : public EnemigoP {
private:
	int limite1, limite2;
	bool estado;
public:
	Enemigo2(int _ancho, int _alto) : EnemigoP(ancho, alto) {
		this->x = 160;
		this->y = 145;
		this->ancho = _ancho;
		this->alto = _alto;
		this->dx = rand() % 5 + 5;
		this->dy = rand() % 5 + 5;
		this->indx = 0;
		this->indy = 0;
		this->estado = true;

		this->limite1 = 0;
		this->limite2 = 0;
	}
	~Enemigo2() {}

	void setX(int _x) { this->x = _x; }
	void setY(int _y) { this->y = _y; }
	void setEstado(bool _estado) { this->estado = _estado; }
	void setLimite1(int _limite1) { this->limite1 = _limite1; }
	void setLimite2(int _limite2) { this->limite2 = _limite2; }


	int getX() { return this->x; }
	int getY() { return this->y; }
	bool getEstado() { return this->estado; }
	int getLimite1() { return this->limite1; }
	int getLimite2() { return this->limite2; }

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(indx * ancho, indy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.9, alto * 0.9);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);


		//Pen^ p = gcnew Pen(Color::Yellow, 2);
		//g->DrawRectangle(p, x + 13, y + 9, ancho * 0.4, alto * 0.4);
	}

	void mover(Graphics^ g) {
		if (y < limite1 || y + alto* 0.9 > limite2) {//arriba abajo
			dy *= -1;
			if (dy > 0)
				indy = 0;
			else indy = 1;
		}
		y += dy;

		indx++;
		if (indx > 2)indx = 0;
	}

	Rectangle getRectangle() {
		return Rectangle(x + 13, y + 9, ancho * 0.4, alto * 0.4);
	}

};