#pragma once
#include "PersonaC.h"
#include<mysql.h>
#include <iostream>
#include"ConexionBD.h"
#include<string>
using namespace std;
class Cliente : PersonaC {
	// atributos

	   // metodo constructor
public:
	Cliente() {
	}

	Cliente(string nom, string ape, string N, string gn, int tel, string ctc, string ing) : PersonaC(nom, ape, N, gn, tel, ctc, ing) {

	}
	// metodos de modificar datos
	// set ( modificar)

	void setnombre(string nom) { nombres = nom; }
	void setapellidos(string ape) { apellidos = ape; }
	void setNIT(string N) { NIT = N; }
	void setgenero(string gn) { genero = gn; }
	void settelefono(int tel) { telefono = tel; }
	void setcorreo_electronico(string ctc) { correo_electronico = ctc; }
	void setfecha_ingreso(string ing) { fecha_ingreso = ing; }
	// get(mostrar)
	string getnombres() { return nombres; }
	string getapellidos() { return apellidos; }
	string getNIT() { return NIT; }
	string getgenero() { return genero; }
	int gettelefono() { return telefono; }
	string getcorreo_electronico() { return correo_electronico; }
	string getfecha_ingreso() { return fecha_ingreso; }

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string T = to_string(telefono);
		if (cn.getConectar()) {
			string insert = "insert into clientes(nombres, apellidos, NIT,  genero, telefono, correo_electronico,fecha_ingreso) VALUES ('" + nombres + "',  '" + apellidos + "','" + NIT + "', '" + genero + "','" + T + "', '" + correo_electronico + "' , now() )";
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
		

	void leer() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {


			string consulta = "select * from  clientes ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "----------------------------Clientes------------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "  |  " << fila[1] << "  |  " << fila[2] << "  |  " << fila[3] << "  |  " << fila[4] << "  |  " << fila[5] << "  |  " << fila[6] << endl;
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
			string id_Clientes;
			cout << " ingrese id a modificar :";
			cin >> id_Clientes;
			string T = to_string(telefono);
			string update = " update clientes   set nombres='" + nombres + "', apellidos='" + apellidos + "', NIT='" + NIT + "', genero='" + genero + "', telefono='" + T + "', correo_electronico='" + correo_electronico + "', fecha_ingreso= '" + fecha_ingreso + "' WHERE id_Clientes= '" + id_Clientes + "'";
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
	void eliminar() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Clientes;
			cout << " ingrese id a eliminar :";
			cin >> id_Clientes;
			string sel = " DELETE FROM clientes   WHERE id_Clientes= '" + id_Clientes + "'";
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

			cout << " xxxxx error en la concexion xxxxx";
		}

		cn.cerrar_conexion();



	}



};


/*#pragma once
#include "PersonaC.h"
#include<mysql.h>
#include <iostream>
#include"ConexionBD.h"
#include<string>
using namespace std;
class cliente : PersonaC {

	// atributos

	   // metodo constructor
public:
	cliente() {
	}

	cliente(string nom, string ape, string n, string gn, int tel, string correo, string ing) : PersonaC(nom, ape, n,gn, tel, correo, ing) {

	}
	// metodos de modificar datos
	// set ( modificar)

	void setnombre(string nom) { nombres = nom; }
	void setapellidos(string ape) { apellidos = ape; }
	void setnit(string n) { nit = n; }
	void setgenero(string gn) { genero = gn; }
	void settelefono(int tel) { telefono = tel; }
	void setcorreo_electronico(string correo) { correo_electronico = correo; }
	void setfecha_ingreso(string ing) { fecha_ingreso = ing; }
	// get(mostrar)
	string getnombres() { return nombres; }
	string getapellidos() { return apellidos; }
	string getnit() { return nit; }
	string getgenero() { return genero; }
	int gettelefono() { return telefono; }
	string getcorreo_electronico() { return correo_electronico; }
	string getfecha_ingreso() { return fecha_ingreso; }

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string T = to_string(telefono);
		if (cn.getConectar()) {
			string insert = "insert into empleados(nombres, apellidos, NIT,genero, telefono,correo_electronico,fecha_ingreso) VALUES ('" + nombres + "',  '" + apellidos + "','" + nit + "','" + genero + "', '" + T + "','" + correo_electronico + "', now();)";
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
		string T = to_string(telefono);
		if (cn.getConectar()) {


			//string consulta = "select * from  empleados ";
			string consulta = "select e.id_Empleados,e.nombres,e.apellidos,e.direccion,e.telefono,e.DPI,e.genero,e.fecha_nacimiento,p.puesto,e.fecha_inicio_labores,e.fecha_ingreso from empleados as e inner join puestos as p on e.id_Puesto = p.id_Puestos; ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "----------------------------Empleados------------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "  ,  " << fila[1] << "  ,  " << fila[2] << "  ,  " << fila[3] << "  ,  " << fila[4] << "  ,  " << fila[5] << "  ,  " << fila[6] << "  ,  " << fila[7] << "  ,  " << fila[8] << "  ,  " << fila[9] << "  ,  " << fila[10] << endl;
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
			string id_Empleados;
			cout << " ingrese id a modificar :";
			cin >> id_Empleados;
			string T = to_string(telefono);
			string update = " update empleados   set nombres='" + nombres + "', apellidos='" + apellidos + "',  genero='" + genero + "', NIT='" + nit + "', telefono='" + T + "',  correo_electronico= '" + correo_electronico + "', fecha_ingreso= '" + fecha_ingreso + "' WHERE id_Empleados= '" + id_Empleados + "'";
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
	void eliminar() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Empleados;
			cout << " ingrese id a eliminar :";
			cin >> id_Empleados;
			string sel = " DELETE FROM empleados   WHERE id_Empleados= '" + id_Empleados + "'";
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

			cout << " xxxxx error en la concexion xxxxx";
		}

		cn.cerrar_conexion();



	}





};*/

