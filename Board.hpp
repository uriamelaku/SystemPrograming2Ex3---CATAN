#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <unordered_map>
#include <array>
#include <map>
#include "HexTile.hpp"
#include "Corner.hpp"
#include "Edge.hpp"
#include "DevelopmentCard.hpp"
#include "DevelopmentCardDeck.hpp"
#include "Player.hpp"

class Board {
private:
    std::vector<HexTile> tiles;
    std::unordered_map<int, Corner> corners;
    std::unordered_map<int, Edge> edges;
    DevelopmentCardDeck developmentDeck;
    std::vector<Player> players; // ודא שהמשתנה מוגדר כאן

    void initializeTile(int index, ResourceType type, int number);
    void initializeConnections();

public:
    Board();
    void initialize();
    void printBoard() const;
    void printPlayerStatus(int playerId) const;
    void printAllPlayersStatus() const;

    bool addSettlement(int cornerId, int playerId);
    bool upgradeSettlement(int cornerId, int playerId);
    bool addRoad(int edgeId, int playerId);
    DevelopmentCard drawDevelopmentCard(int playerId);
    void processCommand(const std::string& command, int playerId);
    int rollDice() const;

    void addPlayer(int playerId);
};

#endif // BOARD_HPP
