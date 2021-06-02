#pragma once
#include<iostream>
using namespace std;
class venta {
protected: string cantidad,precio_uni,serie, fecha_factura, fecha_ingreso;
		 int no_factura = 0;
		 int id_Clientes = 0;
		 int id_Empleados = 0;
		 string id_Ventas;
		 int id_Producto = 0;

		 // constructor
protected:
	venta() {
	}
	venta(string vn, int nf,string cant,string unit, string se, string fft, int idc, int ide, string ing,int pr) {
		id_Producto = pr;
		cantidad = cant;
		precio_uni = unit;
		id_Ventas = vn;
		no_factura = nf;
		serie = se;
		fecha_factura = fft;
		id_Clientes = idc;
		id_Empleados = ide;
		fecha_ingreso = ing;


	}
};

/*#pragma once
#include<iostream>
using namespace std;
class Ventas
{
protected: string id_ventas, id_producto, cantidad, precio_unitario, no_factura, serie, fecha_factura, id_Clientes, id_Empleado, fecha_ingreso;
		 // constructor
protected:
	Ventas() {
	}
	Ventas(string id_vent, string id_produc, string cant, string precio_uni, string fac, string ser, string fecha_fac,  string id_client, string id_emple, string fecha_ingre) {
		id_ventas = id_vent;
		id_producto = id_produc;
		cantidad = cant;
		precio_unitario = precio_uni;
		no_factura = fac;
		serie = ser;
		fecha_factura = fecha_fac;
		id_Clientes = id_client;
		id_Empleado = id_emple;
		fecha_ingreso = fecha_ingre;


	}
};*/
