#ifndef ROPE_HPP
#define ROPE_HPP

#include <vector>
#include <math.h>
#include <stdlib.h>

float gravity = -9.8f;
float dt = 0.01f;
unsigned int max_iterations = 10;

struct particle
{
    float x, y;
    float xp, yp;

    bool fixed;
};

class rope
{
    public:
    rope(float x1, float x2, float y1, float y2, unsigned int nparticles);

    void step();

    private:
    void verletintegration();
    void enforceconstraints();

    std::vector<particle> _particles;
    float _desireddistance;
};
#endif