#ifndef     __TEST_PARTS__
#   define  __TEST_PARTS__

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
            void            informations(void) const;
    };
}

#endif //   !__TEST_PARTS__