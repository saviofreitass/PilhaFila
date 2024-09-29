#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "Fila.h"

using namespace std;

void testaPosicao(float notaTempF, float notaTempP,Aluno aluno, int matriculaTempF, int matriculaTempP){
    Aluno Temp;
    if(notaTempF < notaTempP){
        Pilha_Desempilhar(aluno);
        Fila_Enfileirar(aluno);
        Fila_Frente(aluno);
        Pilha_Topo(aluno);
        notaTempP = aluno.nota;
            if(notaTempP < notaTempF){
                Fila_Desenfileirar(aluno);
                Pilha_Empilhar(aluno);
            }else{
                //chama a funcao novamente para testar os numeros que estao abaixo do topo
                testaPosicao(notaTempF, notaTempP, aluno, matriculaTempF, matriculaTempP);
            }
    }else if(notaTempF>notaTempP){
        Fila_Frente(aluno);
        Fila_Desenfileirar(aluno);
        Pilha_Empilhar(aluno);
    }else if(notaTempF == notaTempP){
        if(matriculaTempF > matriculaTempP){
            Fila_Desenfileirar(aluno);
            Pilha_Empilhar(aluno);
        }else{
            Pilha_Desempilhar(aluno);
            Temp = aluno;
            Fila_Desenfileirar(aluno);
            Pilha_Empilhar(aluno);
            Pilha_Empilhar(Temp);
        }
    }
}

int main(){

    int opc;
    float notaTempF, notaTempP;
    int matriculaTempF, matriculaTempP;
    Aluno aluno;
    Fila_Construtor();
    Pilha_Construtor();

    cout << "Intrucoes para utilizar o programa:";
    cout << "\n1-Voce devera incluir obrigatoriamente a matricula e a nota do aluno.";
    cout << "\n2-A matricula nao podera repetir em mais de um aluno.\n";

    //Recebe os dados do teclado e enfileira;
    do{
    cout << "\nDigite a matricula do aluno: ";
    cin >> aluno.matricula;
    cout << "Digite a nota do aluno: ";
    cin >> aluno.nota;
    cout << "\nPara continuar adicionando, digite 1, para sair digite qualquer outro valor: ";
    cin >> opc;

    Fila_Enfileirar(aluno);
    }while(opc==1);

    //Empilho o primeiro aluno e tiro da lista
    Fila_Frente(aluno);
    Pilha_Empilhar(aluno);
    Fila_Desenfileirar(aluno);

    //Faz as necessarias verificacoes para ordenar enquanto a lista nao tiver vazia
    while(Fila_Tamanho()!=0){
        if(Fila_Frente(aluno)){
            Fila_Frente(aluno);
            notaTempF = aluno.nota;
            matriculaTempF = aluno.matricula;
            Pilha_Topo(aluno);
            notaTempP = aluno.nota;
            matriculaTempP = aluno.matricula;
            //funcao para conseguir fazer recursividade
            testaPosicao(notaTempF, notaTempP, aluno, matriculaTempF, matriculaTempP);
        }
    }

    //Imprime a pilha da ordem maior para o menor
    while(Pilha_Tamanho()!=0){
        Pilha_Topo(aluno);
        cout << "Matricula: "<< aluno.matricula<< " Nota: " << aluno.nota << endl;
        Pilha_Desempilhar(aluno);
    }

    return 0;
}
