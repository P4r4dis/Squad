#ifndef     __PARTS__
#   define  __PARTS__

#include <string>
namespace   Parts
{
    class   Arms
    {
        private:
            std::string     _serial;
            bool            _functional;
        public:
            Arms(std::string serial = "A-01", bool functional = true);
            ~Arms(void);

            bool            isFunctional(void) const;
            std::string     serial(void) const;
    };
}


#endif //   !__PARTS__