#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

typedef std::vector<double> vector;

int getnumberofrows(const std::string& name);
int getnumberofcols(const std::string& name);
vector get_data(const std::string& name, int j);


int getnumberofrows(const std::string& name)
{
    int number_of_rows = 0;
    std::string line;

    std::ifstream file(name);

    while (std::getline(file, line))

        ++number_of_rows;

    file.close();

    return number_of_rows;
}

int getnumberofcols(const std::string& name)
{
    std::ifstream file(name); //open your file
    std::string line;
    std::stringstream s;
    int number_of_cols = 0;
    double value;

    std::getline(file, line);         //read the first line of your file to string

    s << line;                   //send the line to the stringstream object...

    while(s >> value) number_of_cols++;  //while there's something in the line, increase the number of columns

    file.close();

    return number_of_cols;
}

vector get_data(const std::string& name, int j)
{
    //ESTE PROGRAMA CREA UNA MATRIZ A PARTIR DEL ARCHIVO EXISTENTE, PARA PODER EXTRAER LOS DATOS POR COLUMNAS

    int N = getnumberofrows(name);
    int M = getnumberofcols(name);

    //SE CREA LA MATRIZ Y UN VECTOR AUXILIAR PARA RETORNAR LAS COLUMNAS
    std::vector<std::vector<double>> matrix(M, std::vector<double>(N));//emula una matriz de n filas y m columnas, la sintaxis matrix[j][i] indica que se está en la columna j y la fila i
    vector aux(N, 0.0);

    //SE EXTRAEN LOS DATOS DEL ARCHIVO name EN LA MATRIZ
    std::ifstream file(name);

    for(int ii = 0; ii <= N-1; ++ii){
        for(int jj = 0; jj <= M-1; ++jj){
            file >> matrix[jj][ii];//ifstream barre por columnas, en este bucle interno se cargan vectores fila, es decir, se indexa cada columna (jj) de la matriz para una misma fila (ii)
                                   //se tiene en general el primer elemento de la j-ésima columna, al sali del blucle se cambia de elemento en cada columna
        }
    }

    file.close();

    for(int k = 0; k <= N-1; ++k){
        aux[k] = matrix[j][k];
    }

    return aux;
}
