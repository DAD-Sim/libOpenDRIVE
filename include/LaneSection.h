#pragma once
#include "Lane.h"
#include "XmlNode.h"

#include <map>
#include <string>
#include <vector>

namespace odr
{

struct LaneSection : public XmlNode
{
    LaneSection(std::string road_id, double s0);

    std::vector<Lane> get_lanes() const;

    int  get_lane_id(const double s, const double t) const;
    Lane get_lane(const double s, const double t) const;
    bool is_on_road(const double s, const double t) const;

    int id; // Only for internal use
    std::string         road_id = "";
    double              s0 = 0;
    std::map<int, Lane> id_to_lane;
};

} // namespace odr
