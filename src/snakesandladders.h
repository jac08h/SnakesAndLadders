#ifndef SNAKESANDLADDERS_H
#define SNAKESANDLADDERS_H

#include <vector>
#include <map>

#include <player.h>
#include <positionevent.h>


class SnakesAndLadders
{
private:
    std::map<int, int> m_position_events;
    std::vector<Player> m_players;

    int m_player_to_move_index{0};
    int m_die_max_value{6};
    int m_n_squares{100};
    bool m_is_finished{false};

    int m_player_max_index{-1};

    int get_position_after_event(int current_pos);
    void add_position_event(int start, int end);
    int get_index_of_next_player(int die1, int die2);
    int get_updated_position(int current_pos);
public:
    SnakesAndLadders();
    int roll_die();
    void print_position_events();
    std::string play(int die1, int die2);
};

#endif // SNAKESANDLADDERS_H
