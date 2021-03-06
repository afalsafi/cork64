// +-------------------------------------------------------------------------
// | main.cpp
// |
// | Author: Ali Falsafi
// +-------------------------------------------------------------------------
// | COPYRIGHT:
// |    Copyright Gilbert Bernstein 2013
// |    See the included COPYRIGHT file for further details.
// |
// |    This file is part of the Cork library.
// |
// |    Cork is free software: you can redistribute it and/or modify
// |    it under the terms of the GNU Lesser General Public License as
// |    published by the Free Software Foundation, either version 3 of
// |    the License, or (at your option) any later version.
// |
// |    Cork is distributed in the hope that it will be useful,
// |    but WITHOUT ANY WARRANTY; without even the implied warranty of
// |    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// |    GNU Lesser General Public License for more details.
// |
// |    You should have received a copy
// |    of the GNU Lesser General Public License
// |    along with Cork.  If not, see <http://www.gnu.org/licenses/>.
// +-------------------------------------------------------------------------

#include "cork.hh"
#include "cork_interface.hh"

// namespace corkpp {
int main(int argc, char * argv[]) {
  std::vector<corkpp::point_t> vertices_precipitate;
  corkpp::point_t origin_precipitate{1.40, 1.40, 0.00};
  corkpp::point_t size_precipitate{1.40, 1.40, 1.00};
  // vertices_precipitate =
  //     corkpp::cube_vertice_maker(origin_precipitate, size_precipitate);

  vertices_precipitate.push_back({0.10, 0.10, 0.10});
  vertices_precipitate.push_back({0.75, 0.10, 0.10});
  vertices_precipitate.push_back({0.10, 0.75, 0.10});
  vertices_precipitate.push_back({0.10, 0.10, 0.75});
  vertices_precipitate.push_back({0.50, 0.50, 0.50});

  std::vector<corkpp::point_t> vertices_pixel;
  corkpp::point_t origin_pixel{0.1, 0.1, -0.1};
  corkpp::point_t size_pixel{1.0, 1.0, 1.0};
  vertices_pixel = corkpp::cube_vertice_maker(origin_pixel, size_pixel);

  auto && vol_norm = corkpp::calculate_intersection_volume_normal(
      vertices_precipitate, vertices_pixel);

  auto && vol = corkpp::calculate_intersection_volume(vertices_precipitate,
                                                      vertices_pixel);
  for (uint i = 0; i < vol_norm.size(); ++i) {
    std::cout << vol_norm[i] << std::endl;
  }
  std::cout << vol << std::endl;

  return 0;
}
