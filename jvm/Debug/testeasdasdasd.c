
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

union u_double
{
    double  dbl;
    char    data[sizeof(double)];
};

int main(){

printf("******tamanho de int %d\n",sizeof(short int));
    union u_double d,d1;
    d.dbl = 34.0346;
    int i = 0;
    unsigned int aux,aux2;
    printf("d = %f\n",d.dbl);

    printf("c0 = %d\n",d.data[0]);
    printf("c1 = %d\n",d.data[1]);
    printf("c2 = %d\n",d.data[2]);
    printf("c3 = %d\n",d.data[3]);
    printf("c4 = %d\n",d.data[4]);
    printf("c5 = %d\n",d.data[5]);
    printf("c6 = %d\n",d.data[6]);
    printf("c7 = %d\n",d.data[7]);

    aux = ((d.data[0]&0x00ff)<<24)|((d.data[1]&0x00ff)<<16)|((d.data[2]&0x00ff)<<8)|((d.data[3]&0x00ff));
    aux2 = ((d.data[4]&0x00ff)<<24)|((d.data[5]&0x00ff)<<16)|((d.data[6]&0x00ff)<<8)|((d.data[7]&0x00ff));

    printf("%d ... %d\n",aux,aux2);

    d1.data[0] = (aux&0xFF000000)>>24;
    d1.data[1] = (aux&0x00FF0000)>>16;
    d1.data[2] = (aux&0x0000FF00)>>8;
    d1.data[3] = (aux&0x000000FF);
    d1.data[4] = (aux2&0xFF000000)>>24;
    d1.data[5] = (aux2&0x00FF0000)>>16;
    d1.data[6] = (aux2&0x0000FF00)>>8;
    d1.data[7] = (aux2&0x000000FF);
    //d1.dbl = ((long long)(aux&0x0000FFFF)<<32)|(0x0000FFFF&aux2);
    /*d1.data[0]=d.data[0];
    d1.data[1]=d.data[1];
    d1.data[2]=d.data[2];
    d1.data[3]=d.data[3];
    d1.data[4]=d.data[4];
    d1.data[5]=d.data[5];
    d1.data[6]=d.data[6];
    d1.data[7]=d.data[7];*/
    printf("c0 = %d\n",d1.data[0]);
    printf("c1 = %d\n",d1.data[1]);
    printf("c2 = %d\n",d1.data[2]);
    printf("c3 = %d\n",d1.data[3]);
    printf("c4 = %d\n",d1.data[4]);
    printf("c5 = %d\n",d1.data[5]);
    printf("c6 = %d\n",d1.data[6]);
    printf("c7 = %d\n",d1.data[7]);
    printf("d1 = %f\n",d1.dbl);

  /*  double d3= 653.076869;
    double d1,d2;
	unsigned int aux,aux2,aux3,aux4;
//int endereco = ((&d3+sizeof(double)/2));
	memcpy(&aux,&d3,sizeof(unsigned int));
	memcpy(&aux2,((&d3)+sizeof(unsigned int)),sizeof(unsigned int));
	aux3 = aux;
	aux4 = aux2;
	printf("%d ... %d\n",aux,aux2);
	printf("iniciando\n");
	memcpy(&d1,&aux3,sizeof(unsigned int));
	printf("iniciando2\n");
	//memcpy((&d1)+sizeof(unsigned int),&aux4,sizeof(unsigned int));
	printf("finalizando\n");
	//printf("%f",*d1);
	//printf("%d ...  %d",*aux,*aux2);
	printf("result: %lf",d1);*/
    return 0;
}






