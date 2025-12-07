#pragma once

class Cell {
    protected:
        int x;
        int y;
        bool state;
    public:
        Cell(int x, int y);
        int GetX() const;
        int GetY() const;
        void SetState(bool state);
        virtual ~Cell() {}
        virtual bool GetState() = 0;
};