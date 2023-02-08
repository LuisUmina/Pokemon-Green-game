#pragma once
#include <iostream>
#include "EnemigoP.h"
using namespace System::Drawing;

class Enemigo1Nivel2 : public EnemigoP {
private:

public:
	Enemigo1Nivel2(int ancho, int alto) : EnemigoP(ancho, alto) {
		this->dx = 0;
		this->dy = rand() % 10 + 7;
		this->x = rand() % 930;
		this->y = rand() % 50;
		this->indx = 0;
		this->indy = 0;
	}
	~Enemigo1Nivel2() {}

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(indx * ancho, indy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.1, alto * 0.1);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);

		/*Pen^ p = gcnew Pen(Color::White, 2);
		g->DrawRectangle(p, x, y, ancho * 0.7, alto * 0.7);*/
	}

	//Solo pueden bajar
	void mover(Graphics^ g) {

		if (y + alto * 0.1 < g->VisibleClipBounds.Height) {
			y += dy;
			indy = 0;
		}
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * 0.1, alto * 0.1);
	}

};