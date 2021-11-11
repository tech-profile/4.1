#include <iostream>
#include <vector>
#include <string>
#include "Vertice.h"
#include "Arista.h"

using namespace std;

void validateNumber(int n) {
    if(n < 0) {
        throw "No se aceptan numeros negativos";
    }
}

int * parseNumbers(string sentence, int *numbers) {
    string word = "";;

    int counter = 0;

    for(int i=0;i<sentence.length();i++) {
        // Cada que encuentre una ',' significara que termino de
        // recorrer una frase, entonces proseguimos a ingresarla en el arreglo
        if(sentence[i] == ',') {
            numbers[counter] = stoi(word);
            counter = counter + 1;
            word = "";
        } 
        // En caso en que no halla una ',', concatenara cada caracter
        // para asi despues ser ingresado en una variable temporal
        // que nos permitira llevar un control de lo que se quiere
        // ir separando por ','
        else {
            word = word + sentence[i];
        }

        if(i == sentence.length() - 1) {
            numbers[counter] = stoi(word);
        }
    }

    return numbers;
}

struct graph {
    Vertice vertice;
    Arista arista;
};

int main() {
    int num_vertices;
    string sentence;

    cout << endl;
    cout << "*****************************************************" << endl << endl;

    cout << "Ingresar el numero de vertices: ";
    cin >> num_vertices;
    
    try {
        validateNumber(num_vertices);
    } catch(const char *msg) {
        cout << msg << endl;
    }

    int arr[num_vertices];

    cout << endl;

    cout << "Ingresa los numeros de los vertices: ";
    cin >> sentence;

    int *list = parseNumbers(sentence, arr);

    // Arreglo que puede recibir cualquier tipo de dato
    // gracias a la estructura 'struct'
    graph grafo[num_vertices];

    for(int i=0;i<num_vertices;i++) {
        Vertice vertice;
        int aux;

        if(i > 0) {
            Arista arista;

            arista.setVi(aux);
            arista.setVj(list[i]);

            // Con el i-1 accedemos al anterior elemento
            // Esto con el fin de poder asignarle la arista al anterior
            // elemento que fue iterado, ya que por eso guardamos
            // en 'aux' el dato de ese vertice y lo juntamos entonces
            // con el dato actual
            grafo[i-1].arista = arista;
        }

        vertice.setID(i+1);
        vertice.setDato(list[i]);

        grafo[i].vertice = vertice;

        // Guardamos el ultimo dato para despues ser utilizado en la
        // proxima iteracion con el fin de crear la arista que contendra
        // el dato del vertice y el dato del vertice al cual señala
        aux = vertice.getDato();
    }

    cout << endl;

    for(int i=0;i<num_vertices-1;i++) {
        cout << grafo[i].vertice.getDato() << "->";
        cout << "(" << grafo[i].arista.getVi() << "," << grafo[i].arista.getVj() << ")" << endl;
        cout << endl;
    }

    cout << "*****************************************************" << endl;
    cout << endl;

    return 0;
};