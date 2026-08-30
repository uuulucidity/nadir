///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
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
///   File: sleep.hpp
///
/// Author: $author$
///   Date: 1/25/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_OS_SLEEP_HPP
#define XOS_OS_SLEEP_HPP

#include "xos/os/os.hpp"

#if defined(WINDOWS)  
#include "xos/os/microsoft/windows/sleep.hpp"
#elif defined(APPLEOSX)  
#include "xos/os/apple/osx/sleep.hpp"
#elif defined(APPLEIOS)  
#include "xos/os/apple/ios/sleep.hpp"
#elif defined(SOLARIS)  
#include "xos/os/oracle/solaris/sleep.hpp"
#elif defined(MACH)  
#include "xos/os/mach/sleep.hpp"
#elif defined(LINUX)  
#include "xos/os/linux/sleep.hpp"
#else /// defined(LINUX)  
#include "xos/os/posix/sleep.hpp"
#endif /// defined(LINUX) 

namespace xos {
namespace os {

/// sleep seconds
inline int sleep(seconds_t seconds) {
    return xos::os::os::sleep(seconds);
}

/// msleep milliseconds
inline int msleep(seconds_t mseconds) {
    return xos::os::os::msleep(mseconds);
}

/// usleep microseconds
inline int usleep(useconds_t useconds) {
    return xos::os::os::usleep(useconds);
}

} /// namespace os
} /// namespace xos

#endif /// XOS_OS_SLEEP_HPP
