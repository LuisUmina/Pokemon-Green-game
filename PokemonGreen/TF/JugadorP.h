#pragma once

using namespace System::Drawing;

class JugadorP {
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int indx, indy;
	int vidas;
	bool visible;

public:
	JugadorP(int ancho, int alto) {
		this->x = 0; this->y = 0;
		this->dx = 0; this->dy = 0;
		this->ancho = ancho; this->alto = alto;
		this->indx = 0;	this->indy = 0;
		this->vidas = 5;
		this->visible = true;
	}
	~JugadorP() {}

	void setX(int _x) { this->x = _x; }
	void setY(int _y) { this->y = _y; }
	void setVisible(bool _visible) { visible = _visible; }
	void setAncho(int _ancho) { this->ancho = _ancho; }
	void setAlto(int _alto) { this->alto = _alto; }
	void setVidas(int _vidas) { this->vidas = _vidas; }

	int getX() { return this->x; }
	int getY() { return this->y; }
	bool getVisible() { return visible; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getVidas() { return vidas; }


	virtual void dibujar() {}
	virtual void mover() {}
	virtual void bajarVida() {
		vidas--;
	}
};