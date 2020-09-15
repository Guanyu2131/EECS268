/*------------------------------------------------------------------------------
@Author: Guanyu Li
@File:browser.h
@Date:9/14/2018
@Brief: this file is connect the function from LinkedList.h to satisfy more
@precise function, such as forward, back, navigate, print.
------------------------------------------------------------------------------*/
#ifndef BROWSER_H
#define BROWSER_H
#include "WebBrowserInterface.h"
#include "LinkedList.h"
#include<string>
#include<iostream>

class browser: public WebBrowserInterface
{
private:
  LinkedList<string>* myhistory;
  int current;

public:
  
  /**
  * @post All memory allocated by the implementing class should be freed.
  *       This, as with all virtual destrucors, is an empty definition since we
  *       have no knowledge of specific implementation details.
  */
  ~browser();

  /**
  *@pre nothing is there
  *@post initialize the browser
  **/
  browser();

  /**
  * @pre none
  * @post the browser navigate to the given url
  * @param url, a string representing a URL
  */
  void navigateTo(string url);

  /**
  * @pre none
  * @post if possible, the browser navigates forward in the history otherwise it
  * keeps focus on the current URL
  */
  void forward();

  /**
  * @pre none
  * @post if possible, the browser navigates backwards in the history otherwise
  *it keeps focus on the current URL
  */
  void back();

  /**
  * @return the current URL
  */
  string currentURL() const;

  /**
  *@print all the node
  **/
  void print();

  /**
  * @pre The list being passed in is empty
  * @post The current browser history is copied into the given list
  * @param destination, an empty list of strings that will have a copy of current history copied into
  */
  void copyCurrentHistory(ListInterface<string>& destination);
};
#include "browser.cpp"
#endif
