#include <iostream>
#include <sstream>
#include <locale>
#include <vector>

#include "bspline.hpp"

int main(){

    std::cout << "Calcul de bspline " << std::endl;

    //Vecteur de point de contrôle
    int nbPointsControle(3);

    //ordre
    int k(2);

    //vecteur nodal uniforme
    std::vector<int> vectNodal(k+nbPointsControle);

    for(unsigned int i = 0; i<vectNodal.size(); i++){
      vectNodal[i] = i;
    }

    //points de contrôles
    std::vector<Point> pointsControles;

    // for(int i = 0; i<nbPointsControle; i++){
    //   float val(i);
    //   Point p{val,val,0};
    //   pointsControles.push_back(p);
    // }
    Point p0{1,1,0};
    pointsControles.push_back(p0);
    Point p1{2,4,0};
    pointsControles.push_back(p1);
    Point p2{4,0,0};
    pointsControles.push_back(p2);

    Bspline b(pointsControles, vectNodal, k);
    b.afficherBSpline();

    return 0;

}
