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

Dado_aluno Cadastro_de_aluno(Dado_aluno A, Lista_alunos * l){

    bool valido = false;
    Celula_aluno * aux = (Celula_aluno*) malloc(sizeof(Celula_aluno));
    aux = l->Primeiro;

    cout<<"\nMatricula do aluno: ";
    cin>>A.Matricula;
    cin.ignore();

    while(valido == false){
        while(aux != NULL){
            if(A.Matricula == aux->Aluno.Matricula){
                valido = false;
                aux = NULL;
            } else {
                valido = true;
                aux = aux->Proximo;
            }
        }
        if(valido == false){
            aux=l->Primeiro;
            cout<<"\nMatricula já existe tente novamente: ";
            cin>>A.Matricula;
            cin.ignore();

        }

    }

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
free(aux);
}

void Gravar_arquivo_alunos (FILE *arq, Dado_aluno aux){
    arq= fopen("dados_aluno.txt", "a+");
        if (!arq) {
            perror(strerror(errno)); // inclua os headers  string.h  e  errno.h
            //return EXIT_FAILURE; // inclua stdlib.h
        }
            fprintf(arq, "%i\t%s\t%i %i %i\t%s\t%lld\t%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i",
                        aux.Matricula, aux.Nome, aux.Data.Dia,
                        aux.Data.Mes, aux.Data.Ano, aux.Endereco,
                        aux.Telefone, aux.cod_materia[0], aux.cod_materia[1],
                        aux.cod_materia[2], aux.cod_materia[3], aux.cod_materia[4],
                        aux.cod_materia[5], aux.cod_materia[6], aux.cod_materia[7]);


    fclose(arq);
}

    //===========================================Fim Procedimentos Lista de Alunos

    //===========================================Procedimentos Lista Materias

struct Materia{
    char Nome[50];
    int Codigo;
    char Descricao[500];
};

struct Celula_materia{
    Materia Materia;
    Celula_materia * Proximo;
};

struct Lista_materias{
    Celula_materia *Primeiro, *Ultimo;
    int Tam;
};

void Inicializa_lista_de_materias(Lista_materias * L){
    L->Primeiro = (Celula_materia*) malloc (sizeof(Celula_materia));
    L->Primeiro->Proximo = NULL;
    L->Ultimo= L->Primeiro;
    L->Tam = 0;

}

void Insere_materias_na_lista(Lista_materias * L, Materia Materias){
    Celula_materia *nova= (Celula_materia*) malloc (sizeof(Celula_materia));
    nova->Materia=Materias;
    nova->Proximo=NULL;
    L->Ultimo->Proximo=nova;
    L->Ultimo=nova;
    L->Tam++;

}

