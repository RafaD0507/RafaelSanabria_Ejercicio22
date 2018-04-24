#include <iostream>
#include <cmath>

using namespace std;

double u_t_inicial(double x);

int main(){
  double D = 1.0;
  double x_max = 2.0;
  double x = 0;
  double dx = 0.01;
  double dt = dx*dx*dx;
  int N_x = x_max/dx + 1;
  double *u = new double[N_x];
  double *temp = new double[N_x];
  double *init = new double[N_x];

  for(int i=0; i<N_x; i++){
    init[i] = u_t_inicial(x);
    u[i] = u_t_inicial(x);
    temp[i] = u_t_inicial(x);
    x = x + dx;
  }
  
  while(u[N_x/2]>0.5){
    for(int i=1; i<N_x-1; i++){
      u[i] = temp[i]+D*(dt/(dx*dx))*(temp[i+1]+temp[i-1]-2*temp[i]);
    }
    
    for(int i=1; i<N_x-1; i++){
      temp[i] = u[i];
    }
  }
  
  x = 0;
  for(int i=0; i<N_x; i++){
    cout<<x<<" "<<u[i]<< " " << init[i] << endl;
    x = x+ dx;
  }
return 0;
}

double u_t_inicial(double x){
  return exp(-(pow(x-1,2))/(2*pow(0.1,2)));
}
