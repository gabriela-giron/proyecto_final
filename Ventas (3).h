#pragma once
#include<iostream>
#include"ConexionBD.h"
#include<string>

using namespace std;
class venta {
protected: string serie, fecha_factura, fecha_ingreso;
		 int no_factura = 0;
		 int id_Clientes = 0;
		 int id_Empleados = 0;
		
		 

		 // constructor
public:
	venta() {
	}
	venta( int nf,string se, string fft, int idc, int ide, string ing) {
		
		no_factura = nf;
		serie = se;
		fecha_factura = fft;
		id_Clientes = idc;
		id_Empleados = ide;
		fecha_ingreso = ing;


	}
	void setno_factura(int nf) { no_factura = nf; }
	void setserie(string se) { serie = se; }
	void setfecha_factura(string fft) { fecha_factura = fft; }
	void setid_Clientes(int ide) { id_Empleados = ide; }
	void setfecha_ingreso(string ing) { fecha_ingreso = ing; }


	// get(mostrar)
	int getno_factura(){ return no_factura; }
	string getserie() { return serie; }
	string getfecha_factura() { return fecha_factura; }
	int getid_Clientes() { return id_Empleados; }
	string getfecha_ingreso() { return fecha_ingreso; }

	string asignar(int no_factura) {

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