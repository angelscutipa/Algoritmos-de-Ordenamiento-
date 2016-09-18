#include <iostream>

using namespace std;

void swap(int *a,int *b){
    int *c;
    c=a;
    *a=*b;
    *b=*c;
}

void burbuja(int *p, int tam){
    for (int i =0; i<tam; i++){
        for (int j =0; j<tam-1; j++){
            if(*(p+j)>*(p+j+1))
                swap(*(p+j),*(p+j+1));
        }
    }
}

void selection(int *p, int tam){
    int *tem;
    for (int i=0; i<tam-1; i++){
        tem=(p+i);
        for (int j=i+1; j<tam; j++){
            if(*(p+j)<*tem){
                tem=(p+j);
            }
        }
        swap(*(p+i),*tem);
    }
}

void insercion(int *p, int tam){
    int *tem; int j=0;

    for (int i=0; i<tam-1; i++){
        tem=(p+(i+1));
        j=i;
        while(*(p+j)>*tem && j>=0){
            swap(*(p+j),*tem);
            tem=(p+j);
            j--;
        }

        for(int a=0; a<tam; a++)
            cout<<*(p+a)<<"  ";
        cout<<endl;
    }
}

void cocktail(int *p, int tam){
    int izq=0, der=tam-1;
    for (int i=0; i<tam/2; i++){
        for (int j=izq; j<der; j++){
            if(*(p+j)>*(p+j+1))
                swap(*(p+j),*(p+j+1));
        }
        der--;
        for (int j=der; j>izq; j--){
            if(*(p+j)<*(p+j-1))
                swap(*(p+j),*(p+j-1));
        }
        izq++;
    }
}

void quicksort(int *p, int ini, int tam1){
    int tam=tam1-1;
    int i=ini,j=tam;
    int *pivot=(p+((ini+tam)/2));
    while(i<=j){
        while((*(p+i)<*pivot) && (j<=tam)){
            i++;
        }
        while((*pivot<*(p+j)) && (j>ini)){
            j--;
        }
        if(i<=j){
            swap(*(p+i),*(p+j));
            i++;
            j--;
        }
    }
    if(ini<j)quicksort(p,ini,j+1);
    if(i<tam)quicksort(p,i,tam);
}

int main()
{
    int a[]={87,6,3,8,4,9,7,2,12,67,34,5,23,76,1};
    int *p=a;
    int tam=15;
    for(int i=0; i<tam; i++)
        cout<<a[i]<<"--"<<endl;
    insercion(p,tam);
    for(int i=0; i<tam; i++)
        cout<<a[i]<<endl;
    return 0;
}
