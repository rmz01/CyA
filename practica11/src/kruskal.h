#pragma once

#include <vector>
#include "sub_tree.h"
#include "point_types.h"

namespace EMST
{
    class Kruskal
    {
    public:
        static sub_tree computeEMST(const CyA::point_vector &points);

    private:
        static double distance(const CyA::point &a, const CyA::point &b);
    };
}