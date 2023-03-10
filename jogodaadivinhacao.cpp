#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhacao! *" << endl;
    cout << "**************************************" << endl;

    cout << "Escolha o seu nivel de dificuldade: "<< endl;
    cout << "FACIL[F], MEDIO[M] OU DIFICIL[D]" << endl;

    char dificuldade;
    
    cin >> dificuldade;

    int numeroDeTentativas;

    if (dificuldade == 'F')
    {
        numeroDeTentativas = 15;
    }
    else if(dificuldade == 'M')
    {
        numeroDeTentativas = 10;
    }
    else
    {
        numeroDeTentativas = 5;
    }
    
    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for(tentativas = 1; tentativas <= numeroDeTentativas; tentativas++)
    {
        cout << "\nTentativa " << tentativas << ":" << endl;
        int chute;
        cout << "Qual eh seu chute? ";
        cin >> chute;
        
        double pontosPerdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos = pontos - pontosPerdidos;

        // cout << "O valor do seu chute eh: " << chute << endl;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou)
        {
            cout << "Parabens! Voce acertou o numero secreto!" << endl;
            nao_acertou = false;
            break;
        }
        else if (maior)
        {
            cout << "Seu chute foi maior que o numero secreto!" << endl;
        }
        else 
        {
            cout << "Seu chute foi menor que o numero secreto!" << endl;
        }
    }
    if (nao_acertou)
    {
        cout << "\n\nVoce perdeu! Tente novamente!" << endl;
    }
    else
    {
        cout << "\n\nVoce precisou de " << tentativas << " tentativas para encontrar o numero." << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuacao foi de " << pontos << " pontos." << endl;
    }
    
    cout << "\n\n==== Fim de Jogo ====" << endl;

} 