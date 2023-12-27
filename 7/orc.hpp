#pragma once
#include "npc.hpp"

struct Orc : public NPC
{
    Orc(int x, int y);
    Orc(std::istream &is);

    void print() override;
    void print(std::ostream &os) override;

    bool accept(std::shared_ptr<NPC> visitor) override;

    bool fight(std::shared_ptr<Orc> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Bear> other) override;

    void save(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream &os, Orc &orc);
};