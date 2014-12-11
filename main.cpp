#include <iostream>
#include <stdlib.h>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

void descargar(string);
void borrar(string);
void mostrarDatos(string);

int main()
{
    cout<<"Consulta del clima con la api de openweathermap.org"<<endl;
    string nombre;
    cout << "Ingrese el nombre deciudad: ";
    cin >> nombre;
    descargar(nombre);
    mostrarDatos(nombre);
    borrar(nombre);
    return 0;
}

void descargar(string nombre){
    cout<<"---------------------------\n\tDescarga"<<endl;
    cout<<"---------------------------"<<endl;
    string descarga="wget -N -nv \"http://api.openweathermap.org/data/2.5/weather?q="+nombre+"&mode=xml\"";
    system(descarga.c_str());
}

void borrar(string nombre){
    cout<<"---------------------------\n\tBorrando Cache"<<endl;
    cout<<"---------------------------"<<endl;
    string borrar="rm \"weather?q="+nombre+"&mode=xml\"";
    system(borrar.c_str());
}

void mostrarDatos(string nombre){
    cout<<"---------------------------\n\tVer Datos"<<endl;
    cout<<"---------------------------"<<endl;
    XMLDocument doc;
    string archivo = "weather?q="+nombre+"&mode=xml";
    doc.LoadFile(archivo.c_str());
    if(doc.Error()){
        borrar(nombre);
    }
    XMLElement* Current = doc.FirstChildElement("current");
    XMLElement* City = Current->FirstChildElement("city");
    cout<<"Ciudad: "<<City->Attribute("name")<<endl;
    XMLElement* Temperature = Current->FirstChildElement("temperature");
    cout<<"Unidad de Temperatura: "<<Temperature->Attribute("unit")<<endl;
    cout<<"Temperatura Actual: "<<Temperature->Attribute("value")<<endl;
    cout<<"Temperatura Minima: "<<Temperature->Attribute("min")<<endl;
    cout<<"Temperatura Maxima: "<<Temperature->Attribute("max")<<endl;
    XMLElement* Humidity = Current->FirstChildElement("humidity");
    cout<<"Humedad: "<< Humidity->Attribute("value")<<Humidity->Attribute("unit")<<endl;
    XMLElement* Pressure = Current->FirstChildElement("pressure");
    cout<<"Presion Atmosferica: "<<Pressure->Attribute("value")<<Humidity->Attribute("unit")<<endl;
    XMLElement* Wind = Current->FirstChildElement("wind");
    XMLElement* Speed = Wind->FirstChildElement("speed");
    XMLElement* Direction = Wind->FirstChildElement("direction");
    cout<<"Velocidad del Viento: "<<Speed->Attribute("value")<<endl;
    cout<<"Comentario Sobre Velocidad: "<<Speed->Attribute("name")<<endl;
    cout<<"Direccion del Viento: "<<Direction->Attribute("name")<<endl;
    XMLElement* Clouds = Current->FirstChildElement("clouds");
    cout<<"Nubes: "<<Clouds->Attribute("value")<<endl;
    cout<<"Comentario Sobre las Nubes: "<<Clouds->Attribute("name")<<endl;
    XMLElement* Precipitation = Current->FirstChildElement("precipitation");
    cout<<"Tener Precaucion? "<<Precipitation->Attribute("mode")<<endl;
    XMLElement* Weather = Current->FirstChildElement("weather");
    cout<<"Clima: "<<Weather->Attribute("value")<<endl;
    XMLElement* Lastupdate = Current->FirstChildElement("lastupdate");
    cout<<"Ultima Actualizacion: "<<Lastupdate->Attribute("value")<<endl;
}
