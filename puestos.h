#pragma once
#include "puesto.h"
#include<mysql.h>
#include <iostream>
#include"ConexionBD.h"
#include<string>
using namespace std;
class puestos : puesto {
	// atributos

	   // metodo constructor
public:
	puestos() {
	}

	puestos(string pu) : puesto(pu) {

	}
	// metodos de modificar datos
	// set ( modificar)

	void setPuesto(string pu) { Puesto = pu; }

	// get(mostrar)
	string getPuesto() { return Puesto; }


	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string  insert = "insert into puestos(Puesto) VALUES ('" + Puesto + "')";
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

			string consulta = "select * from  puestos ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "----------------------------Puestos------------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "  ,  " << fila[1] << endl;
				}

			}
			else {

				cout << "xxxxx error de  consulta xxxx" << endl;
			}



		}
		else {

			cout << " xxxxx error en la concexion xxxxx";
		}

		cn.cerrar_conexion();


	}


	

	void modificar() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Puestos;
			cout << " ingrese id del puesto a modificar :";
			cin >> id_Puestos;
			string update = " update puestos set Puesto='" + Puesto + "' WHERE id_Puestos= '" + id_Puestos + "'";
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

			cout << " xxxxx error en la concexion xxxxx";
		}

		cn.cerrar_conexion();
	}

	/*void modificar() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Puestos, puesto;
			char s;
			cout << "------------------------------------------------" << endl;
			cout << "Ingrese el id del registro que desea modificar: ";
			cin >> id_Puestos;
			string consulta = "select * from puestos where id_Puestos='" + id_Puestos + "'";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {

				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					cout << "Id Puesto: " << fila[0] << endl;
					cout << "PUESTO : " << fila[1] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {

						cout << "\ningrese el nuevo puesto: ";
						cin >> puesto;

						string update = " update puestos   set Puesto='" + puesto + "' WHERE id_Puestos= '" + id_Puestos + "'";
						const char* y = update.c_str();
						q_estado = mysql_query(cn.getConectar(), y);
					}
					else {
						cout << ("Modificacion exitosa") << endl;
					}
				}
			}

			else {
				cout << "Error al modificar\n";
			}
		}
		else {
			cout << "Error en la conexion\n";
		}
		cn.cerrar_conexion();


	}*/
	void eliminar() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Puestos;
			cout << " ingrese id a eliminar :";
			cin >> id_Puestos;
			string sel = " DELETE FROM puestos   WHERE id_Puestos= '" + id_Puestos + "'";
			const char* io = sel.c_str();
			q_estado = mysql_query(cn.getConectar(), io);
			if (!q_estado) {
				cout << " eliminacion exitosa ..." << endl;

			}
			else {

				cout << "xxxxx error al eliminar xxxx" << endl;
			}





		}
		else {

			cout << " xxxxx error en la concexion xxxxx";
		}

		cn.cerrar_conexion();



	}





};


