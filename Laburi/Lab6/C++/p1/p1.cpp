#include <bits/stdc++.h>
#include "nim.h"

using namespace std;

Move::Move(int amount = 0, int heap = -1): amount(amount), heap(heap) { }

Nim::Nim() {
    heaps[0] = 3;
    heaps[1] = 4;
    heaps[2] = 5;
}

/**
 * Returneaza o lista cu mutarile posibile
 * care pot fi efectuate de player
 */
std::vector<Move> Nim::get_moves(int player) {

    std::vector<Move> ret;
    for (int i = 0; i < 3; i++)
        for (int k = 1; k <= 3; k++)
            if (k <= heaps[i])
                ret.push_back(Move(k, i));
    return ret;
}

/**
 * Intoarce true daca jocul este intr-o stare finala
 */
bool Nim::ended() {

    for(int i = 0 ; i < 3; ++i)
        if(heaps[i])
            return false;
    return true;
}

/**
 * Functia de evaluare a starii curente a jocului
 * Evaluarea se face din perspectiva jucatorului
 * aflat curent la mutare (player)
 */
int Nim::eval(int player) {
    //daca plyer castiga in starea asta returneaza 1, altfel -1

    Move return_move;
    int res = 0;

    if(ended())
        res = -1;

    int divby4 = 0;
    int notdivby4 = 0;

    for (int i = 0 ; i < 3; ++i) {
        if(heaps[i] % 4)
            notdivby4++;
        else
            divby4++;
    }

    if(notdivby4 % 2 == 0)
        res = 1;
    else
        res =  -1;

    return res;
}

/**
 * Aplica o mutarea a jucatorului asupra starii curente
 * Returneaza false daca mutarea e invalida
 */
bool Nim::apply_move(const Move &move) {

    heaps[move.heap] -= move.amount;

    return false;
}

/**
 * Afiseaza starea jocului
 */
void Nim::print() {

    for (int i = 0; i < 3; i++)
    {
        std::cout << i << ":";
        for (int j = 0; j < heaps[i]; j++)
            std::cout << " *";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/**
 * Implementarea algoritmului minimax (negamax)
 * Intoarce o pereche <x, y> unde x este cel mai bun scor
 * care poate fi obtinut de jucatorul aflat la mutare,
 * iar y este mutarea propriu-zisa
 */
pair<int, Move> mini(Nim, int, int);

pair<int, Move> maxi(Nim state, int player, int depth) {

    if(depth == 0 || state.ended()) {
        return pair<int, Move>(state.eval(player), Move(0, 0));
    }

    int maxv = -Inf ;
    Move best_move;
    vector<Move> moves = state.get_moves(player);

    for (Move m : moves) {

        Nim next_state = state;

        next_state.apply_move(m);

        pair<int, Move> res_mini = mini(next_state, player, depth - 1);

        int score = res_mini.first;

        if(score > maxv) {
            maxv = score;
            best_move = m;
        }
    }

    return pair<int, Move>(maxv, best_move);
}

pair<int, Move> mini(Nim state, int player, int depth) {

    if(depth == 0 || state.ended()) {
        return pair<int, Move>(state.eval(player), Move(0, 0));
    }

    int minv = Inf ;
    Move best_move;

    vector<Move> moves = state.get_moves(player);

    for(Move m : moves) {

        Nim next_state = state;
        next_state.apply_move(m);

        pair<int, Move> res_maxi = maxi(next_state, player, depth - 1);

        int score = res_maxi.first;

        if(score < minv) {
            minv = score;
            best_move = m;
        }
    }

    return pair<int, Move>(minv, best_move);
}

std::pair<int, Move> minimax(Nim init, int player, int depth) {
    /**
     * TODO Implementati conditia de oprire
     */

    if (depth == 0) {
        std::vector<Move> moves = init.get_moves(player);
    }



    /**
     * TODO Determinati cel mai bun scor si cea mai buna mutare
     * folosind algoritmul minimax
     */

    return std::pair<int, Move>(-Inf, Move());
}

/**
 * Implementarea de negamax cu alpha-beta pruning
 * Intoarce o pereche <x, y> unde x este cel mai bun scor
 * care poate fi obtinut de jucatorul aflat la mutare,
 * iar y este mutarea propriu-zisa
 */
std::pair<int, Move> minimax_abeta(Nim init, int player, int depth, int alfa, int beta)
{
    std::vector<Move> moves = init.get_moves(player);

    return std::pair<int, Move>(-Inf, Move());
}

int main()
{
    Nim nim;

    nim.heaps[0] = 8;
    nim.heaps[1] = 12;
    nim.heaps[2] = 20;
    cout << "Initial state:\n";
    nim.print();

    /* Choose here if you want COMP vs HUMAN or COMP vs COMP */
    bool HUMAN_PLAYER = false;
    int player = 1;

    while (!nim.ended())
    {
        std::pair<int, Move> p;

        if (player == 1)
        {
            p = maxi(nim, player, 1);
            std::cout << "Player " << player << " evaluates to " << p.first << std::endl;

            cout <<"Amount: " << p.second.amount << ' ' << " from heap: " << p.second.heap << '\n';
            nim.apply_move(p.second);
        }
        else
        {
            if (!HUMAN_PLAYER)
            {
                p = maxi(nim, player, 1);

                std::cout << "Player " << player << " evaluates to " << p.first << std::endl;
                cout <<"Amount: " << p.second.amount << ' ' << " from heap: " << p.second.heap << '\n';

                nim.apply_move(p.second);
            }
            else
            {
                bool valid = false;
                while (!valid)
                {
                    int am, h;
                    std::cout << "Insert amount [1, 2 or 3] and heap [0, 1 or 2]: ";
                    std::cin >> am >> h;
                    valid = nim.apply_move(Move(am, h));
                }
            }
        }

        nim.print();
        player *= -1;
    }

    int w = nim.heaps[0] + nim.heaps[1] + nim.heaps[2];
    if (w == 0)
        std::cout << "Player " << player << " WON!" << std::endl;
    else
        std::cout << "Player " << player << " LOST!" << std::endl;
}
