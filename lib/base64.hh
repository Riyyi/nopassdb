/**
 * @package de.atwillys.cc.swl
 * @license BSD (simplified)
 * @author Stefan Wilhelm (stfwi)
 *
 * @file base64.hh
 * @ccflags
 * @ldflags
 * @platform linux, bsd, windows
 * @standard >= c++98
 *
 * -----------------------------------------------------------------------------
 *
 * Base64 encoding/decoding class.
 *
 * - Template: template <string_type> class sw::templates::basic_base64;
 *
 * - std::string specialisation: sw::base64;
 *
 * Provided methods for binary data:
 *
 *  - static bool encode(const void* si, size_t len, string_type & s);
 *
 *  - static bool decode(const string & s, void* so, size_t max_so, size_t *n);
 *
 * Provided methods for text data:
 *
 *  - static bool encode(const string & s_in, string & s_out);
 *
 *  - static bool decode(const string & s_in, string & s_out);
 *
 * Usage example (using text encoding/decoding functions):
 *
 *  #include <sw/base64.hh>
 *  int main()
 *  {
 *    std::string src="test", enc, dec;
 *    if(!base64::encode(src, enc)) { return 1; }
 *    if(!base64::decode(enc, dec)) { return 2; }
 *    return (src==dec) ? 0 : 3;
 *  }
 *
 * -----------------------------------------------------------------------------
 * +++ BSD license header (You know that ...) +++
 * Copyright (c) 2008-2014, Stefan Wilhelm (stfwi, <cerbero s@atwilly s.de>)
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met: (1) Redistributions
 * of source code must retain the above copyright notice, this list of conditions
 * and the following disclaimer. (2) Redistributions in binary form must reproduce
 * the above copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the distribution.
 * (3) Neither the name of atwillys.de nor the names of its contributors may be
 * used to endorse or promote products derived from this software without specific
 * prior written permission. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS
 * AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
 * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
 * WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 * -----------------------------------------------------------------------------
 */
#ifndef BASE64_HH
#define BASE64_HH
#include <string>
#include <sstream>

namespace sw { namespace templates {

// <editor-fold desc="interface" defaultstate="collapsed">
template <typename string_type>
class basic_base64
{
public:

  /**
   * Returns the memory size required to decode given encoded data
   * @param const string_type & s
   * @return size_t
   */
  static inline size_t max_decode_size(const string_type & s);

  /**
   * Encode binary dat
   * @param const void* si
   * @param size_t len
   * @param string_type& s
   * @return bool
   */
  static bool encode(const void* si, size_t len, string_type & s);

  /**
   * Decode binary data
   * @param const string_type& s
   * @param void* so
   * @param size_t max_so
   * @param size_t *n_so_converted
   * @return bool
   */
  static bool decode(const string_type & s, void* so, size_t max_so, size_t *n_so_converted);

  /**
   * Encode string
   * @param const string_type& s_in
   * @param string_type & s_out
   * @return bool
   */
  static inline bool encode(const string_type & s_in, string_type & s_out);

