// pr_c_mysql.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include"empleados.h"
#include"proveedores.h"
#include"puestos.h"
#include"Cliente.h"
#include"marcas.h"
#include"Venta_Detalle.h"
#include"Productos.h"
#include<string>
#include <iostream>
#include<Windows.h>

using namespace std;

void menu_principal();
void menu_empleados();
void menu_puestos();
void menu_clientes();
void menu_marcas();
void menu_productos();
void menu_ventas();
void menu_proveedores();

int main() {

	menu_principal();
	return 0;

}
int no_factura = 0;
int variable = 0;
int id_Ventas =9;
int id_Producto = 0;

char cadena[] = "ABCDE";


void menu_principal() {


	int opc;
	do {
		cout << "\t\t -------------- Menu Principal ----------------" << endl;
		cout << "\t 1. Tabla de Empleados" << endl;
		cout << "\t 2. Tabla de Puestos" << endl;
		cout << "\t 3. Tabla de Clientes" << endl;
		cout << "\t 4. Tabla de Marcas" << endl;
		cout << "\t 5. Tabla de Productos" << endl;
		cout << "\t 6. Tabla de Proovedores" << endl;
		cout << "\t 7. Tabla de Ventas" << endl;
		cout << "\t 8. Tabla de Compras" << endl;
		cout << "\t 9. Facturacion" << endl;
		cout << "\t 0. Salir" << endl;
		cout << "\t Seleccione su opcion: " << endl;
		cin >> opc;

		system("cls");
		switch (opc) {
		case 1:
			system("cls");
			menu_empleados();
			system("pause>nul");
			break;

		case 2:
			system("cls");
			menu_puestos();
			system("pause>nul");
			break;

		case 3:
			system("cls");
			menu_clientes();
			system("pause>nul");
			break;

		case 4:
			system("cls");
			menu_marcas();
			system("pause>nul");
			break;

		case 5:
			system("cls");
			menu_productos();
			system("pause>nul");
			break;

		case 6:
			system("cls");
			menu_proveedores();
			system("pause>nul");
			break;

		case 7:
			system("cls");
			menu_ventas();
			system("pause>nul");
			break;

		case 8:
			system("cls");
			//menu_compras();
			system("pause>nul");
			break;

		case 9:
			system("cls");
			//facturacion();
			system("pause>nul");
			break;

		case 0:
			opc = false;
			break;

		}
	} while (opc);
}

//empleados
void menu_empleados() {
	system("cls");
	int opcion;
	cout << "-------------- Menu Empleados: ----------------" << endl;
	cout << " 1. Crear....." << endl;
	cout << " 2. Leer....." << endl;
	cout << " 3. Modificar..." << endl;
	cout << " 4. Eliminar..." << endl;
	cout << " 0. Menu Principal..." << endl;
	cout << " Seleccione su opcion: " << endl;
	cin >> opcion;
	system("cls");
	switch (opcion) {

	case 1: {


		cout << " para insertar......." << endl;
		string nombres, apellidos, direccion, DPI, genero, fecha_nacimiento, id_Puestos, fecha_inicio_labores, fecha_ingreso;
		int telefono;
		cin.ignore();
		cout << " ingrese nombres: ";
		getline(cin, nombres);
		cout << " ingrese apellidos: ";
		getline(cin, apellidos);
		cout << " ingrese direccion: ";
		getline(cin, direccion);
		cout << " ingrese telefono :";
		cin >> telefono;
		cin.ignore();
		cout << " ingrese DPI : ";
		getline(cin, DPI);
		cout << " ingrese genero [0=M/1=F]: ";
		getline(cin, genero);
		cout << " ingrese la fecha de nacimiento [AAAA-MM-DD]: ";
		getline(cin, fecha_nacimiento);
		puestos p = puestos();
		p.leer();
		cout << " ingrese el id de puestos : ";
		getline(cin, id_Puestos);
		cout << " ingrese la fecha de inicio de labores [AAAA-MM-DD]: " << endl;
		getline(cin, fecha_inicio_labores);


		empleados e = empleados(nombres, apellidos, direccion,telefono, DPI, genero, fecha_nacimiento, id_Puestos, fecha_inicio_labores, fecha_ingreso);

		e.crear();
		system("pause");
		system("cls");
		break;
	}
	case 2: {
		empleados e = empleados();

		e.leer();
		system("pause");
		system("cls");
		break;

	}
	case 3: {
		cout << " para modificar......." << endl;
		string nombres, apellidos, direccion, DPI, genero, fecha_nacimiento, id_Puestos, fecha_inicio_labores, fecha_ingreso;
		int telefono;
		cin.ignore();
		cout << " ingrese nombres modificados: ";
		getline(cin, nombres);
		cout << " ingrese apellidos modificados: ";
		getline(cin, apellidos);
		cout << " ingrese direccion modificada: ";
		getline(cin, direccion);
		cout << " ingrese telefono modificado:";
		cin >> telefono;
		cin.ignore();
		cout << " ingrese DPI modificado: ";
		getline(cin, DPI);
		cout << " ingrese genero modificado [0=M/1=F]: ";
		getline(cin, genero);
		cout << " ingrese fecha de nacimiento modificada[AAAA-MM-DD]: ";
		getline(cin, fecha_nacimiento);
		puestos p = puestos();
		p.leer();
		cout << " ingrese  id del puesto modificado: ";
		getline(cin, id_Puestos);
		cout << " ingrese fecha de inicio de labores modificada [AAAA-MM-DD]: " << endl;
		getline(cin, fecha_inicio_labores);
		cout << " ingrese fecha y hora de ingreso modificada [AAAA-MM-DD  HH:MM:SS]: " << endl;
		getline(cin, fecha_ingreso);



		empleados e = empleados(nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, id_Puestos, fecha_inicio_labores, fecha_ingreso);
		e.leer();
		e.modificar();
		system("cls");
		system("pause");
		e.leer();
		system("pause");
		system("cls");
		break;
	}
	case 4: {
		empleados e = empleados();
		e.leer();
		e.eliminar();
		system("pause");
		system("cls");
		break;
	}
	case 0: {
		menu_principal();
		system("pause>nul");
		break;
	}
	}
}

