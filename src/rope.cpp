#include "rope.hpp"

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
        p.xp = 0;
        p.yp = 0;
        p.fixed = false;
        _particles.push_back(p);
    }
    unsigned int noofsegments = nparticles - 1;
    float ropelength = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    float _desireddistance = ropelength/noofsegments;
}