  /**
   * Decode string
   * @param const string_type& s_in
   * @param string_type& s_out
   * @return bool
   */
  static inline bool decode(const string_type & s_in, string_type & s_out);

private:
  static inline bool decode4to3(const char* c4i, unsigned char* c3);
  static inline bool encode3to4(const unsigned char* c3, char* c4);
  static const char emap_[64];
  static const unsigned char dmap_[256];
};
// </editor-fold>

// <editor-fold desc="implementation" defaultstate="collapsed">
template <typename string_type>
const char basic_base64<string_type>::emap_[64] = {
  0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50,
  0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66,
  0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76,
  0x77, 0x78, 0x79, 0x7a, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x2b, 0x2f
};

template <typename string_type>
const unsigned char basic_base64<string_type>::dmap_[256] = {
  0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3e, 0xff, 0xff, 0xff, 0x3f,
  0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff,
  0xff, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e,
  0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
  0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

template <typename string_type>
bool basic_base64<string_type>::encode3to4(const unsigned char* c3, char* c4)
{
  c4[0] = emap_[ (unsigned char) (((c3[0] & 0xfc) >> 2)) ];
  c4[1] = emap_[ (unsigned char) (((c3[0] & 0x03) << 4) + ((c3[1] & 0xf0) >> 4)) ];
  c4[2] = emap_[ (unsigned char) (((c3[1] & 0x0f) << 2) + ((c3[2] & 0xc0) >> 6)) ];
  c4[3] = emap_[ (unsigned char) (((c3[2] & 0x3f))) ];
  return true;
}

template <typename string_type>
bool basic_base64<string_type>::decode4to3(const char* c4i, unsigned char* c3)
{
  unsigned char c4[4];
  for (int i = 0; i < 4; ++i) {
    c4[i] = dmap_[ (unsigned char) c4i[i]];
  } // printf("%c->%02x|", c4i[i], c4[i], c4[i]);
  c3[0] = (((c4[0] << 2)) + ((c4[1] & 0x30) >> 4));
  c3[1] = (((c4[1] & 0xf) << 4) + ((c4[2] & 0x3c) >> 2));
  c3[2] = (((c4[2] & 0x3) << 6) + ((c4[3])));
  return c4[0] < 0xfa && c4[1] < 0xfa && c4[2] < 0xfa && c4[3] < 0xfa;
}

template <typename string_type>
size_t basic_base64<string_type>::max_decode_size(const string_type & s)
{ return s.length() * 3 / 4; }


template <typename string_type>
bool basic_base64<string_type>::encode(const string_type & s_in, string_type & s_out)
{ return encode(s_in.c_str(), s_in.length(), s_out); }


template <typename string_type>
bool basic_base64<string_type>::decode(const string_type & s_in, string_type & s_out)
{
  s_out = "";
  if(s_in.empty()) return true;
  size_t n = max_decode_size(s_in)+1, nw=0;
  char *tmp;
  try { tmp = new char[n]; } catch(...) { return false; } // Legacy promise preventing exceptions
  bool ok = decode(s_in, tmp, n, &nw);
  if(ok) tmp[nw] = '\0';
  s_out = tmp;
  delete [] tmp;
  return ok;
}

template <typename string_type>
bool basic_base64<string_type>::encode(const void* si, size_t len, string_type & s)
{
  s.clear();
  if (!si) {
    return false;
  } else if (len == 0) {
    return true;
  } else {
    std::stringstream so;
    char c4[4];
    const unsigned char* pi = (unsigned char*) si; // byte stepped pointer
    const unsigned char* pe = (unsigned char*) si + len; // end pointer
    const unsigned char* pm = (unsigned char*) si + (len - (len % 3)); // loop end pointer
    unsigned int i = 0;
    while (pi < pm) {
      encode3to4(pi, c4);
      pi += 3;
      for (int i = 0; i < 4; ++i) so << c4[i];
    }
    if (pe > pm) {
      unsigned char c3[3];
      for (i = 0; i < (len % 3); ++i) c3[i] = *(pi++);
      while (i < 4) c3[i++] = '\0';
      encode3to4(c3, c4);
      for (i = 0; i < (len % 3) + 1; ++i) so << c4[i];
      while (i++ < 4) so << "=";
    }
    s = so.str();
    return true;
  }
  return false;
}

template <typename string_type>
bool basic_base64<string_type>::decode(const string_type & s, void* so, size_t max_so, size_t *n_so_converted)
{
  size_t nc = 0;
  if(n_so_converted) *n_so_converted = 0;
  if (max_so < max_decode_size(s)) return false;
  const char* pi = (const char*) s.c_str(); // input iteration pointer
  const char* pe = (const char*) pi + s.length(); // input iteration end() pointer
  unsigned char* po = (unsigned char*) so; // output (iterated) pointer
  bool isend = false;
  while (pi < pe) {
    if (decode4to3(pi, po)) {
      nc += 3;
      pi += 4;
      po += 3;
    } else {
      char c4[4];
      size_t c4l = 0;
      c4[0]=c4[1]=c4[2]=c4[3] = 0; //memset(c4, 0, 4);
      while (c4l < 4 && pi < pe && !isend) {
        switch (dmap_[(unsigned char) *pi]) {
          case 0xff: if(n_so_converted) *n_so_converted=nc; return false; // invalid char
          case 0xfe: ++pi; break; // ignored char (space char, newline...)
          case 0xfd: isend = true; break; // (id 0xff-1) in decode map is '='
          case 0xfc: isend = true; break; // 0xfc in decode map is '\0'
          default: c4[c4l++] = *pi++;
        }
      }
      if (!isend) {
        if (decode4to3(c4, po)) {
          nc += 3;
          po += 3;
        } else {
          if(n_so_converted) *n_so_converted=nc;
          return false;
        }
      } else {
        for (int i = c4l; i < 4; i++) c4[i] = '\0';
        decode4to3(c4, po);
        nc += c4l - 1;
        pi = pe;
      }
    }
  }
  if(n_so_converted) *n_so_converted=nc;
  return true;
}
// </editor-fold>

// <editor-fold desc="lut-gen" defaultstate="collapsed">
#ifdef BASE64_ENABLE_MK_TABLES
  void make_base_64tables()
  {
    const string_type cmap = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    unsigned char dmap[256];
    char emap[64];
    int i;
    for(i=0; i<cmap.length(); ++i) emap[i] = cmap[i];
    memset(dmap, 0xff, 256);
    for(i=0; i<cmap.length(); ++i) dmap[(unsigned char) emap[i]] = (unsigned char) i;
    printf("const char emap = { \n");
    for(i=0; i<sizeof(emap); ++i) {
      if(i%8==0) printf("\n");
      printf("0x%02x,", (unsigned) emap[i]);
    }
    printf("}; \n\n const unsigned char base64::dmap_[256] = {");
    for(i=0; i<sizeof(dmap); ++i) {
      if(i%8==0) printf("\n");
      if(i==0) printf("0xfc,");
      else if(i == '=') printf("0xfd,");
      else if(isspace(i) || i=='\n' || i=='\r') printf("0xfe,");
      else printf("0x%02x,", (unsigned) dmap[i]);
    }
    printf("\n};\n");
  }
#endif

}} // namespace sw/templates
// </editor-fold>

// <editor-fold desc="specialisation" defaultstate="collapsed">
/**
 * std::string specialisation
 * THIS IS THE ONE NORMALLY USED
 */
namespace sw {
  typedef templates::basic_base64<std::string> base64;
}
// </editor-fold>

#endif
