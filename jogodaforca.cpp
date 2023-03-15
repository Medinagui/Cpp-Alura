#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

string palavra_secreta = "MELANCIA";

map<char, bool> chutou;

vector<char> chutes_errados;

bool letra_existe(char chute)
{
    for(char letra : palavra_secreta)
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
    for(char letra : palavra_secreta)
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
    for(char letra : palavra_secreta)
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

vector<string> le_arquivo()
{
    ifstream arquivo;
    arquivo.open("../palavras.txt");

    if(arquivo.is_open())
    {
        int quantidade_palavras;
        arquivo >> quantidade_palavras;

        vector<string> palavras_do_arquivo;

        for(int i = 0; i < quantidade_palavras; i++)
        {
            string palavra_lida;
            arquivo >> palavra_lida;
            palavras_do_arquivo.push_back(palavra_lida);
        }
        arquivo.close();
        return palavras_do_arquivo;
    }
    else
    {
        cout << "Nao foi possivel acessar o banco de palavras.\n\n" << endl;
        exit(0);      
    }


}

void sorteia_palavra()
{
    vector<string> palavras = le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();
    palavra_secreta = palavras[indice_sorteado];
}

void salva_arquivo(vector<string> nova_lista)
{
    ofstream arquivo;
    arquivo.open("../palavras.txt");
    if(arquivo.is_open())
    {
        arquivo << nova_lista.size() << endl;
        for(string palavra : nova_lista)
        {
            arquivo << palavra << endl;
        }
        arquivo.close();
    }
    else
    {
        cout << "Nao foi possivel acessar o banco de palavras.\n\n" << endl;
        exit(0);   
    }
}

void adiciona_palavra()
{
    cout << "Digite a nova palavra, utilizando letras maiusculas: ";
    string nova_palavra;
    cin >> nova_palavra;

    vector<string> lista_palavras = le_arquivo();
    lista_palavras.push_back(nova_palavra);
    
    salva_arquivo(lista_palavras);
}

void finaliza_jogo()
{
    cout << "\n\n ===== FIM DE JOGO ===== \n"<< endl;
    cout << "A palavra secreta era " << palavra_secreta << endl;

    if(nao_acertou())
    {
        cout << "\nVoce perdeu! Tente novamente!\n\n" << endl;
    }
    else
    {
        cout << "\nParabens! Voce acertou a palavra secreta!\n\n" << endl;
        cout << "Gostaria de adicionar uma nova palavra ao banco? [S/N] "<< endl;
        char resposta;
        cin >> resposta;
        if(resposta == 'S')
        {
            adiciona_palavra();
        }
    }
}

int main()
{
    system("cls");

    le_arquivo();
    sorteia_palavra();

    while(nao_acertou() && nao_enforcou())
    {
        imprime_cabecalho();
        imprime_erros();
        imprime_palavra();

        chuta();

        system("cls");
    }
    
    imprime_cabecalho();
    finaliza_jogo();

    return 0;
}
