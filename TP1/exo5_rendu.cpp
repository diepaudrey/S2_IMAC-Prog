#include <iostream>
#include <cmath>

using namespace std;

struct Complexe{
    double reel;
    double img;
};


double moduleComplexe(Complexe c){
    double module = sqrt(c.reel*c.reel + c.img*c.img);
    return module;

}

int Mandelbrot(Complexe z, int n, Complexe point){
    Complexe z_n;
    if(n==0){
        return 0;
    }
    z_n.reel = z.reel*z.reel - z.img*z.img + point.reel; //partie reelle
    z_n.img = 2*z.reel*z.img + point.img;  //partie imaginaire
    
    int mod = moduleComplexe(z_n); 

    if(mod<2){
        return Mandelbrot(z_n, n-1, point); 
    }
    else{
        return -1; //le point n'appartient pas à l'ens 
    }
}


int main(){
    Complexe z;
    Complexe point1 = {-1,0};
    Complexe point2 = {1,0};

    if(Mandelbrot(z,10,point2)==0){
        cout << "Le point appartient à l'ensemble de Mandelbrot" << endl;
    }
    else{
        cout << "Le point n'appartient pas à l'ensemble de Mandelbrot" << endl;
    }
    
    return 0;
}