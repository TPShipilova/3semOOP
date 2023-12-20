#include <gtest/gtest.h>
#include "orc.hpp"
#include "knight.hpp"
#include "bear.hpp"
#include "npc.hpp"


TEST(Orc_test, _01) {
    Orc Orc(40,50);
    Orc.print();
}

TEST(Orc_test, _02) {
    std::shared_ptr<NPC> orc= std::make_shared<Orc>(40, 50);
    std::shared_ptr<NPC> bear= std::make_shared<Bear>(40, 10);
    std::shared_ptr<NPC> knight= std::make_shared<Knight>(30, 45);

    //success = defender->accept(attacker);
    bool successb = bear->accept(orc);
    bool successr = knight->accept(orc);
    bool successw = orc->accept(orc);
    ASSERT_TRUE(successb);
    ASSERT_FALSE(successw);
    ASSERT_FALSE(successr);
}

TEST(Orc_test, _03) {
    std::shared_ptr<Orc> orc= std::make_shared<Orc>(40, 50);
    std::shared_ptr<Bear> bear= std::make_shared<Bear>(40, 10);
    std::shared_ptr<Knight> knight= std::make_shared<Knight>(30, 45);

    //success = defender->accept(attacker);
    bool successb = bear->fight(orc);
    bool successk = knight->fight(orc);
    ASSERT_TRUE(successk);
    ASSERT_FALSE(successb);
}

TEST(Orc_test, _04) {

    Orc orc(40,50);
    std::cout << orc << std::endl;

}

TEST(Knight_test, _01) {
    Knight knight(40,10);
    knight.print();
}

TEST(Knight_test, _02) {
    std::shared_ptr<NPC> orc= std::make_shared<Orc>(40, 50);
    std::shared_ptr<NPC> bear= std::make_shared<Bear>(40, 10);
    std::shared_ptr<NPC> knight= std::make_shared<Knight>(30, 45);

    //success = defender->accept(attacker);
    bool successb = bear->accept(knight);
    bool successk = knight->accept(knight);
    bool successo = orc->accept(knight);
    ASSERT_FALSE(successk);
    ASSERT_TRUE(successo);
    ASSERT_FALSE(successb);
}

TEST(Knight_test, _03) {
    std::shared_ptr<Orc> orc= std::make_shared<Orc>(40, 50);
    std::shared_ptr<Bear> bear= std::make_shared<Bear>(40, 10);
    std::shared_ptr<Knight> knight= std::make_shared<Knight>(30, 45);

    //success = defender->accept(attacker);
    bool successk = knight->fight(orc);
    bool successkk = knight->fight(bear);
    ASSERT_FALSE(successkk);
    ASSERT_TRUE(successk);
}

TEST(Knight_test, _04) {
    Knight knight(40,10);
    std::cout << knight << std::endl;
}

TEST(Bear_test, _01) {
    Bear bear(30,45);
    bear.print();
}

TEST(Bear_test, _02) {
    std::shared_ptr<NPC> orc= std::make_shared<Orc>(40, 50);
    std::shared_ptr<NPC> bear= std::make_shared<Bear>(40, 10);
    std::shared_ptr<NPC> knight= std::make_shared<Knight>(30, 45);

    //success = defender->accept(attacker);
    bool successb = bear->accept(bear);
    bool successk = knight->accept(bear);
    bool successo = orc->accept(bear);
    ASSERT_FALSE(successb);
    ASSERT_TRUE(successk);
    ASSERT_FALSE(successo);
}

TEST(Bear_test, _03) {
    std::shared_ptr<Orc> orc= std::make_shared<Orc>(40, 50);
    std::shared_ptr<Bear> bear= std::make_shared<Bear>(40, 10);
    std::shared_ptr<Knight> knight= std::make_shared<Knight>(30, 45);

    //success = defender->accept(attacker);
    bool successb = bear->fight(orc);
    bool successbb = knight->fight(bear);
    ASSERT_FALSE(successb);
    ASSERT_FALSE(successbb);
}

TEST(Bear_test, _04) {
    Bear bear(30,45);
    std::cout << bear << std::endl;
}

TEST(npc_test, _01) {
    std::set<std::shared_ptr<NPC>> array;

    std::shared_ptr<Orc> orc= std::make_shared<Orc>(40, 50);
    std::shared_ptr<Bear> bear= std::make_shared<Bear>(40, 10);
    std::shared_ptr<Knight> knight= std::make_shared<Knight>(30, 45);

    array.insert(orc);
    array.insert(bear);
    array.insert(knight);

    size_t distance = 20;
    std::set<std::shared_ptr<NPC>> dead_list;

    for (const auto &attacker : array)
        for (const auto &defender : array)
            if ((attacker != defender) && (attacker->is_close(defender, distance)))
            {
                bool success{false};
                success = defender->accept(attacker);
                
                if (success)
                    dead_list.insert(defender);
            }

    std::cout << "killed : " << dead_list.size() << std::endl;


}

TEST(npc_test, _02) {
    std::set<std::shared_ptr<NPC>> array;

    std::shared_ptr<Orc> orc= std::make_shared<Orc>(40, 50);
    std::shared_ptr<Bear> bear= std::make_shared<Bear>(40, 10);
    std::shared_ptr<Knight> knight= std::make_shared<Knight>(30, 45);

    array.insert(orc);
    array.insert(bear);
    array.insert(knight);

    size_t distance = 20;
    std::set<std::shared_ptr<NPC>> dead_list;

    for (const auto &attacker : array)
        for (const auto &defender : array)
            if ((attacker != defender) && (attacker->is_close(defender, distance)))
            {
                bool success{false};
                success = defender->accept(attacker);
                
                if (success)
                    dead_list.insert(defender);
            }

    for (auto &d : dead_list)
            array.erase(d);

    std::cout << "Survivors : " << std::endl;

    for (auto &n : array)
        n->print();

}


int main(int argc, char** argv){

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}