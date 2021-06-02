#pragma once
#include "persona.h"
#include<mysql.h>
#include <iostream>
#include"ConexionBD.h"
#include<string>
using namespace std;
class empleados : persona {

	// atributos

	   // metodo constructor
public:
	empleados() {
	}

	empleados(string nom, string ape, string dire, int tel, string D, string gn, string fn, string idp, string fnc, string ing) : persona(nom, ape, dire, tel, D, gn, fn, idp, fnc, ing) {

	}
	// metodos de modificar datos
	// set ( modificar)

	void setnombre(string nom) { nombres = nom; }
	void setapellidos(string ape) { apellidos = ape; }
	void setdireccion(string dire) { direccion = dire; }
	void settelefono(int tel) { telefono = tel; }
	void setDPI(string D) { DPI = D; }
	void setgenero(string gn) { genero = gn; }
	void setfecha_nacimiento(string fn) { fecha_nacimiento = fn; }
	void setid_puesto(string idp) { id_Puestos = idp; }
	void setfecha_inicio_labores(string fnc) { fecha_inicio_labores = fnc; }
	void setfecha_ingreso(string ing) { fecha_ingreso = ing; }
	// get(mostrar)
	string getnombre() { return nombres; }
	string getapellidos() { return apellidos; }
	string getdireccion() { return direccion; }
	int gettelefono() { return telefono; }
	string getDPI() { return DPI; }
	string getgenero() { return genero; }
	string getfecha_nacimiento() { return fecha_nacimiento; }
	string getid_puesto() { return id_Puestos; }
	string getfecha_inicio_labores() { return fecha_inicio_labores; }
	string getfecha_ingreso() { return fecha_ingreso; }

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string T = to_string(telefono);

		if (cn.getConectar()) {
			string insert = "insert into empleados(nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, id_Puestos, fecha_inicio_labores, fecha_ingreso) VALUES ('" + nombres + "','" + apellidos + "','" + direccion + "', '" + T + "','" + DPI + "','" + genero + "' , '" + fecha_nacimiento + "', '" + id_Puestos + "', '" + fecha_inicio_labores + "', now() )";
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


			string consulta = "select e.id_Empleados,e.nombres,e.apellidos,e.direccion,e.telefono,e.DPI,e.genero,e.fecha_nacimiento,p.puesto,e.fecha_inicio_labores,e.fecha_ingreso from empleados as e inner join puestos as p on e.id_Puestos = p.id_Puestos; ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "----------------------------Empleados------------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "  |  " << fila[1] << "  |  " << fila[2] << "  |  " << fila[3] << "  |  " << fila[4] << "  |  " << fila[5] << "  |  " << fila[6] << "  |  " << fila[7] << "  |  " << fila[8] << "  |  " << fila[9] << "  |  " << fila[10] << endl;
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
			string update = " update empleados   set nombres='" + nombres + "', apellidos='" + apellidos + "', direccion='" + direccion + "', telefono='" + T + "', DPI='" + DPI + "', genero='" + genero + "', fecha_nacimiento= '" + fecha_nacimiento + "', id_Puestos= '" + id_Puestos + "', fecha_inicio_labores= '" + fecha_inicio_labores + "', fecha_ingreso= '" + fecha_ingreso + "' WHERE id_Empleados= '" + id_Empleados + "'";
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





};



	/*void modificarfechaingreso() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Empleados;
			cout << " ingrese id a modificar :";
			cin >> id_Empleados;
			string T = to_string(telefono);
			string update = " update empleados   set  fecha_ingreso= '" + fecha_ingreso + "' WHERE id_Empleados= '" + id_Empleados + "'";
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
	}*/
	/*void modificarfechainiciolabores() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Empleados;
			cout << " ingrese id a modificar :";
			cin >> id_Empleados;
			string T = to_string(telefono);
			string update = " update empleados   set  fecha_inicio_labores= '" + fecha_inicio_labores + "' WHERE id_Empleados= '" + id_Empleados + "'";
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
	}*/
	/*void modificaridpuesto() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Empleados;
			cout << " ingrese id a modificar :";
			cin >> id_Empleados;
			string T = to_string(telefono);
			string update = " update empleados   set id_puesto= '" + id_puesto + "' WHERE id_Empleados= '" + id_Empleados + "'";
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
	}*/
	/*void modificarfechanacimiento() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Empleados;
			cout << " ingrese id a modificar :";
			cin >> id_Empleados;
			string T = to_string(telefono);
			string update = " update empleados   set  fecha_nacimiento= '" + fecha_nacimiento + "' WHERE id_Empleados= '" + id_Empleados + "'";
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
	}*/
/*	void modificargenero() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Empleados;
			cout << " ingrese id a modificar :";
			cin >> id_Empleados;
			string T = to_string(telefono);
			string update = " update empleados   set  genero='" + genero + "' WHERE id_Empleados= '" + id_Empleados + "'";
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
	}*/
	/*void modificardpi() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Empleados;
			cout << " ingrese id a modificar :";
			cin >> id_Empleados;
			string T = to_string(telefono);
			string update = " update empleados   set DPI='" + DPI + "' WHERE id_Empleados= '" + id_Empleados + "'";
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
	}*/
	/*void modificartelefono() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Empleados;
			cout << " ingrese id a modificar :";
			cin >> id_Empleados;
			string T = to_string(telefono);
			string update = " update empleados   set  telefono='" + T + "' WHERE id_Empleados= '" + id_Empleados + "'";
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
	}*/
	/*void modificardireccion() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Empleados;
			cout << " ingrese id a modificar :";
			cin >> id_Empleados;
			string T = to_string(telefono);
			string update = " update empleados   set  direccion='" + direccion + "' WHERE id_Empleados= '" + id_Empleados + "'";
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
	}*/
	/*void modificarapellidos() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Empleados;
			cout << " ingrese id a modificar :";
			cin >> id_Empleados;
			string T = to_string(telefono);
			string update = " update empleados   set  apellidos='" + apellidos + "' WHERE id_Empleados= '" + id_Empleados + "'";
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
	}*/
	/*void modificarnombre() {

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_Empleados;
			cout << " ingrese id a modificar :";
			cin >> id_Empleados;
			string T = to_string(telefono);
			string update = " update empleados   set nombres='" + nombres + "' WHERE id_Empleados= '" + id_Empleados + "'";
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
	}*/

	

