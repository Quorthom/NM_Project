#include "parameters.h"

//constructor
parametros::parametros(){
  //variables
  m_xi = 0;
  m_xs = 0;
  m_xm = 0;
  m_xf = 0;

  //funciones
  m_fxi = 0;
  m_fxs = 0;
  m_fxm = 0;
  m_fxf = 0;
}

//accessors
const double& parametros::xi() const{
  return m_xi;
}
const double& parametros::xs() const{
  return m_xs;
}
const double& parametros::xm() const{
  return m_xm;
}
const double& parametros::xf() const{
  return m_xf;
}
const double& parametros::xf() const{
  return m_xr;
}

const double& parametros::fxi() const{
  return m_fxi;
}
const double& parametros::fxs() const{
  return m_fxs;
}
const double& parametros::fxm() const{
  return m_fxm;
}
const double& parametros::fxf() const{
  return m_fxf;
}
const double& parametros::fxf() const{
  return m_fxr;
}

//mutators
double& parametros::xi(){
  return m_xi;
}
double& parametros::xs(){
  return m_xs;
}
double& parametros::xm(){
  return m_xm;
}
double& parametros::xf(){
  return m_xf;
}
double& parametros::xr(){
  return m_xr;
}

double& parametros::fxi(){
  return m_fxi;
}
double& parametros::fxs(){
  return m_fxs;
}
double& parametros::fxm(){
  return m_fxm;
}
double& parametros::fxf(){
  return m_fxf;
}
double& parametros::fxf(){
  return m_fxr;
}

void parametros::getxm(){
  m_xm = (m_xi + m_xs)/2;
}

void parametros::getxf(){
  m_xf = m_xs - ( ( m_fxs * ( m_xs - m_xi ) ) / ( m_fxs - m_fxi ) );
}

void parametros::getxr(){
  double a[3];
  a[0] = ( m_fxi*m_xm*m_xs )/( (m_xi*m_xm) + (m_xi*m_xs) - (m_xm*m_xs) - (m_xi*m_xi) ) - ( m_fxm*m_xi*m_xs )/( m_xi*m_xm - m_xi*m_xs + m_xm*m_xs - m_xm*m_xm ) + ( m_fxs*m_xi*m_xm )/( m_xi*m_xm - m_xi*m_xs - m_xm*m_xs + m_xs*m_xs );
  a[1] = ( m_fxi*(m_xm+m_xs) )/( m_xi*m_xm + m_xi*m_xs - m_xm*m_xs - m_xi*m_xi ) + ( m_fxm*(m_xi+m_xs) )/( m_xi*m_xm - m_xi*m_xs + m_xm*m_xs - m_xm*m_xm ) + ( m_fxs*(m_xi+m_xm) )/( m_xi*m_xm - m_xi*m_xs - m_xm*m_xs + m_xs*m_xs );
  a[2] = -(m_fxi)/( m_xi*m_xm + m_xi*m_xs - m_xm*m_xs - m_xi*m_xi ) + (m_fxm)/( m_xi*m_xm - m_xi*m_xs + m_xm*m_xs - m_xm*m_xm ) + (m_fxs)/( m_xi*m_xm - m_xi*m_xs - m_xm*m_xs + m_xs*m_xs );

  xr[0] = (-a[1]+sqrt(a[1]*a[1]+4*a[0]*a[2])) / (2*a[2]);
  xr[1] = (-a[1]-sqrt(a[1]*a[1]+4*a[0]*a[2])) / (2*a[2]);
}
