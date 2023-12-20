#include "bear.hpp"
#include "knight.hpp"
#include "orc.hpp"

Bear::Bear(int x, int y) : NPC(BearType, x, y) {}
Bear::Bear(std::istream &is) : NPC(BearType, is) {}

void Bear::print()
{
    std::cout << *this;
}

void Bear::print(std::ostream &outfs) {
    outfs << *this;
}

/*bool Bear::is_bear() const 
{
    return true;
}*/
bool Bear::accept(std::shared_ptr<NPC> visitor) {
    std::shared_ptr<Bear> This = std::make_shared<Bear>(*this);
    return visitor->visit(This);
}

bool Bear::fight(std::shared_ptr<Bear> other) 
{
    fight_notify(other, false);
    return false;
}

bool Bear::fight(std::shared_ptr<Knight> other) 
{
    fight_notify(other, true);
    return true;
}

bool Bear::fight(std::shared_ptr<Orc> other) 
{
    fight_notify(other, false);
    return false;
}

void Bear::save(std::ostream &os) 
{
    os << BearType << std::endl;
    NPC::save(os);
}

std::ostream &operator<<(std::ostream &os, Bear &bear)
{
    os << "bear: " << *static_cast<NPC *>(&bear) << std::endl;
    return os;
}