#pragma once
#include<iostream>
using namespace std;
class PersonaC {
protected: string nombres, apellidos, NIT, genero, correo_electronico, fecha_ingreso;
	int telefono; 

		 // constructor
protected:
	PersonaC() {
	}
	PersonaC(string nom, string ape, string N, string gn, int tel, string ctc, string ing) {
		nombres = nom;
		apellidos = ape;
		NIT = N;
		genero = gn;
		telefono = tel;
		correo_electronico = ctc;
		fecha_ingreso = ing;


	}




};



/*#pragma once
#include<iostream>
using namespace std;
class PersonaC {
protected: string nombres, apellidos,nit,genero, correo_electronico, fecha_ingreso;
		 int telefono = 0;
		 // constructor
protected:
	PersonaC() {
	}
	PersonaC(string nom, string ape, string n, string gn, int tel, string correo, string ing) {
		nombres = nom;
		apellidos = ape;
		nit = n;
		genero = gn;
		telefono = tel;
		correo_electronico = correo;
		fecha_ingreso = ing;


	}
};*/

