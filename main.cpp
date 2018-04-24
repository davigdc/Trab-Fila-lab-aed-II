#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <locale.h>

using namespace std;


    //===========================================Procedimentos Lista de Alunos

struct Data_nasc{

    int Dia;
    int Mes;
    int Ano;

};

struct Dado_aluno{

    int Matricula;
    char Nome[50];
    Data_nasc Data;
    char Endereco[50];
    int64_t Telefone;

};

struct Celula_aluno{

    Dado_aluno Aluno;
    Celula_aluno * Proximo;

};

struct Lista_alunos{

    Celula_aluno *Primeiro , *Ultimo;
    int Tam;

};

void Inicializa_lista_de_alunos(Lista_alunos * L){

    L->Primeiro = (Celula_aluno *)malloc(sizeof(Celula_aluno));
    L->Primeiro->Proximo = NULL;
    L->Ultimo = L->Primeiro;
    L->Tam = 0;

}

void insere_alunos_na_lista(Lista_alunos * L, Dado_aluno A){

    Celula_aluno *nova= (Celula_aluno*) malloc (sizeof(Celula_aluno));
    nova->Aluno=A;
    nova->Proximo=NULL;
    L->Ultimo->Proximo=nova;
    L->Ultimo=nova;
    L->Tam++;

}

void Imprimir_lista_de_alunos (Lista_alunos *L){
int i=1;
Celula_aluno *aux=L->Primeiro->Proximo;
cout<<"\n\t\tNumero de alunos cadastrados: "<<L->Tam<<endl;
    while(aux!=NULL){
        if(aux!=NULL){
            cout<<endl;
            cout<<"\tDados aluno "<<i;
            cout<<"\nMatricula: "<<aux->Aluno.Matricula;
            cout<<"\nNome: "<<aux->Aluno.Nome;
            cout<<"\nData nascimento: "<<aux->Aluno.Data.Dia<<"/"<<aux->Aluno.Data.Mes<<"/"<<aux->Aluno.Data.Ano;
            cout<<"\nEndereco: "<<aux->Aluno.Endereco;
            cout<<"\nTelefone: "<<aux->Aluno.Telefone;
            i++;
            cout<<endl<<endl;
            aux=aux->Proximo;
        }
    }
}

Dado_aluno Cadastro_de_aluno(Dado_aluno A){

    cout<<"\nMatricula do aluno: ";
    cin>>A.Matricula;
    cin.ignore();

    cout<<"\nNome aluno: ";
    gets(A.Nome);

    cout<<"\nData Nascimento (formato dd/mm/aaaa)";
        do{
            cout<<"\nDia (1 a 31): ";
            cin>>A.Data.Dia;
        } while ( (A.Data.Dia < 1) || (A.Data.Dia > 31) );

        do{
            cout<<"\nMes (1 a 12): ";
            cin>>A.Data.Mes;
        } while( (A.Data.Mes < 1) || (A.Data.Mes > 12) );

        do{
            cout<<"\nAno (<2018): ";
            cin>>A.Data.Ano;
        } while( A.Data.Ano > 2017 );

    cin.ignore();

    cout<<"\nEndereco: ";
    gets(A.Endereco);

    cout<<"\nTelefone: ";
    cin>>A.Telefone;
    cout<<endl<<endl;

return A;
}


    //===========================================Fim Procedimentos Lista de Alunos

    //===========================================Procedimentos Lista Materias

struct Materia{
    char Nome[50];
    int Codigo;
    char Descricao[500];
};

struct Celula_materia
{
    Materia Materia;
    Celula_materia * Proximo;
};

struct Lista_materias
{
    Celula_materia *Primeiro, *Ultimo;
    int Tam;
};

void Inicializa_lista_de_materias(Lista_materias * L)
{
    L->Primeiro = (Celula_materia*) malloc (sizeof(Celula_materia));
    L->Primeiro->Proximo = NULL;
    L->Ultimo= L->Primeiro;
    L->Tam = 0;

}

void Insere_materias_na_lista(Lista_materias * L, Materia Materias)
{
    Celula_materia *nova= (Celula_materia*) malloc (sizeof(Celula_materia));
    nova->Materia=Materias;
    nova->Proximo=NULL;
    L->Ultimo->Proximo=nova;
    L->Ultimo=nova;
    L->Tam++;

}


Materia Cadastro_de_materia(Materia M){

        cout<<"\nCodigo da mat�ria: ";
        cin>>M.Codigo;
        cin.ignore();

        cout<<"\nNome materia: ";
        gets(M.Nome);

        cout<<"\nDescri��o: ";
        gets(M.Descricao);

        cout<<endl;

return M;
}

