#pragma once
#include <iostream>
#include "compra.h"

using namespace std;

class compra{
protected: string fecha_orden, fecha_ingreso;
		 int no_orden_compra = 0;
		 int id_proveedor = 0;
		

		 // constructor
protected:
	compra() {
	}
	compra(int nor, int idpr, string ford, string fin) {
		no_orden_compra = nor;
		id_proveedor= idpr;
		fecha_orden = ford;
		fecha_ingreso = fin;

	}
};

class compra_detalle {
protected:
	int id_producto = 0;

	int cantidad = 0;

		 // constructor
protected:
	compra_detalle() {
	}
	compra_detalle(int pro, int can) {
		id_producto = pro;
		cantidad = can;
	}
};