//puesto
void menu_puestos() {
	int opcion;
	cout << "-------------- Menu Puestos: ----------------" << endl;
	cout << " 1. crear....." << endl;
	cout << " 2. leer....." << endl;
	cout << " 3. modificar..." << endl;
	cout << " 4. eliminar..." << endl;
	cout << " 0. Menu Principal" << endl;
	cout << " Seleccione su opcion: ";

	cin >> opcion;
	system("cls");
	switch (opcion) {
	case 1: {

		cout << " para ingresar......." << endl;

		string Puesto;
		cin.ignore();
		cout << " ingrese puesto: ";
		getline(cin, Puesto);
		puestos p = puestos(Puesto);

		p.crear();
		system("pause");
		system("cls");
		break;

	}

	case 2: {

		string Puesto;
		puestos p = puestos(Puesto);

		p.leer();
		system("pause");
		system("cls");
		break;

	}

	case 3: {
		cout << " para modificar......." << endl;
		string Puesto;
		cin.ignore();
		cout << " ingrese puesto modificado: ";
		getline(cin, Puesto);
		puestos p = puestos(Puesto);

		p.leer();
		p.modificar(); 
		system("cls");
		system("pause");
		p.leer();
		system("pause");
		system("cls");
		break;
	}

	case 4: {
		string Puesto;
		puestos p = puestos(Puesto);
		p.leer();
		p.eliminar();
		system("pause");
		system("cls");
		break;
	}
	case 0: {
		menu_principal();
		system("pause>nul");
		break;

	}

	}
}

