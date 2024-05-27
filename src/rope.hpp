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
}

#endif