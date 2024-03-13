/*
Implemente uma estrutura de dados pilha, utilizando encadeamento de nós, para implementar um inventário de itens em um jogo digital. A estrutura deve possibilitar, pelo menos, as seguintes ações: empilhamento e desempilhamento de itens, verificação do item no topo da pilha e limpeza do inventário (remoção de todos os elementos da pilha). O desempilhamento deve escrever mensagem de erro na saída ("Erro: pilha vazia!"), quando a pilha já estiver vazia. Os itens do inventários possuem os seguintes atributos: nome (uma string sem espaços), tipo (um único caracter) e valor (um inteiro).

Entradas:

O programa deve aceitar os seguintes comandos:

i: seguido de uma string, um caracter e um inteiro: para inserir um item no inventário
r: para retirar um item do inventário
l: para limpar (remover todos) os itens do inventário
e: para espiar o topo do inventário (escreve o topo sem removê-lo)
f: para finalizar a execução do programa
Saídas:

Todas as saídas de comandos já estão implementadas na função principal desse código exemplo fornecido. Ao terminar a execução do programa, todos os itens da pilha são desempilhados e escritos.

Exemplo de Entrada e Saída juntas:

r
Erro: pilha vazia!
i um a 1
i dois b 2
i quatro d 4
i sete g 7
i oito h 8
r
Nome: oito Tipo: h Valor: 8
e
Nome: sete Tipo: g Valor: 7
r
Nome: sete Tipo: g Valor: 7
f
Nome: quatro Tipo: d Valor: 4
Nome: dois Tipo: b Valor: 2
Nome: um Tipo: a Valor: 1

*/

#include <iostream>

using namespace std;

class noh
{
    friend class pilha;

private:
    int mValor;
    noh *mProximo;
    string mNome;
    char mTipo;

public:
    noh(string nome, char tipo, int valor); 
};

noh::noh(string nome, char tipo, int valor) 
{
    mValor = valor;
    mProximo = NULL;
    mNome= nome;
    mTipo= tipo;


}
class pilha
{
private:
    noh *mTopo;
    int mTamanho;
    string mNome;
    char mTipo;
    int mValor;

public:
    pilha();
    ~pilha();
    int tamanho();
    void empilha(string nome, char tipo, int valor); 
    string desempilha();
    void limpaPilha();
    bool vazia();
    string espiar();
};

pilha::pilha()
{
    mTopo = NULL;
    mTamanho = 0;
    string nome;
}

pilha::~pilha()
{
    limpaPilha();
}

void pilha::limpaPilha()
{
    while (mTamanho > 0)
    { 
        desempilha();
    }
}

int pilha::tamanho()
{
    return mTamanho;
}

void pilha::empilha(string nome, char tipo, int valor)
{                                           
    noh *novo = new noh(nome, tipo, valor);
    novo->mProximo = mTopo;
    mTopo = novo;
    mTamanho++;
}

string pilha::desempilha()
{
    string nome = mTopo->mNome;
    char tipo = mTopo->mTipo;
    int valor = mTopo->mValor;

    noh *temp = mTopo;
    mTopo = mTopo->mProximo;
    delete temp;
    mTamanho--;

    string tudo;
    tudo = "Nome: " + nome + " Tipo: " + tipo + " Valor: " + to_string(valor);

    return tudo;
}

string pilha::espiar(){
    if (mTopo == NULL)
    {
        return "Erro: pilha vazia!";
    } else{
        string tudo;
        tudo = "Nome: " + mTopo->mNome + " Tipo: " + mTopo->mTipo + " Valor: " + to_string(mTopo->mValor);
        return tudo;
    }
}

bool pilha::vazia()
{
    if (mTopo == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    pilha p1;
    
    char acao;
    while (acao != 'f')
    {
        acao = 'j';
        string nome;
        char tipo;
        int valor;
        cin >> acao;
        if (acao == 'i')
        {
            cin >> nome >> tipo >> valor;
            p1.empilha(nome, tipo, valor);
        }

        else if (acao == 'r')
        {
            if (p1.vazia())
            {
                cout << "Erro: pilha vazia!" << endl;
            }
            else
            {
                cout << p1.desempilha() << endl;
            }
        }

        else if (acao == 'l')
        {
            p1.limpaPilha();
            cout << "Pilha limpa!" << endl;
        }

        else if (acao == 'e')
        {
            cout << p1.espiar();
        }

        else if (acao == 'f')
        {
            while (not p1.vazia())
            {
                cout << p1.desempilha() << endl;
            }
        }
    }
    return 0;
}
