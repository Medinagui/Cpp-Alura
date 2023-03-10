#include <iostream>

using namespace std;

int main(){
    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhacao! *" << endl;
    cout << "**************************************" << endl;

    const int NUMERO_SECRETO = 42;

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    while (nao_acertou)
    {
        tentativas += 1;
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
    
    cout << "\n\nVoce precisou de " << tentativas << " tentativas para encontrar o numero." << endl;
    cout.precision(2);
    cout << fixed;
    cout << "Sua pontuacao foi de " << pontos << " pontos." << endl;
    cout << "\n\n==== Fim de Jogo ====" << endl;

} 