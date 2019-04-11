// skel PA 2017

#pragma once

#include <vector>

#define Inf 123456789
#define N 6 /* Pastrati N par, N >= 4 */

/**
 * Reprezinta o mutare efectuata de un jucator
 */
class Move
{
    public:
        int player; /* Jucatorul care face mutarea */
        int x; /* Linia */
        int y; /* Coloana */

        Move() { }

        Move(int player, int x, int y);
};

/**
 * Reprezinta starea jocului
 */
class Reversi
{
    private:
        int data[N][N];
    public:
        Reversi();

        /**
         * Intoarce true daca jocul este intr-o stare finala
         */
        bool ended();

        /**
         * Functia de evaluare a starii curente a jocului
         * Evaluarea se face din perspectiva jucatorului
         * aflat curent la mutare (player)
         */
        int eval(int player);

        /**
         * Aplica o mutare a jucatorului, modificand starea jocului
         * Plaseaza piesa jucatorului move.player in pozitia move.x, move.y
         * Mutarea move.x == -1, move.y == -1 semnifica ca jucatorul
         * paseaza randul la mutare
         * Returneaza true daca mutarea este valida
         */
        bool apply_move(const Move &move);

        /**
         * Returns 1 if player won, 0 if draw and -1 if lost
         */
        int winner(int player);

        /**
         * Afiseaza starea jocului
         */
        void print();
};
