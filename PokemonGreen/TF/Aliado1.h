#pragma once
#include <iostream>
#include "AliadoP.h"
using namespace System::Drawing;

class Aliado1 : public AliadoP {	
	private:
		int limite1, limite2;
		bool estado;
	public:
		Aliado1(int ancho, int alto) : AliadoP(ancho, alto) {
			this->x = 200;
			this->y = 145;
			this->ancho = ancho;
			this->alto = alto;
			this->dx = rand() % 5 + 5;
			this->dy = rand() % 5 + 5;
			this->indx = 0;
			this->indy = 2;
			this->estado = true;
			this->limite1 = 0;
			this->limite2 = 800;
		}
		~Aliado1() {}

		void setX(int _x) { this->x = _x; }
		void setY(int _y) { this->y = _y; }
		void setEstado(bool _estado) { this->estado = _estado; }
		void setLimite1(int _limite1) { this->limite1 = _limite1; }
		void setLimite2(int _limite2) { this->limite2 = _limite2; }


		int getX() { return this->x; }
		int getY() { return this->y; }
		bool getEstado() { return this->estado; }
		int getLimite1() { return this->limite1; }
		int getLimite2() { return this->limite2; }

		void dibujar(Graphics^ g, Bitmap^ bmp) {
			Rectangle sectionShown = Rectangle(indx * ancho, indy * alto, ancho, alto);
			Rectangle zoom = Rectangle(x, y, ancho * 0.8, alto * 0.8);
			g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);


			/*Pen^ p = gcnew Pen(Color::White, 2);
			g->DrawRectangle(p, x + 17, y + 28, ancho * 0.3, alto * 0.3);*/
		}

		void mover(Graphics^ g) {
			if (x < limite1 || x + ancho * 0.8 > limite2) {//Derecha a izquierda
				dx *= -1;
				if (dx > 0)
					indy = 2;
				else indy = 1;
			}
			x += dx;

			indx++;
			if (indx > 3)indx = 0;
		}

		Rectangle getRectangle() {
			return Rectangle(x + 17, y + 28, ancho * 0.3, alto * 0.3);
		}
	};





