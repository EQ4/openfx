/*
Software License :

Copyright (c) 2007-2009, The Open Effects Association Ltd. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.
* Neither the name The Open Effects Association Ltd, nor the names of its 
contributors may be used to endorse or promote products derived from this
software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "ofxCore.h"
#include "ofxhUtilities.h"
#ifdef WINDOWS
#include <windows.h>
#endif

namespace OFX {

  /// get me deepest bit depth 
  std::string FindDeepestBitDepth(const std::string &s1, const std::string &s2)
  {
    if(s1 == kOfxBitDepthNone) {
      return s2;
    }
    else if(s1 == kOfxBitDepthByte) {
      if(s2 == kOfxBitDepthShort || s2 == kOfxBitDepthFloat)
        return s2;
      return s1;
    }
    else if(s1 == kOfxBitDepthShort) {
      if(s2 == kOfxBitDepthFloat)
        return s2;
      return s1;
    }
    else if(s1 == kOfxBitDepthHalf) {
      if(s2 == kOfxBitDepthFloat)
        return s2;
      return s1;
    }
    else if(s1 == kOfxBitDepthFloat) {
      return s1;
    }
    else {
      return s2; // oooh this might be bad dad.
    }
  }

# ifdef WINDOWS
  std::wstring stringToWideString(const std::string& s)
  {
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
  }
  
  std::string  wideStringToString(const std::wstring& s)
  {
	size_t sz = s.length();
    int nd = WideCharToMultiByte(CP_UTF8, 0, &s[0], sz, 0, 0, 0, 0);
    std::string ret(nd, 0);
    WideCharToMultiByte(CP_UTF8, 0, &s[0], sz, &ret[0], nd, 0, 0);
    return ret;
  }
# endif

}
