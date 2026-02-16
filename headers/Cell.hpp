#pragma once // Inclusion multiple protection

// Classe abstraite représentant une cellule
class Cell {
    protected:
        int x;
        int y;
        bool state;
    public:
        Cell();
        Cell(int x, int y);
        int GetX() const;
        int GetY() const;
        void SetState(bool state);
        virtual ~Cell() {}
        virtual bool GetState() = 0;
};