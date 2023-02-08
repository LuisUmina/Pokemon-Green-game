#pragma once
#include "JugadorP.h"
using namespace System::Drawing;

class Ash1 : public JugadorP {
private:
	bool pasar;

public:
	Ash1(int ancho, int alto) : JugadorP(ancho, alto) {
		this->x = 255;
		this->y = 590;
		this->ancho = ancho;
		this->alto = alto;
		this->dy = 1;
		this->dx = 1;
		this->indx = 0;
		this->indy = 0;
		this->pasar = true;
	}
	~Ash1() {}

	void setPasar(bool _pasar) { this->pasar = _pasar; }
	bool getPasar() { return this->pasar; }

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(indx * ancho, indy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.7, alto * 0.7);//En cambio este es el tamaño del objeto
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);

		//Pen^ p = gcnew Pen(Color::White, 2);
		//g->DrawRectangle(p, x + 17, y + 28, ancho* 0.2, alto* 0.2);//Solo por 0.2 aca porque esto es lo que reconocera el cruce
	}

	void mover(Graphics^ g, char tecla) {
		switch (tecla)
		{
		case 'W':
		{
			if (pasar == false) { y += 21; }

			if (y > 0) {
				y -= dy;
				indy = 3;
			}
			break;
		}
		case 'S':
		{
			if (pasar == false) {
				y -= 21;
			}

			if (y + alto * 0.7 < g->VisibleClipBounds.Height ) {
				y += dy;
				indy = 0;
			}
			break;
		}
		case 'A':
		{
			if (pasar == false) {
				x += 21;
			}


			if (x > 0 ) {
				x -= dx;
				indy = 1;
			}
			break;
		}
		case 'D':
		{
			if (pasar == false) {
				x -= 21;
			}

			if (x + ancho * 0.7 < g->VisibleClipBounds.Width) {
				x += dx;
				indy = 2;
			}
			break;
		}
		}
		pasar = true;

		indx++;
		if (indx > 3)indx = 0;
	}

	void aumentarVelocidad() {
		dy += 1;
		dx += 1;
	}

	Rectangle getRectangle() {
		return Rectangle(x + 17, y + 28, ancho * 0.2, alto * 0.2);//Solo por 0.2 aca porque esto es lo que reconocera el cruce
	}
};