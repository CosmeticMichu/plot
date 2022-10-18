#include <iostream>
//#include <fstream>
#include <vector>
//#include <boost/tuple/tuple.hpp>
#include "get_data.h"
#include "gnuplot-iostream.h"
//#include "/home/eariasp/include/gnuplot-iostream/gnuplot-iostream.h"

typedef std::vector<double> vector;
typedef std::vector<std::vector<double>> matrix;

int main(void){

    Gnuplot gp;

    std::string name = "R-P.txt";//recibe el nombre del archivo -y su extensión- en el que se encuentran los datos

    int N = 0;
    int M = 0;

    N = getnumberofrows(name);
    M = getnumberofcols(name);
                                                \
    vector x(N, 0.0);//importante declararlos despues de esto porque luego no se vuelven a llenar,
    vector y(N, 0.0);//si se declaran cuando M y N = 0, arroja seegmentation fault

    matrix data(M, std::vector<double>(N));

    //std::vector <std::vector<double>> gnup(M, std::vector<double>(N));

    data = get_data(name);

    //LOAD VECTORS

    for (int ii = 0; ii <= N-1; ++ii){
        x[ii] = data[0][ii];
        y[ii] = data[1][ii];
    }

    //PRINT DATA

    gp << "plot '-' w lp t 'aja y q'\n";
    gp.send1d(data);
}