//clientes
void menu_clientes() {
	int opcion;
	cout << "-------------- Menu Clientes: ----------------" << endl;
	cout << " 1. crear....." << endl;
	cout << " 2. leer....." << endl;
	cout << " 3. modificar..." << endl;
	cout << " 4. eliminar..." << endl;
	cout << " 0. Menu Principal" << endl;
	cout << " Seleccione su opcion: ";


	cin >> opcion;
	system("cls");
	switch (opcion) {
	case 1: {

		string nombres, apellidos, NIT, genero, correo_electronico, fecha_ingreso;
		int telefono = 0;
		cout << " ingrese nombres: " << endl;
		cin >> nombres;
		cout << " ingrese apellidos: " << endl;
		cin >> apellidos;
		cout << " ingrese direccion: " << endl;
		cin >> NIT;
		cout << " ingrese genero [0=M/1=F] : " << endl;
		cin >> genero;
		cout << " ingrese telefono :" << endl;
		cin >> telefono;
		cout << " ingrese correo electronico: " << endl;
		cin >> correo_electronico;


		Cliente c = Cliente(nombres, apellidos, NIT, genero, telefono, correo_electronico, fecha_ingreso);

		c.crear();
		system("pause");
		system("cls");
		break;
	}
	case 2: {
		string nombres, apellidos, nit, genero, telefono, correo_electronico, fecha_ingreso;
		Cliente c = Cliente();
		c.leer();
		system("pause");
		system("cls");
		break;
	}
	case 3: {
		string nombres, apellidos, NIT, genero, correo_electronico, fecha_ingreso;
		int telefono = 0;
		cout << " ingrese nombres modificados: " << endl;
		cin >> nombres;
		cout << " ingrese apellidos modificados: " << endl;
		cin >> apellidos;
		cout << " ingrese direccion modificada: " << endl;
		cin >> NIT;
		cout << " ingrese genero modificado [0=M/1=F]: " << endl;
		cin >> genero;
		cout << " ingrese telefono modificado:" << endl;
		cin >> telefono;
		cout << " ingrese correo electronico modificado: " << endl;
		cin >> correo_electronico;
		cout << " ingrese la fecha ingreso modificada: " << endl;
		cin >> fecha_ingreso;


		Cliente c = Cliente(nombres, apellidos, NIT, genero, telefono, correo_electronico, fecha_ingreso);
		c.leer();
		c.modificar();
		system("cls");
		system("pause");
		c.leer();
		system("cls");
		break;
	}
	case 4: {
		Cliente c = Cliente();

		c.leer();
		c.eliminar();
		system("pause");
		system("cls");
		break;
	}



	}
}

//marcas
void menu_marcas() {
	int opcion;
	cout << "-------------- Menu Marcas: ----------------" << endl;
	cout << " 1. crear....." << endl;
	cout << " 2. leer....." << endl;
	cout << " 3. modificar..." << endl;
	cout << " 4. eliminar..." << endl;
	cout << " 0. Menu Principal" << endl;
	cout << " Seleccione su opcion: ";


	cin >> opcion;
	system("cls");
	switch (opcion) {
	case 1: {

		cout << " para ingresar......." << endl;

		string Marca;
		cin.ignore();
		cout << " ingrese Marca: ";
		getline(cin, Marca);
		marcas m = marcas(Marca);

		m.crear();
		system("pause");
		system("cls");
		break;

	}

	case 2: {

		string Marca;
		marcas m = marcas(Marca);

		m.leer();
		system("pause");
		system("cls");
		break;

	}

	case 3: {
		cout << " para modificar......." << endl;
		string Marca;
		cin.ignore();

		cout << " ingrese marca: ";
		getline(cin, Marca);
		marcas m = marcas(Marca);
		
		m.leer();
		m.modificar();
		system("cls");
		system("pause");
		m.leer();
		system("pause");
		system("cls");
		break;
	}

	case 4: {
		string Marca;
		marcas m = marcas(Marca);
		m.leer();
		m.eliminar();
		system("pause");
		system("cls");
		break;
	}
	case 0: {
		menu_principal();
		system("pause>nul");
		break;

	}

	}

}

