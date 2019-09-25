#ifndef BSPLINE_HPP
#define BSPLINE_HPP

#include <iostream>
#include <vector>

struct Point{
	float x;
	float y;
	float z;
};

class Bspline{
  public:
  	Bspline(std::vector<Point> pc,std::vector<int> vectNodal,int ordre) : _pc(pc), _vectNodal(vectNodal), _ordre(ordre) {};
  	inline std::vector<int> getVectNodal(){return _vectNodal;};
  	inline std::vector<Point> getPc(){return _pc;};
  	inline int getOrdre(){return _ordre;};
	/*Floraison donne un point de la courbe à un instant t */
  	Point floraison(float t);
  	//Calcule le vecteur de points sur la courbe par approximation
    std::vector<Point> calculerPointsBSpline();
    void afficherBSpline();
    ~Bspline(){};
  private:
    std::vector<Point> _pc;
    std::vector<int> _vectNodal;
    int _ordre;
};

#endif
