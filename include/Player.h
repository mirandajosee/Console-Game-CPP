#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    public:
        Player();

        void CallInput();
        void ResetToSafePosition();
        int GetXAxis();
        int GetYAxis();
        int lastX,lastY;
    protected:
     int x,y;
    private:
};

#endif //PLAYER_H