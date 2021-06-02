#pragma once
#include "Ventas.h"
#include<mysql.h>
#include <iostream>
#include"ConexionBD.h"
#include<string>

using namespace std;

class ventas : venta {
	// atributos

	   // metodo constructor
public:
	ventas() {
	}

	ventas(string cant, string unit, int pr, string vn, int nf, string se, string fft, int idc, int ide, string ing): venta(vn,nf,cant,unit,se,fft,idc,ide,ing,pr) {

	}
	// metodos de modificar datos
	// set ( modificar)
	void setcantidad(string cant) { cantidad = cant; }
	void setprecio_unitario(string unit) { precio_uni = unit; }
	void setid_Producto(int pr) { id_Producto = pr; }
	void setid_Ventas(string vn) { id_Ventas = vn; }
	void setno_factura(int nf) { no_factura = nf; }
	void setserie(string se) { serie = se; }
	void setfecha_factura(string fft) { fecha_factura = fft; }
	void setid_Clientes(int idc) { id_Clientes = idc; }
	void setid_Empleados(int ide) { id_Empleados = ide; }
	void setfecha_ingreso(string ing) { fecha_ingreso = ing; }
	
	// get(mostrar)
	string setcantidad() { return cantidad; }
	string setprecio_unitario() { return precio_uni; }
	int setid_Producto() { return id_Producto; }
	string setid_Ventas() { return id_Ventas; }
	int getno_factura() { return no_factura; }
	string setserie() { return serie; }
	string setfecha_factura() { return fecha_factura; }
	int setid_Clientes() { return id_Clientes; }
	int setid_Empleados() { return id_Empleados; }
	string setfecha_ingreso() { return fecha_ingreso; }
	
	string asignar(int no_factura) {

		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select id_ventas from  ventas string asignar(int no_factura)";

			int q_estado;
			ConexionBD cn = ConexionBD();
			MYSQL_ROW fila;
			MYSQL_RES* resultado;
			cn.abrir_conexion();
			if (cn.getConectar()) {
				string nofac = to_string(no_factura);
				string consulta = "select id_ventas from  ventas where no_factura values('" + nofac + "')";
				const char* c = consulta.c_str();
				q_estado = mysql_query(cn.getConectar(), c);

				if (!q_estado) {
					resultado = mysql_store_result(cn.getConectar());
					cout << "----------------------------Ventas Detalle------------------------" << endl;
					while (fila = mysql_fetch_row(resultado)) {
						return fila[0];
					}
				}
				else {

					cout << "xxxxx error de  consulta xxxx" << endl;
				}

			}
			else {

				cout << " xxxxx error en la conexion xxxxx";
			}

			cn.cerrar_conexion();
		}
	}


	void crearVentas() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		string NF = to_string(no_factura);
		string IDC = to_string(id_Clientes);
		string IDE = to_string(id_Empleados);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			//string consultaid = "select id_Ventas from  ventas order by id_Ventas desc limit 1";
			//consultaid = (id_Ventas);
			string insert = "insert into ventas(no_factura, serie, fecha_factura, id_Clientes, id_Empleado, fecha_ingreso) VALUES ('" + NF + "',  '" + serie + "',now(), '" + IDC + "','" + IDE + "' , now());";
			// executar el query
			const char* h = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), h);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;



			}
			else {
				cout << " xxx Error al Ingresar en venta  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}

		cn.cerrar_conexion();
	}

	void crearVentaDetalle() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		string produc = to_string(id_Producto);
		//string vent = to_string(id_Ventas);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			
			string insert = " insert into ventas_detalle (id_Ventas,id_Productos, cantidad, precio_unitario) VALUES ('" + id_Ventas+ "','" + produc + "',  '" + cantidad + "','" + precio_uni + "' );";
			// executar el query
			const char* h = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), h);
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

	void leerVentas() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {


			string consulta = "select * from  ventas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "----------------------------Ventas------------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "  |  " << fila[1] << "  |  " << fila[2] << "  |  " << fila[3] << "  |  " << fila[4] << "  |  " << fila[5] << endl;
				}

			}
			else {

				cout << "xxxxx error de  consulta xxxx" << endl;
			}



		}
		else {

			cout << " xxxxx error en la conexion xxxxx";
		}

		cn.cerrar_conexion();


	}

	void leerVentaDetalle() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {


			string consulta = "select * from  ventasdetalle ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "----------------------------VentaDetalle------------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[1] << "  |  " << fila[2] << "  |  " << fila[3] << endl;
				}

			}
			else {

				cout << "xxxxx error de  consulta xxxx" << endl;
			}



		}
		else {

			cout << " xxxxx error en la conexion xxxxx";
		}

		cn.cerrar_conexion();


	}

	void modificar() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string NF = to_string(no_factura);
		string IDC = to_string(id_Clientes);
		string IDE = to_string(id_Empleados);
		if (cn.getConectar()) {
			string id_Ventas;
			cout << " ingrese id a modificar :";
			cin >> id_Ventas;
			string update = " update ventas   set no_factura='" + NF + "', serie='" + serie + "', fecha_factura='" + fecha_factura + "', id_Clientes='" + IDC + "', id_Empleado='" + IDE + "', fecha_ingreso= '" + fecha_ingreso + "' WHERE id_Ventas= '" + id_Ventas + "'";
			const char* o = update.c_str();
			q_estado = mysql_query(cn.getConectar(), o);
			if (!q_estado) {
				cout << " modificacion Exitosa..." << endl;

			}
			else {

				cout << "xxxxx error de  modificacion xxxx" << endl;
			}

		}
		else {

			cout << " xxxxx error en la conexion xxxxx";
		}

		cn.cerrar_conexion();
	}
	void eliminar() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Ventas;
			cout << " ingrese id a eliminar :";
			cin >> id_Ventas;
			string sel = " DELETE FROM ventas   WHERE id_Ventas= '" + id_Ventas + "'";
			const char* u = sel.c_str();
			q_estado = mysql_query(cn.getConectar(), u);
			if (!q_estado) {
				cout << " eliminacion exitosa ..." << endl;

			}
			else {

				cout << "xxxxx error al eliminar xxxx" << endl;
			}





		}
		else {

			cout << " xxxxx error en la conexion xxxxx";
		}

		cn.cerrar_conexion();



	}


};



