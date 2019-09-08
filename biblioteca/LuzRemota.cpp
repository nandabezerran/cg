#include "LuzRemota.hpp"
# define M_PI 3.14159265358979323846  /* pi */

LuzRemota::LuzRemota(int r, int g, int b, VectorXd Dr): Luz(r, g, b){

}

VectorXd LuzRemota::calcularIntensidadeRemota(PontoIntersecao* p){

    VectorXd Ir(3);
 
 /*
    VectorXd normal = p->o->calcularNormal(p);
    normaDr = sqrt(biblioteca::ProdutoEscalar(this->Dr,this->Dr,3));
    normaN = sqrt(biblioteca::ProdutoEscalar(normal,normal,3));

    angulo = (biblioteca::ProdutoEscalar(normal, this->Dr, 3))/normaDr*normaN;


	Ir[0] = 0;
  	Ir[1] = 0;
  	Ir[2] = 0;

    if (0 < angulo && angulo < M_PI){

    	Ir[0] = intensidadeRgb[0] * p->o->rgb[0];
    	Ir[1] = intensidadeRgb[1] * p->o->rgb[1];
    	Ir[2] = intensidadeRgb[2] * p->o->rgb[2];

    }
*/   
	return Ir; 

}

