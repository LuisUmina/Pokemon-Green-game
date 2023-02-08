#pragma once
#include <vector>
using namespace std;
using namespace System::Drawing;

class Pared {
private:
	int x, y, ancho, alto;

public:
	Pared(int _x, int _y, int _ancho, int _alto) {
		this->x = _x;
		this->y = _y;
		this->ancho = _ancho;
		this->alto = _alto;
	}
	~Pared() {}

	void dibujar(Graphics^ g) {
		Pen^ p = gcnew Pen(Color::Red, 3);
		g->DrawRectangle(p, x, y, ancho, alto);
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};
