/******************************************************************************
MIT License

Copyright (c) 2019 Cyrille Gaillardet

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/



#ifndef _CGE_LOG_MANAGEMENT_H
#define _CGE_LOG_MANAGEMENT_H

#ifdef NEED_LOG
  #ifdef NEED_QUEUE_LOG
    #define LOG(x)    {do {Serial.print(x); Logger.addLog(x);)}while(0);}
    #define LOG_LN(x)  {do {Serial.println(x); Logger.addLog(x);}while(0);}
  #else
    #define LOG(x)     {Serial.print(x);}
    #define LOG_LN(x)   {Serial.println(x);}
  #endif
#else
  #define LOG(x)      {}
  #define LOG_LN(x)    {} 
#endif 



#include <queue>
#include <ostream>
#include <string>

#include "arduino.h"
#define CGE_MAX_LOG_COUNT 12

using namespace std; 
class LogManagement
{
	
  public:
  
  LogManagement(int maxLogCount= CGE_MAX_LOG_COUNT); 
  ~LogManagement(void);
  void begin(void);
  void addLog(int logToAdd);
  void addLog(string &logToAdd);
  void addLog(char * logToAdd);

  string getOneLog(void);
  string getAllLogs(bool withBrSeparator);
  
  private:
  int _maxLogCount;
  queue<string*> _logQueue;  
};

extern LogManagement Logger;

#endif