/*#pragma once
#include "Ventas.h"
#include<mysql.h>
#include <iostream>
#include"ConexionBD.h"
#include<string>
using namespace std;
class Venta_Detalle : Ventas
{
public:
	Venta_Detalle() {
	}

	Venta_Detalle(string id_vent, string id_produc, string cant, string precio_uni, string fac, string ser, string fecha_fac, string id_client, string id_emple, string fecha_ingre) : Ventas(id_vent, id_produc, cant, precio_uni, fac, ser, fecha_fac, id_client, id_emple, fecha_ingre) {

	}
	void setid_ventas(string id_vent) { id_ventas = id_vent; }
	void setid_producto(string id_produc) { id_producto = id_produc; }
	void setcantidad(string cant) { cantidad = cant; }
	void setprecio_unitario(string precio_uni) { precio_unitario = precio_uni; }
	void setno_factura(string fac) { no_factura = fac; }
	void setserie(string ser) { serie = ser; }
	void setfecha_factura(string fecha_fac) { fecha_factura = fecha_fac; }
	void setid_Clientes(string id_client) { id_Clientes = id_client; }
	void setid_Empleado(string id_emple) { id_Empleado = id_emple; }
	void setfecha_ingreso(string fecha_ingre) { fecha_ingreso = fecha_ingre; }
	// get(mostrar)
	string getid_ventas() { return id_ventas; }
	string getid_producto() { return id_producto; }
	string getcantidad() { return cantidad; }
	string getprecio_unitario() { return precio_unitario; }
	string getno_factura() { return no_factura; }
	string getserie() { return serie; }
	string getfecha_factura() { return fecha_factura; }
	string getid_Clientes() { return id_Clientes; }
	string getid_Empleado() { return id_Empleado; }
	string getfecha_ingreso() { return fecha_ingreso; }

	void crearVentas() {
		int q_estado,q_estado2;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		if (cn.getConectar()) {
			//string insert = "insert into ventas(no_factura, serie, fecha_factura, id_Clientes, id_Empleado, fecha_ingreso) VALUES('" + no_factura + "', '" + serie + "', '" + fecha_factura + "', '" + id_Clientes + "', '" + id_Empleado + "', '" + fecha_ingreso + "'); insert into ventas_detalle(id_ventas, id_producto, cantidad, precio_unitario) VALUES('" + id_ventas + "', '" + id_producto + "', '" + cantidad + "', '" + precio_unitario + "')";
			string insert = "insert into ventas(no_factura, serie, fecha_factura, id_Clientes, id_Empleado, fecha_ingreso) VALUES ('" + no_factura + "',  '" + serie + "','" + fecha_factura + "','" + id_Clientes + "', '" + id_Empleado + "' , now())";
			// executar el query
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
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

	void crearVentaDetalle() {
		int q_estado, q_estado2;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		if (cn.getConectar()) {
			//string insert = "insert into ventas(no_factura, serie, fecha_factura, id_Clientes, id_Empleado, fecha_ingreso) VALUES('" + no_factura + "', '" + serie + "', '" + fecha_factura + "', '" + id_Clientes + "', '" + id_Empleado + "', '" + fecha_ingreso + "'); insert into ventas_detalle(id_ventas, id_producto, cantidad, precio_unitario) VALUES('" + id_ventas + "', '" + id_producto + "', '" + cantidad + "', '" + precio_unitario + "')";
			//string insert = "insert into ventas(no_factura, serie, fecha_factura, id_Clientes, id_Empleado, fecha_ingreso) VALUES ('" + no_factura + "',  '" + serie + "','" + fecha_factura + "','" + id_Clientes + "', '" + id_Empleado + "' , '" + fecha_ingreso + "')";
			string insert = "insert into ventas_detalle(id_Ventas, id_Productos, cantidad, precio_unitario) VALUES ('" + id_ventas + "',  '" + id_producto + "','" + cantidad + "','" + precio_unitario + "')";
			// executar el query
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
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

	void leer() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {


			//string consulta = "select v.id_Ventas,v.no_factura,v.serie,v.fecha_factura,v.id_Clientes,v.id_Empleado,v.fecha_ingreso from ventas as v inner join clientes as c on v.id_Clientes = c.id_Clientes inner join empleados as e on v.id_Empleado = e.id_Empleados; ";
			string consulta = "SELECT * FROM `ventas` LEFT OUTER JOIN `ventas_detalle` ON `ventas`.`id_Ventas` = `ventas_detalle`.`id_Ventas_detalle` UNION SELECT * FROM `ventas` RIGHT OUTER JOIN `ventas_detalle` ON `ventas`.`id_Ventas` = `ventas_detalle`.`id_Ventas_detalle`;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "----------------------------Ventas/Venta_Detalle------------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "  ,  " << fila[1] << "  ,  " << fila[2] << "  ,  " << fila[3] << "  ,  " << fila[4] << "  ,  " << fila[5] << "  ,  " << fila[6] << "  ,  " << fila[7] << "  ,  " << fila[8] << "  ,  " << fila[9] << "  ,  " << fila[10] << "  ,  " << fila[11] << endl;
				}

			}
			else {

				cout << "xxxxx error de  consulta xxxx" << endl;
			}



		}
		else {

			cout << " xxxxx error en la conexion xxxxx";
		}

		cn.cerrar_conexion();


	}

	void modificarVentaDetalle() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Ventas_Detalle;
			cout << " ingrese id de ventas_detalle a modificar :";
			cin >> id_Ventas_Detalle;
			string update = " update ventas set id_Ventas='" + id_ventas + "',id_Productos='" + id_producto + "',cantidad='" + cantidad + "',precio_unitario='" + precio_unitario + "' WHERE id_Ventas_Detalle= '" + id_Ventas_Detalle + "';";
			const char* o = update.c_str();
			q_estado = mysql_query(cn.getConectar(), o);
			if (!q_estado) {
				cout << " modificacion Exitosa..." << endl;

			}
			else {

				cout << "xxxxx error de  modificacion xxxx" << endl;
			}

		}
		else {

			cout << " xxxxx error en la conexion xxxxx";
		}

		cn.cerrar_conexion();
	}

	void modificarVentas() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Ventas;
			cout << " ingrese id de ventas_detalle a modificar :";
			cin >> id_Ventas;
			string update = "update ventas set no_factura='" + no_factura + "', serie='" + serie + "', fecha_factura='" + fecha_factura + "', id_Clientes='" + id_Clientes + "', id_Empleado='" + id_Empleado + "', fecha_ingreso= '" + fecha_ingreso + "' WHERE id_Ventas= '" + id_ventas + "'";
			const char* o = update.c_str();
			q_estado = mysql_query(cn.getConectar(), o);
			if (!q_estado) {
				cout << " modificacion Exitosa..." << endl;

			}
			else {

				cout << "xxxxx error de  modificacion xxxx" << endl;
			}

		}
		else {

			cout << " xxxxx error en la conexion xxxxx";
		}

		cn.cerrar_conexion();
	}


	void eliminarVentas() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Ventas;
			cout << " ingrese id a eliminar :";
			cin >> id_Ventas;
			string sel = " DELETE FROM ventas  WHERE id_Ventas= '" + id_Ventas + "'";
			const char* u = sel.c_str();
			q_estado = mysql_query(cn.getConectar(), u);
			if (!q_estado) {
				cout << " eliminacion exitosa ..." << endl;

			}
			else {

				cout << "xxxxx error al eliminar xxxx" << endl;
			}





		}
		else {

			cout << " xxxxx error en la conexion xxxxx";
		}

		cn.cerrar_conexion();



	}

	void eliminarVentasDetalle() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Ventas_Detalle;
			cout << " ingrese id a eliminar :";
			cin >> id_Ventas_Detalle;
			string sel = " DELETE FROM ventas_detalle   WHERE id_Empleados= '" + id_Ventas_Detalle + "'";
			const char* u = sel.c_str();
			q_estado = mysql_query(cn.getConectar(), u);
			if (!q_estado) {
				cout << " eliminacion exitosa ..." << endl;

			}
			else {

				cout << "xxxxx error al eliminar xxxx" << endl;
			}





		}
		else {

			cout << " xxxxx error en la conexion xxxxx";
		}

		cn.cerrar_conexion();



	}

};*/
