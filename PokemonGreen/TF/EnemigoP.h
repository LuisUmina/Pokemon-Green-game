#pragma once

using namespace System::Drawing;

class EnemigoP {
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int indx, indy;
	bool visible;
public:
	EnemigoP(int ancho, int alto) {
		this->ancho = ancho;
		this->alto = alto;
		this->indx = 0;
		this->indy = 0;
		visible = true;
	}
	~EnemigoP() {}


	void setX(int _x) { this->x = _x; }
	void setY(int _y) { this->y = _y; }
	void setVisible(bool v) { visible = v; }
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