#pragma once
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace System;
using namespace std;

class Archivo {
private:
	ofstream escribirArchivo; //Escribir
	ifstream leerArchivo; //Leer
	string text;

	int PosXnivel1, PosYnivel1;
	int PosXnivel2, PosYnivel2;

public:
	Archivo() {
		readData();
	}
	~Archivo() {}

	void readData() {
		leerArchivo.open("configuracion.txt", ios::in);

		getline(leerArchivo, text);
		PosXnivel1 = stoi(text);
		getline(leerArchivo, text);
		PosYnivel1 = stoi(text);

		getline(leerArchivo, text);
		PosXnivel2 = stoi(text);
		getline(leerArchivo, text);
		PosYnivel2 = stoi(text);

		leerArchivo.close();
	}

	int getPosXnivel1() { return PosXnivel1; }
	int getPosYnivel1() { return PosYnivel1; }
	int getPosXnivel2() { return PosXnivel2; }
	int getPosYnivel2() { return PosYnivel2; }
};