#pragma once

#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <fstream>
#include <set>
#include <math.h>

// type for npcs
struct NPC;
struct Bear;
struct Knight;
struct Orc;
using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType
{
    Unknown = 0,
    BearType = 1,
    KnightType = 2,
    OrcType = 3
};

struct IFightVisitor{
    virtual void on_fight(const std::shared_ptr<NPC> attacker,const std::shared_ptr<NPC> defender,bool win) = 0;
};

struct NPC : public std::enable_shared_from_this<NPC>
{
    NpcType type;
    int x{0};
    int y{0};
    std::vector<std::shared_ptr<IFightVisitor>> visitors;

    NPC(NpcType t, int _x, int _y);
    NPC(NpcType t, std::istream &is);

    void subscribe(std::shared_ptr<IFightVisitor>visitor );
    void fight_notify(const std::shared_ptr<NPC> defender,bool win);
    virtual bool is_close(const std::shared_ptr<NPC> &other, size_t distance) const;
    
    /*
    virtual bool is_bear() const;
    virtual bool is_knight() const;
    virtual bool is_orc() const ;
    */

    virtual bool accept(std::shared_ptr<NPC> visitor) = 0;
    virtual bool fight(std::shared_ptr<Bear> other) = 0;
    virtual bool fight(std::shared_ptr<Knight> other) = 0;
    virtual bool fight(std::shared_ptr<Orc> other) = 0;

    bool visit(std::shared_ptr<Orc> other);
    bool visit(std::shared_ptr<Knight> other);
    bool visit(std::shared_ptr<Bear> other);

    virtual void print() = 0;
    virtual void print(std::ostream &os) = 0;

    virtual void save(std::ostream &os);

    friend std::ostream &operator<<(std::ostream &os, NPC &npc);
};
