//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2025 $organization$
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
///   File: main.hpp
///
/// Author: $author$
///   Date: 7/23/2025
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_SERVER_MAIN_HPP
#define XOS_APP_SERVER_MAIN_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace app {
namespace server {

//////////////////////////////////////////////////////////////////////////
/// class maint
template <class TExtends = xos::app::base::maint<>, class TImplements = typename TExtends::implements>
class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    //////////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    maint() {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy): extends(copy) {
    }
public:

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class maint
typedef maint<> main;

} /// namespace server 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_SERVER_MAIN_HPP

