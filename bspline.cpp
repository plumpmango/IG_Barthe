#include "bspline.hpp"
#include <assert.h>


/*Floraison donne un point de la courbe à un instant t */
  Point Bspline::floraison(float t){
    //Determination des points d'influence
    int dec = 0;
    int ind = getOrdre();
    std::vector<int> vNodal = getVectNodal();

    while(vNodal.at(ind)<t){
      ++dec;
      ++ind;
    }

    std::vector<Point> pt = getPc();

    //assert(pt.size() =getOrdre());

      //algorithme de Floraison
    int k = getOrdre();
    int l = k;
    for(int j = 0; j<k-1;j++){
      for(int i = 0; i<l-1;i++){
        pt.at(i).x = (vNodal[dec+l+i]-t) / (vNodal[dec+l+i]-vNodal[dec+1+i])*pt[i].x + (t-vNodal[dec+1+i]) / (vNodal[dec+l+i]-vNodal[dec+1+i])*pt[i+1].x;
        pt.at(i).y = (vNodal[dec+l+i]-t) / (vNodal[dec+l+i]-vNodal[dec+1+i])*pt[i].y + (t-vNodal[dec+1+i]) / (vNodal[dec+l+i]-vNodal[dec+1+i])*pt[i+1].y;
        pt.at(i).z = (vNodal[dec+l+i]-t) / (vNodal[dec+l+i]-vNodal[dec+1+i])*pt[i].z + (t-vNodal[dec+1+i]) / (vNodal[dec+l+i]-vNodal[dec+1+i])*pt[i+1].z;
        // std::cout << pt[i].x << "  "  << pt[i].y << "  " << pt[i].z << std::endl;
      }
      --l;
      ++dec;
      // std::cout << "dec = " << dec << " l = " << l;
    }

    return pt[0];

  }

  //Calcule le vecteur de points sur la courbe par approximation en appellant l'algo de floraison
  std::vector<Point> Bspline::calculerPointsBSpline(){
    std::vector<int> vNodal = getVectNodal();
    std::vector<Point> pt = getPc();
    //Determiner l'intervalle
    float tmin(vNodal.at(getOrdre()-1));
    float tmax(vNodal.at(pt.size()));
    float dt(0.1);

    std::vector<Point> ptsBspline;
    for(float i = tmin ; i <= tmax; i+=dt){
      ptsBspline.push_back(floraison(i));
    }

    return ptsBspline;
  }


  void Bspline::afficherBSpline(){
    std::vector<Point> ptsCourbes = calculerPointsBSpline();

    // for(std::vector<Point>::iterator it = ptsCourbes.begin(); it != ptsCourbes.end();++it){
    //   std::cout << *it << std::endl;
    // }
    for(unsigned int i = 0; i<ptsCourbes.size(); i++){
      std::cout << "(" << ptsCourbes.at(i).x << "," << ptsCourbes.at(i).y << "," << ptsCourbes.at(i).z << ")" << std::endl;
    }

  }
