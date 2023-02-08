#pragma once
#include <iostream>
#include "AliadoP.h"
using namespace System::Drawing;

class Aliado1Nivel2 : public AliadoP {
private:
	bool estado;

public:
	Aliado1Nivel2(int ancho, int alto) : AliadoP(ancho, alto) {
		this->x = 855;
		this->y = 220;
		this->ancho = ancho;
		this->alto = alto;
		this->dx = 0;
		this->dy = rand() % 5 + 5;
		this->indx = 0;
		this->indy = 1;
		this->estado = true;

	}
	~Aliado1Nivel2() {}

	void setX(int _x) { this->x = _x; }
	void setY(int _y) { this->y = _y; }
	void setEstado(bool _estado) { this->estado = _estado; }


	int getX() { return this->x; }
	int getY() { return this->y; }
	bool getEstado() { return this->estado; }


	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(indx * ancho, indy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.6, alto * 0.6);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);


		/*Pen^ p = gcnew Pen(Color::White, 2);
		g->DrawRectangle(p, x, y , ancho * 0.6, alto * 0.6);*/
	}

	void mover(Graphics^ g) {

		if (y + alto * 0.6 > g->VisibleClipBounds.Height || y < 200)
			dy *= -1;
		y += dy;

		indx++;
		if (indx > 2)indx = 0;
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * 0.6, alto * 0.6);
	}
};





