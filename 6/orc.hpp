#pragma once
#include "npc.hpp"

struct Orc : public NPC
{
    Orc(int x, int y);
    Orc(std::istream &is);

    void print() override;
    void save(std::ostream &os) override;
    void print(std::ostream &os) override; //печать куда-то в файл или не

    //bool is_bear() const override;

    bool accept(std::shared_ptr<NPC> visitor) override;
    bool fight(std::shared_ptr<Bear> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Orc> other) override;
    friend std::ostream &operator<<(std::ostream &os, Orc &orc);
};