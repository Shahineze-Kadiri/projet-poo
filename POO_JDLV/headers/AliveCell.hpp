#include "../headers/Cell.hpp"

class AliveCell : public Cell {
public:
    AliveCell(int x, int y);

    bool isAlive() const override;   // Renvoie true
};
