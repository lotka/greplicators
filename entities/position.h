#ifndef POSITION_H
#define POSITION_H

class position
{
    std::vector<int> positionVector;
public:

    position();

    void setPosition(position &otherPositionClass);
    void setPosition(std::vector<int> &otherPositionVector);
    void setPositionRandom();
    void moveRandom();

    int operator[](int i)
    {
        return positionVector[i];
    }
};

#endif /* POSITION_H */
