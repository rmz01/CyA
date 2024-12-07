#include "kruskal.h"
#include <algorithm>
#include <cmath>

namespace EMST
{
    sub_tree Kruskal::computeEMST(const CyA::point_vector &points)
    {
        sub_tree result;
        std::vector<CyA::weigthed_arc> edges;

        // Step 1: Create all edges with their weights (distances)
        for (size_t i = 0; i < points.size(); ++i)
        {
            for (size_t j = i + 1; j < points.size(); ++j)
            {
                double weight = distance(points[i], points[j]);
                edges.push_back({weight, {points[i], points[j]}});
            }
        }

        // Step 2: Sort edges by weight
        std::sort(edges.begin(), edges.end(), [](const CyA::weigthed_arc &a, const CyA::weigthed_arc &b) {
            return a.first < b.first;
        });

        // Step 3: Initialize each point as a separate tree
        std::vector<sub_tree> forest;
        for (const auto &point : points)
        {
            sub_tree tree;
            tree.add_point(point);
            forest.push_back(tree);
        }

        // Step 4: Kruskal's algorithm
        for (const auto &edge : edges)
        {
            sub_tree *tree1 = nullptr;
            sub_tree *tree2 = nullptr;

            // Find the trees containing the endpoints of the edge
            for (auto &tree : forest)
            {
                if (tree.contains(edge.second.first))
                {
                    tree1 = &tree;
                }
                if (tree.contains(edge.second.second))
                {
                    tree2 = &tree;
                }
            }

            // If they are in different trees, merge them
            if (tree1 != tree2)
            {
                tree1->merge(*tree2, edge);
                forest.erase(std::remove(forest.begin(), forest.end(), *tree2), forest.end());
            }

            // If only one tree remains, we have our EMST
            if (forest.size() == 1)
            {
                result = forest.front();
                break;
            }
        }

        return result;
    }

    double Kruskal::distance(const CyA::point &a, const CyA::point &b)
    {
        return std::sqrt(std::pow(a.first - b.first, 2) + std::pow(a.second - b.second, 2));
    }
}