//productos
void menu_productos() {
	system("cls");
	int opcion;
	cout << "-------------- Menu Productos: ----------------" << endl;
	cout << " 1. Crear....." << endl;
	cout << " 2. Leer....." << endl;
	cout << " 3. Modificar..." << endl;
	cout << " 4. Eliminar..." << endl;
	cout << " 0. Menu Principal..." << endl;
	cout << " Seleccione su opcion: " << endl;
	cin >> opcion;
	switch (opcion) {

	case 1: {


		cout << " para insertar......." << endl;
		string product, id_Marca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso;
		cin.ignore();
		cout << " ingrese producto: ";
		getline(cin, product);
		marcas m = marcas();
		m.leer();
		cout << " ingrese id marca: ";
		getline(cin, id_Marca);
		cout << " ingrese descripcion: ";
		getline(cin, descripcion);
		cout << " ingrese imagen: ";
		getline(cin, imagen);
		cout << " ingrese el precio_costo: ";
		getline(cin, precio_costo);
		cout << " ingrese el precio_venta: ";
		getline(cin, precio_venta);
		cout << " ingrese la existencia:";
		getline(cin, existencia);



		Productos pr = Productos(product, id_Marca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso);
		pr.crear();
		system("pause");
		system("cls");
		break;
	}
	case 2: {
		Productos pr = Productos();

		pr.leer();
		system("pause");
		system("cls");
		break;

	}
	case 3: {
		cout << " para modificar......." << endl;
		string product, id_Marca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso;
		cin.ignore();
		cout << " ingrese producto modificado: ";
		getline(cin, product);
		marcas m = marcas();
		m.leer();
		cout << " ingrese id marca modificado: ";
		getline(cin, id_Marca);
		cout << " ingrese descripcion modificada: ";
		getline(cin, descripcion);
		cout << " ingrese imagen modificada: ";
		getline(cin, imagen);
		cout << " ingrese el precio_costo modificado: ";
		getline(cin, precio_costo);
		cout << " ingrese el precio_venta modificado: ";
		getline(cin, precio_venta);
		cout << " ingrese la existencia modificada: ";
		getline(cin, existencia);
		cout << " ingrese fecha y hora de ingreso modificada [AAAA-MM-DD  HH:MM:SS]: " << endl;
		getline(cin, fecha_ingreso);



		Productos pr = Productos( product, id_Marca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso);
		pr.leer();
		pr.modificar();
		system("cls");
		system("pause");
		pr.leer();
		system("pause");
		system("cls");
		break;
	}
	case 4: {
		Productos pr = Productos();
		pr.leer();
		pr.eliminar();
		system("pause");
		system("cls");
		break;
	}
	case 0: {
		menu_principal();
		system("pause>nul");
		break;
	}
	}
}

//venta
void menu_ventas() {
	int opcion;
	cout << "-------------- Menu Ventas: ----------------" << endl;
	cout << " 1. crear....." << endl;
	cout << " 2. leer....." << endl;
	cout << " 3. modificar..." << endl;
	cout << " 4. eliminar..." << endl;
	cout << " 0. Menu Principal" << endl;
	cout << " Seleccione su opcion: ";

	cin >> opcion;
	system("cls");
	switch (opcion) {
	case 1: {
		cout << " para ingresar......." << endl;

		string cantidad, precio_uni, serie, fecha_factura, fecha_ingreso, consulta;
		int id_Ventas;
		int id_Clientes;
		int id_Empleados;

		if (no_factura == 100) {
			no_factura = 0;
			variable++;
		}
		cin.ignore();
		no_factura++;
		cin.ignore();
		cout << " numero de factura: " << endl;
		cout << no_factura;
		cin.ignore();
		cout << " ingrese serie: " << endl;
		serie = cadena[variable];
		cout << serie;
		cin.ignore();
		Cliente c = Cliente();
		c.leer();
		cout << " ingrese id de cliente :" << endl;
		cin >> id_Clientes;
		cin.ignore();
		empleados e = empleados();
		e.leer();
		cout << " ingrese id de empleado : " << endl;
		cin >> id_Empleados;
		cin.ignore();
		Productos pr = Productos();
		pr.leer();
		cout << " ingrese id del producto : " << endl;
		cin >> id_Producto;
		cin.ignore();
		cout << " ingrese cantidad : " << endl;
		cin >> cantidad;
		cin.ignore();
		cout << " ingrese precio unitario: " << endl;
		cin >> precio_uni;
		cin.ignore();
		
		ventas v = ventas(cantidad, precio_uni, id_Producto, id_Ventas, no_factura, serie, fecha_factura, id_Clientes, id_Empleados, fecha_ingreso);
		int vent = stoi(id_Ventas);
		v.crearVentas();
		id_Ventas = v.asignar();
		v.crearVentaDetalle();
		system("pause");
		system("cls");
		break;
	}
	case 2: {
		ventas v = ventas();

		v.leerVentas();
		v.leerVentaDetalle();
		system("pause");
		system("cls");
		break;
	}
	case 3: {
		cout << " para modificar......." << endl;
		string cantidad, precio_uni, serie, fecha_factura, fecha_ingreso;
		int no_factura;
		int id_Clientes;
		int id_Empleados;
		cout << " ingrese numero de factura: " << endl;
		cin >> no_factura;
		cout << " ingrese serie: " << endl;
		cin >> serie;
		cout << " ingrese fecha de factura: " << endl;
		cin >> fecha_factura;
		cout << " ingrese id de cliente :" << endl;
		cin >> id_Clientes;
		cout << " ingrese id de empleado : " << endl;
		cin >> id_Empleados;
		cout << " ingrese fecha ingreso : " << endl;
		cin >> fecha_ingreso;
		cout << " ingrese id del producto : " << endl;
		cin >> id_Producto;
		cin.ignore();
		cout << " ingrese cantidad : " << endl;
		cin >> cantidad;
		cin.ignore();
		cout << " ingrese precio unitario: " << endl;
		cin >> precio_uni;
		cin.ignore();

		ventas v = ventas(cantidad, precio_uni,id_Producto, id_Ventas,no_factura, serie, fecha_factura, id_Clientes, id_Empleados, fecha_ingreso);
		v.modificar();
		v.leerVentas();
		system("pause");
		system("cls");
		break;
	}
	case 4: {
		ventas v = ventas();

		v.eliminar();
		system("pause");
		system("cls");
		break;

	}
	case 0: {
		menu_principal();
		system("pause>nul");
		break;

	}

	}
}

