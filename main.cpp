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
struct nota{
    int aluno_matricula;
    int cod_materia;
    int nota;
};

struct dado_aluno{
    int matricula;
    char nome[50];
    data_nasc data;
    char endereco[50];
    int telefone;
    Materia disciplina;
    nota * notas;
};

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
void imprimir_materias(Materia * materias, int n){
    for(int i=0; i<n; i++){
        cout<<"\tDados materia "<<i+1;
        cout<<"\nCódigo: "<<materias[i].codigo;
        cout<<"\nMatéria: "<<materias[i].nome;
        cout<<"\nDescrição: "<<materias[i].descricao;
        cout<<endl<<endl;
    }
}
int main() {
    setlocale(LC_ALL,"");
    int n_alunos=0;

    do{
        if(n_alunos < 1){
        cout<<"Quantos alunos serao cadastrados?";
        cin>>n_alunos;
        }
    } while ( n_alunos <= 0 );

    dado_aluno *aluno=(dado_aluno*) malloc (n_alunos*sizeof(dado_aluno));

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

    int n_materias = 0;
    do{
        cout<<"Quantas matérias serão cadastrados?";
        cin>>n_materias;
    } while ( n_materias < 1 );

    Materia * materias = (Materia * ) malloc (n_materias*sizeof(Materia));

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

    imprimir_materias(materias, n_materias);
    imprimir_aluno(aluno, n_alunos);

    free(aluno);

    return 0;
}
