class Cell {
protected:
    int x;
    int y;
    bool state;

public:
    Cell();
    Cell(int x, int y);
    virtual ~Cell();

    virtual bool isAlive() const = 0;   


    int getX() const;
    int getY() const;
};