//proveedores
void menu_proveedores() {
	int opcion;
	cout << "-------------- Menu Productos: ----------------" << endl;
	cout << " 1. crear....." << endl;
	cout << " 2. leer....." << endl;
	cout << " 3. modificar..." << endl;
	cout << " 4. eliminar..." << endl;
	cout << " 0. Menu Principal" << endl;
	cout << " Seleccione su opcion: ";


	cin >> opcion;
	system("cls");
	switch (opcion) {

	case 1: {
		cout << " para ingresar......." << endl;

		string proveedor, nit, direccion, telefono;
		cin.ignore();
		cout << " ingrese proveedor: " << endl;
		getline(cin, proveedor);
		cout << " ingrese NIT: " << endl;
		getline(cin, nit);
		cout << " ingrese direccion: " << endl;
		getline(cin, direccion);
		cout << " ingrese telefono:" << endl;
		getline(cin, telefono);


		proveedores pr = proveedores(proveedor, nit, direccion, telefono);

		pr.crear();
		system("pause");
		system("cls");
		break;


	}
	case 2: {
		proveedores pr = proveedores();
		pr.leer();
		system("pause");
		system("cls");
		break;
	}
	case 3: {
		cout << " para modificar......." << endl;

		string proveedor, nit, direccion, telefono;
		cin.ignore();
		cout << " ingrese proveedor: " << endl;
		getline(cin, proveedor);
		cout << " ingrese NIT: " << endl;
		getline(cin, nit);
		cout << " ingrese direccion: " << endl;
		getline(cin, direccion);
		cout << " ingrese telefono:" << endl;
		getline(cin, telefono);


		proveedores pr = proveedores(proveedor, nit, direccion, telefono);

		pr.modificar();
		system("pause");
		system("cls");
		break;


	}
	case 4: {
		proveedores pr = proveedores();
		pr.eliminar();
		system("pause");
		system("cls");
		break;


	}
	case 0: {
		menu_principal();
		system("pause>nul");
		break;

	}
	}
}

