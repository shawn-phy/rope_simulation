#include "rope.hpp"


float gravity = -9.81f;
float dt = 0.01f;
unsigned int max_iterations = 10;
rope::rope(float x1, float x2, float y1, float y2, unsigned int nparticles)
{
    for (unsigned int i = 0; i < nparticles; i++)
    {
        // How close are we to the last point?
        float w = (float)i / (nparticles - 1);

        float x = w * x2 + (1 - w) * x1;
        float y = w * y2 + (1 - w) * y1;
        particle p;
        p.x = x;
        p.y = y;
        p.xp = x;
        p.yp = y;
        p.fixed = i == 0;
        _particles.push_back(p);
    }
    unsigned int noofsegments = nparticles - 1;
    float ropelength = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    float _desireddistance = ropelength / noofsegments;
}

void rope::verletintegration()
{
    for (particle &p : _particles)
    {
        if (p.fixed)
            continue;

        float xcopy = p.x;
        float ycopy = p.y;

        float xvelocity = (p.x - p.xp) / dt;
        float yvelocity = (p.y - p.yp) / dt;

        float xinstantvelocity = xvelocity + 0 * dt;
        float yinstantvelocity = yvelocity + gravity * dt;

        float xtruevelocity = (xinstantvelocity + xvelocity) / 2;
        float ytruevelocity = (yinstantvelocity + yvelocity) / 2;

        p.x += xtruevelocity * dt;
        p.y += ytruevelocity * dt;

        p.xp = xcopy;
        p.yp = ycopy;
    }
}

void rope::enforceconstraints()
{
    // We perform the enforcement multiple times
    for (unsigned iteration = 0; iteration < max_iterations; iteration++)
    {
        // We iterate over each pair of pa
        for (size_t i = 1; i < _particles.size(); i++)
        {
            particle &p1 = _particles[i - 1];
            particle &p2 = _particles[i];

            // Calculating distance between the particles
            float distance = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
            float distanceError = distance - _desireddistance;

            // The direction in which particles should be pulled or pushed
            float xDifference = p2.x - p1.x;
            float yDifference = p2.y - p1.y;

            // We need to make it a unit vector
            // This will allow us to easily scale the impact we have
            // on each particle's position.
            float xDirection = xDifference / sqrt(pow(xDifference, 2) + pow(yDifference, 2));
            float yDirection = yDifference / sqrt(pow(xDifference, 2) + pow(yDifference, 2));

            // Finally, we can update particles' positions
            // We need to remember that fixed particles should stay in place
            if (p1.fixed && !p2.fixed)
            {
                p2.x -= xDirection * distanceError;
                p2.y -= yDirection * distanceError;
            }
            else if (p2.fixed && !p1.fixed)
            {
                p1.x += xDirection * distanceError;
                p1.y += yDirection * distanceError;
            }
            else if (!p1.fixed && !p2.fixed)
            {
                p2.x -= 0.5 * xDirection * distanceError;
                p2.y -= 0.5 * yDirection * distanceError;
                p1.x += 0.5 * xDirection * distanceError;
                p1.y += 0.5 * yDirection * distanceError;
            }
        }
    }
}

void rope::step()
{
    verletintegration();
    enforceconstraints();
}