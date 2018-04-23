#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <locale.h>

using namespace std;

struct Materia{
    char nome[50];
    int codigo;
    char descricao[500];
};

struct data_nasc{
    int dia;
    int mes;
    int ano;
};
struct Nota{
    int aluno_matricula;
    int cod_materia;
    int nota;
};

struct dado_aluno{
    int matricula;
    char nome[50];
    data_nasc data;
    char endereco[50];
    int64_t telefone;
    Materia disciplina;
    Nota * notas;
};

void imprimir_aluno(dado_aluno *aluno, int n){
    for(int i=0; i<n; i++){
        cout<<"\tDados aluno "<<i+1;
        cout<<"\nMatricula: "<<aluno[i].matricula;
        cout<<"\nNome: "<<aluno[i].nome;
        cout<<"\nData nascimento: "<<aluno[i].data.dia<<"/"<<aluno[i].data.mes<<"/"<<aluno[i].data.ano;
        cout<<"\nEndereco: "<<aluno[i].endereco;
        cout<<"\nTelefone: "<<aluno[i].telefone;
        cout<<endl<<endl;
    }
}

void imprimir_materias(Materia * materias, int n){
    for(int i=0; i<n; i++){
        cout<<"\tDados materia "<<i+1;
        cout<<"\nCódigo: "<<materias[i].codigo;
        cout<<"\nMatéria: "<<materias[i].nome;
        cout<<"\nDescrição: "<<materias[i].descricao;
        cout<<endl<<endl;
    }
}

void imprimir_notas(Nota * notas, int n){
    for(int i=0; i<n; i++){
        cout<<"\tNota "<<i+1;
        cout<<"\nCódigo de matéria: "<< notas[i].cod_materia;
        cout<<"\nMatricula: "<<notas[i].aluno_matricula;
        cout<<"\nNota: "<<notas[i].nota;
        cout<<endl<<endl;
    }
}

struct celula_materia{
    Materia materia;
    celula_materia * proximo;
};

struct celula_aluno{
    dado_aluno aluno;
    celula_aluno * proximo;
};

struct celula_nota{
    Nota nota;
    celula_nota * proximo;
};

struct Lista_materias{
    celula_materia * ultimo, * primeiro;
    int tam;
};

struct Lista_alunos{
    celula_aluno * ultimo, * primeiro;
    int tam;
};

struct Lista_notas{
    celula_nota * ultimo, * primeiro;
    int tam;
};

void inicializa_lista_de_materias(Lista_materias * L){
    L->primeiro = (celula_materia *)malloc(sizeof(celula_materia));
    L->primeiro->proximo = NULL;
    L->ultimo = L->primeiro;
    L->tam = 0;
}

void inicializa_lista_de_alunos(Lista_alunos * L){
    L->primeiro = (celula_aluno *)malloc(sizeof(celula_aluno));
    L->primeiro->proximo = NULL;
    L->ultimo = L->primeiro;
    L->tam = 0;
}

void inicializa_lista_de_notas(Lista_notas * L){
    L->primeiro = (celula_nota *)malloc(sizeof(celula_nota));
    L->primeiro->proximo = NULL;
    L->ultimo = L->primeiro;
    L->tam = 0;
}

/*
*cadastro de materia = insersão de fila
*/
void insere_materias_na_lista(Lista_materias * L_de_materias, Materia * materias, int n_materias){
    cout << "cu de rola";
}

void insere_alunos_na_lista(Lista_alunos * L_de_alunos, dado_aluno * alunos, int n_alunos){
    cout << "cu de rola";
}

void insere_notas_na_lista(Lista_notas * L_de_materias, Nota * notas, int n_notas){
    cout << "cu de rola";
}

