#pragma once
#include <iostream>
#include "EnemigoP.h"
using namespace System::Drawing;

class Boss : public EnemigoP {
private:
	int vidas;

public:
	Boss(int ancho, int alto) : EnemigoP(ancho, alto) {
		this->dx = rand() % 10 + 5;
		this->dy = 0;
		//this->x = 450;
		this->x = 1200;
		this->y = 15;
		this->indx = 0;
		this->indy = 0;
		this->vidas = 9;
	}
	~Boss() {}

	void setVidas(int _vidas) { this->vidas = _vidas; }
	int getVidas() { return vidas; }

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(indx * ancho, indy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 1.0, alto * 1.0);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);

		/*Pen^ p = gcnew Pen(Color::White, 2);
		g->DrawRectangle(p, x, y, ancho * 1, alto * 1);*/
	}

	//Solo puede ir de derecha a izquierda
	void mover(Graphics^ g) {

		if (x + ancho * 1.0> g->VisibleClipBounds.Width - 120|| x < 0)
			dx *= -1;

			x += dx;
	}

	void bajarVidaBoss() {
		vidas--;
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * 1.0, alto * 1.0);
	}
};