#include <gtest/gtest.h>
#include "knight.hpp"
#include "orc.hpp"
#include "bear.hpp"
#include "npc.hpp"


TEST(Knight_test, _01) {
    Knight knight(25,50);
    knight.print();
}

TEST(Knight_test, _02) {
    std::shared_ptr<NPC> knight= std::make_shared<Knight>(25, 50);
    std::shared_ptr<NPC> bear= std::make_shared<Bear>(25, 10);
    std::shared_ptr<NPC> orc= std::make_shared<Orc>(15, 45);

    //success = defender->accept(attacker);
    bool successb = bear->accept(knight);
    bool successo = orc->accept(knight);
    bool successk = knight->accept(knight);
    ASSERT_FALSE(successb);
    ASSERT_FALSE(successk);
    ASSERT_TRUE(successo);
}

TEST(Knight_test, _03) {
    std::shared_ptr<Knight> knight= std::make_shared<Knight>(25, 50);
    std::shared_ptr<Bear> bear= std::make_shared<Bear>(25, 10);
    std::shared_ptr<Orc> orc= std::make_shared<Orc>(15, 45);

    //success = defender->accept(attacker);
    bool successb = bear->fight(knight);
    bool successo = orc->fight(knight);
    bool successk = knight->fight(knight);
    ASSERT_FALSE(successo);
    ASSERT_FALSE(successk);
    ASSERT_TRUE(successb);
}

TEST(Knight_test, _04) {

    Knight Knight(25,50);
    std::cout << Knight << std::endl;

}

TEST(Orc_test, _01) {
    Orc Orc(25,10);
    Orc.print();
}

TEST(Orc_test, _02) {
    std::shared_ptr<NPC> knight= std::make_shared<Knight>(25, 50);
    std::shared_ptr<NPC> bear= std::make_shared<Bear>(25, 10);
    std::shared_ptr<NPC> orc= std::make_shared<Orc>(15, 45);

    //success = defender->accept(attacker);
    bool successb = bear->accept(orc);
    bool successo = orc->accept(orc);
    bool successk = knight->accept(orc);
    ASSERT_FALSE(successo);
    ASSERT_FALSE(successk);
    ASSERT_TRUE(successb);
}

TEST(Orc_test, _03) {
    std::shared_ptr<Knight> knight= std::make_shared<Knight>(25, 50);
    std::shared_ptr<Bear> bear= std::make_shared<Bear>(25, 10);
    std::shared_ptr<Orc> orc= std::make_shared<Orc>(15, 45);

    //success = defender->accept(attacker);
    bool successo = orc->fight(knight);
    bool successor = orc->fight(bear);
    ASSERT_FALSE(successo);
    ASSERT_TRUE(successor);
}

TEST(Orc_test, _04) {
    Orc orc(25,10);
    std::cout << orc << std::endl;
}

TEST(Bear_test, _01) {
    Bear bear(15,45);
    bear.print();
}

TEST(Bear_test, _02) {
    std::shared_ptr<NPC> knight= std::make_shared<Knight>(25, 50);
    std::shared_ptr<NPC> bear= std::make_shared<Bear>(25, 10);
    std::shared_ptr<NPC> orc= std::make_shared<Orc>(15, 45);

    //success = defender->accept(attacker);
    bool successb = bear->accept(bear);
    bool successo = orc->accept(bear);
    bool successk = knight->accept(bear);
    ASSERT_FALSE(successb);
    ASSERT_FALSE(successo);
    ASSERT_TRUE(successk);
}

TEST(Bear_test, _03) {
    std::shared_ptr<Knight> knight= std::make_shared<Knight>(25, 50);
    std::shared_ptr<Bear> bear= std::make_shared<Bear>(25, 10);
    std::shared_ptr<Orc> orc= std::make_shared<Orc>(15, 45);

    //success = defender->accept(attacker);
    bool successb = bear->fight(knight);
    bool successbb = orc->fight(bear);
    ASSERT_TRUE(successb);
    ASSERT_TRUE(successbb);
}

TEST(Bear_test, _04) {
    Bear bear(15,45);
    std::cout << bear << std::endl;
}

TEST(npc_test, _01) {
    std::set<std::shared_ptr<NPC>> array;

    std::shared_ptr<Knight> knight= std::make_shared<Knight>(25, 50);
    std::shared_ptr<Bear> bear= std::make_shared<Bear>(25, 10);
    std::shared_ptr<Orc> orc= std::make_shared<Orc>(15, 45);

    array.insert(knight);
    array.insert(bear);
    array.insert(orc);

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

    std::cout << "killed: " << dead_list.size() << std::endl;


}

TEST(npc_test, _02) {
    std::set<std::shared_ptr<NPC>> array;

    std::shared_ptr<Knight> knight= std::make_shared<Knight>(25, 50);
    std::shared_ptr<Bear> bear= std::make_shared<Bear>(25, 10);
    std::shared_ptr<Orc> orc= std::make_shared<Orc>(15, 45);

    array.insert(knight);
    array.insert(bear);
    array.insert(orc);

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

    std::cout << "Survivors: " << std::endl;

    for (auto &n : array)
        n->print();

}


int main(int argc, char** argv){

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}