void Imprimir_lista_de_materias (Lista_materias *L){
int i=1;
Celula_materia *aux=L->Primeiro->Proximo;
cout<<"\n\t\tNumero de materias cadastrados: "<<L->Tam;
    while(aux!=NULL){
        if(aux!=NULL){
            cout<<endl;
            cout<<"\tDados Materia "<<i;
            cout<<"\nC�digo:"<<aux->Materia.Codigo;
            cout<<"\nNome Mat�ria: "<<aux->Materia.Nome;
            cout<<"\nDescri��o: "<<aux->Materia.Descricao;
            cout<<endl<<endl;
            i++;
            aux=aux->Proximo;
        }
    }
}

    //===========================================Fim Procedimentos Lista Materias

struct Nota{
    int aluno_matricula;
    int cod_materia;
    int nota;
};

void imprimir_notas(Nota * notas, int n){
    for(int i=0; i<n; i++){
        cout<<"\tNota "<<i+1;
        cout<<"\nC�digo de mat�ria: "<< notas[i].cod_materia;
        cout<<"\nMatricula: "<<notas[i].aluno_matricula;
        cout<<"\nNota: "<<notas[i].nota;
        cout<<endl<<endl;
    }
}
/*
*celulas das listas
*/


struct celula_nota
{
    Nota nota;
    celula_nota * proximo;
};
/*
*tipos de listas
*/

struct Lista_notas
{
    celula_nota * ultimo, * primeiro;
    int tam;
};
/*
*Inicializacao das filas
*/

void inicializa_lista_de_notas(Lista_notas * L)
{
    L->primeiro = (celula_nota *)malloc(sizeof(celula_nota));
    L->primeiro->proximo = NULL;
    L->ultimo = L->primeiro;
    L->tam = 0;

}
/*
*cadastro de materia = insers�o de fila
*/

void insere_notas_na_lista(Lista_notas * L_de_notas, Nota notas)
{
    celula_nota *nova= (celula_nota*) malloc (sizeof(celula_nota));
    nova->nota=notas;
    nova->proximo=NULL;
    L_de_notas->ultimo=nova;
    L_de_notas->tam++;

}
/*
*Impressao das listas
*/

void cadastro_de_notas(Nota * notas,int n_notas){

    for( int i = 0; i < n_notas; i++ ){
        cout<<"\n\t\t Cadastro nota "<<i+1<<"/";
        cin.ignore();

        cout<<"\nCodigo da mat�ria: ";
        cin>>notas[i].cod_materia;
        cin.ignore();

        cout<<"\nMatricula : ";
        cin >> notas[i].aluno_matricula;
        cin.ignore();

        cout << "\nNotas: ";
        cin >> notas[i].nota;

    }
}



int main() {

    setlocale(LC_ALL,"portuguese");

    Lista_alunos * Lista_de_alunos = (Lista_alunos*) malloc (sizeof(Lista_alunos));
    Inicializa_lista_de_alunos(Lista_de_alunos);

    Lista_materias * Lista_de_materias = (Lista_materias*) malloc (sizeof(Lista_materias));
    Inicializa_lista_de_materias(Lista_de_materias);

    Lista_notas * lista_de_notas = (Lista_notas*) malloc (sizeof(Lista_notas));
    inicializa_lista_de_notas(lista_de_notas);

        //Fazer menu
    //Fazer switch case 1
    int n_alunos=0;
    do{
        if(n_alunos < 1){
        cout<<"Quantos alunos serao cadastrados?";
        cin>>n_alunos;
        }
    } while ( n_alunos <= 0 );

    for(int i=0; i<n_alunos; i++){
        cout<<"\t\tCadastro Aluno "<<i+1;
        Dado_aluno Aluno;
        Aluno= Cadastro_de_aluno(Aluno);
        insere_alunos_na_lista(Lista_de_alunos, Aluno);
    }
    Imprimir_lista_de_alunos(Lista_de_alunos);

   //Fazer switch case 2
    int n_materias=0;
     do{
        if(n_materias < 1){
        cout<<"Quantas materias serao cadastradas? ";
        cin>>n_materias;
        }
    } while ( n_materias <= 0 );


    for(int i=0; i<n_materias; i++){
        cout<<"\t\tCadastro Materia "<<i+1;
        Materia M;
        M= Cadastro_de_materia(M);
        Insere_materias_na_lista(Lista_de_materias, M);
    }
    Imprimir_lista_de_materias(Lista_de_materias);



/*
    int n_notas = 0;

    do{
        cout<<"Quantas notas ser�o cadastradas?";
        cin>>n_notas;
    } while ( n_materias < 1 );

    Nota * notas = (Nota *) malloc(sizeof(Nota));
    cadastro_de_notas(notas, n_notas);

    insere_materias_na_lista(lista_de_materias, materias, n_materias);
    imprimir_materias(materias, n_materias);
    imprimir_aluno(aluno, n_alunos);
    imprimir_notas(notas, n_notas);

    free(aluno);
*/
    free(Lista_de_alunos);
    free(Lista_de_materias);
    free(lista_de_notas);

    return 0;
}
