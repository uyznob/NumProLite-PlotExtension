#include <string>
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;
.
.
.
// Plot deformed mesh
void Discretization::plot_msh()
{
  std::vector<double> xcoorVec, ycoorVec;
  std::vector<double> coorX, coorY;

  int nnode = node.get_size();
  int nelem = element.get_size();
  double centerX, centerY;

  // Plot node
  plt::figure(1);
  for (int i = 0; i < nnode; i++)
  {
    // Node's coordinates
    xcoorVec.push_back(node[i]->get_x());
    ycoorVec.push_back(node[i]->get_y());

    // Plot node ID
    plt::text(node[i]->get_x(), node[i]->get_y(),
              std::to_string(node[i]->get_id()));
  }
  plt::scatter(xcoorVec, ycoorVec, 5);

  // Plot element via lines
  for (int i = 0; i < nelem; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      // Coordinate X
      coorX.push_back(element[i]->nodes_get(j)->get_x());
      coorX.push_back(element[i]->nodes_get(j + 1)->get_x());

      // Coordinate Y
      coorY.push_back(element[i]->nodes_get(j)->get_y());
      coorY.push_back(element[i]->nodes_get(j + 1)->get_y());
    }

    // Coordinate X
    coorX.push_back(element[i]->nodes_get(3)->get_x());
    coorX.push_back(element[i]->nodes_get(0)->get_x());

    // Coordinate Y
    coorY.push_back(element[i]->nodes_get(3)->get_y());
    coorY.push_back(element[i]->nodes_get(0)->get_y());

    // Plot quadrilateral element by four lines
    plt::plot(coorX, coorY, "b-");

    // Reset coordinate vectors
    coorX.clear();
    coorY.clear();

    // Plot quadrilateral element ID
    centerX = 0.25 * (element[i]->nodes_get(0)->get_x() +
                      element[i]->nodes_get(1)->get_x() +
                      element[i]->nodes_get(2)->get_x() +
                      element[i]->nodes_get(3)->get_x());

    centerY = 0.25 * (element[i]->nodes_get(0)->get_y() +
                      element[i]->nodes_get(1)->get_y() +
                      element[i]->nodes_get(2)->get_y() +
                      element[i]->nodes_get(3)->get_y());

    plt::text(centerX, centerY, std::to_string(element[i]->get_id()));
  }
  plt::show(true);

  return;
}

// Plot deformed mesh
void Discretization::plot_defo_msh()
{
  std::vector<double> xcoorVec, ycoorVec;
  std::vector<double> coorX, coorY;

  int nnode = node.get_size();
  int nelem = element.get_size();
  double scaleFactor = 0.1;

  // Plot node
  plt::figure(2);
  for (int i = 0; i < nnode; i++)
  {
    // Node's coordinates
    xcoorVec.push_back(node[i]->get_x() + node[i]->get_sol(0) * scaleFactor);
    ycoorVec.push_back(node[i]->get_y() + node[i]->get_sol(1) * scaleFactor);
  }
  plt::scatter(xcoorVec, ycoorVec, 5);

  // Plot element via lines
  for (int i = 0; i < nelem; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      // Deformed X
      coorX.push_back(element[i]->nodes_get(j)->get_x() +
                      element[i]->nodes_get(j)->get_sol(0) * scaleFactor);
      coorX.push_back(element[i]->nodes_get(j + 1)->get_x() +
                      element[i]->nodes_get(j + 1)->get_sol(0) * scaleFactor);

      // Deformed Y
      coorY.push_back(element[i]->nodes_get(j)->get_y() +
                      element[i]->nodes_get(j)->get_sol(1) * scaleFactor);
      coorY.push_back(element[i]->nodes_get(j + 1)->get_y() +
                      element[i]->nodes_get(j + 1)->get_sol(1) * scaleFactor);
    }

    // Deformed X
    coorX.push_back(element[i]->nodes_get(3)->get_x() +
                    element[i]->nodes_get(3)->get_sol(0) * scaleFactor);
    coorX.push_back(element[i]->nodes_get(0)->get_x() +
                    element[i]->nodes_get(0)->get_sol(0) * scaleFactor);

    // Deformed Y
    coorY.push_back(element[i]->nodes_get(3)->get_y() +
                    element[i]->nodes_get(3)->get_sol(1) * scaleFactor);
    coorY.push_back(element[i]->nodes_get(0)->get_y() +
                    element[i]->nodes_get(0)->get_sol(1) * scaleFactor);

    // Plot quadrilateral element by four lines
    plt::plot(coorX, coorY, "m-");

    // Reset coordinate vectors
    coorX.clear();
    coorY.clear();
  }
  plt::show(true);

  return;
}
