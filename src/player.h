#ifndef PLAYER_H
#define PLAYER_H


class Player
{
private:
    int m_player_index{-1};
    int m_position{-1};
public:
    Player() {};
    Player(int player_index, int position)
        : m_player_index{player_index}, m_position{position} {}

    int get_position();
    void set_position(int position);
};

#endif // PLAYER_H
