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

#include "LogManagement.h"

  LogManagement Logger;

  LogManagement::LogManagement(int maxLogCount)
  {
    if (maxLogCount > CGE_MAX_LOG_COUNT)
      maxLogCount =CGE_MAX_LOG_COUNT;

      _maxLogCount = maxLogCount;
  }
  
  LogManagement::~LogManagement(void)
  {
    while(!_logQueue.empty())
    {
      delete _logQueue.front();
      _logQueue.pop(); 
    }
  }

  std::string LogManagement::GetOneLog(void)
  { 
	std::string str("");
	
    if (!_logQueue.empty())
    {
      std::string *pStr = _logQueue.front();
	  str.append(*pStr);
	  delete pStr;
      _logQueue.pop();
    }
	
    return str;
  } 

  std::string LogManagement::GetAllLogs(bool withBrSeparator)
  { 
	std::string str("");
	std::string *pStr=NULL;
    while(!_logQueue.empty())
    {
      pStr = _logQueue.front();
	  str.append(*pStr);
	  if (withBrSeparator)
		  str.append("<BR>");
	  else 
		  str.append("\n");
	  delete pStr;
      _logQueue.pop();
    }
	
    return str;
  } 



  void LogManagement::AddLog(const std::string &logToAdd)
  { 
      /* check if we reached max size, and if so, cleanup */
    while (_logQueue.size() >= _maxLogCount)
    {
      delete _logQueue.front();
      _logQueue.pop();
    }

    /* now insert the new element */
    std::string *pStr = new std::string(logToAdd);
    _logQueue.push(pStr);
  } 
  

  void LogManagement::AddLog(const int &logToAdd)
  {
	char tmpBuffer[60];
	snprintf(tmpBuffer,59,"%d",logToAdd);
	
	AddLog((const char *)tmpBuffer);
  }
  
  void LogManagement::AddLog(const char * logToAdd)
  { 
    const std::string str(logToAdd);
    AddLog(str);
  } 

  void LogManagement::AddLog(const String &logToAdd)
  { 
    std::string str(logToAdd.c_str());
    AddLog(str);
  } 