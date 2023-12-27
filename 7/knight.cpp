#include "knight.hpp"
#include "bear.hpp"
#include "orc.hpp"

Knight::Knight(int x, int y) : NPC(KnightType, x, y) {}
Knight::Knight(std::istream &is) : NPC(KnightType, is) {}

void Knight::print()
{
    std::cout << *this;
}

void Knight::print(std::ostream &outfs) {
    outfs << *this;
}

bool Knight::accept(std::shared_ptr<NPC> other) {
    return other->fight(std::shared_ptr<Knight>(this,[](Knight*){}));
}

void Knight::save(std::ostream &os)
{
    os << KnightType << std::endl;
    NPC::save(os);
}

bool Knight::fight(std::shared_ptr<Orc> other)
{
    fight_notify(other, true);
    return true;
}

bool Knight::fight(std::shared_ptr<Knight> other)
{
    fight_notify(other, false);
    return false;
}

bool Knight::fight(std::shared_ptr<Bear> other)
{
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Knight &knight)
{
    os << "Knight: " << *static_cast<NPC *>(&knight) << std::endl;
    return os;
}