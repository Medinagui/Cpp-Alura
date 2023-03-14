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

bool nao_acertou()
{
    for(char letra : PALAVRA_SECRETA)
    {
        if(!chutou[letra])
        {
            return true;
        }
    }
    return false;
}

bool nao_enforcou()
{
    if(chutes_errados.size() < 5)
    {
        return true;
    }
    return false;
}

void imprime_cabecalho()
{
    cout << "\n\n*****************" << endl;
    cout << "* Jogo da Forca *" << endl;
    cout << "*****************\n\n" << endl;
}

void imprime_erros()
{
    cout << "\nChutes errados: ";
    for(char letra: chutes_errados)
    {
        cout << letra << " ";
    }
    cout << "\n " <<endl;
}

void imprime_palavra()
{
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
}

void chuta()
{
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

void finaliza_jogo()
{
    cout << "\n\n ===== FIM DE JOGO ===== \n"<< endl;
    cout << "A palavra secreta era " << PALAVRA_SECRETA << endl;

    if(nao_acertou())
    {
        cout << "\nVoce perdeu! Tente novamente!\n\n" << endl;
    }
    else
    {
        cout << "\nParabens! Voce acertou a palavra secreta!\n\n" << endl;
    }
}

int main()
{
    imprime_cabecalho();

    while(nao_acertou() && nao_enforcou())
    {
        imprime_erros();

        imprime_palavra();

        chuta();
    }
    
    finaliza_jogo();

    return 0;
}
