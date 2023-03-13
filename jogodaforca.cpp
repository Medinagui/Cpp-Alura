#include <iostream>
#include <string>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";

bool letra_existe(char chute)
{
    for(int i = 0; i < PALAVRA_SECRETA.size(); i++)
    {
        if(chute == PALAVRA_SECRETA[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cout << "*****************" << endl;
    cout << "* Jogo da Forca *" << endl;
    cout << "*****************" << endl;

    bool nao_acertou = true;
    bool nao_enforcou = true;

    cout << PALAVRA_SECRETA << endl;

    while(nao_acertou && nao_enforcou)
    {
        char chute;
        cout << "Digite uma letra para encontrar a palavra: ";
        cin >> chute;

        if(letra_existe(chute))
        {
            cout << "Voce acertou! Sua letra esta na palavra." << endl;
        }
        else
        {
            cout << "Voce errou! Sua letra nao esta na palavra" << endl;
        }
    }
    
    
    return 0;
}
