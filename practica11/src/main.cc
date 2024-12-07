#include <iostream>
#include <fstream>
#include <vector>
#include "point_types.h"
#include "sub_tree.h"
#include "kruskal.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>\n";
        return 1;
    }

    std::ifstream input_file(argv[1]);
    if (!input_file)
    {
        std::cerr << "Error opening input file\n";
        return 1;
    }

    std::ofstream output_file(argv[2]);
    if (!output_file)
    {
        std::cerr << "Error opening output file\n";
        return 1;
    }

    int num_points;
    input_file >> num_points;

    CyA::point_vector points(num_points);
    for (int i = 0; i < num_points; ++i)
    {
        input_file >> points[i].first >> points[i].second;
    }

    EMST::sub_tree emst = EMST::Kruskal::computeEMST(points);

    for (const auto &arc : emst.get_arcs())
    {
        output_file << "(" << (arc.first.first >= 0 ? " " : "") << arc.first.first << ", " 
                    << (arc.first.second >= 0 ? " " : "") << arc.first.second << ") -> ("
                    << (arc.second.first >= 0 ? " " : "") << arc.second.first << ", " 
                    << (arc.second.second >= 0 ? " " : "") << arc.second.second << ")\n";
    }

    output_file << "\n" << emst.get_cost() << std::endl;

    return 0;
}