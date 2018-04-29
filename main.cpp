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
    int cod_materia[8];
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
            cout<<endl<<"Materias Cadastradas: ";
            for(int j=0; j<8; j++){
                if(aux->Aluno.cod_materia[j]>0){
                    printf(" %i", &aux->Aluno.cod_materia[j]);
                }
            }
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

    for(int i=0; i<8; i++){
        cout<<"Numero de matéria matriculada (Maximo 8 materias - caso nao tenha mais materias digite 0)";
        cout<<endl<<"Matéria "<<i+1<<": ";
        cin>>A.cod_materia[i];
    }
    cout<<endl<<endl;

return A;
}


void openFile_aluno (Lista_alunos * l){

    Celula_aluno * aux = (Celula_aluno * )malloc(sizeof(Celula_aluno));

    if(aux == NULL){
        cout << "não há memoria suficiente";
    } else {
        //inicia abertura do arquivo em modo leitura
        FILE * arq = fopen("dados_aluno.txt", "r");

        while (!feof(arq)){
            if(!feof(arq)){
                fscanf
                (arq, "%i\t%[^\t]\t%i %i %i\t%[^\t]\t%lld\t%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i",
                        &aux->Aluno.Matricula, &aux->Aluno.Nome,
                        &aux->Aluno.Data.Dia, &aux->Aluno.Data.Mes, &aux->Aluno.Data.Ano,
                        &aux->Aluno.Endereco, &aux->Aluno.Telefone,
                        &aux->Aluno.cod_materia[0], &aux->Aluno.cod_materia[1],
                        &aux->Aluno.cod_materia[2], &aux->Aluno.cod_materia[3],
                        &aux->Aluno.cod_materia[4], &aux->Aluno.cod_materia[5],
                        &aux->Aluno.cod_materia[6], &aux->Aluno.cod_materia[7]
                );
/*
                printf
                ("%i\t%s\t%i/%i/%i\t%s\t%lld\nMaterias matriculadas: %i, %i, %i, %i, %i, %i, %i, %i\n",
                        aux->Aluno.Matricula, aux->Aluno.Nome,
                        aux->Aluno.Data.Dia, aux->Aluno.Data.Mes, aux->Aluno.Data.Ano,
                        aux->Aluno.Endereco, aux->Aluno.Telefone,
                        aux->Aluno.cod_materia[0], aux->Aluno.cod_materia[1],
                        aux->Aluno.cod_materia[2], aux->Aluno.cod_materia[3],
                        aux->Aluno.cod_materia[4], aux->Aluno.cod_materia[5],
                        aux->Aluno.cod_materia[6], aux->Aluno.cod_materia[7]);
*/
                insere_alunos_na_lista(l, aux->Aluno);

            } else {
                cout<<"Fim da desgraca\n";
            }
        }

    }

}


void Gravar_arquivo_alunos (FILE *arq, Lista_alunos *l){
    arq= fopen("dados_aluno.txt", "a+");
    Celula_aluno *aux=l->Primeiro->Proximo;
        if (!arq) {
            perror(strerror(errno)); // inclua os headers  string.h  e  errno.h
            //return EXIT_FAILURE; // inclua stdlib.h
        }

        while(aux!=NULL){
            if(aux!=NULL){
                fprintf(arq, "%i\t%s\t%i %i %i\t%s\t%lld\t%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i",
                        aux->Aluno.Matricula, aux->Aluno.Nome, aux->Aluno.Data.Dia,
                        aux->Aluno.Data.Mes, aux->Aluno.Data.Ano, aux->Aluno.Endereco,
                        aux->Aluno.Telefone, aux->Aluno.cod_materia[0], aux->Aluno.cod_materia[1],
                        aux->Aluno.cod_materia[2], aux->Aluno.cod_materia[3], aux->Aluno.cod_materia[4],
                        aux->Aluno.cod_materia[5], aux->Aluno.cod_materia[6], aux->Aluno.cod_materia[7]);
        aux=aux->Proximo;
            }
        }
    fclose(arq);
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

        cout<<"\nCodigo da matéria: ";
        cin>>M.Codigo;
        cin.ignore();

        cout<<"\nNome materia: ";
        gets(M.Nome);

        cout<<"\nDescrição: ";
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
            cout<<"\nCódigo:"<<aux->Materia.Codigo;
            cout<<"\nNome Matéria: "<<aux->Materia.Nome;
            cout<<"\nDescrição: "<<aux->Materia.Descricao;
            cout<<endl<<endl;
            i++;
            aux=aux->Proximo;
        }
    }
}


