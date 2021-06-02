#pragma once
#include "compra.h"
#include<mysql.h>
#include <iostream>
#include"conexiondb.h"
#include<string>

using namespace std;
class Compras : compra {
	// atributos

	   // metodo constructor
public:
	Compras() {
	}

	Compras(int nor, int idpr, string ford, string fin) : compra(nor,  idpr,  ford, fin) {

	}
	// metodos de modificar datos
	// set ( modificar)

	void setno_orden_compra(int nor) { no_orden_compra = nor; }
	void setid_proveedor(int idpr) { id_proveedor = idpr; }
	void setfecha_orden(string ford) { fecha_orden = ford; }
	void setfecha_ingreso(string fin) { fecha_ingreso = fin; }
	
	// get(mostrar)
	int getno_orden_compra() { return no_orden_compra; }
	int setid_proveedores() { return id_proveedor; }
	string setfecha_orden() { return fecha_orden; }
	string setfecha_ingreso() { return fecha_ingreso; }
	

	void crear() {
		int q_estado;
		conexiondb cn = conexiondb();
		string NC = to_string(no_orden_compra);
		string IDCP = to_string(id_proveedor);
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string insert = "insert into compras(no_orden_compra, id_proveedor, fecha_orden, fecha_ingreso) VALUES ('" + NC + "',  '" + IDCP + "','" + fecha_orden + "' , '" + fecha_ingreso + "')";
			// executar el query
			const char* h = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), h);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;



			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}

		cn.cerrar_conexion();
	}
};



class Compras2 : compra_detalle {
	// atributos

	   // metodo constructor
public:
	Compras2() {
	}

	Compras2(int pro, int can) : compra_detalle(pro, can) {

	}
	// metodos de modificar datos
	// set ( modificar)

	void setid_producto(int pro) { id_producto = pro; }
	void setcantidad(int can) { cantidad = can; }
	// get(mostrar)
	int getid_producto() { return id_producto; }
	int setcantidad() { return cantidad; }
	void() {

	}
	void crear2() {
		int q_estado;
		conexiondb cn = conexiondb();
		string a = to_string(id_producto);
		string b = to_string(cantidad);
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string  insertar = "insert into compras_detalle(idCompra,idProducto,cantidad,precio_costo_unitario) VALUES (" + hj + "," + a + "," + b + "," + hk + ")";
			// executar el query
			const char* h = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), h);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;



			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}

		cn.cerrar_conexion();
	}
};