void cadastro_de_materia(Materia * materias,int n_materias){

    for( int i = 0; i < n_materias; i++ ){
        cout<<"\n\t\t Cadastro materia "<<i+1;
        cin.ignore();

        cout<<"\ncodigo da matéria: ";
        cin>>materias[i].codigo;
        cin.ignore();

        cout<<"\nNome materia: ";
        gets(materias[i].nome);
        cin.ignore();

        cout<<"\nDescrição: ";
        gets(materias[i].descricao);
        cin.ignore();
    }
}

void cadastro_de_notas(Nota * notas,int n_notas){

    for( int i = 0; i < n_notas; i++ ){
        cout<<"\n\t\t Cadastro nota "<<i+1<<"/";
        cin.ignore();

        cout<<"\nCodigo da matéria: ";
        cin>>notas[i].cod_materia;
        cin.ignore();

        cout<<"\nMatricula : ";
        cin >> notas[i].aluno_matricula;
        cin.ignore();

        cout << "\nNotas: ";
        cin >> notas[i].nota;

    }
}

void cadastro_de_aluno(dado_aluno * aluno, int n_alunos){

    for(int i=0; i<n_alunos; i++){

        cout<<"\n\t\t Cadastro aluno "<<i+1;
        cin.ignore();

        cout<<"\nMatricula do aluno: ";
        cin>>aluno[i].matricula;
        cin.ignore();

        cout<<"\nNome aluno: ";
        gets(aluno[i].nome);
        cin.ignore();

        cout<<"\nData Nascimento (formato dd/mm/aaaa)";
        do{
            cout<<"\nDia (1 a 31): ";
            cin>>aluno[i].data.dia;
        } while ( (aluno[i].data.dia < 1) || (aluno[i].data.dia > 31) );

        do{
            cout<<"\nMes (1 a 12): ";
            cin>>aluno[i].data.mes;
        } while( (aluno[i].data.mes < 1) || (aluno[i].data.mes > 12) );

        do{
            cout<<"\nAno (<2018): ";
            cin>>aluno[i].data.ano;
        } while( aluno[i].data.ano > 2017 );

        cin.ignore();

        cout<<"\nEndereco: ";
        gets(aluno[i].endereco);

        cout<<"\nTelefone: ";
        cin>>aluno[i].telefone;
    }

}

int main() {

    setlocale(LC_ALL,"");
    int n_alunos=0;

    Lista_alunos * lista_de_alunos = (Lista_alunos *)malloc(sizeof(Lista_alunos));
    Lista_materias * lista_de_materias = (Lista_materias *)malloc(sizeof(Lista_materias));
    Lista_notas * lista_de_notas = (Lista_notas *)malloc(sizeof(Lista_notas));

    inicializa_lista_de_materias(lista_de_materias);
    inicializa_lista_de_alunos(lista_de_alunos);
    inicializa_lista_de_notas(lista_de_notas);

    do{
        if(n_alunos < 1){
        cout<<"Quantos alunos serao cadastrados?";
        cin>>n_alunos;
        }
    } while ( n_alunos <= 0 );

    dado_aluno *aluno=(dado_aluno*) malloc (n_alunos*sizeof(dado_aluno));
    //cadastro_de_aluno(aluno, n_alunos);

    int n_materias = 0;

    do{
        cout<<"Quantas matérias serão cadastrados?";
        cin>>n_materias;
    } while ( n_materias < 1 );

    Materia * materias = (Materia *) malloc (n_materias*sizeof(Materia));
    //cadastro_de_materia(materias, n_materias);

    int n_notas = 0;

    do{
        cout<<"Quantas notas serão cadastradas?";
        cin>>n_notas;
    } while ( n_materias < 1 );

    Nota * notas = (Nota *) malloc(sizeof(Nota));
    cadastro_de_notas(notas, n_notas);

    insere_materias_na_lista(lista_de_materias, materias, n_materias);
    imprimir_materias(materias, n_materias);
    imprimir_aluno(aluno, n_alunos);
    imprimir_notas(notas, n_notas);

    free(aluno);

    return 0;
}
