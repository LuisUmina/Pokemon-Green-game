#pragma once
using namespace System::Drawing;

class BalaAliadoNivel2 {
private:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int indx, indy;
	bool visible;

public:
	BalaAliadoNivel2(int ancho, int alto, int x, int y) {
		this->x = x;
		this->y = y;
		this->ancho = ancho;
		this->alto = alto;
		this->dx = rand()% 15 + 5;
		this->dy = 0;
		this->indy = 0;
		this->indx = 6;
		this->visible = true;
	}
	~BalaAliadoNivel2() {}

	void setX(int _x) { this->x = _x; }
	void setY(int _y) { this->y = _y; }
	void setAncho(int _ancho) { this->ancho = _ancho; }
	void setAlto(int _alto) { this->alto = _alto; }
	void setVisible(bool _visible) { this->visible = _visible; }

	int getX() { return this->x; }
	int getY() { return this->y; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	bool getVisible() { return this->visible; }

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(indx * ancho, indy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.3, alto * 0.3);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);


		/*Pen^ p = gcnew Pen(Color::White, 2);
		g->DrawRectangle(p, x, y, ancho * 0.5, alto * 0.5);*/
	}

	//Solo pueden subir
	void mover(Graphics^ g) {
		if (x > 0) {
			x -= dx;
		}

		if (indx >= 1)
			indx--;
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * 0.3, alto * 0.3);
	}

};