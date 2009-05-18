#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

void removeBarras (string &kText)
{
	int iTileInit = (int)(kText.find("<tilesetTile"));
	while (iTileInit != (int)(kText.npos))
	{
		int iPosBarra = (int)(kText.find('/', iTileInit));
		kText.replace(iPosBarra, 1, " ");
		iTileInit = (int)(kText.find("<tilesetTile", iTileInit + 1));
	}

	int iAnimTileInit = (int)(kText.find("<animatedTile"));
	while (iAnimTileInit != (int)(kText.npos))
	{
		int iPosBarra = (int)(kText.find('/', iAnimTileInit));
		kText.replace(iPosBarra, 1, " ");
		iAnimTileInit = (int)(kText.find("<animatedTile", iAnimTileInit + 1));
	}

	int iNullTileInit = (int)(kText.find("<nullTile"));
	while (iNullTileInit != (int)(kText.npos))
	{
		int iPosBarra = (int)(kText.find('/', iNullTileInit));
		kText.replace(iPosBarra, 1, " ");
		iNullTileInit = (int)(kText.find("<nullTile", iNullTileInit + 1));
	}
}

void main( int argc, char *argv[] ) 
{
	ifstream kArchivoXML;
	ofstream kArchivoDestino;

	/*
	cout << "Ingrese la ruta del archivo de origen" << endl;

	string kOriginalFilePath;
	cin >> kOriginalFilePath;

	cout << "Ingrese la ruta del archivo de destino" << endl;

	string kDesFilePath;
	cin >> kDesFilePath;
	
	char* cOriginalFilePath((char*)kOriginalFilePath.c_str());
	char* cArchivoDestino((char*)kDesFilePath.c_str());
	*/
	char* cOriginalFilePath(argv[1]);
	char* cArchivoDestino(argv[1]);

	kArchivoXML.open(cOriginalFilePath);

	if (kArchivoXML.is_open())
	{
		string kFileText="";
		char cAux[51];
		while (!kArchivoXML.eof())
		{
			kArchivoXML.read(cAux,50);
			cAux[kArchivoXML.gcount()]='\0';
			kFileText.append(cAux);
		}
		kArchivoXML.close();
		/*
		cout << kFileText << endl;
		cout << "------------------ X --------------------" << endl;
		*/

		removeBarras(kFileText);
		
		/*
		cout << kFileText << endl;
		cout << "------------------ X --------------------" << endl;
		*/

		kArchivoDestino.open(cArchivoDestino);

		if (kArchivoDestino.is_open())
		{
			kArchivoDestino << kFileText;
			kArchivoDestino.close();
		}
		else
		{
			cout << "No se pudo abrir el archivo de salida" << endl;
		}

		cout << "Proceso completado con exito" << endl;
		
	}
	else
	{
		cout << "No se pudo abrir el archivo original" << endl;
	}

	system("PAUSE");
}