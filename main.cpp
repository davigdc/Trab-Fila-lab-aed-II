#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

struct Materia{
    char nome[50];
    int codigo;
    int nota;
    char descricao[500];
};

struct data_nasc{
    int dia;
    int mes;
    int ano;
};

struct dado_aluno{
    int matricula;
    char nome[50];
    data_nasc data;
    char endereco[50];
    int telefone;
    Materia disciplina;
};

/*
struct celdupla
{
    aluno a ;
    celdupla *prox, *ant;
};

struct lista
{
    celdupla *primeiro, *ultimo;
    int tam;
};

void inicializa (lista *l)
{
    l->primeiro=(celdupla*)malloc(sizeof(celdupla));
    l->primeiro->prox=NULL;
    l->primeiro->ant=NULL;
    l->ultimo=l->primeiro;
    l->tam=0;
}

bool inserir (lista *l, aluno a, int pos)
{
    if(pos<1 || pos>lista->tam+1)

        return false;

    celdupla nova=(celdupla)malloc(sizeof(celdupla));
    nova->a=a;
    celdupla*celant=l->primeiro;
    for(int i=0; i<pos-1; i++)

        celant=celant->prox;

    nova->ant=celant;
    nova->prox=celprox;
    celant->prox=nova;
    if(celprox==NULL)

        l->ultimo=nova;

    else

        celprox->ant=nova;

    l->tam++;
    return true;
}

aluno remover(lista *l, int pos)
{
    if(pos<1 || pos>l->tam)

        return -1;

    celdupla *celant=l->primeiro;
    for(int i=0; i<pos-1; i++)

        celant=celant->prox;

    celdupla *velha=celant ->prox;
    celdupla *celprox=velha->prox;
    celant->prox=celprox;
    if(celprox==NULL)
        lista->ultimo=celant;
    else
        celprox->ant=celant;
    aluno a=velha->a;
    free(velha);
    return a;
}

void finaliza(lista *l)
{
    while(!vazia(l))
        remover(l,1);
    free(l->primeiro);
}
*/
void imprimir_aluno(dado_aluno *aluno, int n){
    for(int i=0; i<n; i++){
        cout<<"\tDados aluno "<<i+1;
        cout<<"\nMatricula: "<<aluno[i].matricula;
        cout<<"\nNome: "<<aluno[i].nome;
        cout<<"\nData nascimento: "<<aluno[i].data.dia<<"/"<<aluno[i].data.mes<<"/"<<aluno[i].data.ano;
        cout<<"\nEndereco: "<<aluno[i].endereco;
        cout<<"\nTelefone"<<aluno[i].telefone;
        cout<<endl<<endl;
    }
}


using namespace std;

int main()
{
int n_alunos=0;
do{
    cout<<"Quantos alunos serao cadastrados?";
    cin>>n_alunos;
}while(n_alunos<1);

dado_aluno *aluno=(dado_aluno*) malloc (n_alunos*sizeof(dado_aluno));

for(int i=0; i<n_alunos; i++){
    cout<<"\n\t\t Cadastro aluno "<<i+1;
    cin.ignore();
    cout<<"\nMatricula do aluno: ";
    cin>>aluno[i].matricula;
    cin.ignore();
    cout<<"\nNome aluno: ";
    gets(aluno[i].nome);
    cout<<"\nData Nascimento (formato dd/mm/aaaa)";
        do{
            cout<<"\nDia (1 a 31): ";
            cin>>aluno[i].data.dia;
        }while((aluno[i].data.dia < 1) || (aluno[i].data.dia > 31));

        do{
            cout<<"\nMes (1 a 12): ";
            cin>>aluno[i].data.mes;
        }while((aluno[i].data.mes < 1) || (aluno[i].data.mes > 12));

        do{
            cout<<"\nAno (<2018): ";
            cin>>aluno[i].data.ano;
        }while(aluno[i].data.ano > 2017);
    cin.ignore();
    cout<<"\nEndereco: ";
    gets(aluno[i].endereco);
    cout<<"\nTelefone: ";
    cin>>aluno[i].telefone;

}
    imprimir_aluno(aluno, n_alunos);
    free(aluno);
    return 0;
}
