#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Menú principal
void menuPrincipal()
{
    cout << "\n=== Juego de Dados ===" << endl;
    cout << "|      1. Jugar      |" << endl;
    cout << "|      2. Salir      |" << endl;
    cout << "=== Por TasteLessT ===" << endl;
}

// Generar número aleatorio entre 1 y 6
int numeroAleatorio()
{
    return (rand() % 6) + 1;
}

int main()
{
    // Inicializar el generador de números aleatorios con el tiempo actual
    srand(time(0));

    bool salir = false;
    int jugadorPuntaje = 0;
    int computadoraPuntaje = 0;
    char continuar;

    while (!salir)
    {
        menuPrincipal();

        // Variables
        int jugar;
        cout << "\n\nElija →  ";
        cin >> jugar;

        switch (jugar)
        {
        case 1:
            cout << "\n\n\n=== Juego de Dados ===" << endl;

            do
            {
                // Lanzamiento de dados
                int resultadoJugador = numeroAleatorio();
                int resultadoComputadora = numeroAleatorio();

                cout << "\n\n=== Nueva Ronda ===" << endl;

                cout << "\nTiraste el dado y obtuviste: " << resultadoJugador << endl;
                cout << "La computadora tiró el dado y obtuvo: " << resultadoComputadora << endl;

                // Comparar los resultados
                if (resultadoJugador > resultadoComputadora)
                {
                    cout << "\n¡Ganaste esta ronda!" << endl;
                    jugadorPuntaje++;
                }
                else if (resultadoJugador == resultadoComputadora)
                {
                    cout << "\nEs un empate en esta ronda." << endl;
                }
                else
                {
                    cout << "\n¡La computadora ganó esta ronda!" << endl;
                    computadoraPuntaje++;
                }

                // Mostrar el puntaje actual
                cout << "\nPuntaje actual:" << endl;
                cout << "Jugador: " << jugadorPuntaje << " - Computadora: " << computadoraPuntaje << endl;

                // Preguntar al jugador si quiere continuar
                cout << "\n¿Quieres jugar otra ronda? (s/n): ";
                cin >> continuar;

            } while (continuar == 's' || continuar == 'S');

            // Mostrar el resultado final
            cout << "\n=== Resultado final ===" << endl;
            cout << "Puntaje final:" << endl;
            cout << "\nJugador: " << jugadorPuntaje << " - Computadora: " << computadoraPuntaje << endl;

            // Determinar el ganador
            if (jugadorPuntaje > computadoraPuntaje)
            {
                cout << "¡Felicidades, ganaste el juego!" << endl;
            }
            else if (jugadorPuntaje < computadoraPuntaje)
            {
                cout << "La computadora ganó el juego. ¡Inténtalo de nuevo!" << endl;
            }
            else
            {
                cout << "El juego terminó en empate." << endl;
            }
            break;

        case 2:
            cout << "\n\nCerrando la aplicación..." << endl;
            salir = true;
            break;

        default:
            cout << "Por favor, introduzca '1' o '2'" << endl;
            break;
        }
    }
    return 0;
}