//ventas mio
/*void menu_ventas() {
	system("cls");
	int opcion;
	cout << "-------------- Menu Productos: ----------------" << endl;
	cout << " 1. Crear Ventas....." << endl;
	cout << " 2. Crear Venta Detalle....." << endl;
	cout << " 3. Leer....." << endl;
	cout << " 4. Modificar Ventas..." << endl;
	cout << " 5. Modificar Venta Detalle..." << endl;
	cout << " 6. Eliminar Ventas..." << endl;
	cout << " 7. Eliminar Venta Detalle..." << endl;
	cout << " 0. Menu Principal..." << endl;
	cout << " Seleccione su opcion: " << endl;
	cin >> opcion;
	switch (opcion) {

	case 1: {

		cout << " para insertar......." << endl;
		string id_ventas, id_producto, cantidad, precio_unitario, no_factura, serie, fecha_factura, id_Clientes, id_Empleado, fecha_ingreso;
		cin.ignore();
		cout << " ingrese no factura: ";
		getline(cin, no_factura);
		cout << " ingrese serie: ";
		getline(cin, serie);
		cout << " ingrese fecha_factura: ";
		getline(cin, fecha_factura);
		Cliente c = Cliente();
		cout << " ingrese id cliente: ";
		getline(cin, id_Clientes);
		empleados e = empleados();
		cout << " ingrese el id empleado: ";
		getline(cin, id_Empleado);


		Venta_Detalle v = Venta_Detalle(id_ventas, id_producto, cantidad, precio_unitario, no_factura, serie, fecha_factura, id_Clientes, id_Empleado, fecha_ingreso);
		v.crearVentas();
		system("pause");
		system("cls");
		break;
	}

	case 2: {

		cout << " para insertar en Venta/Detalle......." << endl;
		string id_ventas, id_producto, cantidad, precio_unitario, no_factura, serie, fecha_factura, id_Clientes, id_Empleado, fecha_ingreso;
		cin.ignore();
		cout << " ingrese el id venta: ";
		getline(cin, id_ventas);
		Productos pr = Productos();
		pr.leer();
		cout << " ingrese id producto: ";
		getline(cin, id_producto);
		cout << " ingrese cantidad: ";
		getline(cin, cantidad);
		cout << " ingrese precio unitario: ";
		getline(cin, precio_unitario);


		Venta_Detalle v = Venta_Detalle(id_ventas, id_producto, cantidad, precio_unitario, no_factura, serie, fecha_factura, id_Clientes, id_Empleado, fecha_ingreso);
		v.crearVentas();
		system("pause");
		system("cls");
		break;
	}

	case 3: {
		Venta_Detalle v = Venta_Detalle();

		v.leer();
		system("pause");
		system("cls");
		break;

	}
	case 4: {
		cout << " para modificar ventas......." << endl;
		string id_ventas, id_producto, cantidad, precio_unitario, no_factura, serie, fecha_factura, id_Clientes, id_Empleado, fecha_ingreso;
		cin.ignore();
		cin.ignore();
		cout << " ingrese no factura: ";
		getline(cin, no_factura);
		cout << " ingrese serie: ";
		getline(cin, serie);
		cout << " ingrese fecha_factura: ";
		getline(cin, fecha_factura);
		Cliente c = Cliente();
		cout << " ingrese id cliente: ";
		getline(cin, id_Clientes);
		empleados e = empleados();
		cout << " ingrese el id empleado: ";
		getline(cin, id_Empleado);
		cout << " ingrese fecha y hora de ingreso modificada [AAAA-MM-DD  HH:MM:SS]: " << endl;
		getline(cin, fecha_ingreso);



		Venta_Detalle v = Venta_Detalle(id_ventas, id_producto, cantidad, precio_unitario, no_factura, serie, fecha_factura, id_Clientes, id_Empleado, fecha_ingreso);
		v.leer();
		v.modificarVentas();
		system("cls");
		system("pause");
		v.leer();
		system("pause");
		system("cls");
		break;
	}
	

	case 5: {
		cout << " para modificar venta detalle......." << endl;
		string id_ventas, id_producto, cantidad, precio_unitario, no_factura, serie, fecha_factura, id_Clientes, id_Empleado, fecha_ingreso;
		cin.ignore();
		cout << " ingrese el id venta: ";
		getline(cin, id_ventas);
		Productos pr = Productos();
		pr.leer();
		cout << " ingrese id producto: ";
		getline(cin, id_producto);
		cout << " ingrese cantidad: ";
		getline(cin, cantidad);
		cout << " ingrese precio unitario: ";
		getline(cin, precio_unitario);

		Venta_Detalle v = Venta_Detalle(id_ventas, id_producto, cantidad, precio_unitario, no_factura, serie, fecha_factura, id_Clientes, id_Empleado, fecha_ingreso);
		v.leer();
		v.modificarVentaDetalle();
		system("cls");
		system("pause");
		v.leer();
		system("pause");
		system("cls");
		break;
	}
	case 6: {
		Venta_Detalle v = Venta_Detalle();
		v.leer();
		v.eliminarVentas();
		system("pause");
		system("cls");
		break;
	}
	case 7: {
		Venta_Detalle v = Venta_Detalle();
		v.leer();
		v.eliminarVentasDetalle();
		system("pause");
		system("cls");
		break;
	}
	case 0: {
		menu_principal();
		system("pause>nul");
		break;
	}
	}
}*/



