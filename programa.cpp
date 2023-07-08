#include <iostream>
#include <stdio.h>
#include <cctype>

int main(){
    char palavra[20], verificacao;
    char palavraIncompleta[20];
    bool verifTrue = false;
    bool finalizado = false;
    int chances = 5;


    do{
        std::cout << "-------------------Forca!--------------------- \n \n \n";
        std::cout << "---------------------------------------------- \n";
        std::cout << "---------------------------------------------- \n \n";
        // Solicitando numero de chances
        std::cout << "Digite o numero de erros permitidos ate o enforcamento: ";
        std::cin >> chances;
        std::cout << '\n';

        // Solicitando a palavra
        std::cout << "Digite uma palavra (sem espacos, maximo de 20 letras): ";
        std::cin >> palavra;

        for (int i = 0; i < palavra[i] != '\0'; i++){
            palavra[i] = (char) toupper(palavra[i]);
            palavraIncompleta[i + 1] = '\0';
        }

        // Verificar palavra
        std::cout << "\n A palavra escolhida foi ''" << palavra << "'': Confirma (s/n)? ";
        std::cin >> verificacao;

        

        if(verificacao == 's' || verificacao == 'S' )
            verifTrue = true;    

        std::cout << '\n';
            
    }while (verifTrue == false);

    // system("clear");
    system("cls");

    //  conforme o numero de caracter preenche palavra Incompleta com '-'
    for (int i = 0; i < palavra[i] != '\0'; i++){
        palavraIncompleta[i] = '-' ;
        palavraIncompleta[i + 1] = '\0';
    }

    // inicia loop conforme o numero de chances;
    while(chances > 0 && finalizado == false){
        char letra;

        std::cout << palavraIncompleta << '\n';
        std::cout << "Erros ate enforcamento: ";

        // Loop faz o numero de chances ser expressa em '*' e retorna feedback
        for (int i = 0; i < chances; i++)
            std::cout << " " << "*" << " ";
            
        std::cout << "\n";
        
        // trecho que solicita a letra para usuario
        std::cout << "Digite uma letra e tecle <Enter>: ";
        std::cin >> letra;

        letra = (char) toupper(letra);

        // loop caso letra faça parte da palavra
        bool letraCerta = false;
        for (int i = 0; i < palavra[i] != '\0'; i++)
            if(palavra[i] == letra){ 
                palavraIncompleta[i] = (char) toupper(letra);
                letraCerta = true;
            }
        
        // Feedback ao usuario sobre a letra escolhida
        if(letraCerta == false)
            chances--;

        //Verifica se a palavra esta completa conforme a presença do '-'
        bool palavraCompleta = true;
        for(int i = 0; i < palavra[i] != '\0'; i++)
            if(palavraIncompleta[i] == '-'){
                palavraCompleta = false;
                break;
            }

        //Caso completo palavraCompleta finaliza o loop
        if(palavraCompleta){
            finalizado = true;
            break;
        }
    }

    // Feedback caso jogo ganho
    if(finalizado){
        std::cout << "PARABENS! ENCONTROU A CERTA (" << palavraIncompleta;
        std::cout << ") RESTANDO " << chances << " CHANCES!" <<"\n";
    }

    // Caso numero de chances seja 0
    if(chances == 0)
        std::cout << "ENFORCADO! A PALAVRA CERTA ERA ''" << palavra <<"''\n";

    system("pause");
    
    return 0;
}