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

#define NEED_LOG 1
#define NEED_QUEUE_LOG 1


#include "LogManagement.h"
#include <string>


String str2("test log String");
std::string str;  
char *str3;
int a =50;
  
void setup(void)  
{
	Serial.begin(115200);
   str3 = (char *)malloc(20); 
   sprintf(str3,"test log char*");
}

void loop(void)
{

 
  LOG_LN(str2)
  LOG("test log int ")
  LOG_LN(a)
  LOG_LN(str3)
  
	str = Logger.GetOneLog();
	Serial.println(str.c_str());

delay(200);
  str = Logger.GetAllLogsWithNSeparator();
  Serial.println(str.c_str());

delay(200);
}
