#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <vector>
#include "date.h"
#include "date.cc"

TEST(esBisiestoTest, Bisiesto){
  Fecha d1{13,11,2012};
  Fecha d2{14,12,2013};
  
  ASSERT_EQ(true, esBisiesto(d1));
  ASSERT_EQ(false, esBisiesto(d2));
}

TEST(esBisiestoTest, NoOrdenado){
  Fecha d1{2012,11,13};
  Fecha d2{13,11,2012};
  
  ASSERT_EQ(true, esBisiesto(d2));
  ASSERT_EQ(false, esBisiesto(d1));
}

TEST(TestComparar, Mayor){
  Fecha d1{12,12,2008};
  Fecha d2{13,10,2007};
  Fecha d3{14,10,2007};
  
  ASSERT_EQ(false, comparar(d1, d2));
  ASSERT_EQ(true, comparar(d2, d1));
  ASSERT_EQ(false, comparar(d1, d2));
  
TEST(TestComparar, Igual){
  Fecha d1{12,12,2008};
  Fecha d2{12,12,2008};
  
  ASSERT_EQ(false, comparar(d1,d2));
}

TEST(TestOrdenarFechas, SóloAñosDistintos){
  Fecha arr[3] = {{12,12,2011}, {11,11,2011}, {14,1,2011}};
  
  ordenarFechas(arr, 3);
  ASSERT_EQ(14, arr[0].d)
  ASSERT_EQ(1, arr[0].m)
  ASSERT_EQ(2011, arr[0].a)
  ASSERT_EQ(11, arr[1].d)
  ASSERT_EQ(11, arr[1].m)
  ASSERT_EQ(2011, arr[1].a)
  ASSERT_EQ(12, arr[2].d)
  ASSERT_EQ(12, arr[2].m)
  ASSERT_EQ(2011, arr[2].a)
}

TEST(TestOrdenarFechas, SóloDíasDistintos){
  Fecha arr[3] = {{22,11,2011}, {21,11,2011}, {20,11,2011}};
  
  ordenarFechas(arr, 3);
  ASSERT_EQ(20, arr[0].d)
  ASSERT_EQ(11, arr[0].m)
  ASSERT_EQ(2011, arr[0].a)
  ASSERT_EQ(21, arr[1].d)
  ASSERT_EQ(11, arr[1].m)
  ASSERT_EQ(2011, arr[1].a)
  ASSERT_EQ(22, arr[2].d)
  ASSERT_EQ(12, arr[2].m)
  ASSERT_EQ(2011, arr[2].a)
}
