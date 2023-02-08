#pragma once
#include <iostream>
using namespace System::Drawing;

class Basura {
private:
	int x, y;
	int ancho, alto;
	int indx, indy;
	bool visible;

public:
	Basura(int _x, int _y, int _ancho, int _alto) {
		this->x = _x;
		this->y = _y;
		this->ancho = _ancho;
		this->alto = _alto;
		indx = indy = 0;
		this->visible = true;
	}
	~Basura() {}

	void setX(int _x) { this->x = _x; }
	void setY(int _y) { this->y = _y; }
	void setVisible(bool _visible) { this->visible = _visible; }

	int getX() { return this->x; }
	int getY() { return this->y; }
	bool getVisible() { return this->visible; }


	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(indx * ancho, indy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.07, alto * 0.07);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);


		//Pen^ p = gcnew Pen(Color::Yellow, 2);//Con esto estoy modificando el rectangles para mostrarlo
		//g->DrawRectangle(p, x+6, y+8, ancho * 0.07 - 10, alto * 0.07 -10);
	}

	Rectangle getRectangle() {
		return Rectangle(x + 6, y + 8, ancho * 0.07 - 10, alto * 0.07 - 10);//Con esto estoy modificando el rectangles
	}
};