#include <iostream>

using namespace std;

int main(){
    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhacao! *" << endl;
    cout << "**************************************" << endl;

    const int NUMERO_SECRETO = 42;

    bool nao_acertou = true;

    while (nao_acertou)
    {
        int chute;
        cout << "Qual eh seu chute? ";
        cin >> chute;

        cout << "O valor do seu chute eh: " << chute << endl;

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
    

} 