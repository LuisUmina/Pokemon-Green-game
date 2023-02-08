#pragma once

using namespace System::Drawing;

class AliadoP {
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int indx, indy;
	bool visible;
public:
	AliadoP(int _ancho, int _alto) {
		this->ancho = _ancho;
		this->alto = _alto;
		this->indx = 0;
		this->indy = 0;
		this->visible = true;
	}
	~AliadoP() {}

	void setX(int _x) { this->x = _x; }
	void setY(int _y) { this->y = _y; }
	void setVisible(bool _visible) { visible = _visible; }
	void setAncho(int _ancho) { this->ancho = _ancho; }
	void setAlto(int _alto) { this->alto = _alto; }

	int getX() { return this->x; }
	int getY() { return this->y; }
	bool getVisible() { return visible; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }

	virtual void dibujar() {}
	virtual void mover() {}
};