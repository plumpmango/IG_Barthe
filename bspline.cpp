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

    std::vector<Point> ptI;
    for(int i = 0; i < getOrdre(); i++){
      Point p;
      p.x = pt.at(i+dec).x;
      p.y = pt.at(i+dec).y;
      p.z = pt.at(i+dec).z;
      ptI.push_back(p);
    }

    std::cout << "\nPoints interets : " << std::endl;
    for(unsigned int i = 0; i<ptI.size(); i++){
      std::cout << "(" << ptI.at(i).x << "," << ptI.at(i).y << "," << ptI.at(i).z << "," << ")"<< std::endl;
    }
    //assert(pt.size() =getOrdre());

      //algorithme de Floraison
    int k = getOrdre();
    int l = k;
    for(int j = 0; j<k-1;j++){
      for(int i = 0; i<l-1;i++){
        std::cout << "ptI(" << i << ") = (" << ptI.at(i).x << "," << ptI.at(i).y << "," << ptI.at(i).z << ") ; pt(" << i+1 << ") = (" << ptI.at(i+1).x << "," << ptI.at(i+1).y << "," << pt.at(i+1).z << ")" << std::endl;
        ptI.at(i).x = (vNodal[dec+l+i]-t) / (vNodal[dec+l+i]-vNodal[dec+1+i])*ptI[i].x + (t-vNodal[dec+1+i]) / (vNodal[dec+l+i]-vNodal[dec+1+i])*ptI[i+1].x;
        ptI.at(i).y = (vNodal[dec+l+i]-t) / (vNodal[dec+l+i]-vNodal[dec+1+i])*ptI[i].y + (t-vNodal[dec+1+i]) / (vNodal[dec+l+i]-vNodal[dec+1+i])*ptI[i+1].y;
        ptI.at(i).z = (vNodal[dec+l+i]-t) / (vNodal[dec+l+i]-vNodal[dec+1+i])*ptI[i].z + (t-vNodal[dec+1+i]) / (vNodal[dec+l+i]-vNodal[dec+1+i])*ptI[i+1].z;
        // std::cout << pt[i].x << "  "  << pt[i].y << "  " << pt[i].z << std::endl;
      }
      l--;
      dec++;
      // std::cout << "dec = " << dec << " l = " << l;
    }

    return ptI[0];

  }

  //Calcule le vecteur de points sur la courbe par approximation en appellant l'algo de floraison
  std::vector<Point> Bspline::calculerPointsBSpline(){
    std::vector<int> vNodal = getVectNodal();
    std::vector<Point> pt = getPc();

    for(unsigned int i = 0; i<pt.size(); i++){
      std::cout << "pt(" << i << ") = (" << pt.at(i).x << "," << pt.at(i).y << "," << pt.at(i).z << ")" << std::endl;
    }
    //Determiner l'intervalle
    float tmin(vNodal.at(getOrdre()-1));
    float tmax(vNodal.at(pt.size()));
    float dt(0.1);

    std::cout << "\ntmin = " << tmin << " & tmax = " << tmax << std::endl;

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
