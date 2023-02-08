#pragma once
using namespace System::Drawing;

class BalaBoss {
private:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int indx, indy;
	bool visible;

public:
	BalaBoss(int ancho, int alto, int x, int y) {
		this->x = x;
		this->y = y;
		this->ancho = ancho;
		this->alto = alto;
		this->dx = 0;
		this->dy = rand()% 10 + 8;
		this->indy = 0;
		this->indx = 0;
		this->visible = true;
	}
	~BalaBoss() {}

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
		Rectangle zoom = Rectangle(x, y, ancho * 0.2, alto * 0.2);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);


		/*Pen^ p = gcnew Pen(Color::White, 2);
		g->DrawRectangle(p, x, y, ancho * 0.5, alto * 0.5);*/
	}

	//Solo pueden subir
	void mover(Graphics^ g) {
		if (y + alto * 0.2 < g->VisibleClipBounds.Height) {
			y += dy;
		}


		indy++;
		if (indy == 3) {
			indy = 0;
		}
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * 0.2, alto * 0.2);
	}

};