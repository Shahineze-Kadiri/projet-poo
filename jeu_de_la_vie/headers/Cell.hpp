class Cell {
protected:
    int x;
    int y;
    bool state;

public:
    Cell();
    Cell(int x, int y);
    virtual ~Cell();

    virtual bool isAlive() const = 0;    // Méthode polymorphe obligatoire
    void setState(bool state);
    void applyState();                   // Applique nextState pour la prochaine génération

    int getX() const;
    int getY() const;
};
