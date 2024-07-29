#include <stdio.h>

struct ponto{
    float x, y;
};
typedef struct ponto Ponto;

struct circulo{
    Ponto p; //centro do circulo
    float r; //raio do circulo
};
typedef struct circulo Circulo;

float distancia (Ponto* p, Ponto* q){
    float d = sqrt(pow(q->x - p->x, 2));
    return d;
}

int interior (Circulo* c, Ponto* p){
    float d = distancia(&c->p, p);
    return (d < c-> r);
}

int main(){
    
}