#include <iostream>
using namespace std;

struct NO {
    int valor;
    NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);

int main() {
    menu();
}

void menu() {
    int op = 0;
    while (op != 7) {
        system("cls"); // Somente no Windows
        cout << "Menu Lista Ligada Ordenada\n\n";
        cout << "1 - Inicializar Lista \n";
        cout << "2 - Exibir quantidade de elementos \n";
        cout << "3 - Exibir elementos \n";
        cout << "4 - Buscar elemento \n";
        cout << "5 - Inserir elemento \n";
        cout << "6 - Excluir elemento \n";
        cout << "7 - Sair \n\n";
        cout << "Opcao: ";
        cin >> op;
        switch (op) {
        case 1: inicializar(); break;
        case 2: exibirQuantidadeElementos(); break;
        case 3: exibirElementos(); break;
        case 4: buscarElemento(); break;
        case 5: inserirElemento(); break;
        case 6: excluirElemento(); break;
        case 7: return;
        default: break;
        }
        system("pause"); // Somente no Windows
    }
}

void inicializar() {
    NO* aux = primeiro;
    while (aux != NULL) {
        NO* paraExcluir = aux;
        aux = aux->prox;
        free(paraExcluir);
    }
    primeiro = NULL;
    ultimo = NULL;
    cout << "Lista inicializada \n";
}

void exibirQuantidadeElementos() {
    int nElementos = 0;
    NO* aux = primeiro;
    while (aux != NULL) {
        nElementos++;
        aux = aux->prox;
    }
    cout << "Quantidade de elementos: " << nElementos << endl;
}

void exibirElementos() {
    if (primeiro == NULL) {
        cout << "Lista vazia \n";
        return;
    }
    else {
        cout << "Elementos: \n";
        NO* aux = primeiro;
        while (aux != NULL) {
            cout << aux->valor << endl;
            aux = aux->prox;
        }
    }
}

void inserirElemento() {
    int num;
    cout << "Digite o elemento: ";
    cin >> num;

    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) return;

    novo->valor = num;
    novo->prox = NULL;

    if (primeiro == NULL) {
        primeiro = novo;
        ultimo = novo;
        return;
    }

    NO* atual = primeiro;
    NO* anterior = NULL;

    while (atual != NULL && atual->valor < num) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL && atual->valor == num) {
        cout << "Elemento já existe na lista!\n";
        free(novo);
        return;
    }

    if (anterior == NULL) {
        novo->prox = primeiro;
        primeiro = novo;
    }
    else {
        anterior->prox = novo;
        novo->prox = atual;
    }

    if (novo->prox == NULL) {
        ultimo = novo;
    }
}

void buscarElemento() {
    int num;
    cout << "Digite o elemento para buscar: ";
    cin >> num;

    NO* atual = primeiro;

    while (atual != NULL && atual->valor <= num) {
        if (atual->valor == num) {
            cout << "Elemento encontrado!\n";
            return;
        }
        atual = atual->prox;
    }

    cout << "Elemento nao encontrado!\n";
}

void excluirElemento() {
    int num;
    cout << "Digite o elemento para excluir: ";
    cin >> num;

    NO* atual = primeiro;
    NO* anterior = NULL;

    while (atual != NULL && atual->valor < num) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL || atual->valor != num) {
        cout << "Elemento nao encontrado!\n";
        return;
    }

    if (anterior == NULL) {
        primeiro = atual->prox;
    }
    else {
        anterior->prox = atual->prox;
    }

    if (atual->prox == NULL) {
        ultimo = anterior;
    }

    free(atual);
    cout << "Elemento removido!\n";
}