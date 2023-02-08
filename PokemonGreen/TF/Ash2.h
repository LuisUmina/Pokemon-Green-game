#pragma once
#include "JugadorP.h"
using namespace System::Drawing;

class Ash2 : public JugadorP {
private:

public:
	Ash2(int ancho, int alto) : JugadorP(ancho, alto) {
		this->dx = 15;
		this->dy = 0;
		this->x = 350;
		this->y = 550;
	}
	~Ash2() {}


	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(indx * ancho, indy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 1, alto * 1);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);


		/*Pen^ p = gcnew Pen(Color::White, 2);
		g->DrawRectangle(p, x, y, ancho * 0.7, alto * 0.7);*/
	}

	void mover(Graphics^ g, char tecla) {
		switch (tecla)
		{
		case 'D'://DERECHA
		{
			if (x + ancho * 1 < g->VisibleClipBounds.Width) {
				x += dx;
				indy = 2;
			}
			break;
		}
		case 'A'://IZQUIERDA
		{
			if (x > 0) {
				x -= dx;
				indy = 1;
			}
			break;
		}
		}

		indx++;
		if (indx > 3)indx = 0;
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * 1, alto * 1);
	}
};