Materia Cadastro_de_materia(Materia M, Lista_materias * L){

    cout<<"\nCodigo da matéria: ";
    cin>>M.Codigo;
    cin.ignore();

    bool valido = false;
    Celula_materia * aux_pesquisa = (Celula_materia*) malloc(sizeof(Celula_materia));
    aux_pesquisa = L->Primeiro;

    while(valido == false){
        while(aux_pesquisa != NULL){
            if(M.Codigo == aux_pesquisa->Materia.Codigo){
                valido = false;
                printf("%i = %i ", M.Codigo, aux_pesquisa->Materia.Codigo);
                aux_pesquisa = NULL;
            } else {
                valido = true;
                printf("%i == %i ", M.Codigo, aux_pesquisa->Materia.Codigo);
                aux_pesquisa = aux_pesquisa->Proximo;
            }
        }
        if(valido == false){
            aux_pesquisa = L->Primeiro;
            cout<<"\nCodigo da matéria já existe tente novamente: ";
            cin>>M.Codigo;
            cin.ignore();
        }
    }
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

void Gravar_arquivo_materias (FILE *arq, Materia aux){
    arq= fopen("dados_materia.txt", "a+");
        if (!arq) {
            perror(strerror(errno)); // inclua os headers  string.h  e  errno.h
            //return EXIT_FAILURE; // inclua stdlib.h
        }

        fprintf(arq, "%i\t%s\t%s\n", aux.Codigo, aux.Nome, aux.Descricao);

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

    //===========================================Procedimentos Lista Notas

struct Nota{
    int aluno_matricula;
    int cod_materia;
    int nota;
};

struct Celula_nota{
    Nota nota;
    Celula_nota * proximo;
};

struct Lista_notas{
    Celula_nota * ultimo, * primeiro;
    int tam;
};

void inicializa_lista_de_notas(Lista_notas * L){
    L->primeiro = (Celula_nota *)malloc(sizeof(Celula_nota));
    L->primeiro->proximo = NULL;
    L->ultimo = L->primeiro;
    L->tam = 0;

}

void insere_notas_na_lista(Lista_notas * L_de_notas, Nota notas){
    Celula_nota *nova= (Celula_nota*) malloc (sizeof(Celula_nota));
    nova->nota=notas;
    nova->proximo=NULL;
    L_de_notas->ultimo->proximo=nova;
    L_de_notas->ultimo=nova;
    L_de_notas->tam++;

}

Nota Cadastro_de_notas(Nota aux){

    cout<<"\t\tCadastro de nota: \n";
    cout<<"Matricula do aluno: ";
    cin>>aux.aluno_matricula;

    cout<<"Código da matéria para lançamento de nota: ";
    cin>>aux.cod_materia;

    cout<<"Nota obtida na matéria "<<aux.cod_materia<<": ";
    cin>>aux.nota;

    cout<<endl<<endl;

return aux;
}

void Imprimir_lista_de_notas (Lista_notas *L){
int i=1;
Celula_nota *aux=L->primeiro->proximo;
cout<<"\n\t\tNumero de alunos cadastrados: "<<L->tam;
    while(aux!=NULL){
        if(aux!=NULL){
            cout<<endl;
            cout<<"\tDados aluno "<<i;
            cout<<"\nMatricula aluno: "<<aux->nota.aluno_matricula;
            cout<<"\nNota na materia: "<<aux->nota.cod_materia;
            cout<<"\nNota: "<<aux->nota.nota;
            i++;
            cout<<endl<<endl;
            aux=aux->proximo;
        }
    }

}

void openFile_notas (Lista_notas * l){

    Celula_nota * aux = (Celula_nota *) malloc (sizeof(Celula_nota));

    if(aux == NULL){
        cout << "\n\t\tNão há memoria suficiente\n\n";
    } else {
        //inicia abertura do arquivo em modo leitura
        FILE * arq = fopen("dados_notas.txt", "r");
        if (arq){
            while (!feof(arq)){
                if(!feof(arq)){
                    fscanf
                    (arq, "%i\t%i\%i\n",
                            &aux->nota.aluno_matricula, &aux->nota.cod_materia, &aux->nota.nota
                    );
/*
                    printf
                    ("%i\t%i\%i\n",
                            aux->nota.aluno_matricula, aux->nota.cod_materia, aux->nota.nota);
*/
                    insere_notas_na_lista(l, aux->nota);

                } else {
                    cout<<"Fim da desgraca\n";
                }
            }
        }
    }
free(aux);
}

void Gravar_arquivo_notas (FILE *arq, Nota aux){
    arq= fopen("dados_notas.txt", "a+");
        if (!arq) {
            perror(strerror(errno)); // inclua os headers  string.h  e  errno.h
            //return EXIT_FAILURE; // inclua stdlib.h
        }
            fprintf(arq, "%i\t%i\t%i\n", aux.aluno_matricula, aux.cod_materia, aux.nota);


    fclose(arq);
}

    //=========================================== Fim Procedimentos Lista Notas


int main() {

    setlocale(LC_ALL,"portuguese");

    Lista_materias * Lista_de_materias = (Lista_materias*) malloc (sizeof(Lista_materias));
    Inicializa_lista_de_materias(Lista_de_materias);
    FILE *arq_materias;
    openFile_materia(Lista_de_materias);

    Lista_alunos * lista_de_alunos = (Lista_alunos*) malloc (sizeof(Lista_alunos));
    Inicializa_lista_de_alunos(lista_de_alunos);
    FILE *arq_alunos;
    openFile_aluno(lista_de_alunos);

    Lista_notas * lista_de_notas = (Lista_notas*) malloc (sizeof(Lista_notas));
    inicializa_lista_de_notas(lista_de_notas);
    FILE *arq_notas;
    openFile_notas(lista_de_notas);

    int n_materias=0, n_alunos=0, n_notas=0;
    int menu;

    do{
    printf("\t----> Opções disponíveis: <----\n[1]-> Cadastrar materias ou alunos;\n[2]-> Inserir nota;\n[3]-> Pesquisas;\n[4]-> Imprimir;\n[5]-> Sair.\nEntrada: ");
    cin>>menu;
    if(menu==5){
        break;
    }
    if(menu < 1 || menu > 4){
        cout<<"\t\tOpção inválida, digite novamente...\n";
    }

    switch(menu){

    case 1:

        int op1;
        do{
        cout<<endl;
        printf("\t--> Cadastrar materias ou alunos: <--\n[1]-> Cadastrar Materia;\n[2]-> Cadastrar Aluno; \n[3]-> Voltar;\nEntrada: ");
        cin>>op1;
        if(op1 < 1 || op1 > 3){
            cout<<"Opção inválida, digite novamente...\n";
        }

        switch(op1){
            case 1:
                cout<<"Quantas materias serao inseridos? ";
                cin>>n_materias;

                for(int i=0; i<n_materias; i++){
                    Materia aux_m;
                    aux_m= Cadastro_de_materia(aux_m, Lista_de_materias);
                    Insere_materias_na_lista(Lista_de_materias, aux_m);
                    Gravar_arquivo_materias(arq_materias, aux_m);
                }
            break;

            case 2:
                cout<<"Quantos alunos serao inseridos? ";
                cin>>n_alunos;

                for(int i=0; i<n_alunos; i++){
                    Dado_aluno aux_a;
                    aux_a= Cadastro_de_aluno(aux_a, lista_de_alunos);
                    insere_alunos_na_lista(lista_de_alunos, aux_a);
                    Gravar_arquivo_alunos(arq_notas, aux_a);
                }
            break;
        }

        }while(op1!=3);
        cout<<endl;

    break;

    case 2:

        int op2;
        do{
        cout<<endl;
        printf("\t--> Inserir nota: <--\n[1]-> Inserir nota;\n[2]-> Voltar;\nEntrada: ");
        cin>>op1;
        if(op1 < 1 || op1 > 2){
            cout<<"Opção inválida, digite novamente...\t";
        }

        switch(op1){
            case 1:
                cout<<"Quantas notas serao inseridos? ";
                cin>>n_notas;

                for(int i=0; i<n_notas; i++){
                    Nota aux;
                    aux= Cadastro_de_notas(aux);
                    insere_notas_na_lista(lista_de_notas, aux);
                    Gravar_arquivo_notas(arq_notas, aux);
                }
            break;
        }

        }while(op1!=2);
        cout<<endl;

    break;

    case 3:
        int op3;
        do{
        cout<<endl;
        printf("\t--> Pesquisas: <--\n[1]-> Notas de uma disciplina;\n[2]-> Nome dos alunos que foram aprovados em uma disciplina;\n[3]-> Maior e menor nota, em uma disciplina;\n[4]-> Voltar;\nEntrada: ");
        cin>>op3;
        if(op3 < 1 || op3 > 4){
            cout<<"Opção inválida, digite novamente...\n";
        }

        switch(op3){
            case 1:
                cout<<"\nListar as notas de todos os alunos de uma determinada disciplina\n";
            break;

            case 2:
                cout<<"\nListar quais os alunos (pelo nome) foram reprovados (leve em consideração mínimo de 60 pontos para aprovação) em uma determinada disciplina.\n";
            break;

            case 3:
                cout<<"\nListar a maior e a menor nota obtida em cada disciplina.\n";
            break;
        }

        }while(op3!=4);
        cout<<endl;
    break;

    case 4:
        int op4;
        do{
        cout<<endl;
        printf("\t--> Imprimir: <--\n[1]-> Lista de matérias;\n[2]-> Lista de alunos;\n[3]-> Lista de notas;\n[4]-> Voltar;\nEntrada: ");
        cin>>op4;
        if(op4 < 1 || op4 > 4){
            cout<<"Opção inválida, digite novamente...\n";
        }

        switch(op4){
            case 1:
                Imprimir_lista_de_materias(Lista_de_materias);
            break;

            case 2:
                Imprimir_lista_de_alunos(lista_de_alunos);
            break;

            case 3:
                Imprimir_lista_de_notas(lista_de_notas);
            break;
        }

        }while(op4!=4);
        cout<<endl;
    break;

    }
    }while(menu!=5);


    free(lista_de_alunos);
    free(Lista_de_materias);
    free(lista_de_notas);

    return 0;
}
