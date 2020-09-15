/*------------------------------------------------------------------------------
@Author: Guanyu Li
@File:ProductionRule.cpp
@Date:10/13/2018
@Brief: this file is using vector as fundation to statisfy multiple functions, such
@ as get name of the vector, and get entry of the vector or get size of the vector.
------------------------------------------------------------------------------*/
#include"ProductionRule.h"
ProductionRule::ProductionRule(string name)
{
  department = name;
}

bool ProductionRule::isEmpty()
{
  return(myProduct.empty());
}

void ProductionRule::setTerminal(string Terminal)
{
  myProduct.push_back(Terminal);
}

int ProductionRule::getSize()const
{
  return(myProduct.size());
}

string ProductionRule::getDepart()const
{
  return(department);
}

string ProductionRule::getTerminal(int position)throw(runtime_error)
{
  if(position>myProduct.size()||position<1)
    throw(runtime_error("Invalid Position!"));
  return(myProduct.at(position-1));
}
