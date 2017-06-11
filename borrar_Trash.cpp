#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <dirent.h>

using namespace std;

void list_dir(string dir);
void delete_file(string dir, string file);
list<string> aList;

int main(int argc, char const *argv[])
{
	list<string> kaList;
	list<string> trList;
	list<string>::iterator kazaa;
	list<string>::iterator trash;		
	if(argc != 3)
	{
		cout << "Forma de uso = " << argv[0] << " [directorio KAZAA]" << "[directorio TRASH]"<< endl;
		exit(0);
	}
	string dir = argv[1];
	string dir2 = argv[2];
	//Se genera  la lista de archivos  del directorio KAZAA  y del directorio TRASH
	list_dir(dir);
	for(kazaa = aList.begin(); kazaa != aList.end(); kazaa++)
	{
	   //cout << *iter << endl;
		kaList.push_back(*kazaa);
	}	
	aList.clear();

	list_dir(dir2);
	for(trash = aList.begin(); trash != aList.end(); trash++)
	{
	   //cout << *iter << endl;
		trList.push_back(*trash);
	}
	aList.clear();

	/*Ciclo para comparar listas en caso de que coincida el nombre de archivo de
	la carpeta TRASH con un archivo de la carpeta KAZAA lo eliminara*/
	for(trash = trList.begin(); trash != trList.end(); trash++)
	{
		string ftrash =  *trash;		
		for(kazaa = kaList.begin(); kazaa != kaList.end(); kazaa++)
		{			
	   		if(ftrash == *kazaa)
	   		{
	   			delete_file(dir, ftrash);
	   			cout << "Archivo " << ftrash << " eliminado de carpeta KAZAA" <<  endl;
	   		}		
		}	   		
	}


	return 0;
}

void list_dir(string dir)
{
	DIR * directorio;
	struct dirent * archivo;
	string arch;
	if (directorio = opendir(dir.c_str()))
	 {
	 	while(archivo = readdir(directorio))
	 	{
	 		arch  = archivo -> d_name;
	 		if (arch != "." && arch != "..")
	 		{
	 			aList.push_back(arch);
	 		}
	 	}
	 }	 
	 closedir(directorio);

	 return;	
}

void delete_file(string dir, string file)
{	
	string comando;
	 	comando = "rm " + dir + "/" +file;
	 	system(comando.c_str()); 			 
	 return;	
}