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
///   Date: 1/27/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_OS_MICROSOFT_WINDOWS_SLEEP_HPP
#define XOS_OS_MICROSOFT_WINDOWS_SLEEP_HPP

#include "xos/base/time.hpp"

namespace xos {
namespace os {
namespace microsoft {
namespace windows {

/// sleep seconds
inline int sleep(seconds_t seconds) {
    ::Sleep(seconds_mseconds(seconds));
    return 0;
}

/// msleep milliseconds
inline int msleep(mseconds_t mseconds) {
    ::Sleep(mseconds);
    return 0;
}

/// usleep microseconds
inline int usleep(useconds_t useconds) {
    ::Sleep(useconds_mseconds(useconds));
    return 0;
}

} /// namespace windows
} /// namespace microsoft
} /// namespace os
} /// namespace xos

#endif /// XOS_OS_MICROSOFT_WINDOWS_SLEEP_HPP
