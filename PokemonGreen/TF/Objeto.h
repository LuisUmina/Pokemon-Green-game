#pragma once

using namespace System::Drawing;

class Objeto {
protected:
	int x, y;
	int ancho, alto;
	int indx, indy;
	double zoomXY;
	bool visible;

public:
	Objeto(int _x, int _y, int _ancho, int _alto, double _zoomXY) {
		this->x = _x;
		this->y = _y;
		this->ancho = _ancho;
		this->alto = _alto;
		this->indx = 0;
		this->indy = 0;
		this->visible = true;
		this->zoomXY = _zoomXY;//Tiene que ser como 1.0
	}
	~Objeto() {}

	void setX(int _x) { this->x = _x; }
	void setY(int _y) { this->y = _y; }
	void setVisible(bool _visible) { visible = _visible; }
	void setAncho(int _ancho) { this->ancho = _ancho; }
	void setAlto(int _alto) { this->alto = _alto; }
	void setIndX(int _indx) { this->indx = _indx; }
	void setIndY(int _indy) { this->indy = _indy; }

	int getX() { return this->x; }
	int getY() { return this->y; }
	bool getVisible() { return visible; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getIndX() { return this->indx; }
	int getIndY() { return this->indy; }

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(indx * ancho, indy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * zoomXY, alto * zoomXY);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);

		/*Pen^ p = gcnew Pen(Color::White, 2);
		g->DrawRectangle(p, x, y, ancho * zoomXY, alto * zoomXY);*/
	}

	Rectangle getRectangle() {
		return Rectangle(x , y , ancho * zoomXY, alto * zoomXY);
	}
};