void Grava_arquivo_materias (FILE *arq, Materia aux){
    arq= fopen("dados_materia.txt", "a+");
    //Celula_materia *aux=m->Primeiro->Proximo;
        if (!arq) {
            perror(strerror(errno)); // inclua os headers  string.h  e  errno.h
            //return EXIT_FAILURE; // inclua stdlib.h
        }
                fprintf(arq, "%i\t%s\t%s\n",
                        aux.Codigo, aux.Nome, aux.Descricao);

    fclose(arq);
}


void openFile_materia (Lista_materias * m){



    Celula_materia * aux = (Celula_materia * )malloc(sizeof(Celula_materia));

    if(aux == NULL){
        cout << "não há memoria suficiente";
    } else {
        //inicia abertura do arquivo em modo leitura
        FILE * arq = fopen("dados_materia.txt", "r");
        if (arq){
            while (!feof(arq)){
                if(!feof(arq)){
                    fscanf
                    (arq, "%i\t%[^\t]\t%[^\n]\n",
                            &aux->Materia.Codigo, &aux->Materia.Nome, &aux->Materia.Descricao
                    );
    /*
                    printf
                    ("%i, %s, %s\n",
                            aux->Materia.Codigo, aux->Materia.Nome, aux->Materia.Descricao
                    );
    */
                    Insere_materias_na_lista(m, aux->Materia);

                } else {
                    cout<<"Fim da desgraca\n";
                }
            }
        }

    }
    free(aux);
}
    //===========================================Fim Procedimentos Lista Materias

void notas (){
struct Nota{
    int aluno_matricula;
    int cod_materia;
    int nota;
};

void imprimir_notas(Nota * notas, int n){
    for(int i=0; i<n; i++){
        cout<<"\tNota "<<i+1;
        cout<<"\nCódigo de matéria: "<< notas[i].cod_materia;
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
*cadastro de materia = insersão de fila
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
}


int main() {

    setlocale(LC_ALL,"portuguese");

    Lista_alunos * lista_de_alunos = (Lista_alunos*) malloc (sizeof(Lista_alunos));
    Inicializa_lista_de_alunos(lista_de_alunos);

    Lista_materias * Lista_de_materias = (Lista_materias*) malloc (sizeof(Lista_materias));
    Inicializa_lista_de_materias(Lista_de_materias);

    //Lista_notas * lista_de_notas = (Lista_notas*) malloc (sizeof(Lista_notas));
    //inicializa_lista_de_notas(lista_de_notas);
    Dado_aluno Aluno;
    //Aluno= Cadastro_de_aluno(Aluno);
    //insere_alunos_na_lista(lista_de_alunos, Aluno);
    FILE *arq_alunos;
    //Gravar_arquivo_alunos(arq_alunos, lista_de_alunos);
    openFile_aluno(lista_de_alunos);
    cout<<endl<<endl;
    Imprimir_lista_de_alunos(lista_de_alunos);
    //Fazer menu
    //Fazer switch case 1
 /*
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
        insere_alunos_na_lista(lista_de_alunos, Aluno);
    }
    Imprimir_lista_de_alunos(lista_de_alunos);

    FILE *arq_alunos;
    arquivo_alunos(arq_alunos, lista_de_alunos);




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


*/
/*
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
*/
    free(lista_de_alunos);
    free(Lista_de_materias);
    //free(lista_de_notas);

    return 0;
}
