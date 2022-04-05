/*
	Villeda Patricio Arón Alejandro
	2BV1 - Estructrua de Datos
	Instituto Politecnico nacional - ESCOM
	Ingeniería en Inteligencía Artificial
*/

//LIBRERIAS
#include <iostream>
#include <time.h>
using namespace std;

//CREACION DEL NODO
typedef struct
{
    string Nombre;
    float Precio;
    char Clave;
    short int ID;
}   Informacion;



typedef struct Nodo
{
    Informacion informacion;
    Nodo *ElementoSiguiente;
}   Nodo;

//PROTOTIPOS
void AgregarInicio(Nodo *INICIO);
void AgregarFinal(Nodo *INICIO);
void ImprimirLista(Nodo *INICIO);
ostream& operator<<(ostream &os, Nodo &Iterador);


//CLASE PRINCIPAL
int main()
{
    system("Color F0");
    system("title MENU DE LISTAS");

    short int Respuesta;
    Nodo *INICIO = NULL; //Se crea un nuevo nodo llamado lista, cuyo valor es NULL
    INICIO = new Nodo(); //Se reserva en memoria

//MENU
    do
    {
        system("cls");

        cout<< "**********************"<< endl;
        cout<< "\tListas\n";
        cout<< "**********************"<< endl;

        cout<< "\tMENU DE LISTAS"<< endl;
        cout<< "\t  [1]. Agregar elemento al inicio de la lista"<< endl;
        cout<< "\t  [2]. Agregar elemento al final de la lista"<< endl;
        cout<< "\t  [3]. Mostrar lista"<< endl;
        cout<< "\t  [4]. Salir"<< endl;
        cout<< "\tRespuesta:  ";
        cin>> Respuesta;

        switch(Respuesta)
        {
            case 1: AgregarInicio(INICIO); break;

            case 2: AgregarFinal(INICIO); break;

            case 3: ImprimirLista(INICIO); break;

            case 4: cout<< "\n\t\tGracias por su tiempo"<< endl; break;

            default: cout<< "\n\tEscriba otro numero"<< endl; break;
        }
         cout<< "\n\t\t"; system("pause");

    }   while(Respuesta != 4);


	return 0;
}

//ESTA FUNCION SIRVE PARA AGREGAR ELEMENTOS A LA LISTA
void AgregarInicio(Nodo *INICIO)
{
    string nombre;
    float precio;
    char clave;
    short int id;

    cout<< "\n\tAGREGANDO DATO A INICIO"<< endl;
    cout<< "\t\tEscriba el nombre del dato: ";
    cin>> nombre;
    cout<< "\t\tEscriba el precio del dato: $";
    cin>> precio;
    cout<< "\t\tEscriba la clave del dato: ";
    cin>> clave;
    id = rand()%1001;

    Nodo *DatoNuevo = new Nodo();           //Creamos un nuevo nodo llamado DatoNuevo
    DatoNuevo -> informacion.Nombre= nombre;    //Le asignamos valor al nuevo nodo
    DatoNuevo -> informacion.Precio = precio;   //Le asignamos valor al nuevo nodo
    DatoNuevo -> informacion.Clave = clave;     //Le asignamos valor al nuevo nodo
    DatoNuevo -> informacion.ID = id;           //Le asignamos valor al nuevo nodo
    DatoNuevo -> ElementoSiguiente = NULL;  //Apunta a NULL

    if(INICIO == NULL)
    {
        INICIO -> ElementoSiguiente = DatoNuevo; //Ahora, la lista apunta al nuevo elemento
    }

    else
    {
        DatoNuevo -> ElementoSiguiente = INICIO -> ElementoSiguiente;    //Decimos que el nuevo nodo apunte al anterior nodo creado
        INICIO -> ElementoSiguiente = DatoNuevo;         //Ahora el nodo INICIO apunta al nodo recien creado
    }
}

//ESTA FUNCION SIRVE PARA AGREGAR ELEMENTOS AL FINAL DE LA LISTA
void AgregarFinal(Nodo *INICIO)
{
    string nombre;
    float precio;
    char clave;
    short int id;

    Nodo *Iterador;                 //Se crea un nodo llamado iterador, nos ayudará a recorrer nuestra lista
    Nodo *DatoNuevo = new Nodo();   //Creamos nuestro nodo nuevo
    Iterador = INICIO;               //Igualamos al iterador con INICIO


    cout<< "\n\tAGREGANDO DATO A FINAL"<< endl;
    cout<< "\t\tEscriba el nombre del dato: ";
    cin>> nombre;
    cout<< "\t\tEscriba el precio del dato: $";
    cin>> precio;
    cout<< "\t\tEscriba la clave del dato: ";
    cin>> clave;
    id = rand()%1001;

    while( (Iterador -> ElementoSiguiente) != NULL )    //Siempre que el elemento siguiente del iterador sea distinto de NULL
    {
        Iterador = Iterador -> ElementoSiguiente;   //El iterador avanza
    }

    DatoNuevo -> ElementoSiguiente = NULL;      //Nuestro nuevo elemento apunta a NULL
    Iterador -> ElementoSiguiente = DatoNuevo;  //El nodo anterior apunta al nuevo nodo

    DatoNuevo -> informacion.Nombre= nombre;    //Le asignamos valor al nuevo nodo
    DatoNuevo -> informacion.Precio = precio;   //Le asignamos valor al nuevo nodo
    DatoNuevo -> informacion.Clave = clave;     //Le asignamos valor al nuevo nodo
    DatoNuevo -> informacion.ID = id;           //Le asignamos valor al nuevo nodo
}

//ESTA FUNCION SIRVE IMPRIMIR TODOS LOS ELEMENTOS PRESENTES EN LA LISTA
void ImprimirLista(Nodo *INICIO)
{
    Nodo *Iterador;      //Creamos el iterador
    Iterador = INICIO;   //Lo igualamos a la lista para que comience en el inicio
    short int NumeroNodos = 0;

    cout<< "\n\tImpresion: [INICIO ---- FINAL]";
    while( (Iterador -> ElementoSiguiente) != NULL )    //Siempre que el elemento siguiente del iterador sea distinto de NULL
    {
        NumeroNodos++;
        Iterador = Iterador -> ElementoSiguiente;   //El iterador avanza
        cout<< "\n\n\t\tNodo "<< NumeroNodos<< "\n\t\t\t";
        cout<< (*Iterador);
        //ostream(*Iterador);

    }
}

//SOBRECARGA DE OPERADOR
//ostream& operator<<(ostream& os, Nodo &nodo)
ostream& operator<<(ostream &os, Nodo &Iterador)
{
    os<< "Nombre: "<< Iterador.informacion.Nombre<< "\n\t\t\t";
    os<< "Precio: $"<< Iterador.informacion.Precio<< "\n\t\t\t";
    os<< "Clave:\t"<< Iterador.informacion.Clave<< "\n\t\t\t";
    os<< "ID:\t"<< Iterador.informacion.ID<< endl;
    return os;
}
