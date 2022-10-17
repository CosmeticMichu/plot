#include <iostream>
//#include <fstream>
#include <vector>
//#include <boost/tuple/tuple.hpp>
#include "get_data.h"
#include "/home/eariasp/include/gnuplot-iostream/gnuplot-iostream.h"

typedef std::vector<double> vector;

int getnumberofrows(const std::string& name);
int getnumberofcols(const std::string& name);
vector get_data(const std::string& name, int j);

int main(void){

    std::string name = "R-P.txt";//recibe el nombre del archivo -y su extensión- en el que se encuentran los datos

    int N = 0;
    int M = 0;

    N = getnumberofrows(name);
    M = getnumberofcols(name);

    vector x(N, 0.0);
    vector y(N, 0.0);
    std::vector<std::vector<double>> aux;

    x = get_data(name, 0);
    y = get_data(name, 1);
    //toca meter ambos vectores en una matriz para pasarselo a gnuplot, si se imprime en un archivo, aumenta el tiempo de compilación innecesariamente
    //Gnuplot gp;
    //gp << "plot '-' w lp, plot '-' with lp\n";
    //gp.send1d(x);

}
