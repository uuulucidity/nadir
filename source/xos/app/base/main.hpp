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
///   File: main.hpp
///
/// Author: $author$
///   Date: 3/19/2023, 7/22/2025
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_BASE_MAIN_HPP
#define XOS_APP_BASE_MAIN_HPP

#include "xos/main/io.hpp"
#include "xos/io/reader.hpp"
#include "xos/io/writer.hpp"
#include "xos/base/logged.hpp"
#include "xos/base/logger.hpp"
#include "xos/base/location.hpp"

namespace xos {
namespace app {
namespace base {

/// class maint
template 
<typename TChar = char, class TIo = xos::main::iot<TChar>, 
 class TExtends = xos::extended::logged, class TImplements = TIo>
class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef TIo io_t;
    typedef xos::io::sequencet<TChar> sequence_t;
    typedef xos::io::seekert<sequence_t> seeker_t;
    typedef xos::io::readert<seeker_t> reader_t;
    typedef xos::io::writert<sequence_t> writer_t;
    typedef xos::io::char_sequencet<TChar> char_sequence_t;
    typedef xos::io::char_seekert<char_sequence_t> char_seeker_t;
    typedef xos::io::char_readert<char_seeker_t> char_reader_t;
    typedef xos::io::char_writert<char_sequence_t> char_writer_t;
    typedef typename implements::file_t file_t;
    typedef typename implements::string_t string_t;
    typedef TChar char_t;
    typedef char_t end_char_t;
    enum { end_char = 0 };

    /// constructor / destructor
    maint(): run_(0), in_reader_(*this), out_writer_(*this), err_writer_(*this) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy): run_(0), in_reader_(*this), out_writer_(*this), err_writer_(*this) {
        throw exception(exception_unexpected);
    }
public:

    virtual int all_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_run(argc, argv, env))) {
            int err2 = 0;
            err = run(argc, argv, env);
            if ((err2 = after_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

protected:
    typedef xos::extend io_extends_t;

    /// class io_extend_t
    class exported io_extend_t: public io_extends_t {
    public:
        typedef io_extends_t extends;
        typedef io_extend_t derives;
    
        /// constructor / destructor
        io_extend_t(const io_extend_t& copy): extends(copy), io_(copy.io_) {
        }
        io_extend_t(io_t& io): io_(io) {
        }
        virtual ~io_extend_t() {
        }
    protected:
        io_t& io_;
    }; /// class io_extend_t
    
    /// class in_reader_t
    class exported in_reader_t: virtual public reader_t, public io_extend_t {
    public:
        typedef reader_t implements;
        typedef io_extend_t extends;
        typedef in_reader_t derives;
    
        typedef typename implements::what_t what_t;
        typedef typename implements::sized_t sized_t;

        /// constructor / destructor
        in_reader_t(const in_reader_t& copy): extends(copy) {
        }
        in_reader_t(io_t& io): extends(io) {
        }
        virtual ~in_reader_t() {
        }
        virtual ssize_t read(what_t* what, size_t size) {
            ssize_t count = 0;
            count = this->io_.in(what, size);
            return count;
        }    
    }; /// class in_reader_t
    
    /// class out_writer_t
    class exported out_writer_t: virtual public writer_t, public io_extend_t {
    public:
        typedef writer_t implements;
        typedef io_extend_t extends;
        typedef out_writer_t derives;
    
        typedef typename implements::what_t what_t;
        typedef typename implements::sized_t sized_t;

        /// constructor / destructor
        out_writer_t(const out_writer_t& copy): extends(copy) {
        }
        out_writer_t(io_t& io): extends(io) {
        }
        virtual ~out_writer_t() {
        }
        virtual ssize_t write(const what_t* what, size_t size) {
            ssize_t count = 0;
            count = this->io_.out(what, size);
            return count;
        }    
        virtual ssize_t flush() {
            ssize_t count = 0;
            count = this->io_.out_flush();
            return count;
        }    
    }; /// class out_writer_t
    
    /// class err_writer_t
    class exported err_writer_t: virtual public writer_t, public io_extend_t {
    public:
        typedef writer_t implements;
        typedef io_extend_t extends;
        typedef err_writer_t derives;
    
        typedef typename implements::what_t what_t;
        typedef typename implements::sized_t sized_t;

        /// constructor / destructor
        err_writer_t(const err_writer_t& copy): extends(copy) {
        }
        err_writer_t(io_t& io): extends(io) {
        }
        virtual ~err_writer_t() {
        }
        virtual ssize_t write(const what_t* what, size_t size) {
            ssize_t count = 0;
            count = this->io_.err(what, size);
            return count;
        }    
        virtual ssize_t flush() {
            ssize_t count = 0;
            count = this->io_.err_flush();
            return count;
        }    
    }; /// class err_writer_t
    
protected:
    /// ...run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (run_) {
            if (!(err = (this->*run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

protected:
    in_reader_t in_reader_;
    out_writer_t out_writer_;
    err_writer_t err_writer_;
}; /// class maint
typedef maint<> main;

} /// namespace base 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_BASE_MAIN_HPP
