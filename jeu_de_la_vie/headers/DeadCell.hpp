class DeadCell : public Cell {
public:
    DeadCell(int x, int y);

    bool isAlive() override;  
};
