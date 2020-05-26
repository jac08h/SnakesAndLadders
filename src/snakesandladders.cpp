#include "snakesandladders.h"

#include <iostream>
#include <random>
#include <map>
#include <stdexcept>
#include <string>


typedef std::mt19937 MyRNG;
 SnakesAndLadders::SnakesAndLadders() {
    std::map<int, int> m_position_events;
    add_position_event(2, 38);
    add_position_event(7, 14);
    add_position_event(8, 31);
    add_position_event(15, 26);
    add_position_event(21, 42);
    add_position_event(28, 84);
    add_position_event(36,44);
    add_position_event(51,67);
    add_position_event(71,91);
    add_position_event(78,98);
    add_position_event(87,94);
    add_position_event(16,6);
    add_position_event(46,25);
    add_position_event(49,11);
    add_position_event(62,19);
    add_position_event(64,60);
    add_position_event(74,53);
    add_position_event(89,68);
    add_position_event(92,88);
    add_position_event(95,75);
    add_position_event(99,80);

    m_players = {Player(0, 0), Player(1,0)};
    m_player_max_index = m_players.size()-1;


}

int SnakesAndLadders::roll_die() {
    std::random_device dev;
    MyRNG rng(dev());
    std::uniform_int_distribution<MyRNG::result_type> dist(1, m_die_max_value);
    return dist(rng);
}

int SnakesAndLadders::get_position_after_event(int current_pos) {
    try {
        return m_position_events.at(current_pos);
    }  catch (std::out_of_range) {
        return current_pos;
    }
}

int SnakesAndLadders::get_updated_position(int current_pos) {
    if (current_pos > m_n_squares) {
        int squares_over = (current_pos - m_n_squares);
        current_pos = m_n_squares - squares_over;
    }

    int new_pos = get_position_after_event(current_pos);
    return new_pos;
}

void SnakesAndLadders::add_position_event(int start, int end) {
    m_position_events.insert(std::pair<int, int>(start, end));
}


void SnakesAndLadders::print_position_events() {
    for (auto const& [start, end] : m_position_events) {
        std::cout << start << ":" << end << std::endl;
    }
}

int SnakesAndLadders::get_index_of_next_player(int die1, int die2) {
    if (die1 != die2) {
        if (m_player_to_move_index == m_player_max_index) {
            return 0;
        }
        else {
            return 1;
        }
    }
    return m_player_to_move_index;
}

std::string SnakesAndLadders::play(int die1, int die2) {
    if (m_is_finished) {
        return "Game over!";
    }

    Player& current_player = m_players.at(m_player_to_move_index);
    int current_pos = current_player.get_position();
    int new_pos_without_events = (current_pos + die1 + die2);
    int new_pos = get_position_after_event(new_pos_without_events);

    int next_player_index = get_index_of_next_player(die1, die2);
    int player_this_move = m_player_to_move_index;

    // win if exactly on 100
    if (new_pos == m_n_squares) {
        m_is_finished = true;
        return "Player " + std::to_string(m_player_to_move_index+1) + " Wins!";
    }

    // bounce back if too much
    else if (new_pos > m_n_squares) {
        int squares_over = (new_pos - m_n_squares);
        new_pos_without_events = m_n_squares - squares_over;
        new_pos = get_position_after_event(new_pos_without_events);
    }

    current_player.set_position(new_pos);

    m_player_to_move_index = next_player_index;
    return "Player " + std::to_string(player_this_move+1) + " is on square " + std::to_string(new_pos);
}
