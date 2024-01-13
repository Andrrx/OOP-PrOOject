main.cpp

// main.cpp
#include "game.h"

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int choice;

    // Definirea atacurilor disponibile
    Attack a1("Slash", 10, 0.8, 0.2, 1.5);
    Attack a2("Hadouken", 15, 0.7, 0.3, 1.8);
    Attack a3("Puch", 12, 0.9, 0.1, 1.7);
    Attack a4("Hadoken", 18, 0.6, 0.4, 2.0);

    // Crearea jucatorilor cu asocierea atacurilor disponibile
    Character player1("Ryu", 100);
    player1.addAttack(a1);
    player1.addAttack(a2);

    Character player2("Ken", 100);
    player2.addAttack(a3);
    player2.addAttack(a4);

    try {
        do {
            choice = displayMenu();

            switch (choice) {
                case 1: {
                    cout << "Jocul a inceput!\n";

                    while (player1.getHP() > 0 && player2.getHP() > 0) {
                        cout << "Starea jucatorilor:\n";
                        cout << player1 << endl;
                        cout << player2 << endl;

                        // Jucatorul 1 alege un atac
                        cout << "Jucator 1, este randul tau!\n";
                        player1.chooseAttacks();

                        // Aplica atacul asupra jucatorului 2
                        player1.performAttack(player2);

                        // Verifica daca jucatorul 2 a ramas fara HP
                        if (player2.getHP() <= 0) {
                            cout << "Jucatorul 1 a castigat! Felicitari!\n";
                            break;
                        }

                        // Jucatorul 2 alege un atac
                        cout << "Jucator 2, este randul tau!\n";
                        player2.chooseAttacks();

                        // Aplica atacul asupra jucatorului 1
                        player2.performAttack(player1);

                        // Verifica daca jucatorul 1 a ramas fara HP
                        if (player1.getHP() <= 0) {
                            cout << "Jucatorul 2 a castigat! Felicitari!\n";
                            break;
                        }
                    }
                    break;
                }
                case 2:
                    cout << "Jocul s-a incheiat.\n";
                    break;
                default:
                    cout << "Optiune invalida. Va rugam alegeti o optiune valida.\n";
            }

        } while (choice != 2);

    } catch (const exception& e) {
        cerr << "Exceptie: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    std::system("pause");

    return 0;
}
