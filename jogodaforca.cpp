#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";

map<char, bool> chutou;

vector<char> chutes_errados;

bool letra_existe(char chute)
{
    for(char letra : PALAVRA_SECRETA)
    {
        if(chute == letra)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cout << "\n\n*****************" << endl;
    cout << "* Jogo da Forca *" << endl;
    cout << "*****************\n\n" << endl;

    bool nao_acertou = true;
    bool nao_enforcou = true;



    while(nao_acertou && nao_enforcou)
    {
        cout << "\nChutes errados: ";
        for(char letra: chutes_errados)
        {
            cout << letra << " ";
        }
        cout << "\n " <<endl;

        for(char letra : PALAVRA_SECRETA)
        {
            if(chutou[letra])
            {
                cout << letra << " ";
            }
            else
            {
                cout << "_ ";
            }
        }

        cout << "\n" << endl;

        char chute;
        cout << "Seu chute: ";
        cin >> chute;
        chutou[chute] = true;

        if(letra_existe(chute))
        {
            cout << "Voce acertou! Sua letra esta na palavra." << endl;
        }
        else
        {
            cout << "Voce errou! Sua letra nao esta na palavra" << endl;
            chutes_errados.push_back(chute);
        }
    }
    
    
    return 0;
}
