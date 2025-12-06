#pragma once

class Cell {
    protected:
        int x;
        int y;
        bool state;
    public:
        Cell(int x, int y);
        Cell(int x, int y, bool state);
        void SetState(bool state);
        int GetX() const;
        int GetY() const;
        virtual ~Cell() {}
        virtual bool GetState() = 0;
};