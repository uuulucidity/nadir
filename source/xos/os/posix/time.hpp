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
///   File: time.hpp
///
/// Author: $author$
///   Date: 1/26/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_OS_POSIX_TIME_HPP
#define XOS_OS_POSIX_TIME_HPP

#include "xos/base/time.hpp"
#include <sys/time.h>

namespace xos {
namespace os {
namespace posix {

/// clockid_t
#if !defined(CLOCK_REALTIME)
typedef int clockid_t;
enum { CLOCK_REALTIME = 0 };
#endif /// !defined(CLOCK_REALTIME)

/// clock_gettime
#if !defined(CLOCK_HAS_GETTIME)
#define CLOCK_HAS_GETTIME
#endif /// !defined(CLOCK_HAS_GETTIME)
inline int clock_gettime(clockid_t clk_id, struct timespec *res) {
    if ((res) && (CLOCK_REALTIME == clk_id)) {
        int err = 0;
        struct timeval tv;
        if ((err = ::gettimeofday(&tv, NULL))) {
            res->tv_sec = 0;
            res->tv_nsec = 0;
            return errno;
        } else {
            res->tv_sec = tv.tv_sec;
            res->tv_nsec = ::xos::useconds_nseconds(tv.tv_usec);
            return 0;
        }
    }
    return EINVAL;
}

/// gettimeofday
inline int gettimeofday(struct timeval* tv, void* p) {
    return ::gettimeofday(tv, p);
}

} /// namespace posix
} /// namespace os
} /// namespace xos

#endif /// XOS_OS_POSIX_TIME_HPP
