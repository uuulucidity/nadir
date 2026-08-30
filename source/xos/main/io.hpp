//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2023 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: io.hpp
///
/// Author: $author$
///   Date: 3/19/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_MAIN_IO_HPP
#define XOS_MAIN_IO_HPP

#include "xos/main/input.hpp"
#include "xos/main/output.hpp"
#include "xos/main/error.hpp"

namespace xos {
namespace main {

/// class iot
template 
<typename TChar = char, typename TFile = FILE*, class TLocked = xos::locked, 
 class TSequence = xos::main::sequencet<TChar, TFile, TLocked>, 
 class TInput = xos::main::inputt<TChar, TFile, TLocked>, 
 class TOutput = xos::main::outputt<TChar, TFile, TLocked>, 
 class TError = xos::main::errort<TChar, TFile, TLocked>, 
 class TSequenceImplements = TSequence, class TInputImplements = TInput, 
 class TOutputImplements = TOutput, class TErrorImplements = TError>

class exported iot
: virtual public TSequenceImplements, virtual public TInputImplements,
  virtual public TOutputImplements, virtual public TErrorImplements {
public:
    typedef TSequenceImplements sequence_implements;
    typedef TInputImplements input_implements;
    typedef TOutputImplements output_implements;
    typedef TErrorImplements error_implements;
    typedef iot derives; 
    
    typedef TFile file_t;
    typedef int null_file_t;
    enum { null_file = 0 };

    typedef stringt<TChar> string_t;
    typedef TChar char_t;
    typedef char_t end_char_t;
    enum { end_char = 0 };

    typedef char_t what_t;
    typedef char_t sized_t;
    
    /// constructors / destructor
    virtual ~iot() {
    }

}; /// class iot
typedef iot<> io;

namespace extended {
/// class iot
template 
<typename TChar = char, typename TFile = FILE*, class TIo = iot<TChar, TFile>, 
 class TExtends = xos::extended::lockt<extend, TIo>, class TImplements = typename TExtends::implements>
class exported iot: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef iot derives;

    /// constructor / destructor
    iot() {
    }
    virtual ~iot() {
    }
private:
    iot(const iot &copy) {
    }
public:

protected:
}; /// class iot
typedef iot<> io;
} /// namespace extended 

} /// namespace main 
} /// namespace xos 

#endif /// ndef XOS_MAIN_IO_HPP
